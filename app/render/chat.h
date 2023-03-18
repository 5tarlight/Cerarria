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
  chat::message make() const;

  static std::vector<chat::message> chats;
  static void addChat(User author, std::string content);
  static void render();
};
