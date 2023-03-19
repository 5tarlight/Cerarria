#pragma once

#include <string>

class ColorString {
  std::string str;
  std::string color;
  std::string decoration;

public:
  ColorString();
  ColorString(const char *str);
  ColorString(std::string str);
  ColorString(std::string str, const char *color);
  ColorString(std::string str, const char *color, const char *decoration);

  std::string operator()() const;
  void print() const;
  void println() const;
  int length() const { return this->str.length(); }

  std::string operator[](const int &i) const {
    // return std::string(&this->str[i]);
    return this->str.substr(i, 1);
  }
  friend ColorString operator+(const ColorString &str1,
                               const ColorString &str2);
};
