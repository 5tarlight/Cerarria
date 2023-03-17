#include "render/ConsoleWindow.h"
#include <ColorString.h>
#include <color.h>
#include <input.h>
#include <iostream>

int main() {
  ColorString title("Welcome to Cerarria", PURPLE, BOLD);
  title.println();
  // clear(true);

  Window::updateWindow();
}
