#!/bin/sh

cd ../fuente
ACTUAL=$PWD

for directorio in *
do
        if
                test -d $ACTUAL/$directorio
        then
                cd $ACTUAL/$directorio
        else
                continue
        fi
        for shellscript in *.sh
        do
                if
                        [ -x $PWD/$shellscript ]
                then
                        ./$shellscript fclean
                        echo ""
                fi
        done
done
