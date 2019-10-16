#!/usr/bin/env python

from Crypto.PublicKey import RSA

def xgcd(a, b):
    if a == 0L:
        return (b, 0L, 1L)
    else:
        g, x, y = xgcd(b%a, a)
        return (g, y - (b // a) * x, x)

def modularInverse(a, b):
    g, x, _ = xgcd(a, b)
    if g == 1:
        return x % b

def main():
    
    n = 0x00d748e7389e3e2be7ebc931b7659e53cb
    prim1 = 15892154504452115339L
    prim2 = 18006529832677728449L
    e = 65537L

    d = modularInverse(e, ( prim1 - 1L ) * (prim2 - 1L) )

    llave_privada = RSA.construct((n,e,d))
    
    print llave_privada.exportKey()

main()