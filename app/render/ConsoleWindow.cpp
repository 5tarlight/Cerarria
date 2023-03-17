#include "ConsoleWindow.h"
#include "../constants.h"
#include <ColorString.h>
#include <color.h>
#include <input.h>
#include <vector>

using std::string;
using std::vector;

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
  clear(false);

  vector<vector<ColorString>> &game = Window::windows[0].content;
  vector<vector<ColorString>> &chat = Window::windows[1].content;
  game.clear();
  chat.clear();
  game = vector<vector<ColorString>>(cfg::gameHeight);
  chat = vector<vector<ColorString>>(cfg::chatHeight);

  for (int i = 0; i < cfg::gameHeight; i++) {
    game[i] = vector<ColorString>(cfg::gameWidth);
    chat[i] = vector<ColorString>(cfg::chatWidth);

    // TODO : Load map and chat
    for (int j = 0; j < cfg::gameWidth; j++) {
      game[i][j] = ColorString("1");
    }

    for (int j = 0; j < cfg::chatWidth; j++) {
      chat[i][j] = ColorString("2");
    }
  }

  int w = cfg::gameWidth + cfg::chatWidth + 3;
  // Print it
  for (int i = -1; i < cfg::gameHeight; i++) {
    for (int j = 0; j < w; j++) {
      if (i == -1) {
        if (j == 0)
          ColorString("┌", NONE).print();
        else if (j == w - 1)
          ColorString("┐", NONE).print();
        else if (j == cfg::gameWidth + 1)
          ColorString("┬", NONE).print();
        else
          ColorString("─", NONE).print();
      } else if (i == cfg::gameHeight - 1) {
        if (j == 0)
          ColorString("└", NONE).print();
        else if (j == w - 1)
          ColorString("┘", NONE).print();
        else if (j == cfg::gameWidth + 1)
          ColorString("┴", NONE).print();
        else
          ColorString("─", NONE).print();
      } else {
        if (j == 0 || j == w - 1 || j == cfg::gameWidth + 1) {
          ColorString("│", NONE).print();
        } else if (j <= cfg::gameWidth + 1) {
          game[i][j - 1].print();
        } else {
          chat[i][j - 2 - cfg::gameWidth].print();
        }
      }
    }

    ColorString("").println();
  }
}
