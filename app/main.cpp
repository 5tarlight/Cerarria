#include "render/ConsoleWindow.h"
#include <ColorString.h>
#include <color.h>
#include <cpr/cpr.h>
#include <input.h>
#include <iostream>

int main() {
  ColorString title("Welcome to Cerarria", color::PURPLE, color::BOLD);
  title.println();

  cpr::Response r = cpr::Get(
      cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
      cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
      cpr::Parameters{{"anon", "true"}, {"key", "value"}});
  ColorString(r.text).println();

  clear(true);

  Window::updateWindow();
}
