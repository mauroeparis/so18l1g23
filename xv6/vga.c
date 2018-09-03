#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "defs.h"
#include "x86.h"
#include "elf.h"

#define DIR       0xB8000
#define COLOR     (0x5F << 8) // Color: 5 Pink, F White

void
vgainit(void)
{
  uchar SO2018[] = "Aguante SO2018!";
  int len = sizeof(SO2018);

  ushort *VGAs = (ushort *) DIR;
  int offset;
  int x, y = 24; // 24 = last line

  for (x = 0; x < len; x++){
    offset = (80 * y) + x;
    VGAs[offset] = (ushort) (COLOR + SO2018[x]);
  }
}
