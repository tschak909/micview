/**
 * micview - a simple MicroPainter Viewer
 *
 * Author: Thomas Cherryhomes
 *  <thom.cherryhomes@gmail.com>
 *
 * Licensed under the GNU Public License V3
 *
 * See COPYING, for details.
 */

#include <atari.h>
#include <stdbool.h>
#include <string.h>
#include <peekpoke.h>
#include <stdlib.h>
#include "cio.h"
#include "conio.h"

char fn[128];
unsigned char i;
char palette[4];
void *sdlst_save;
void *disp;

extern unsigned char open();
extern void get();
extern void getpalette();
extern void clos();

void dlist =
  {
   DL_BLK8,
   DL_BLK8,
   DL_BLK8,
   DL_LMS(DL_MAP160x1x4),
   0x3150,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_LMS(DL_MAP160x1x4),
   0x4000,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_MAP160x1x4,
   DL_JVB,
   0x2900
  };

bool micview()
{
  unsigned char err=1;
  unsigned char c0,c1,c2,c3;
  
  disp=(void *)0x3150;
  sdlst_save=OS.sdlst;
  memcpy((void *)0x2900,&dlist,sizeof(dlist));

  c0 = OS.color4;
  c1 = OS.color0;
  c2 = OS.color1;
  c3 = OS.color2;
  
  err = open(fn);

  if (err!=1)
    {
      print("ERROR OPENING PICTURE\x9b");
      clos();
      return 1;
    }
  
  get();
  getpalette();
  clos();

  OS.color4=palette[0];
  OS.color0=palette[1];
  OS.color1=palette[2];
  OS.color2=palette[3];
  
  OS.ch=0xFF;

  OS.sdlst = (void *)0x2900;
  
  while (OS.ch == 0xFF) { }

  OS.color4 = c0;
  OS.color0 = c1;
  OS.color1 = c2;
  OS.color2 = c3;
  
  OS.sdlst = sdlst_save;
  OS.ch=0xFF;
  return 0;
}

int main(int argc, char* argv[])
{
  OS.lmargn=2;
  OS.shflok=64;
  
  if (_is_cmdline_dos())
    {
      if (argc<2)
	{
	  print("micview Dx:<filename.mic>\x9b");
	  exit(1);
	}
      strcpy(fn,argv[1]);
      for (i=0;i<sizeof(fn);i++)
	{
	  if (fn[i]==0x00)
	    fn[i]=0x9b;
	}
    }
  else
    {
      print("MICVIEW--FILENAME WITH DEVICESPEC?\x9b");
      get_line(fn,128);

      if (fn[0]==0x9b)
	exit(1);
    }

  return micview();
}
