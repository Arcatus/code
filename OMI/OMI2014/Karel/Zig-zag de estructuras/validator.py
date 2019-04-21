#!/usr/bin/python
# -*- coding: utf-8 -*-
import libkarel
import sys

puntaje = 0

try:
	k_in, k_out, nombre = libkarel.load()
	puntaje2 = 1
	
        arr = a = [[0]*k_in.w for x in xrange(k_in.h)]
	A = []
	B = []
        if k_out.resultado == 'FIN PROGRAMA':
                for key, value in k_out._zumbadores.iteritems():
			B.append( int(value) ) 
                        arr[key[0]-1][key[1]-1] = int(value)
			# validator
		tam = 0
                ok = 1
                for key, value in k_in._zumbadores.iteritems():
			tam = max( tam, key[0] )
			A.append( int(value) ) 
		sys.stderr.write( "-- {0}\n ++ {1}\n".format( A, B ) )
		A.sort() 
		B.sort() 

		if A != B :
			puntaje2 = 0

                for i in range(tam-1) :
			if (i%2)==0 :
				if arr[i][0] > arr[i+1][0] :
					puntaje2 = 0 
			else :
				if arr[i][0] < arr[i+1][0] :
					puntaje2 = 0 

        else:
                puntaje2 = 0
        puntaje = puntaje2	

finally:
	print puntaje
