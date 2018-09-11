#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int img[] = {
    0,0,0,0,0,0,0,4,4,4,4,4,4,0,0,0,0,0,0,0,
    0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0,
    0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,
    0,0,4,4,4,4,4,15,15,4,4,4,4,4,4,15,15,4,0,0,
    0,0,4,4,4,4,15,15,15,15,4,4,4,4,15,15,15,15,0,0,
    0,0,4,4,4,4,15,15,0,0,4,4,4,4,15,15,0,0,0,0,
    0,0,4,4,4,4,15,15,0,0,4,4,4,4,15,15,0,0,0,0,
    0,4,4,4,4,4,4,15,15,4,4,4,4,4,4,15,15,4,4,0,
    0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,
    0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,
    0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,
    0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,
    0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,
    0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,
    0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,
    0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,
    0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,
    0,4,4,0,0,4,4,4,4,0,0,4,4,4,4,0,0,4,4,0,
    0,4,0,0,0,0,4,4,4,0,0,4,4,4,0,0,0,0,4,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
  };

  int img1[] = {
    0,0,0,0,0,0,0,11,11,11,11,11,11,0,0,0,0,0,0,0,
    0,0,0,0,11,11,11,11,11,11,11,11,11,11,11,11,0,0,0,0,
    0,0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,0,
    0,0,11,11,11,11,11,15,15,11,11,11,11,11,11,15,15,11,0,0,
    0,0,11,11,11,11,15,15,15,15,11,11,11,11,15,15,15,15,0,0,
    0,0,11,11,11,11,15,15,0,0,11,11,11,11,15,15,0,0,0,0,
    0,0,11,11,11,11,15,15,0,0,11,11,11,11,15,15,0,0,0,0,
    0,11,11,11,11,11,11,15,15,11,11,11,11,11,11,15,15,11,11,0,
    0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,
    0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,
    0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,
    0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,
    0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,
    0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,
    0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,
    0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,
    0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,
    0,11,11,0,0,11,11,11,11,0,0,11,11,11,11,0,0,11,11,0,
    0,11,0,0,0,0,11,11,11,0,0,11,11,11,0,0,0,0,11,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
  };

  modeswitch(1);

  int i, j;
  for(j=100;j<119;++j)
    for(i=100; i<119; ++i)
      plotpixel(i,j,img[(j-100)*20+(i-100)]);

  for(j=100;j<119;++j)
    for(i=130; i<149; ++i)
      plotpixel(i,j,img1[(j-100)*20+(i-130)]);

  exit();
}
