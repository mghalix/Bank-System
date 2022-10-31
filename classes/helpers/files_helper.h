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
  static bool moveToStartOfLine(std::ifstream& fs)
  {
    fs.seekg(-1, std::ios_base::cur);
    for (long i = fs.tellg(); i > 0; i--)
    {
      if (fs.peek() == '\n')
      {
        fs.get();
        return true;
      }
      fs.seekg(i, std::ios_base::beg);
    }
    return false;
  }

  static std::string getLastLineInFile(std::ifstream& fs)
  {
    // Go to the last character before EOF
    fs.seekg(-2, std::ios_base::end);
    if (!moveToStartOfLine(fs))
      return "";

    std::string lastline = "";
    getline(fs, lastline);
    return lastline;
  }

  static int getLast(std::string fileName) {
    std::ifstream inp(fileName);
    // checking if the file is open
    if (!inp) {
      inp.close();
      throw("File doesn't exist.");
    }
    inp.seekg(0, inp.end);
    // checking if the file is empty after peeking to the end.
    if ((int)inp.tellg() == 0) {
      int id;
      if (fileName == employeeFile)
        id = 1990;
      else if (fileName == adminFile)
        id = 0;
      else id = 6990;
      return id;
    }
    // now that we know that there's at least 1 record, we start to fetch id.
    inp.seekg(-1, std::ios::end);
    char stop = ' '; // init stop anything but '\n'
    while (stop != '\n') {
      // we take 2 steps back, meaning we won't check for last character
      inp.seekg(-2, inp.cur);
      // in case we have 1 record only
      // if stop is * means that id is deleted so we keep going
      if ((int)inp.tellg() <= 0 || stop == '*') { // if we passed the start of the file,
        inp.seekg(0);         // get back to the start of the line
        break;
      }
      inp.get(stop); // as soon as it stores newline char in stop the loop end 
    }
    std::string strID = "";
    // store the first part of the record until the first delimiter is met
    getline(inp, strID, '|'); // inside of strID
    std::cout << strID << std::endl;
    inp.close();
    // return stoi(strID);
    return 200;
  }
  static int getLast2(std::string fileName) {
    std::ifstream fin;
    fin.open(fileName);
    if (fin.is_open()) {
      fin.seekg(-1, std::ios_base::end);                // go to one spot before the EOF

      bool keepLooping = true;
      while (keepLooping) {
        char ch;
        fin.get(ch);                            // Get current byte's data

        if ((int)fin.tellg() <= 1) {             // If the data was at or before the 0th byte
          fin.seekg(0);                       // The first line is the last line
          keepLooping = false;                // So stop there
        }
        else if (ch == '\n') {                   // If the data was a newline
          keepLooping = false;                // Stop at the current position.
        }
        else {                                  // If the data was neither a newline nor at the 0 byte
          fin.seekg(-2, std::ios_base::cur);        // Move to the front of that data, then to the front of the data before it
        }
      }

      std::string lastLine;
      getline(fin, lastLine);                      // Read the current line
      std::cout << "Result: " << lastLine << '\n';     // Display it

      fin.close();
    }
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