#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  //printf("Inside count \n");
  printf(1, "System call count: %d \n", getsyscallno());
  exit();
}
                                                                 
