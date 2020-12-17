#include <stdio.h>

int main() {
     int a = 100;
     int b = -100;
     printf("%d\n", a);
     printf("%d\n", b);

     int c = 1000000000000; // ?
     printf("%d\n", c);
     
     long d = 1000000000000; // ok
     printf("%ld\n", d);

     char e = 'z';
     printf("%c\n", e);

     char s[] = "hola";
     char t[] = {'h','o','l','a','2'};
     printf("%s\n",s);
     printf("%s\n",t);

     float f = 1.2f;
     float r  = 1289371289371.38f; // ?
     double g = 1289371289371.38;

     printf("%f\n",f);
     printf("%f\n",r);
     printf("%lf\n",g);

     return 0;
}
