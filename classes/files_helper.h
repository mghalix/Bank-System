#pragma once
#include <fstream>
class FilesHelper {
public:
  static int getLast(std::string fileName) {
    std::ifstream inp(fileName);
    if (!inp)
      throw("File doesn't exist.\n");
    // the eof is newline (2 bytes), so we want to get before it
    inp.seekg(-2, std::ios::end);
    char stop = ' ';
    while (stop != '\n') {
      inp.seekg(-2, std::ios::cur);
      inp.get(stop);
    }
    std::string strID;
    getline(inp, strID, '|');
    inp.close();
    return stoi(strID);
  }

  static void showClients();

  static void showEmployees();

  static void showAdmins();
  static void clearFile(std::string fileName);
};