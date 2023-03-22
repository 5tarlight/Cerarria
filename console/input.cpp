#include "input.h"
#include "ColorString.h"
#include "color.h"
#include <cstdio>
#include <stdlib.h>

void clear(bool pause) {
  if (pause) {
    ColorString("Press ", color::ITALIC).print();
    ColorString("enter", color::SBLUE, color::ITALIC).print();
    ColorString(" to continue.", color::ITALIC).println();
    getchar();
  }

#if __WIN32__
  system("cls");
#else
  system("clear");
#endif
}
