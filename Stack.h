#ifndef Stack_H
#define Stack_H
#include<bits/stdc++.h>
using namespace std;
#include "Point.h"

class Stack
{
  public:
    void Push(Point p);
    Point Pop();
    Point Top();
    int getLength();
    bool isEmpty();
    Point getSecond();
  private:
    int length = 0;
    vector<Point> v;
};

#endif
