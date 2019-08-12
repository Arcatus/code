#include "ejemplowrite.h"

int main(void)
{
     int da;
     char buf1[TAMBUF],buf2[TAMBUF];
     if((da=creat(ARCHIVO,0644))<0)
     {
          return(-1);
     }
     write(da,buf1,TAMBUF);
     write(da,buf2,TAMBUF);
     return 0;
}
