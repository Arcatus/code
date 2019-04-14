#include "ejemploread1.h"

int main(void)
{
     int da;
     char buf1[TAMBUF],buf2[TAMBUF];
     if((da=open(ARCHIVO,O_RDONLY))<0)
	     return (-1);
     read(da,buf1,TAMBUF);
     read(da,buf2,TAMBUF);
     return (0);
}
