#!/usr/bin/python
# -*- coding: utf-8 -*-
import libkarel
import sys
import math

silent = True
printmap = False
outputbeepers = False

puntaje = 0
dr = [-1,0,1,0]
dc = [0,-1,0,1]
norm_dirs = {'NORTE':3, 'OESTE':0, 'SUR':1, 'ESTE':2}
maxRs = {     'mundo0':25, 
        'mundo1':15,
        'mundo2':42,
        'mundo3':62, 
        'mundo4':189,
        'mundo5':154,
        'mundo6':56,
        'mundo7':841,
        'mundo8':681,
        'mundo9':650 }

def simula( x, y, ort, mat, R, C ):
    res = 0
    while x>=0 and y>=0 and x<R and y<C and mat[x][y]!=-1 :
        ort = (ort+mat[x][y])%4
        mat[x][y] = -1
        x, y = x+dr[ort], y+dc[ort]
        res = res+1
    return res

try:
    k_in, k_out, nombre = libkarel.load()
    puntaje2 = 1

    if outputbeepers:
        sys.stderr.write(str(k_in._lista_zumbadores) + "\n")
        sys.stderr.write(str(k_out._zumbadores) + "\n")
    
    # Copia la matriz de la entrada en varios lados.
    # Nota: La matriz esta rotada 90 grados en sentido horario
    mat = a = [[0]*k_in.h for x in xrange(k_in.w)]
    mat2 = [[0]*k_in.h for x in xrange(k_in.w)]
    if k_out.resultado == 'FIN PROGRAMA':
        if outputbeepers:
            sys.stderr.write("input beepers:\n")
        for key, value in k_in._zumbadores.iteritems():
            if outputbeepers:
                sys.stderr.write(str(key[0]) + "\t" + str(key[1]) + "\n")
            if key[0]<=k_in.w and key[1]<=k_in.h :
                mat[key[0]-1][key[1]-1] = int(value)
        if outputbeepers:
            sys.stderr.write("output beepers:\n")
        for key, value in k_out._zumbadores.iteritems():
            if outputbeepers:
                sys.stderr.write(str(key[0]) + "\t" + str(key[1]) + "\n")
            if key[0]<=k_in.w and key[1]<=k_in.h :
                mat2[key[0]-1][key[1]-1] = int(value)

        if not silent:
            sys.stderr.write("height: " + str(k_in.h) + "\twidth:" + str(k_in.w) + "\n")

        for i in range(k_in.w) :
            for j in range(k_in.h) :
                if (mat2[i][j] < mat[i][j] ) or (mat2[i][j]>1) :
                    puntaje2 = 0

        if printmap:
            for i in range(k_in.w) :
                a = ""
                for j in range(k_in.h) :
                    a += "{0} ".format( mat[i][j] )
                a += "\n"
                sys.stderr.write(a)
            sys.stderr.write("-----------\n")
            for i in range(k_in.w) :
                a = ""
                for j in range(k_in.h) :
                    a += "{0} ".format( mat2[i][j] )
                a += "\n"
                sys.stderr.write(a)

        # Guarda la posicion de karel y simula con eso
        karel_x = k_in.x-1
        karel_y = k_in.y-1
        karel_dir = norm_dirs[k_in.direccion]
        #print "{0} {1} {2}".format( karel_x, karel_y, karel_dir)
        
        n_pasos = simula( karel_x, karel_y, karel_dir, mat2, k_in.w, k_in.h ) 
        maxpasos = maxRs.get(sys.argv[1]) 
        minpasos = simula( karel_x, karel_y, karel_dir, mat, k_in.w, k_in.h ) 

        if not type(maxpasos) == int:
            maxpasos = n_pasos

        if not silent:
            sys.stderr.write( "Inicio:\t{0} {1} -> {2}\n".format(karel_x,karel_y,norm_dirs[k_in.direccion])  )
            sys.stderr.write( "Maxpasos:\t{0}\n".format(maxpasos)  )
            sys.stderr.write( "Minpasos:\t{0}\n".format(minpasos) )
            sys.stderr.write( "Output:\t{0}\n".format(n_pasos) )

        n_pasos = max(minpasos, n_pasos)

        if puntaje2 > 0 :
            x = (n_pasos*1.0-minpasos*1.0)/(maxpasos*1.0-minpasos*1.0)

            if x < 0:
                x = 0
            elif x > 1:
                x = 1

            if x <= .5:
                puntaje2 = (-math.cos( 2*x**2.5*math.pi )+1)/2
            else:
                puntaje2 = (-math.cos(  ((( (2*x-1)**.4 )/2)+.5) * math.pi)+1)/2
        else:
            puntaje2 = 0
        puntaje = puntaje2
finally:
    print puntaje
