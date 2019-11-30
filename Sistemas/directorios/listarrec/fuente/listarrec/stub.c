#include "listarrec.h"

int main(int argc, char** argv)
{
     switch(argc)
     {
     	case 1:
     		ftw(".",procesaarchivo,1);
     		break;
     	case 2:
     		ftw(argv[1],procesaarchivo,1);
     		break;
     	default:
     		fprintf(stderr,"Uso:\n");
     		fprintf(stderr,"%s[directorio]\n");
     		exit(1);
     	break;
     }
     return 0;
}