//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "../helpers/custom_methods.h"
/* <===================|Indexing|===================> */
class Load {
public:
  // <|---------------------------Attributes---------------------------|>
  static std::map<int, int> cliIdx;
  static std::map<int, int> empIdx;
  static std::map<int, int> admIdx;
  static std::string idxFileCli;
  static std::string idxFileEmp;
  static std::string idxFileAdm;
  // <|---------------------------Methods------------------------------|>
  // enhanced version of parseTo method of Parser class
  template<typename T>
  static T *parseTo(const std::string &id) {
    static std::map<int, int> *clone;
    std::string fileName;
    if (typeid(T) == typeid(Client)) {
      clone = &cliIdx;
      fileName = "db/Clients.txt";
    }
    else if (typeid(T) == typeid(Employee)) {
      clone = &empIdx;
      fileName = "db/Employees.txt";
    }
    else if (typeid(T) == typeid(Admin)) {
      clone = &admIdx;
      fileName = "db/Admins.txt";
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
      a->setID(stoi(vec[0]));
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
      for (auto const &cli : cliIdx) {
        std::cout << "***** Client[" << i++ << "] info *****\n";
        Load::search<Client>(cli.first)->display();
      }
    }
    else if (typeid(T) == typeid(Admin)) {
      for (auto const &adm : admIdx) {
        std::cout << "***** Admin[" << i++ << "] info *****\n";
        Load::search<Admin>(adm.first)->display();
      }
    }
    else if (typeid(T) == typeid(Employee)) {
      for (auto const &emp : empIdx) {
        std::cout << "***** Employee[" << i++ << "] info *****\n";
        Load::search<Employee>(emp.first)->display();
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
    rewriteIdx(admIdx, idxFileAdm);
    rewriteIdx(empIdx, idxFileEmp);
    rewriteIdx(cliIdx, idxFileCli);
  }
  // for loading all entities info from index files to maps
  static void loadAll() {
    loadIdx(idxFileCli, cliIdx);
    loadIdx(idxFileAdm, admIdx);
    loadIdx(idxFileEmp, empIdx);
  }
  // for searching, editing and retrieving an entity info
  template<typename T>
  static T *search(const int &id) {
    static std::string *idxFile;
    static std::map<int, int> *clone;
    if (typeid(T) == typeid(Client)) {
      clone = &cliIdx;
      idxFile = &idxFileCli;
    }
    else if (typeid(T) == typeid(Admin)) {
      clone = &admIdx;
      idxFile = &idxFileAdm;
    }
    else if (typeid(T) == typeid(Employee)) {
      clone = &empIdx;
      idxFile = &idxFileEmp;
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
    std::ifstream fin(*idxFile);
    fin.seekg(loc);
    std::string line;
    getline(fin, line);
    std::vector<std::string> record = Helpers::split(line, '|');
    clone = NULL;
    delete clone;
    idxFile = NULL;
    delete idxFile;
    return parseTo<T>(std::to_string(id));
  }
  // for testing indexed files (id - loc)
  static void showCliDic() {
    for (auto const &client : cliIdx)
      std::cout << client.first << '|' << client.second << std::endl;
  }
  static void showEmpDic() {
    for (auto const &employee : empIdx)
      std::cout << employee.first << '|' << employee.second << std::endl;
  }
  static void showAdmDic() {
    for (auto const &admin : admIdx)
      std::cout << admin.first << '|' << admin.second << std::endl;
  }
  // <|----------------------------public end---------------------------------|>
private:
  // private ctor for restricting object creation
  Load() {}
  // |>---------------------------Methods------------------------------<|
  static void rewriteIdx(const std::map<int, int> mp, const std::string &idxFile) {
    std::ofstream ofs(idxFile, std::ios::trunc);
    ofs.seekp(0, std::ios::beg);
    int loc = 0;
    std::string line;
    for (auto record : mp) {
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
    while (fin.peek() != EOF) {
      getline(fin, line);
      vec = Helpers::split(line, '|');
      mp.insert(std::pair<int, int>(stoi(vec[0]), stoi(vec[1])));
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
std::string Load::idxFileCli = "db/idx-cli.txt";
std::string Load::idxFileEmp = "db/idx-emp.txt";
std::string Load::idxFileAdm = "db/idx-adm.txt";
// <--------------------------------------------------------------------------->