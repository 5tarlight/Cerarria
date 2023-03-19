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
using std::move;
using std::string;
using std::vector;

message Chat::make() const {
  ColorString author("<" + this->author.name + ">", YELLOW);
  ColorString content(string(this->content));
  message ch = make_pair(author, content);

  return ch;
}

vector<message> Chat::chats = vector<message>();

void Chat::addChat(Chat ch) {
  message msg = ch.make();
  Chat::chats.push_back(msg);
}

void Chat::render() { auto &chat = Window::windows[cfg::chat]; }
