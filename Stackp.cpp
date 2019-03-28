#include "Stackp.h"
using namespace std;
#define max_size 1000
#include<bits/stdc++.h>

Stackp::Stackp()
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

void Stackp::Pushp(Point p)
{
  this->v.push_back(p);
  // cout << this->v.size();
  this->length++;
}

Point Stackp::Pop()
{
  this->v.pop_back();
  // cout << this->v.size();
  this->length--;

}

Point Stackp::getTop()
{
  return this->v.back();

}
//
int Stackp::getLength()
{
  return length;
}
//
bool Stackp::isEmpty()
{
  if(length==0)
    return true;
  else
    return false;
}

Point Stackp::getSecond()
{
  return *(this->v.rbegin() + 1);

}
