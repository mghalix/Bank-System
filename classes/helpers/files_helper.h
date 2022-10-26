#pragma once

#include <fstream>

class FilesHelper {
public:
  static int getLast(std::string fileName) {
    std::ifstream inp(fileName);
    // checking if the file is open
    if (!inp) {
      inp.close();
      throw("File doesn't exist.\n");
    }
    inp.seekg(0, std::ios::end);
    // checking if the file is empty after peeking to the end.
    if (inp.tellg() == 0)
      throw("File is empty.\n");
    // now that we know that there's at least 1 record, we start to fetch id.
    char stop = ' '; // init stop anything but '\n'
    while (stop != '\n') {
      // we take 2 steps back, meaning we won't check for last character
      inp.seekg(-2, std::ios::cur);
      // in case we have 1 record only
      if (inp.tellg() <= 0) { // if we passed the start of the file,
        inp.seekg(0);         // get back to the start of the line
        break;
      }
      inp.get(stop); // as soon as it stores newline char in stop the loop end 
    }
    std::string strID;
    // store the first part of the record until the first delimiter is met
    getline(inp, strID, '|'); // inside of strID
    inp.close();
    return stoi(strID);
  }

  // the implementation of the functions below is at file_manager.h file
  static void showClients();

  static void showEmployees();

  static void showAdmins();

  static void clearFile(std::string fileName);
};