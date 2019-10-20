#!/usr/bin/env python

from Crypto.PublicKey import RSA

def extended_euclid(a, b):
    if a == 0L:
        return (b, 0L, 1L)
    else:
        g, x, y = extended_euclid(b%a, a)
        return (g, y - (b // a) * x, x)

def modularInverse(a, b):
    # gdc, d, s: solo nos interesa d
    g, x, _ = extended_euclid(a, b)
    if g == 1:
        return x % b

def main():
    
    #n = 0x00d748e7389e3e2be7ebc931b7659e53cb
    #prim1 = 15892154504452115339L
    #prim2 = 18006529832677728449L

    n = 0x00c262478a7171ed793af713edcc3003cb

    prim1 = 14459458659007638593L
    prim2 = 17869308484320582923L
    
    e = 65537L

    d = modularInverse(e, ( prim1 - 1L ) * (prim2 - 1L) )

    llave_privada = RSA.construct((n,e,d))
    
    print llave_privada.exportKey()

main()