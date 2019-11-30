#!/usr/bin/env python

import sys
import time

from scapy.layers.inet import IP
from scapy.layers.inet import ICMP
from subprocess import check_output
from scapy.sendrecv import sr1

_net    = sys.argv[1].split(".")
_rangeA = int(sys.argv[2])
_rangeB = int(sys.argv[3])

size = 35

_all_IP = check_output(['hostname', '--all-ip-addresses']).split(" ")

alive_list = []
unreached_list = []

count = _rangeB - _rangeA + 1

def show(j,_ip):
        x = int(size*j/count)
        sys.stdout.write(
            "Enviando ICMP a Host %s [%s%s] %i/%i\r" % (_ip,"#"*x, "."*(size-x), j, count))
        sys.stdout.flush()

def main():
    for i in range(_rangeA, _rangeB+1):
        _ip_dst = _net[0]+"."+_net[1]+"."+_net[2]+"."+str(i)
        show( i - _rangeA + 1, _ip_dst)
        time.sleep(0.1)
        if _all_IP[0] == _ip_dst:
            alive_list.append(_ip_dst + " is alive")
            continue
        a = sr1(IP(dst=_ip_dst)/ICMP(), timeout=1, verbose=False,retry=3)
        if a:
            alive_list.append(_ip_dst + " is alive")
        else:        
            unreached_list.append( _ip_dst + " is unreachable")
    print ''
    for i in alive_list:
        print i
    for j in unreached_list:
        print j
main()