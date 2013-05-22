#ifndef __24BITCOLOR_H__
#define __24BITCOLOR_H__

#ifdef USE_24_BIT_COLOR

#if !XFT
#error only XFT for now
#endif

#define XFT_COLOR(i,n) \
  XftColor n; \
  n.color.red = (i >> 16) & 0xff; \
  n.color.green = (i >> 8) & 0xff; \
  n.color.blue = i & 0xff; \
  n.color.red *= 0x101; \
  n.color.green *= 0x101; \
  n.color.blue *= 0x101; \
  n.color.alpha = 0xffff; \
  n.pixel = n.color.alpha << 48 \
    + n.color.red << 32 \
    + n.color.green << 16 \
    + n.color.blue; \
  if((i < 512) && (i > 1)) { \
  fprintf(stderr, "COLOR %d -> %d,%d,%d\n", i, n.color.red, n.color.green, n.color.blue); \
  }

#endif

#endif
