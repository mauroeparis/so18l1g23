#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  if(argc < 2){
    printf(2, "Usage: modeswitch 1|0 \n");
    exit();
  }
  modeswitch(1);
  exit();
}
