//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <typeinfo>
#include <map>
#include <fstream>
#include <string>
// #include "../helpers/custom_methods.h"
/* <===================|Indexing|===================> */
class Load {
public:
  // <|---------------------------Attributes---------------------------|>
  static std::map<int, int> cliIdx;
  static std::map<int, int> empIdx;
  static std::map<int, int> admIdx;
  // <|---------------------------Methods------------------------------|>
  // enhanced version of parseTo method of Parser class
  template<typename T>
  static T *parseTo(const std::string &id) {
    static std::map<int, int> *clone;
    std::string fileName;
    if (typeid(T) == typeid(Client)) {
      clone = &cliIdx;
      fileName = FilesHelper::clientFile;
    }
    else if (typeid(T) == typeid(Employee)) {
      clone = &empIdx;
      fileName = FilesHelper::employeeFile;
    }
    else if (typeid(T) == typeid(Admin)) {
      clone = &admIdx;
      fileName = FilesHelper::adminFile;
    }
    else throw("No such file to open.\n");
    if (clone->find(stoi(id)) != clone->end()) {
      int loc = clone->at(stoi(id));
      std::ifstream fin(fileName);
      fin.seekg(loc);
      std::string line;
      getline(fin, line);
      fin.close();
      std::vector<std::string> vec(4);
      vec = Helpers::split(line, '|');
      T *a = new T(vec[1], vec[2], stod(vec[3]));
      a->setID(stoi(id));
      clone = NULL;
      delete clone;
      return a;
    }
    std::string className = Helpers::cName(typeid(T).name());
    clone = NULL;
    delete clone;
    // Employee id #2030 -> doesn't exist
    throw(className + " ID #" + id + " -> doesn't exist.");
  }
  // for listing all existing info of an entity
  template<typename T>
  static void showEvery() {
    int i = 1;
    if (typeid(T) == typeid(Client)) {
      for (std::pair<int, int> const &cli : cliIdx) {
        std::cout << "***** Client[" << i++ << "] info *****\n";
        search<Client>(cli.first)->display();
      }
    }
    else if (typeid(T) == typeid(Admin)) {
      for (std::pair<int, int> const &adm : admIdx) {
        std::cout << "***** Admin[" << i++ << "] info *****\n";
        search<Admin>(adm.first)->display();
      }
    }
    else if (typeid(T) == typeid(Employee)) {
      for (std::pair<int, int> const &emp : empIdx) {
        std::cout << "***** Employee[" << i++ << "] info *****\n";
        search<Employee>(emp.first)->display();
      }
    }
    else
      throw("No such type");
  }
  // for adding new entities into the indexed file
  template<typename T>
  static void addIndex(const int &id, const int &pos) {
    static std::map<int, int> *clone;
    if (typeid(T) == typeid(Client))
      clone = &cliIdx;
    else if (typeid(T) == typeid(Admin))
      clone = &admIdx;
    else if (typeid(T) == typeid(Employee))
      clone = &empIdx;
    else
      throw("No such type");
    clone->insert(std::pair<int, int>(id, pos));
    clone = NULL;
    delete clone;
  }
  // for index files from the map
  static void rewriteAll() {
    rewriteIdx(admIdx, FilesHelper::idxFileAdm);
    rewriteIdx(empIdx, FilesHelper::idxFileEmp);
    rewriteIdx(cliIdx, FilesHelper::idxFileCli);
  }
  // for loading all entities info from index files to maps
  static void loadAll() {
    Admin::initID();
    Employee::initID();
    Client::initID();
    loadIdx(FilesHelper::idxFileCli, cliIdx);
    loadIdx(FilesHelper::idxFileAdm, admIdx);
    loadIdx(FilesHelper::idxFileEmp, empIdx);
  }
  // for searching, editing and retrieving an entity info
  template<typename T>
  static T *search(const int &id) {
    static std::string *idxFile;
    static std::map<int, int> *clone;
    if (typeid(T) == typeid(Client)) {
      clone = &cliIdx;
      idxFile = &FilesHelper::idxFileCli;
    }
    else if (typeid(T) == typeid(Admin)) {
      clone = &admIdx;
      idxFile = &FilesHelper::idxFileAdm;
    }
    else if (typeid(T) == typeid(Employee)) {
      clone = &empIdx;
      idxFile = &FilesHelper::idxFileEmp;
    }
    else {
      idxFile = NULL;
      delete idxFile;
      clone = NULL;
      delete clone;
      throw("No such type");

    }
    std::vector<int> keys = Helpers::toArray(*clone);
    std::string className = Helpers::cName(typeid(T).name());
    if (!Helpers::BS(id, keys)) {
      clone = NULL;
      delete clone;
      idxFile = NULL;
      delete idxFile;
      throw(className + " ID #" + std::to_string(id) + " -> doesn't exist.");
    }

    int loc = clone->at(id);
    std::ifstream fin(*idxFile);
    fin.seekg(loc);
    std::string line;
    getline(fin, line);
    fin.close();
    std::vector<std::string> record = Helpers::split(line, '|');
    clone = NULL;
    delete clone;
    idxFile = NULL;
    delete idxFile;
    return parseTo<T>(std::to_string(id));
  }
  template<typename T>
  static int getLocation(const int &id) {
    static std::string *idxFile;
    static std::map<int, int> *clone;
    if (typeid(T) == typeid(Client)) {
      clone = &cliIdx;
      idxFile = &FilesHelper::idxFileCli;
    }
    else if (typeid(T) == typeid(Admin)) {
      clone = &admIdx;
      idxFile = &FilesHelper::idxFileAdm;
    }
    else if (typeid(T) == typeid(Employee)) {
      clone = &empIdx;
      idxFile = &FilesHelper::idxFileEmp;
    }
    else {
      idxFile = NULL;
      delete idxFile;
      clone = NULL;
      delete clone;
      throw("No such type");

    }
    std::vector<int> keys = Helpers::toArray(*clone);
    std::string className = Helpers::cName(typeid(T).name());
    if (!Helpers::BS(id, keys)) {
      clone = NULL;
      delete clone;
      idxFile = NULL;
      delete idxFile;
      throw(className + " ID #" + std::to_string(id) + " -> doesn't exist.\n");
    }

    int loc = clone->at(id);
    clone = NULL;
    delete clone;
    idxFile = NULL;
    delete idxFile;
    return loc;
  }
  // template<typename T>
  // static void editEntity(const int &id) {
  //   static T *target;
  //   static std::string *file;
  //   if (typeid(T) == typeid(Client)) {
  //     static Client *c = search<Client>(id);
  //     target = c;
  //     file = &FilesHelper::clientFile;
  //   }
  //   else if (typeid(T) == typeid(Admin)) {
  //     static Admin *a = search<Admin>(id);
  //     target = a;
  //     // target = search<Admin>(id);
  //     file = &FilesHelper::adminFile;
  //   }
  //   else if (typeid(T) == typeid(Employee)) {
  //     target = search<Employee>(id);
  //     file = &FilesHelper::employeeFile;
  //   }
  //   else
  //     throw("No such type");
  //   std::ofstream ofs(*file);
  //   ofs.close();
  //   target = NULL;
  //   delete target;
  // }
  // for testing indexed files (id - loc)
  static void showCliDic() {
    for (std::pair<int, int> const &client : cliIdx)
      std::cout << client.first << '|' << client.second << std::endl;
  }
  static void showEmpDic() {
    for (std::pair<int, int> const &employee : empIdx)
      std::cout << employee.first << '|' << employee.second << std::endl;
  }
  static void showAdmDic() {
    for (std::pair<int, int> const &admin : admIdx)
      std::cout << admin.first << '|' << admin.second << std::endl;
  }
  // <|----------------------------public end---------------------------------|>
private:
  // |>--------------------------Attributes----------------------------<|
  std::ifstream fin;
  std::ofstream ofs;
  // |>-------------------------Constructor----------------------------<|
  // private ctor for restricting object creation
  Load() {}
  // |>---------------------------Methods------------------------------<|
  static void rewriteIdx(const std::map<int, int> mp, const std::string &idxFile) {
    std::ofstream ofs(idxFile, std::ios::trunc);
    std::string line;
    for (std::pair<int, int> const &record : mp) {
      line = std::to_string(record.first) + '|' + std::to_string(record.second);
      ofs << line << std::endl;
    }
    ofs.close();
  }
  static void loadIdx(const std::string &fileName, std::map<int, int> &mp) {
    mp.clear();
    std::ifstream fin(fileName);
    fin.seekg(0, std::ios::beg);
    if (!fin) {
      fin.close();
      throw("No such file\n");
    }
    std::string line;
    std::vector<std::string> vec;
    // std::cout << fileName << "\nkey\tloc\n";
    while (fin.peek() != EOF) {
      getline(fin, line);
      vec = Helpers::split(line, '|');
      mp.insert(std::pair<int, int>(stoi(vec[0]), stoi(vec[1])));
      // std::cout << vec[0] << '\t' << vec[1] << '\n';
    }
    fin.close();
  }
  template<typename T>
  static T *search(const int &id, std::map<int, int> &mp, const std::string &idxFile) {
    std::vector<int> keys = Helpers::toArray(mp);
    if (!Helpers::BS(id, keys))
      throw("Not found\n");
    int loc = mp[id];
    std::ifstream fin(idxFile);
    fin.seekg(loc);
    std::string line;
    getline(fin, line);
    std::vector<std::string> record = Helpers::split(line, '|');
    return parseTo<T>(id);
  }
};
// <-----------------------Static members initialization----------------------->
std::map<int, int> Load::cliIdx;
std::map<int, int> Load::empIdx;
std::map<int, int> Load::admIdx;
// <--------------------------------------------------------------------------->