#include "Stack.h"
using namespace std;
#define max_size 1000
#include<bits/stdc++.h>

Stack::Stack()
{
  // this->v = stack(max_size)
  // vector<Point> v(max_size);
  // this->top = NULL;
  // this->v() = vector<Point> stack(100);
  // this->v() =
}

// Stack::Stack(Point p )
// {
//   vector<Point> stack(max_size);
//   stack.push_back(p);
//   top = p;
// }

void Stack::Push(Point p)
{
  this->v.push_back(p);
  // cout << this->v.size();
  this->length++;
}

Point Stack::Pop()
{
  this->v.pop_back();
  // cout << this->v.size();
  this->length--;

}

Point Stack::getTop()
{
  return this->v.back();

}
//
int Stack::getLength()
{
  return this->length;
}
//
bool Stack::isEmpty()
{
  if(length==0)
    return true;
  else
    return false;
}

Point Stack::getSecond()
{
  return *(this->v.rbegin() + 1);

}
