#include "input.h"
#include "ColorString.h"
#include "color.h"
#include <cstdio>
#include <stdlib.h>

void clear(bool pause) {
  if (pause) {
    ColorString("Press ", GREY, ITALIC).print();
    ColorString("enter", SBLUE, ITALIC).print();
    ColorString(" to continue.", GREY, ITALIC).println();
    getchar();
  }

#if __WIN32__
  system("cls");
#else
  system("clear");
#endif
}
