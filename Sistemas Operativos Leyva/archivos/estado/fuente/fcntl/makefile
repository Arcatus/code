# % W %

COMPILADOR=gcc
FUENTE=abrirarchivo.c ejemplofcntl.c estadoarchivo.c
OBJS=$(FUENTE:.c=.o)
HEADER=ejemplofcntl.h
PROG=$(RUTA_BIN)ejemplofcntl

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
