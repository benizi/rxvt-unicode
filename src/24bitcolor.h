#ifndef __24BITCOLOR_H__
#define __24BITCOLOR_H__

#ifdef USE_24_BIT_COLOR

#if !XFT
#error only XFT for now
#endif

#define RXVT_TO_24BIT(xft,out) \
  out = 0; \
  out += (xft.c.color.red >> 8) & 0xff; \
  out <<= 8; \
  out += (xft.c.color.green >> 8) & 0xff; \
  out <<= 8; \
  out += (xft.c.color.blue >> 8) & 0xff

#define XFT_COLOR(i,n) \
  XftColor n; \
  n.color.red = (i >> 16) & 0xff; \
  n.color.green = (i >> 8) & 0xff; \
  n.color.blue = i & 0xff; \
  n.color.red *= 0x101; \
  n.color.green *= 0x101; \
  n.color.blue *= 0x101; \
  n.color.alpha = 0xffff; \
  n.pixel = (((unsigned long)n.color.alpha) << 48) \
    + (((unsigned long)n.color.red) << 32) \
    + (((unsigned long)n.color.green) << 16) \
    + ((unsigned long)n.color.blue); \
  if((i < 512) && (i > 1)) { \
  fprintf(stderr, "COLOR %d -> %d,%d,%d\n", i, n.color.red, n.color.green, n.color.blue); \
  }

#endif

#endif
