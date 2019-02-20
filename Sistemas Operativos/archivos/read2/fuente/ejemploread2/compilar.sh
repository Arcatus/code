#!/bin/sh
#Shell script de compilación de ejemploread1

ACTUAL=$PWD

cd ../incl

INCL=$PWD

cd $ACTUAL

cd ../../bin

BIN=$PWD

cd $ACTUAL

make $* RUTA_BIN=$BIN/ RUTA_INCL=$INCL/


