# % W %

COMPILADOR=gcc
FUENTE=archivoheredado.c imprimeposicion.c $(RUTA_LIB)error.c 
OBJS=$(FUENTE:.c=.o)
HEADER=archivoheredado.h error.h
PROG=$(RUTA_BIN)archivoheredado

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
