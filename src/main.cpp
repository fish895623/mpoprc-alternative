#include <curl/curl.h>
#include <json/json.h>
#include <iostream>
#include <string>
#include "Settings.hpp"
using namespace io::github::fish895623::email;

static size_t
WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}

auto
main() -> int {
  //  CURL* curl;
  //  CURLcode res;
  //  std::string readBuffer;
  //
  //  curl = curl_easy_init();
  //  if (curl) {
  //    curl_easy_setopt(curl, CURLOPT_USERNAME, "username");  // FIXME
  //    curl_easy_setopt(curl, CURLOPT_PASSWORD, "password");  // FIXME
  //    curl_easy_setopt(curl, CURLOPT_URL, "email_server");   // FIXME
  //    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  //    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
  //    curl_easy_perform(curl);
  //    curl_easy_cleanup(curl);
  //
  //    std::cout << readBuffer << std::endl;
  //  }
  //  return 0;
  std::string str;

  {
    Json::Value root;
    root["id"] = "Luna";
    root["name"] = "Silver";
    root["age"] = 19;
    root["hasCar"] = false;

    Json::Value items;
    items.append("nootbook");
    items.append("ipadmini2");
    items.append("iphone5s");
    root["items"] = items;

    Json::Value friends;
    Json::Value tom;
    tom["name"] = "Tom";
    tom["age"] = 21;
    Json::Value jane;
    jane["name"] = "jane";
    jane["age"] = 23;
    friends.append(tom);
    friends.append(jane);
    root["friends"] = friends;

    Json::StyledWriter writer;
    str = writer.write(root);
    std::cout << str << std::endl << std::endl;
  }
  ParseSettings::Parse(str);
}