#include "ejemplosetpgrp.h"
#include "error.h"

int main(void)
{
   int pgid;
   pgid = setpgrp();
   return(0);
}
