#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "defs.h"
#include "x86.h"
#include "elf.h"

#define DIR 0xB8000
#define COLOR 0x700
#define BLINK 0x8000

struct {
  char color;
  int length;
} string;

void
vgainit(void)
{
  char *SO2018 = "Aguante SO2018!";
  int len = 15;

  char *VGA = (char *) DIR;
  int offset;
  int y = 24; // Footer
  int x;

  for (x = 0; x < len; x++)
  {
    offset = (80 * y) + x;
    VGA[offset*2+1] = (char) (0x5F); //Color: b pink, f white
    VGA[offset*2] = (char) (SO2018[x]); // Text
  }

}
