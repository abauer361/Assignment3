#ifndef __GENSTACK_H
#define __GENSTACK_H
#include <iostream>

//https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files

template <typename T> //for template class
class Genstack
{
  public:
    Genstack()
    {
      myArray = new T(25);
      size = 25;
      top = -1;
    }

    Genstack(int maxSize)  //sets stack to maxSize
    {
      myArray = new T(maxSize);
      size = maxSize;
      top = -1;
    }

    ~Genstack()
    {
      delete myArray;
    }

    void push(T element) //adds a stack to the top
    {
      if(isFull())  //if the stack is too full it will grow the stack then add an element
        resize();
    	myArray[++top] = element;
    }

    T peek() //checks on top stack
    {
    	return myArray[top];
    }

    T pop() //gets rid of top stack
    {
      if(isEmpty())
        throw "Your stack is empty.";
      else
    	 return myArray[top--];
    }

    bool isFull() //if its full it's true
    {
    	return (top == size - 1);
    }

    bool isEmpty()
    {
      return (top == -1);
    }

    T* myArray;

  private:
    void resize()  //double the size of the stack
    {
      T* arr = new T[size*2];
      for(int i = 0; i < size; i++)
      {
        arr[i] = myArray[i];
      }
      size *= 2;
      delete myArray;
      myArray = arr;
    }


    int size;
    int top;
};
#endif
