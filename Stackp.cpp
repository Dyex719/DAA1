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
}
//
Point Stackp::Pop()
{
  return v.back();
}
//
// Stack::getTop()
// {
//   return top;
// }
//
// Stack::getLength(Point p)
// {
//   return length;
// }
//
// bool Stack::isEmpty()
// {
//   if(top==-999)
//     return true;
//   else
//     return false;
// }
