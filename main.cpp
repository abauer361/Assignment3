#include <iostream>
#include "Genstack.h"
#include <string>
#include <fstream>
#include "FileReader.h"
using namespace std;

int main(int argc, char** argv)
{
  if(argc > 1)
  {
    string input = argv[1];
    FileReader file(input);
  }
  else
  {
    cout << "You did not enter a file name within the command line.";
  }
}
