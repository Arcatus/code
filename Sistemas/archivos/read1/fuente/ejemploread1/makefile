# % W %

COMPILADOR=gcc
FUENTE=ejemploread1.c
OBJS=$(FUENTE:.c=.o)
HEADER=ejemploread1.h
PROG=$(RUTA_BIN)ejemploread1

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
