//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include "../managers/file_manager.h"
#include "load.h"
class Login {
public:
  template<typename T>
  static T *login(int id, std::string password) {
    Load::loadLogin<T>();
    if (Load::logDb[id] != password)
      throw("User doesn't exist, please try again.\n");
    std::cout << "Login Successfully\n";
    // // TODO: make parseTo method use template
    static T entity = Parser::parseTo<T>(std::to_string(id));
    return &entity;
  }
};
//------------------------------------------------------------------------------