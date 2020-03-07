#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void CalculaRaices(int a, int b, int c, float *x1, float *x2);
void DespliegaRaices(int a, int b, int c, float x1, float x2);

int main (void)
{
  FILE *Archivo;
  int a, b ,c;
  float x1, x2;
  if ( (Archivo = fopen("ecuaciones.txt", "rt") ) == NULL)
    {
      printf("ERROR FATAL: No existe el archivo ecuaciones.txt.\n");
      exit(100);
    }
  while(!feof(Archivo)) //EOF END OF FILE. feof File end of file indica si estas en el final de un archivo o no y eso indica si el ciclo termina o no
    {
      fscanf(Archivo, "%d, %d, %d\n", &a, &b, &c);
      CalculaRaices(a, b, c, &x1, &x2);
      DespliegaRaices(a, b, c, x1, x2);
    }
  fclose(Archivo);
  return 0;
}

void CalculaRaices(int a, int b, int c, float *x1, float *x2)
{
  *x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
  *x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
}

void DespliegaRaices(int a, int b, int c, float x1, float x2)
{
  printf("Para %dx^2 + %dx + %d =, x1 = %.2f, x2 = %.2f\n", a, b, c, x1, x2);
}