#pragma once

#include "../user/user.h"
#include <ColorString.h>
#include <string>
#include <utility>
#include <vector>

namespace chat {
typedef std::pair<ColorString, ColorString> message;
}

class Chat {
  User author;
  std::string content;

public:
  Chat() : author("-1", "unknown"), content("unknown") {}
  Chat(User author, std::string content) : author(author), content(content) {}

  chat::message make() const;

  static std::vector<chat::message> chats;
  static void addChat(Chat ch);
  static void render();
};
