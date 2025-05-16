#!/bin/python
import subprocess
import logging
import time
import netifaces

SSID = "uav123"
PASSWORD = "123456789@"
IFNAME = "wlo1"
IP_SUBFIX = "122"
STATIC_IPS = ["123", "122"]
KNOWN_MAC = ["dc:4a:9e:d3:46:29", "54:8d:5a:3b:86:ed"]


def get_network_interfaces_with_mac():
    global IFNAME
    global IP_SUBFIX
    interfaces = netifaces.interfaces()

    for iface in interfaces:
        addrs = netifaces.ifaddresses(iface)
        if netifaces.AF_LINK in addrs:
            mac = addrs[netifaces.AF_LINK][0].get("addr")
            if mac in KNOWN_MAC:
                IFNAME = iface
                IP_SUBFIX = STATIC_IPS[KNOWN_MAC.index(mac)]
                break

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
def waiting_for_wifi():
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

def main():
    get_network_interfaces_with_mac()
    waiting_for_wifi()
    subprocess.run(
        ["nmcli", "device", "wifi", "connect", SSID, "password", PASSWORD],
        check=True,
    )
    subprocess.run(
        ["nmcli","connection","delete",SSID],
        check=True
    )
    subprocess.run(
        ["nmcli", "device", "wifi", "connect", SSID, "password", PASSWORD],
        check=True,
    )
    res = subprocess.run(["ip", "route"], check=True, stdout=subprocess.PIPE)
    iproutes = res.stdout.decode().split("\n")
    for route in iproutes:
        if IFNAME in route and "default" in route:
            GW = route.split(" ")[2]
            break
    
    IP = ".".join(GW.split(".")[:-1]) + "." + IP_SUBFIX + "/24"
    print(f"setting GW:{GW},setting IP:{IP}")
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
if __name__ == "__main__":
    main()