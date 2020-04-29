#!/usr/bin/env python

import sys

from scapy.sendrecv import sendp, sendpfast
from scapy.layers.l2 import Ether
from scapy.layers.inet import IP

_unicast_hex = "04"
_mac_dst = "02:00:00:00:00:00"
_ip_dst = "172.16.1.253"

def format(mac_address):
    limiter = 1
    mac = ""
    for i in mac_address:
        mac = mac + i
        if limiter%2 == 0 and limiter < 11:
            mac = mac + ":"
        limiter+=1
    return mac

def sendMac( _n_mac ):
    for i in range(0, _n_mac):
        hexval = hex(i).split("x")[1]
        remaind = 12 - 2 - len(hexval)
        mac = _unicast_hex+"0"*remaind+hexval
        sendpfast(Ether(src=format(mac),dst=_mac_dst)/IP(dst=_ip_dst))

def main():
    if len(sys.argv) > 1:
        if sys.argv[1] == "-n":
            count_random_mac = int(sys.argv[2])
            sendMac(count_random_mac)
        else:
            pass
    else:
        sendMac(100)
main()