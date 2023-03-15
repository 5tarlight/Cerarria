#include <ColorString.h>
#include <color.h>
#include <iostream>

int main() {
  ColorString title("Welcome to Cerarria", PURPLE, BOLD);
  std::cout << title() << std::endl;
}
