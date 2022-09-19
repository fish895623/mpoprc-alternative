//
// Created by dan99 on 9/19/22.
//

#pragma once
#include <json/json.h>
#include <iostream>

namespace io::github::fish895623::email {
class ParseSettings {
  void Hello();

 public:
  int Parse();
  int Parse(const std::string&);
};
}  // namespace io::github::fish895623::email