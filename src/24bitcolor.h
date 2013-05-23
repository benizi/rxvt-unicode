#ifndef __24BITCOLOR_H__
#define __24BITCOLOR_H__

#ifdef USE_24_BIT_COLOR

#if !XFT
#error only XFT for now
#endif

#define named_color(color) \
  ((color) == Color_none) ? "Color_none" : \
  ((color) == Color_transparent) ? "Color_transparent" : \
  ((color) == Color_fg) ? "Color_fg" : \
  ((color) == Color_bg) ? "Color_bg" : \
  ((color) == Color_Black) ? "Color_Black" : \
  ((color) == Color_Red3) ? "Color_Red3" : \
  ((color) == Color_Green3) ? "Color_Green3" : \
  ((color) == Color_Yellow3) ? "Color_Yellow3" : \
  ((color) == Color_Blue3) ? "Color_Blue3" : \
  ((color) == Color_Magenta3) ? "Color_Magenta3" : \
  ((color) == Color_Cyan3) ? "Color_Cyan3" : \
  ((color) == Color_AntiqueWhite) ? "Color_AntiqueWhite" : \
  ((color) == Color_Grey25) ? "Color_Grey25" : \
  ((color) == Color_Red) ? "Color_Red" : \
  ((color) == Color_Green) ? "Color_Green" : \
  ((color) == Color_Yellow) ? "Color_Yellow" : \
  ((color) == Color_Blue) ? "Color_Blue" : \
  ((color) == Color_Magenta) ? "Color_Magenta" : \
  ((color) == Color_Cyan) ? "Color_Cyan" : \
  ((color) == Color_White) ? "Color_White" : \
  ((color) == Color_cursor) ? "Color_cursor" : \
  ((color) == Color_cursor2) ? "Color_cursor2" : \
  ((color) == Color_pointer_fg) ? "Color_pointer_fg" : \
  ((color) == Color_pointer_bg) ? "Color_pointer_bg" : \
  ((color) == Color_border) ? "Color_border" : \
  ((color) == Color_BD) ? "Color_BD" : \
  ((color) == Color_IT) ? "Color_IT" : \
  ((color) == Color_UL) ? "Color_UL" : \
  ((color) == Color_RV) ? "Color_RV" : \
  ((color) == Color_underline) ? "Color_underline" : \
  ((color) == Color_HC) ? "Color_HC" : \
  ((color) == Color_HTC) ? "Color_HTC" : \
  ((color) == Color_scroll) ? "Color_scroll" : \
  ((color) == Color_trough) ? "Color_trough" : \
  ((color) == Color_tint) ? "Color_tint" : \
  ((color) == Color_fade) ? "Color_fade" : \
  ((color) == Color_topShadow) ? "Color_topShadow" : \
  ((color) == Color_bottomShadow) ? "Color_bottomShadow" : \
  ((color) == TOTAL_COLORS) ? "TOTAL_COLORS" : \
  "NO NAME"

#define CHECKLESS_RXVT_TO_24BIT(xft,out) \
  out = 0; \
  out += (xft.c.color.red >> 8) & 0xff; \
  out <<= 8; \
  out += (xft.c.color.green >> 8) & 0xff; \
  out <<= 8; \
  out += (xft.c.color.blue >> 8) & 0xff

#define COLOR_CHECK_RXVT(xft,out) \
  fprintf(stderr, "RXVT_TO_24BIT %08x [%s] -> %d, %d, %d (from %s +%d)\n", \
      out, \
      named_color(out), \
      ((xft.c.color.red >> 8) & 0xff), \
      ((xft.c.color.green >> 8) & 0xff), \
      ((xft.c.color.blue >> 8) & 0xff), \
      __FILE__, \
      __LINE__ \
      )

#define PRINT_IF_NAMED(i) \
  if ((i) != 0 && (named_color(i)) != "NO NAME") \
    fprintf(stderr, "COLOR(%d) = %s (from %s +%d)\n", i, named_color(i), __FILE__, __LINE__)

#define RXVT_TO_24BIT(xft,out) \
  CHECKLESS_RXVT_TO_24BIT(xft,out); \
  COLOR_CHECK_RXVT(xft,out)

#define LERT(i) \
  if(i >= 0 && i <= 512) fprintf(stderr, "LERT %d [=%s] (from %s +%d)\n", i, named_color(i), __FILE__, __LINE__);

#define CHECKLESS_XFT_COLOR(i,n) \
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
    + ((unsigned long)n.color.blue)

#define COLOR_PRINT_XFT(i,n) \
  fprintf(stderr, "COLOR %d [=%s] -> %d,%d,%d (from %s +%d)\n", i, named_color(i), n.color.red & 0xff, n.color.green & 0xff, n.color.blue & 0xff, __FILE__, __LINE__)

#define COLOR_PRINT_XFT_VERBOSE(i,n) \
  fprintf(stderr, "COLOR %d [=%s] -> %d,%d,%d (A=%d) %016lx (from %s +%d)\n", i, named_color(i), n.color.red, n.color.green, n.color.blue, n.color.alpha, n.pixel, __FILE__, __LINE__)

#define COLOR_CHECK_XFT(i,n) \
  if((i < 512) && (i > 1)) { \
    COLOR_PRINT_XFT(i,n); \
  }

#define XFT_COLOR(i,n) \
  CHECKLESS_XFT_COLOR(i,n); \
  COLOR_CHECK_XFT(i,n)

#endif

#endif
