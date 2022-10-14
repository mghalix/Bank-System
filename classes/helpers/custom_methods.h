#pragma once

#include <iostream>
#include <vector>

class CustomMethods {
public:
  // Method to remove trailing zeros
  static std::string correctView(double num) {
    std::string strNumber = std::to_string(num);
    int i = strNumber.size();
    while (strNumber[i - 1] == '0')
      i--;
    return (strNumber[i - 1] == '.') ?
      (strNumber.erase(i - 1, strNumber.size() - i + 1))
      : strNumber.erase(i, strNumber.size() - i);
  }

  static std::vector<std::string> split(const std::string &str, const char &del) {
    std::vector<std::string> vec;
    std::string temp = "";
    for (int i = 0; i < str.size(); i++) {
      if (str[i] != del)
        temp += str[i];
      else {
        vec.push_back(temp);
        temp = "";
      }
    }
    vec.push_back(temp);
    return vec;
  }
};