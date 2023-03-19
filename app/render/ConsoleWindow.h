#pragma once
#include "../constants.h"
#include <ColorString.h>
#include <string>
#include <vector>

class Window {
  int width;
  int height;
  bool focus;
  cfg::win_id id;

public:
  std::vector<std::vector<ColorString>> content;

  Window(int w, int h, cfg::win_id id);

  static int focusId;
  static std::vector<Window> windows;
  static void updateWindow();

private:
  static void fetchGame();
  static void fetchChat();
};
