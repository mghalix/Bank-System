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
    rewriteIdx(admIdx, "db/adm-index.txt");
    rewriteIdx(empIdx, "db/emp-index.txt");
    rewriteIdx(cliIdx, "db/cli-index.txt");
  }
  static void loadAll() {
    loadEntity("db/cli-index.txt", cliIdx);
    loadEntity("db/adm-index.txt", admIdx);
    loadEntity("db/emp-index.txt", empIdx);
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
  static T search(const int &id, std::map<int, int> &mp, const std::string &idxFile) {
    std::vector<int> keys = CustomMethods::toArray(mp);
    if (!CustomMethods::BST(id, keys))
      throw("Not found\n");
    int loc = mp[id];
    std::ifstream fin(idxFile);
    fin.seekg(loc);
    std::string line;
    getline(fin, line);
    std::vector<std::string> record = CustomMethods::split(line, '|');
    Parser::parseTo<T>(id);
  }
private:
  static void rewriteIdx(const std::map<int, int> mp, const std::string &idxFile) {
    std::ofstream ofs;
    ofs.open(idxFile);
    int loc = 0;
    std::string line;
    for (auto record : mp) {
      ofs << record.first << '|' << record.second << std::endl;
    }
    ofs.close();
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