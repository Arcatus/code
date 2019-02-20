#include "forkexeclwait.h"

int main(void)
{
   pid_t pid;
   pid = fork();
   if (pid > 0) {
      wait(NULL);
      printf("ls terminado\n");
      exit(0);
   }
   if (!pid) {
      execl("/bin/ls","ls","-FRla",NULL);
      error("Fallo en execl\n");
   }
   error("Fallo el fork\n");
}
