# % W %

COMPILADOR=gcc
FUENTE=micopiador.c copiarchivo.c
OBJS=$(FUENTE:.c=.o)
HEADER=copiarchivo.h
PROG=$(RUTA_BIN)micopiador

$(PROG):$(OBJS)
	$(COMPILADOR) $(OBJS) -lm -o $@
	@-echo "Compilación terminada"
clean:
	@- rm -f $(OBJS)
	@- echo "Borrado de objetos terminado"
fclean:
	@- rm -f $(OBJS) $(PROG)
	@- echo "Borrado de archivos terminado"
.c.o:
	$(COMPILADOR) -c -I$(RUTA_INCL) $*.c -o $*.o
