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

  // '==' cant be used, use strcmp() instead
  if (!strcmp(argv[1], "1")) {
    printf(2, "init graphic mode\n");
    modeswitch(1);
  }
  if (!strcmp(argv[1], "0")) {
    printf(2, "init text mode\n");
    modeswitch(0);
  }
  exit();
}
