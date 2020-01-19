#!/bin/bash

LOCALDIR="/home/sproactivo/dnos"
SERVICEPORT="5000"
LOGBASH="/script/nas_log"
TODAY=$(date +%d%m%y%H%M)

#se valida si el servicio esta arriba
if [[ -z `netstat -an | grep $SERVICEPORT` ]]
then
    #/usr/bin/python3.6 $LOCALDIR/dnos.py & > $LOGBASH/python.log 2>&1
    /usr/bin/python3.6 $LOCALDIR/nas.py & 
    #if $? -eq 0
    if [[ -z `netstat -an | grep $SERVICEPORT` ]]
    then
        echo "Se procede a levantar servicio " + $TODAY >> $LOGBASH/bash.log
        echo "Servicio running" + $TODAY >> $LOGBASH/bash.log
    fi
fi
