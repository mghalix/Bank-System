//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <map>
#include <fstream>
class Load {
public:
  static std::map<int, std::string> logDb;
  static std::map<int, int> cliIdx;
  static std::map<int, int> empIdx;
  static std::map<int, int> admIdx;

  template<typename T>
  static void loadLogin() {
    logDb.clear();
    std::string fileName;
    if (typeid(T) == typeid(Client))
      fileName = FileManager::clientFile;
    else if (typeid(T) == typeid(Employee))
      fileName = FileManager::employeeFile;
    else if (typeid(T) == typeid(Admin))
      fileName = FileManager::adminFile;
    else throw("Error, invalid type.\n");
    std::ifstream fin(fileName);
    if (!fin)
      throw("File doesn't exist\n");
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == 0)
      throw("File is empty\n");
    fin.seekg(0, std::ios::beg);
    std::string line;
    while (fin.peek() != EOF) {
      getline(fin, line);
      std::vector<std::string> vec = CustomMethods::split(line, '|');
      logDb.insert(std::pair<int, std::string>(stoi(vec[0]), vec[2]));
    }
    fin.close();
  }

  template<typename T>
  static void loadEntity() {
    std::string fileName;
    if (typeid(T) == typeid(Client))
      fileName = FileManager::clientFile;
    else if (typeid(T) == typeid(Employee))
      fileName = FileManager::employeeFile;
    else if (typeid(T) == typeid(Admin))
      fileName = FileManager::adminFile;
    else throw("Error, invalid type.\n");
    std::ifstream fin(fileName);
    if (!fin)
      throw("File doesn't exist\n");
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == 0)
      throw("File is empty\n");
    fin.seekg(0, std::ios::beg);
    int pos = 0;
    static std::map<int, int> *clone;
    if (typeid(T) == typeid(Client)) {
      clone = &cliIdx;
    }
    else if (typeid(T) == typeid(Employee)) {
      clone = &empIdx;
    }
    else {
      clone = &admIdx;
    }
    std::string line;
    while (fin.peek() != EOF) {
      pos = fin.tellg();
      getline(fin, line);
      std::vector<std::string> vec = CustomMethods::split(line, '|');
      clone->insert(std::pair<int, int>(stoi(vec[0]), pos));
      pos += 2;
    }
    clone = NULL;
    delete clone;
    fin.close();
  }
  // indexing
  template<typename T>
  static void addIndex(int id, int pos) {
    static std::map<int, int> *clone;
    if (typeid(T) == typeid(Client))
      clone = &cliIdx;
    else if (typeid(T) == typeid(Employee))
      clone = &empIdx;
    else clone = &admIdx;
    clone->insert(std::pair<int, int>(id, pos));
    clone = NULL;
    delete clone;
  }
private:
  // static void loadIndex() {
  //   cliIdx.clear();
  //   empIdx.clear();
  //   admIdx.clear();
  //   std::ifstream cliFin(FileManager::clientFile);
  //   std::ifstream empFin(FileManager::employeeFile);
  //   std::ifstream admFin(FileManager::adminFile);
  //   if (!cliFin || !empFin || !admFin) {
  //     std::cout << "Error, opening file.\n";
  //     return;
  //   }
  //   cliFin.seekg(0, std::ios::end);
  //   empFin.seekg(0, std::ios::end);
  //   admFin.seekg(0, std::ios::end);
  //   if (cliFin.tellg() == 0 || empFin.tellg() == 0 || admFin.tellg() == 0) {
  //     std::cout << "Error, file is empty.\n";
  //     return;
  //   }
  //   std::string line;
  //   cliFin.seekg(0, std::ios::beg);
  //   while (cliFin.peek() != EOF) {
  //     getline(cliFin, line);
  //     std::vector<std::string> record = CustomMethods::split(line, '|');
  //     cliIdx[stoi(record[0])] = stoi(record[1]);
  //   }
  //   empFin.seekg(0, std::ios::beg);
  //   while (empFin.peek() != EOF) {
  //     getline(empFin, line);
  //     std::vector<std::string> record = CustomMethods::split(line, '|');
  //     cliIdx[stoi(record[0])] = stoi(record[1]);
  //   }
  //   admFin.seekg(0, std::ios::beg);
  //   while (admFin.peek() != EOF) {
  //     getline(admFin, line);
  //     std::vector<std::string> record = CustomMethods::split(line, '|');
  //     cliIdx[stoi(record[0])] = stoi(record[1]);
  //   }
  //   cliFin.close();
  //   empFin.close();
  //   admFin.close();
  // }
};
//------------------------------------------------------------------------------
std::map<int, std::string> Load::logDb;

std::map<int, int> Load::cliIdx;
std::map<int, int> Load::empIdx;
std::map<int, int> Load::admIdx;
//------------------------------------------------------------------------------