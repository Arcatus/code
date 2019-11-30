# % W %

COMPILADOR=gcc
FUENTE= $(RUTA_UTIL)error.c sistema.c dametoken.c leerlinea.c procesalinea.c esargumento.c uamashell.c
OBJS=$(FUENTE:.c=.o)
HEADER=sistema.h error.h uamashell.h
PROG=$(RUTA_BIN)uamashell

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