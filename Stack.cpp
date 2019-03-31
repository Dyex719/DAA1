/**
 * @file Stack.cpp
 * @author your name (you@domain.com)
 * @brief Stack Class
 * @version 0.1
 * @date 2019-03-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Stack.h"
using namespace std;

/**
 * @brief Push a point to the stack
 * 
 * @param p Point 
 */
void Stack::Push(Point p)
{
  this->v.push_back(p);
  this->length++;
}

/**
 * @brief Pop an element from the stack
 * 
 * @return Point 
 */
Point Stack::Pop()
{
  this->v.pop_back();
  this->length--;
}

/**
 * @brief Peek at the top element in the stack
 * 
 * @return Point 
 */
Point Stack::Top()
{
  return this->v.back();

}

/**
 * @brief Get the current length of the stack
 * 
 * @return int 
 */
int Stack::getLength()
{
  return this->length;
}

/**
 * @brief Check if the stack is empty or not
 * 
 * @return true 
 * @return false 
 */
bool Stack::isEmpty()
{
  if(this->length==0)
    return true;
  else
    return false;
}

Point Stack::getSecond()
{
  return *(this->v.rbegin() + 1);
}
