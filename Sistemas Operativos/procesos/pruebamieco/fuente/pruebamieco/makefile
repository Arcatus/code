# % W %

COMPILADOR=gcc
FUENTE=pruebamieco.c
OBJS=$(FUENTE:.c=.o)
HEADER=pruebamieco.HEADER
PROG=$(RUTA_BIN)pruebamieco

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