// VGA control
// http://www.techhelpmanual.com/900-video_graphics_array_i_o_ports.html
// https://files.osdev.org/mirrors/geezer/osd/graphics/modes.c

#include "types.h"
#include "defs.h"
#include "x86.h"
#include "vga.h"
#include "memlayout.h"

void
vgainit(int mode)
{
  set_palette();
  if(mode)
    mode_13H();
  else{
    mode_3H();
    salute();
  }
}

// Switch to graphic mode
// SRC: g_320x200x256[] from osdev
void
mode_13H(void)
{
  /* Text mode initialization */

  // 3c2H  Miscellaneous Output Register
  outb(0x3C2, 0x63);

  // 3c4H  Sequencer Address Register
  outb(0x3C4, 0);
  outb(0x3C5, 0x03);
  outb(0x3C4, 1);
  outb(0x3C5, 0x01);
  outb(0x3C4, 2);
  outb(0x3C5, 0x0F);
  outb(0x3C4, 3);
  outb(0x3C5, 0x00);
  outb(0x3C4, 4);
  outb(0x3C5, 0x0E);

  // 3d4H  CRT controller address (CGA)
  outb(0x3D4, 0);
  outb(0x3D5, 0x5F);
  outb(0x3D4, 1);
  outb(0x3D5, 0x4F);
  outb(0x3D4, 2);
  outb(0x3D5, 0x50);
  outb(0x3D4, 3);
  outb(0x3D5, 0x82);
  outb(0x3D4, 4);
  outb(0x3D5, 0x54);
  outb(0x3D4, 5);
  outb(0x3D5, 0x80);
  outb(0x3D4, 6);
  outb(0x3D5, 0xBF);
  outb(0x3D4, 7);
  outb(0x3D5, 0x1F);
  outb(0x3D4, 8);
  outb(0x3D5, 0x00);
  outb(0x3D4, 9);
  outb(0x3D5, 0x41);
  outb(0x3D4, 10);
  outb(0x3D5, 0x00);
  outb(0x3D4, 11);
  outb(0x3D5, 0x00);
  outb(0x3D4, 12);
  outb(0x3D5, 0x00);
  outb(0x3D4, 13);
  outb(0x3D5, 0x00);
  outb(0x3D4, 14);
  outb(0x3D5, 0x00);
  outb(0x3D4, 15);
  outb(0x3D5, 0x00);
  outb(0x3D4, 16);
  outb(0x3D5, 0x9C);
  outb(0x3D4, 17);
  outb(0x3D5, 0x0E);
  outb(0x3D4, 18);
  outb(0x3D5, 0x8F);
  outb(0x3D4, 19);
  outb(0x3D5, 0x28);
  outb(0x3D4, 20);
  outb(0x3D5, 0x40);
  outb(0x3D4, 21);
  outb(0x3D5, 0x96);
  outb(0x3D4, 22);
  outb(0x3D5, 0xB9);
  outb(0x3D4, 23);
  outb(0x3D5, 0xA3);
  outb(0x3D4, 24);
  outb(0x3D5, 0xFF);

  // 3ceH Graphics Address Register
  outb(0x3CE, 0);
  outb(0x3CF, 0x00);
  outb(0x3CE, 1);
  outb(0x3CF, 0x00);
  outb(0x3CE, 2);
  outb(0x3CF, 0x00);
  outb(0x3CE, 3);
  outb(0x3CF, 0x00);
  outb(0x3CE, 4);
  outb(0x3CF, 0x00);
  outb(0x3CE, 5);
  outb(0x3CF, 0x40);
  outb(0x3CE, 6);
  outb(0x3CF, 0x05);
  outb(0x3CE, 7);
  outb(0x3CF, 0x0F);
  outb(0x3CE, 8);
  outb(0x3CF, 0xFF);

  // 3c0H  Attribute Address Register
  outb(0x3C0, 0);
  outb(0x3C0, 0x00);
  outb(0x3C0, 1);
  outb(0x3C0, 0x01);
  outb(0x3C0, 2);
  outb(0x3C0, 0x02);
  outb(0x3C0, 3);
  outb(0x3C0, 0x03);
  outb(0x3C0, 4);
  outb(0x3C0, 0x04);
  outb(0x3C0, 5);
  outb(0x3C0, 0x05);
  outb(0x3C0, 6);
  outb(0x3C0, 0x06);
  outb(0x3C0, 7);
  outb(0x3C0, 0x07);
  outb(0x3C0, 8);
  outb(0x3C0, 0x08);
  outb(0x3C0, 9);
  outb(0x3C0, 0x09);
  outb(0x3C0, 10);
  outb(0x3C0, 0x0A);
  outb(0x3C0, 11);
  outb(0x3C0, 0x0B);
  outb(0x3C0, 12);
  outb(0x3C0, 0x0C);
  outb(0x3C0, 13);
  outb(0x3C0, 0x0D);
  outb(0x3C0, 14);
  outb(0x3C0, 0x0E);
  outb(0x3C0, 15);
  outb(0x3C0, 0x0F);
  outb(0x3C0, 16);
  outb(0x3C0, 0x41);
  outb(0x3C0, 17);
  outb(0x3C0, 0x00);
  outb(0x3C0, 18);
  outb(0x3C0, 0x0F);
  outb(0x3C0, 19);
  outb(0x3C0, 0x00);
  outb(0x3C0, 20);
  outb(0x3C0, 0x00);

  // 3daH  Feature Control Register (CGA)
  inb(0x3DA);

  // Enable screen
  outb(0x3C0, 0x20);

  // Clean screen
  int i;
  uchar *VGA = (uchar*) P2V(0xA0000);
  for (i = 0; i < 320 * 200; i++)
    VGA[i] = 0x00;
}

// Switch to text mode
// SRC: g_80x25_text[] from osdev
void
mode_3H(void)
{
  /* Text mode initialization */

  // 3c2H  Miscellaneous Output Register
  outb(0x3C2, 0x67);

  // 3c4H  Sequencer Address Register
  outb(0x3C4, 0);
  outb(0x3C5, 0x03);
  outb(0x3C4, 1);
  outb(0x3C5, 0x00);
  outb(0x3C4, 2);
  outb(0x3C5, 0x03);
  outb(0x3C4, 3);
  outb(0x3C5, 0x00);
  outb(0x3C4, 4);
  outb(0x3C5, 0x02);

  // 3d4H  CRT controller address (CGA)
  outb(0x3d4, 0);
  outb(0x3d5, 0x5F);
  outb(0x3d4, 1);
  outb(0x3d5, 0x4F);
  outb(0x3d4, 2);
  outb(0x3d5, 0x50);
  outb(0x3d4, 3);
  outb(0x3d5, 0x82);
  outb(0x3d4, 4);
  outb(0x3d5, 0x55);
  outb(0x3d4, 5);
  outb(0x3d5, 0x81);
  outb(0x3d4, 6);
  outb(0x3d5, 0xBF);
  outb(0x3d4, 7);
  outb(0x3d5, 0x1F);
  outb(0x3d4, 8);
  outb(0x3d5, 0x00);
  outb(0x3d4, 9);
  outb(0x3d5, 0x4F);
  outb(0x3d4, 10);
  outb(0x3d5, 0x0D);
  outb(0x3d4, 11);
  outb(0x3d5, 0x0E);
  outb(0x3d4, 12);
  outb(0x3d5, 0x00);
  outb(0x3d4, 13);
  outb(0x3d5, 0x00);
  outb(0x3d4, 14);
  outb(0x3d5, 0x00);
  outb(0x3d4, 15);
  outb(0x3d5, 0x50);
  outb(0x3d4, 16);
  outb(0x3d5, 0x9C);
  outb(0x3d4, 17);
  outb(0x3d5, 0x0E);
  outb(0x3d4, 18);
  outb(0x3d5, 0x8F);
  outb(0x3d4, 19);
  outb(0x3d5, 0x28);
  outb(0x3d4, 20);
  outb(0x3d5, 0x1F);
  outb(0x3d4, 21);
  outb(0x3d5, 0x96);
  outb(0x3d4, 22);
  outb(0x3d5, 0xB9);
  outb(0x3d4, 23);
  outb(0x3d5, 0xA3);
  outb(0x3d4, 24);
  outb(0x3d5, 0xFF);

  // 3ceH Graphics Address Register
  outb(0x3CE, 0);
  outb(0x3CF, 0x00);
  outb(0x3CE, 1);
  outb(0x3CF, 0x00);
  outb(0x3CE, 2);
  outb(0x3CF, 0x00);
  outb(0x3CE, 3);
  outb(0x3CF, 0x00);
  outb(0x3CE, 4);
  outb(0x3CF, 0x00);
  outb(0x3CE, 5);
  outb(0x3CF, 0x10);
  outb(0x3CE, 6);
  outb(0x3CF, 0x0E);
  outb(0x3CE, 7);
  outb(0x3CF, 0x00);
  outb(0x3CE, 8);
  outb(0x3CF, 0xFF);

  // 3c0H  Attribute Address Register
  outb(0x3C0, 0);
  outb(0x3C0, 0x00);
  outb(0x3C0, 1);
  outb(0x3C0, 0x01);
  outb(0x3C0, 2);
  outb(0x3C0, 0x02);
  outb(0x3C0, 3);
  outb(0x3C0, 0x03);
  outb(0x3C0, 4);
  outb(0x3C0, 0x04);
  outb(0x3C0, 5);
  outb(0x3C0, 0x05);
  outb(0x3C0, 6);
  outb(0x3C0, 0x14);
  outb(0x3C0, 7);
  outb(0x3C0, 0x07);
  outb(0x3C0, 8);
  outb(0x3C0, 0x38);
  outb(0x3C0, 9);
  outb(0x3C0, 0x39);
  outb(0x3C0, 10);
  outb(0x3C0, 0x3A);
  outb(0x3C0, 11);
  outb(0x3C0, 0x3B);
  outb(0x3C0, 12);
  outb(0x3C0, 0x3C);
  outb(0x3C0, 13);
  outb(0x3C0, 0x3D);
  outb(0x3C0, 14);
  outb(0x3C0, 0x3E);
  outb(0x3C0, 15);
  outb(0x3C0, 0x3F);
  outb(0x3C0, 16);
  outb(0x3C0, 0x0C);
  outb(0x3C0, 17);
  outb(0x3C0, 0x00);
  outb(0x3C0, 18);
  outb(0x3C0, 0x0F);
  outb(0x3C0, 19);
  outb(0x3C0, 0x08);
  outb(0x3C0, 20);
  outb(0x3C0, 0x00);

  /* Font recovering */

  // seq reset
  outb(0x3C4, 0);
  outb(0x3C5, 0x01);
  // image plane 2
  outb(0x3C4, 2);
  outb(0x3C5, 0x04);
  // disable odd/even in sequencer
  outb(0x3C4, 4);
  outb(0x3C5, 0x07);
  // seq reset
  outb(0x3C4, 0);
  outb(0x3C5, 0x03);

  // read select plane 2
  outb(0x3CE, 4);
  outb(0x3CF, 0x02);
  // odd/even disabled
  outb(0x3CE, 5);
  outb(0x3CF, 0x00);
  // memory map select A0000h-BFFFFh
  outb(0x3CE, 6);
  outb(0x3CF, 0x00);

  int offset, i, j;
  uchar *VGA = (uchar*) P2V(0xA0000);

  for(i = 0; i < 4096; i += 16) {
    for(j = 0; j < 16; j++) {
      offset = (2 * i) + j;
      VGA[offset] = g_8x16_font[i+j];
    }
  }

  // seq reset
  outb(0x3C4, 0);
  outb(0x3C5, 0x01);
  // image plane 0 and 1
  outb(0x3C4, 2);
  outb(0x3C5, 0x03);
  // character sets 0
  outb(0x3C4, 3);
  outb(0x3C5, 0x00);
  // plain 64 kb memory layout, with odd/even for text
  outb(0x3C4, 4);
  outb(0x3C5, 0x02);
  // seq reset
  outb(0x3C4, 0);
  outb(0x3C5, 0x03);

  // no color compare
  outb(0x3CE, 2);
  outb(0x3CF, 0x00);
  // no rotate
  outb(0x3CE, 3);
  outb(0x3CF, 0x00);
  // read select plane 0
  outb(0x3CE, 4);
  outb(0x3CF, 0x00);
  // odd/even enable
  outb(0x3CE, 5);
  outb(0x3CF, 0x10);
  // memory map select: 0xb8000
  outb(0x3CE, 6);
  outb(0x3CF, 0x0E);

  // TODO: Correct the color of the font
  for (int i = 0; i < 80*25; i++) {
    ((ushort *) P2V(0xB8000))[i] = 0x00;
  }

  // 3daH  Feature Control Register (CGA)
  inb(0x3DA);

  // Enable screen
  outb(0x3C0, 0x20);
}

void
salute(void)
{
  uchar SO2018[] = "Aguante SO2018";
  int len = sizeof(SO2018);

  ushort *VGA = (ushort *) P2V(0xB8000);
  int offset;
  int x, y = 24; // 24 = last line

  for (x = 0; x < len; x++){
    offset = (80 * y) + x + (40-len/2);
    VGA[offset] = (ushort) (COLOR(x) + SO2018[x]);
  }
}

void
set_palette(void)
{
  // Load 256 color palette
  int i, value;
  for(i = 0; i < 256; i++){
    value = vga_pal[i];
    outb(0x3C8, i);
    outb(0x3C9, (value>>18)&0x3f);
    outb(0x3C9, (value>>10)&0x3f);
    outb(0x3C9, (value>>2)&0x3f);
  }
}
