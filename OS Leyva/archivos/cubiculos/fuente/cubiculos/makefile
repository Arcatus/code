# % W %

COMPILADOR=gcc
FUENTE=cubiculos.c dimeprofesor.c agregaprofesor.c eliminaprofesor.c
OBJS=$(FUENTE:.c=.o)
HEADER=cubiculos.h
PROG=$(RUTA_BIN)cubiculos

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
