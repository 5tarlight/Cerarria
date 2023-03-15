#pragma once

#include <string>

class ColorString {
  std::string str;
  std::string color;
  std::string decoration;

public:
  ColorString(const char *str);
  ColorString(std::string str);
  ColorString(std::string str, const char *color);
  ColorString(std::string str, const char *color, const char *decoration);

  std::string operator()();
  void print();
  void println();
};
