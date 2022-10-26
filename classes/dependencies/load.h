//------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <map>
#include <fstream>
class Load {
public:
  // Attributes
  static std::map<int, int> cliIdx;
  static std::map<int, int> empIdx;
  static std::map<int, int> admIdx;
  // indexing
  template<typename T>
  static void addIndex(const int &id, const int &pos) {
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
  static void rewriteAll() {
    rewriteIdx("db/Admin.txt", "db/adm-index.txt");
    rewriteIdx("db/Employee.txt", "db/emp-index.txt");
    rewriteIdx("db/Clients.txt", "db/cli-index.txt");
  }
  static void loadAll() {
    loadEntity("db/cli-index.txt", cliIdx);
    loadEntity("db/adm-index.txt", admIdx);
    loadEntity("db/emp-index.txt", empIdx);
  }
  // for testing
  static void showCliDic() {
    for (auto client : cliIdx)
      std::cout << client.first << '|' << client.second << std::endl;
  }
  static void showEmpDic() {
    for (auto employee : empIdx)
      std::cout << employee.first << '|' << employee.second << std::endl;
  }
  static void showAdmDic() {
    for (auto admin : admIdx)
      std::cout << admin.first << '|' << admin.second << std::endl;
  }
private:
  static void rewriteIdx(const std::string &readFile, const std::string &idxFile) {
    std::ifstream fin;
    std::ofstream ofs;
    fin.open(readFile);
    ofs.open(idxFile);
    int loc = 0;
    std::string line;
    while (fin.peek() != EOF) {
      getline(fin, line);
      line = CustomMethods::split(line, '|')[0] + '|' + std::to_string(loc);
      ofs << line << std::endl;
      loc += (int)fin.tellg() + 2;
    }
    ofs.close();
    fin.close();
  }
  static void loadIdx(const std::string &fileName, std::map<int, int> &mp) {
    mp.clear();
    std::ifstream fin(fileName);
    if (!fin) {
      fin.close();
      throw("No such file\n");
    }
    std::string line;
    while (fin.peek() != EOF) {
      getline(fin, line);
      mp.insert(std::pair<int, int>(stoi(CustomMethods::split(line, '|')[0]), stoi(CustomMethods::split(line, '|')[1])));
    }
    fin.close();
  }
  static void loadEntity(const std::string &idxFile, std::map<int, int> &idxMap) {
    loadIdx(idxFile, idxMap);
  }
};
//------------------------------------------------------------------------------
std::map<int, int> Load::cliIdx;
std::map<int, int> Load::empIdx;
std::map<int, int> Load::admIdx;
//------------------------------------------------------------------------------