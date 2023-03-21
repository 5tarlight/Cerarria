#include "ColorString.h"
#include "color.h"
#include <cstdio>

ColorString::ColorString() : ColorString("") {}

ColorString::ColorString(const char *str)
    : ColorString(std::string(str), NONE, NONE) {}

ColorString::ColorString(std::string str) : ColorString(str, NONE, NONE) {}

ColorString::ColorString(std::string str, const char *color)
    : ColorString(str, color, NONE) {}

ColorString::ColorString(std::string str, const char *color,
                         const char *decoration) {
  this->str = str;
  this->color = std::string(color);
  this->decoration = std::string(decoration);
}

std::string ColorString::operator()() const {
  return this->color + this->decoration + this->str + RESET;
}

void ColorString::print() const { printf("%s", this->operator()().c_str()); }

void ColorString::println() const {
  printf("%s\n", this->operator()().c_str());
}

ColorString operator+(const ColorString &str1, const ColorString &str2) {
  return ColorString(str1() + str2());
}
