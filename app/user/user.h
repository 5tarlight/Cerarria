#pragma once

#include <string>

namespace user {
typedef std::string uuid;
}

struct User {
  user::uuid uuid;
  std::string name;

  User() : uuid("unknown"), name("unknown") {}
  User(user::uuid uuid, std::string name) : uuid(uuid), name(name) {}
  User(User &user)
      : uuid(std::string(user.uuid)), name(std::string(user.name)) {}
};
