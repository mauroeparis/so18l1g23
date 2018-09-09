#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  for (int i = 0; i < 320; ++i) {
    plotpixel(i, 4, 0x2);
  }
  exit();
}

