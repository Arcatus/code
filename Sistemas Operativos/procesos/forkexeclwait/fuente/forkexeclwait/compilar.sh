#!/bin/sh
#Shell script de compilación de ejemplowrite

ACTUAL=$PWD

cd ../incl

INCL=$PWD

cd $ACTUAL

cd ../lib

UTIL=$PWD

cd $ACTUAL

cd ../../bin

BIN=$PWD

cd $ACTUAL

make $* RUTA_BIN=$BIN/ RUTA_INCL=$INCL/ RUTA_UTIL=$UTIL/


