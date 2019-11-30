# % W %

COMPILADOR=gcc
FUENTE=medioambiente.c
OBJS=$(FUENTE:.c=.o)
HEADER=imprimeambiente.h 
PROG=$(RUTA_BIN)medioambiente

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
