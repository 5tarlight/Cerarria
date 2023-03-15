#include "ColorString.h"
#include "color.h"

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

std::string ColorString::operator()() {
  return this->color + this->decoration + this->str + RESET;
}
