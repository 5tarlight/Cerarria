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

void Chat::render() {
  auto &chat = Window::windows[cfg::chat].content;
  int width = cfg::chatWidth;
  int height = cfg::chatHeight;
  int line = 0;
  int maxLine = Chat::chats.size();
  int pos = 0;

  vector<vector<ColorString>> lines;
  for (auto &ch : Chat::chats) {
    int size = ch.first.length() + ch.second().size() + 1;
    int authorLength = ch.first.length();

    int wrap = -1;
    do {
      lines.push_back(vector<ColorString>());
      wrap++;

      for (int i = 0; i < width; i++) {
        if (authorLength > 0) {
          lines[lines.size() - 1].push_back(ColorString(ch.first[i], YELLOW));
          authorLength--;
        } else if (authorLength == 0) {
          lines[lines.size() - 1].push_back(ColorString(" "));
          authorLength--;
        } else {
          int index = 0;

          if (wrap == 0) {
            index = i - ch.first.length() - 1;
          } else {
            index = i + wrap * width - ch.first.length() - 1;
          }

          if (index < ch.second.length()) {
            lines[lines.size() - 1].push_back(ColorString(ch.second[index]));
          } else {
            lines[lines.size() - 1].push_back(ColorString(" "));
          }
        }
      }

      size -= width;
    } while (size > 0);
  }

  int start;
  if (lines.size() > height) {
    start = lines.size() - height - 1;
  } else {
    start = 0;
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (i + start >= lines.size()) {
        chat[i][j] = ColorString(" ");
      } else {
        chat[i][j] = std::move(lines[i + start][j]);
      }
    }
  }
}
