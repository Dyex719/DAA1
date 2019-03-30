#include "Stack.h"
using namespace std;
#include<bits/stdc++.h>

void Stack::Push(Point p)
{
  this->v.push_back(p);
  this->length++;
}

Point Stack::Pop()
{
  this->v.pop_back();
  this->length--;
}

Point Stack::Top()
{
  return this->v.back();

}

int Stack::getLength()
{
  return this->length;
}

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
