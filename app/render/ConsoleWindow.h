#pragma once
#include <string>
#include <vector>

class Window {
  int width;
  int height;
  bool focus;
  int id;
  std::vector<std::vector<std::string>> content;

public:
  static int focusId;
  static std::vector<Window> windows;
  static void initWindow();
  static void updateWindow();
};
