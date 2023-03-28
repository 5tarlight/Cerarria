#include "render/ConsoleWindow.h"
#include <ColorString.h>
#include <clear.h>
#include <color.h>
#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  ColorString title("Welcome to Cerarria", color::PURPLE, color::BOLD);
  title.println();

  // cpr::Response r = cpr::Get(cpr::Url{"http://localhost:3000"});
  // json data = json::parse(r.text);
  // ColorString(data["text"]).println();

  clear(true);
  // clear();

  Window::updateWindow();
}
