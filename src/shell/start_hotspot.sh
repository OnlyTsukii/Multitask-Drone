#!/bin/bash

# set hotspot name and password
SSID="uav"
PASSWORD="12345678"
IFNAME="wlx502b73d03038"

# start hotspot
nmcli device wifi hotspot ifname $IFNAME ssid "$SSID" password "$PASSWORD"