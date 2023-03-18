#pragma once

#include <string>

namespace user {
typedef std::string uuid;
}

struct User {
  user::uuid id;
  std::string name;
};
