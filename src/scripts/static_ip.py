#!/bin/python
import subprocess
import logging
import time
import netifaces

SSID = "uav123"
PASSWORD = "123456789@"
IFNAME = "wlo1"
IP_SUBFIX = "122"

KNOWN_MAC = ["dc:4a:9e:d3:46:29", "54:8d:5a:3b:86:ed"]


def get_network_interfaces_with_mac():
    global IFNAME
    interfaces = netifaces.interfaces()

    for iface in interfaces:
        addrs = netifaces.ifaddresses(iface)
        if netifaces.AF_LINK in addrs:
            mac = addrs[netifaces.AF_LINK][0].get("addr")
            if mac == KNOWN_MAC[0] or mac == KNOWN_MAC[1]:
                IFNAME = iface
                break


get_network_interfaces_with_mac()


def scan_ssids():
    try:
        result = subprocess.run(
            ["nmcli", "-t", "-f", "SSID", "dev", "wifi"],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            check=True,
        )
        return result.stdout.decode().splitlines()
    except subprocess.CalledProcessError as e:
        logging.error("Wi-Fi scan failed: %s", e.stderr.decode())
        return []


logging.info("Waiting for SSID '%s'...", SSID)

for _ in range(60):  # 最多等待60秒
    ssids = scan_ssids()
    if SSID in ssids:
        logging.info("SSID '%s' found.", SSID)
        break
    time.sleep(1)
else:
    logging.error("SSID '%s' not found after timeout.", SSID)
    exit(1)

res = subprocess.run(
    ["nmcli", "device", "wifi", "connect", SSID, "password", PASSWORD],
    check=True,
    stdout=subprocess.PIPE,
)
res = subprocess.run(["ifconfig", IFNAME], check=True, stdout=subprocess.PIPE)
ipaddresses = res.stdout.decode().split("\n")
for addr in ipaddresses:
    if "inet" in addr and "inet6" not in addr:
        nowIP = addr.lstrip().split(" ")[1]
if nowIP.split(".")[-1] != IP_SUBFIX:
    res = subprocess.run(["ip", "route"], check=True, stdout=subprocess.PIPE)
    iproutes = res.stdout.decode().split("\n")
    for route in iproutes:
        if IFNAME in route:
            temp = route.split(" ")
            if "default" in temp:
                GW = temp[2]
                break
    print(GW)
    IP = ".".join(GW.split(".")[:-1]) + "." + IP_SUBFIX + "/24"
    print(IP)
    subprocess.run(
        [
            "nmcli",
            "connection",
            "modify",
            SSID,
            "ipv4.addresses",
            IP,
            "ipv4.gateway",
            GW,
            "ipv4.dns",
            GW,
            "ipv4.method",
            "manual",
            "connection.autoconnect",
            "yes",
        ],
        check=True,
        stdout=subprocess.PIPE,
    )
    subprocess.run(["nmcli", "connection", "up", SSID], check=True)
else:
    print("already set target ip")
subprocess.run('echo "123456789" > test.txt', shell=True, check=True)
