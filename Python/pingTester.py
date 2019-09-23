#!/usr/bin/env python

import sys

from scapy.sendrecv import sr
from scapy.layers.inet import IP
from scapy.layers.inet import ICMP

_net    = sys.argv[1].split(".")
_rangeA = int(sys.argv[2])
_rangeB = int(sys.argv[3])

for i in range(_rangeA, _rangeB+1):
    _ip_dst = _net[0]+"."+_net[1]+"."+_net[2]+"."+str(i)
    a, b = sr(IP(dst=_ip_dst)/ICMP(), timeout=3, verbose=False)
    a.summary()
    b.summary()