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
  if (strcmp(argv[1], "1")) // '==' cant be used, use strcmp() instead
    modeswitch(1);
  else
    modeswitch(0);
  exit();
}
