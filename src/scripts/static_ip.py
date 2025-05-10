#!/bin/python
import subprocess
import logging
import time

SSID = "SDUA_WIFI"
PASSWORD = "zhen1234..zz"
IFNAME = "wlP1p1s0"
IP_SUBFIX = "123"


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

for _ in range(20):  # 最多等待20秒
    ssids = scan_ssids()
    if SSID in ssids:
        logging.info("SSID '%s' found.", SSID)
        break
    time.sleep(1)
else:
    logging.error("SSID '%s' not found after timeout.", SSID)
    exit(1)

isconnected = False
res = subprocess.run(
    ["nmcli", "connection", "show", "--active"], check=True, stdout=subprocess.PIPE
)
netinfos = res.stdout.decode().split("\n")
for netinfo in netinfos:
    if IFNAME in netinfo:
        isconnected = True
        break
if not isconnected:
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
            "SDUA_WIFI",
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
    subprocess.run(["nmcli", "connection", "up", "SDUA_WIFI"], check=True)
else:
    print("already set target ip")
subprocess.run('echo "123456789" > test.txt', shell=True, check=True)
