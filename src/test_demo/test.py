import netifaces

def get_network_interfaces_with_mac():
    interfaces = netifaces.interfaces()
    
    for iface in interfaces:
        addrs = netifaces.ifaddresses(iface)
        if netifaces.AF_LINK in addrs:
            mac = addrs[netifaces.AF_LINK][0].get('addr')
            if mac == '58:1c:f8:b9:eb:7d':
                return iface
    
    return None
                
wireless_iface = get_network_interfaces_with_mac()
print(wireless_iface)
