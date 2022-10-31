#pragma once

#include <fstream>
#include <iomanip>
#include <string>
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
  static int getLastID(const std::string& fileName) {
    std::ifstream fin(fileName);
    std::vector<std::string> vec;
    if (fin.fail()) {
      throw ("Error opening file\n");
    } // Guard Clauses
    fin.seekg(0, std::ios::end);
    if (fin.tellg() == 0) {
      throw("Error, file is empty.\n");
    }
    fin.seekg(0, std::ios::beg); // short for beginning  
    std::string id="";
    while (fin.peek() != EOF) { // End of file
      std::string line;
      getline(fin, line);
      std::vector<std::string> record = Helpers::split(line, '|');
      id = record[0];
      vec.push_back(id);
    }
    fin.close();
    if (id[0] == '*') {
      for (int i = vec.size() - 1; i >= 0; i--) {
        if (vec[i][0] == '*') {
          continue;
        }
        id = vec[i];
        break;
      }
    }
    if(id[0] == '*') {
      throw("File is empty");
    }
    return stoi(id);
  }

  static int getLast(const std::string& fileName) {
    std::ifstream inp;
    inp.open(fileName);
    // checking if the file is open
    // if (!inp) {
      // inp.close();
      // throw("File doesn't exist.");
    // }
    // checking if the file is empty after peeking to the end.
    inp.seekg(0, std::ios_base::end);
    // if ((int)inp.tellg() == 0) {
    //   int id;
    //   if (fileName == employeeFile)
    //     id = 1990;
    //   else if (fileName == adminFile)
    //     id = 0;
    //   else id = 6990;
    //   return id;
    // }
    // now that we know that there's at least 1 record, we start to fetch id.
    char stop = ' '; // init stop anything but '\n'
    // inp.seekg(0, std::ios_base::end);
    int i = 0;
    while (stop != '\n') {
      // we take 2 steps back, meaning we won't check for last character
      // inp.seekg(-2, inp.cur);
      inp.seekg(-2, std::ios_base::cur);
      // in case we have 1 record only
      // if stop is * means that id is deleted so we keep going
      if (inp.tellg() <= 0) { // if we passed the start of the file,
        std::cout << 1 << ' ';
        inp.seekg(0);         // get back to the start of the line
        break;
      }
      inp.get(stop); // as soon as it stores newline char in stop the loop end 
    }
    std::string strID = "";
    // store the first part of the record until the first delimiter is met
    getline(inp, strID); // inside of strID
    std::cout << strID << std::endl;
    inp.close();
    // return stoi(strID);
    return 0;
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