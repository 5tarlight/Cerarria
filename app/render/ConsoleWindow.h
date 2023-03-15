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
  Window(int w, int h, int id);

  static int focusId;
  static std::vector<Window> windows;
  static void updateWindow();
};
