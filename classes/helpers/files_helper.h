#pragma once

#include <fstream>

class FilesHelper {
public:
  //Attributes
  static std::string clientFile;
  static std::string employeeFile;
  static std::string adminFile;
  static std::string idxFileCli;
  static std::string idxFileEmp;
  static std::string idxFileAdm;
  // Methods
  static int getLast(std::string fileName) {
    std::ifstream inp(fileName);
    // checking if the file is open
    if (!inp) {
      inp.close();
      throw("File doesn't exist.");
    }
    inp.seekg(0, std::ios::end);
    // checking if the file is empty after peeking to the end.
    if (inp.tellg() == 0) {
      int id;
      if (fileName == employeeFile)
        id = 1990;
      else if (fileName == adminFile)
        id = 0;
      else id = 6990;
      return id;
    }
    // now that we know that there's at least 1 record, we start to fetch id.
    char stop = ' '; // init stop anything but '\n'
    while (stop != '\n') {
      // we take 2 steps back, meaning we won't check for last character
      inp.seekg(-2, inp.cur);
      // in case we have 1 record only
      // if stop is * means that id is deleted so we keep going
      if (int(inp.tellg()) <= 0 || stop == '*') { // if we passed the start of the file,
        inp.seekg(0);         // get back to the start of the line
        break;
      }
      inp.get(stop); // as soon as it stores newline char in stop the loop end 
    }
    std::string strID;
    // store the first part of the record until the first delimiter is met
    getline(inp, strID);
    std::cout << strID << std::endl;
    // getline(inp, strID, '|'); // inside of strID
    inp.close();
    return 200;
    // return stoi(strID);
  }

  // the implementation of the functions below is at file_manager.h file
  static void showClients();

  static void showEmployees();

  static void showAdmins();

  static void clearFile(std::string fileName);
};
//------------------------------------------------------------------------------
std::string FilesHelper::clientFile = "db/Clients.txt";
std::string FilesHelper::employeeFile = "db/Employees.txt";
std::string FilesHelper::adminFile = "db/Admins.txt";
std::string FilesHelper::idxFileCli = "db/idx-cli.txt";
std::string FilesHelper::idxFileEmp = "db/idx-emp.txt";
std::string FilesHelper::idxFileAdm = "db/idx-adm.txt";
//------------------------------------------------------------------------------