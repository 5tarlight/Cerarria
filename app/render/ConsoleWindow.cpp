#include "ConsoleWindow.h"
#include "../constants.h"
#include "./chat.h"
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
  }

  fetchChat();
  fetchGame();

  int w = cfg::gameWidth + cfg::chatWidth + 3;
  // Print it
  for (int i = -1; i < cfg::gameHeight + 1; i++) {
    for (int j = 0; j < w; j++) {
      if (i == -1) {
        if (j == 0)
          ColorString("┌", color::NONE).print();
        else if (j == w - 1)
          ColorString("┐", color::NONE).print();
        else if (j == cfg::gameWidth + 1)
          ColorString("┬", color::NONE).print();
        else
          ColorString("─", color::NONE).print();
      } else if (i == cfg::gameHeight) {
        if (j == 0)
          ColorString("└", color::NONE).print();
        else if (j == w - 1)
          ColorString("┘", color::NONE).print();
        else if (j == cfg::gameWidth + 1)
          ColorString("┴", color::NONE).print();
        else
          ColorString("─", color::NONE).print();
      } else {
        if (j == 0 || j == w - 1 || j == cfg::gameWidth + 1) {
          ColorString("│", color::NONE).print();
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

void Window::fetchGame() {
  auto &game = Window::windows[0].content;

  for (int i = 0; i < cfg::gameHeight; i++) {
    for (int j = 0; j < cfg::gameWidth; j++) {
      if (i == 40)
        game[i][j] = ColorString("#", color::GREEN);
      else if (i > 40)
        game[i][j] = ColorString("#");
      else
        game[i][j] = ColorString(" ");
    }
  }
}

void Window::fetchChat() {
  User system = User("test-uuid", "SYSTEM");
  Chat::addChat(Chat(system, "Hello World!"));
  Chat::addChat(Chat(system, "Welcome to Cararria."));
  Chat::addChat(
      Chat(system, "You can change focus between windows. Press Enter or / to "
                   "focus on chat window and press ESC to focus on "
                   "game window. Using non-alphabetic character may "
                   "cause unexpected behaviour."));
  Chat::render();
}
