#include <iostream>
#include "Genstack.h"
#include "FileReader.h"
#include <fstream>
using namespace std;

FileReader::FileReader()
{
  getFileName();
  stack = new Genstack<char>();   //needed <char> because of template class
}

FileReader::FileReader(string name)
{
  fileName = name;
  stack = new Genstack<char>();

  checkDelim();
}

FileReader::~FileReader()
{
  delete stack;
}

bool FileReader::checkDelim()
{
  string line;
  ifstream input(fileName);

  if(!input) //there's no file named fileName
  {
    cout << "No file was available with the name " << fileName << endl;
    getFileName();
  }

  int lineNum = 0;

  while(getline(input, line)) //goes through file line by line
  {
    for(int i = 0; i < line.length(); ++i)  //goes through line character by character
    {
      if(line[i] == '(' || line[i] == '{' || line[i] == '[' || line[i] == ')' || line[i] == '}' || line[i] == ']') //only checks delimiters
      {
        if(line[i] == '(' || line[i] == '{' || line[i] == '[') //creates stack for open brackets
          stack->push(line[i]);
        else if(line[i] == ')' || line[i] == '}' || line[i] == ']')
        {
          if(stack->isEmpty()) //no delimiters overall
          {
            cout << "There was no other delimiter to match with.";
            return false;
          }
          if(stack->peek() == '(' && line[i] != ')')
          {
            cout << "You see to be missing a ) at line " << lineNum+1 << endl;
            return false;
          }
          else if(stack->peek() == '{' && line[i] != '}')
          {
            cout << "You see to be missing a } at line " << lineNum+1 << endl;
            return false;
          }
          else if(stack->peek() == '[' && line[i] != ']')
          {
            cout << "You see to be missing a ] at line " << lineNum+1 << endl;
            return false;
          }
          stack->pop();
        }

      }

    }
    lineNum++;  //keeps the line count up
  }
  if(stack->isEmpty()) //we good
  {
    cout << "There are no delimiter errors!" << endl;
    return true;
  }
  else //all for end of the file if delimiter is never found
  {
    if(stack->peek() == '(')
    {
      cout << "Reached end of file: missing )." << endl;
    }
    else if(stack->peek() == '{')
    {
      cout << "Reached end of file: missing }." << endl;
    }
    else if(stack->peek() == '[')
    {
      cout << "Reached end of file: missing ]." << endl;
    }
    return false;
  }

  input.close();
}

void FileReader::getFileName() //if name was entered wrong or no name entered at all
{
  cout << "What is the name of your file?" << endl;
  cin >> fileName;
  checkDelim();
}
