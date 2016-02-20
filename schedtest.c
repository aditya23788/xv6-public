#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "param.h"
#include "syscall.h"


#define N 2

void
forktest(void)
{
  int n, pid,cpid;
  uint i=10000;

  printf(1, "fork test\n");
 
  printf(1,"Setnumtickets : %d \n",setnumtickets(15));

  for(n=0; n<N; n++){
    pid = fork();
   
    if(pid < 0)
      break;
    if(pid == 0){
      while(i--){
      }
      cpid = getpid();
      if(cpid == 5){
          setnumtickets(10);
          sleep(2);
      }
      sleep(2);
      exit();
    }
  }

  if(n == N){
    printf(1, "fork claimed to work N times!\n", N);
  }

  for(;;){

    if(wait() > 0){    
         n--;
    }
    
    if(n==0)
       break;

  }

  if(wait() < 0)
     printf(1,"All processes have been cleaned \n"); 


  if(wait() != -1){
    printf(1, "wait got too many\n");
    exit();
  }

  printf(1, "fork test OK\n");
}

int
main(void)
{
  forktest();
  exit();
}

