#include "ConsoleWindow.h"
#include "../constants.h"
#include <ColorString.h>
#include <color.h>

Window::Window(int w, int h, int id) {
  this->width = w;
  this->height = h;
  this->id = id;

  if (id == cfg::game) {
    this->focus = true;
  } else {
    this->focus = false;
  }
}

int Window::focusId = cfg::game;
std::vector<Window> Window::windows = {
    Window(cfg::gameWidth, cfg::gameHeight, cfg::game),
    Window(cfg::chatWidth, cfg::chatHeight, cfg::chat)};

void Window::updateWindow() {
  ColorString str1("###############", GREY);
  str1.print();
  ColorString(std::to_string(Window::windows.size())).println();
}
