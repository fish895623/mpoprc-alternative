//
// Created by dan99 on 9/19/22.
//

#include "Settings.hpp"

using namespace io::github::fish895623::email;

void
ParseSettings::Hello() {
  std::cout << "hello" << std::endl;
}

int
ParseSettings::Parse() {
  std::string str;

  ParseSettings::Parse(str);
}

int
ParseSettings::Parse(const std::string& str) {
  Json::Reader reader;
  Json::Value root;
  bool parsingRet = reader.parse(str, root);

  if (!parsingRet) {
    std::cout << "Failed to parse Json : "
              << reader.getFormattedErrorMessages();
    return 1;
  }

  std::cout << root["hasCar"] << " : " << root["age"] << std::endl << std::endl;

  const Json::Value items = root["items"];
  for (const auto& item : items) {
    std::cout << item.asString() << std::endl;
  }
  std::cout << std::endl;

  auto member = root.getMemberNames();

  for (const std::string& s : member) {
    std::cout << s << std::endl;
  }
  std::cout << std::endl;

  for (const std::string& s : member) {
    if (root[s].isString()) {
      std::cout << root[s] << std::endl;
    }
  }
  std::cout << std::endl;

  Json::Value friends = root["friends"];
  for (auto& it : friends) {
    if (it.isObject()) {
      std::cout << it["name"] << " : " << it["age"] << std::endl;
    }
  }
  std::cout << std::endl;
}