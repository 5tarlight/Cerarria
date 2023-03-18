#include "chat.h"
#include "../constants.h"
#include "../user/user.h"
#include "./ConsoleWindow.h"
#include <color.h>
#include <string>
#include <utility>
#include <vector>

using chat::message;
using std::make_pair;
using std::string;
using std::vector;

message Chat::make() const {
  ColorString author("<" + this->author.name + ">", YELLOW);
  ColorString content(this->content);
  message ch = make_pair(author, content);

  return ch;
}

void Chat::render() { auto &chat = Window::windows[cfg::chat]; }
