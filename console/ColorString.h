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

  void print() const;
  void println() const;
  int length() const { return this->str.length(); }

  std::string operator()() const;
  std::string operator[](const int &i) const;
  friend ColorString operator+(const ColorString &str1,
                               const ColorString &str2);
};
