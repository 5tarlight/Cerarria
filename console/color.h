#pragma once

// https://wiki.archlinux.org/title/Bash/Prompt_customization#Colors
namespace color {
const auto BOLD = "\e[1m";
const auto DIM = "\e[2m";
const auto ITALIC = "\e[3m";
const auto HIGHLIGHT = "\e[7m";
const auto GREY = "\e[30m";
const auto GRAY = "\e[30m";
const auto BG_GRAY = "\e[40m";
const auto BG_GREY = "\e[40m";
const auto RED = "\e[31m";
const auto BG_RED = "\e[41m";
const auto GREEN = "\e[32m";
const auto BG_GREEN = "\e[42m";
const auto YELLOW = "\e[33m";
const auto BG_YELLOW = "\e[43m";
const auto BLUE = "\e[34m";
const auto BG_BLUE = "\e[44m";
const auto PURPLE = "\e[35m";
const auto BG_PURPLE = "\e[45m";
const auto SBLUE = "\e[36m"; // Sky Blue
const auto BG_SBLUE = "\e[46m";
const auto WHITE = "\e[37m";
const auto BG_WHITE = "\e[47m";
const auto RESET = "\e(B\e[m";
const auto NONE = "";
}; // namespace color
