#!/bin/sh
#Shell script de compilación uamashell

ACTUAL=$PWD

cd ../incl

INCL=$PWD

cd $ACTUAL

cd ../lib

LIB=$PWD

cd $ACTUAL

cd ../../bin

BIN=$PWD

cd $ACTUAL

make $* RUTA_BIN=$BIN/ RUTA_INCL=$INCL/ RUTA_UTIL=$LIB/


