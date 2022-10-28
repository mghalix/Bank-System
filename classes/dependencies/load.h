//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>
class Load {
public:
  // Attributes
  static std::map<int, int> cliIdx;
  static std::map<int, int> empIdx;
  static std::map<int, int> admIdx;
  static std::string idxFileCli;
  static std::string idxFileEmp;
  static std::string idxFileAdm;

  // indexing
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
      fileName = "db/Employee.txt";
    }
    else if (typeid(T) == typeid(Admin)) {
      clone = &admIdx;
      fileName = "db/Admin.txt";
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
      vec = CustomMethods::split(line, '|');
      T *a = new T(vec[1], vec[2], stod(vec[3]));
      a->setID(stoi(vec[0]));
      clone = NULL;
      delete clone;
      return a;
    }
    std::string className = correct(typeid(T).name());
    clone = NULL;
    delete clone;
    // Employee id #2030 -> doesn't exist
    throw(className + " ID #" + id + " -> doesn't exist.");
  }
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
  static void rewriteAll() {
    rewriteIdx(admIdx, "db/adm-index.txt");
    rewriteIdx(empIdx, "db/emp-index.txt");
    rewriteIdx(cliIdx, "db/cli-index.txt");
  }
  static void loadAll() {
    loadIdx("db/cli-index.txt", cliIdx);
    loadIdx("db/adm-index.txt", admIdx);
    loadIdx("db/emp-index.txt", empIdx);
  }
  // for testing
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
  template<typename T>
  static T *search(const int &id, std::map<int, int> &mp, const std::string &idxFile) {
    std::vector<int> keys = CustomMethods::toArray(mp);
    if (!CustomMethods::BST(id, keys))
      throw("Not found\n");
    int loc = mp[id];
    std::ifstream fin(idxFile);
    fin.seekg(loc);
    std::string line;
    getline(fin, line);
    std::vector<std::string> record = CustomMethods::split(line, '|');
    return parseTo<T>(id);
  }

  template<typename T>
  static T *search(const int &id) {
    std::string idxFile;
    static std::map<int, int> *clone;
    if (typeid(T) == typeid(Client)) {
      clone = &cliIdx;
      idxFile = "db/cli-index.txt";
    }
    else if (typeid(T) == typeid(Admin)) {
      clone = &admIdx;
      idxFile = "db/adm-index.txt";
    }
    else if (typeid(T) == typeid(Employee)) {
      clone = &empIdx;
      idxFile = "db/emp-index.txt";
    }
    else
      throw("No such type");
    std::vector<int> keys = CustomMethods::toArray(*clone);
    std::string className = correct(typeid(T).name());
    if (!CustomMethods::BST(id, keys))
      // throw("User not found.");
      throw(className + " ID #" + std::to_string(id) + " -> doesn't exist.\n");

    int loc = clone->at(id);
    std::ifstream fin(idxFile);
    fin.seekg(loc);
    std::string line;
    getline(fin, line);
    std::vector<std::string> record = CustomMethods::split(line, '|');
    clone = NULL;
    delete clone;
    return parseTo<T>(std::to_string(id));
  }
private:
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
      vec = CustomMethods::split(line, '|');
      mp.insert(std::pair<int, int>(stoi(vec[0]), stoi(vec[1])));
    }
    fin.close();
  }
private:
  // helpers
  static std::string correct(const char *name) {
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
std::map<int, int> Load::cliIdx;
std::map<int, int> Load::empIdx;
std::map<int, int> Load::admIdx;
std::string Load::idxFileCli = "db/cli-index.txt";
std::string Load::idxFileEmp = "db/adm-index.txt";
std::string Load::idxFileAdm = "db/emp-index.txt";
//------------------------------------------------------------------------------