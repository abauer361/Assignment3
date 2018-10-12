#include <iostream>
#include "Genstack.h"
#include <fstream>
using namespace std;

class FileReader
{
  public:
    FileReader();
    FileReader(string name);
    ~FileReader();
    bool checkDelim();
    void getFileName();

  private:
    string fileName;
    Genstack<char>* stack;
};
