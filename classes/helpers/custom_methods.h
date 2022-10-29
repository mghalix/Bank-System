//------------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <vector>
#include <map>

class Helpers {
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

  template<typename TK, typename TV>
  static std::vector<TK> toArray(const std::map<TK, TV> &mp) {
    std::vector<TK> vec;
    for (auto const &key : mp)
      vec.push_back(key.first);
    return vec;
  }

  template<typename T>
  static bool BS(T elem, std::vector<T> vec) {
    int start = 0, end = vec.size() - 1, mid = (start + end) / 2;
    while (start <= end) {
      mid = (start + end) / 2;
      if (elem == vec[mid])
        return true;
      if (elem < vec[mid])
        end = mid - 1;
      else start = mid + 1;
    }
    return false;
  }

  // for removing digits when getting class name
  static std::string cName(const char *name) {
    std::string output = "";
    for (int i = 0; i < name[i] != '\0'; i++) {
      if (name[i] >= '0' && name[i] <= '9')
        continue;
      output += name[i];
    }
    return output;
  }
};
//------------------------------------------------------------------------------