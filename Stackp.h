#ifndef STACKP_H
#define STACKP_H
#include<bits/stdc++.h>
using namespace std;
#include "Point.h"
// #define max_size 1000

class Stackp
{
  public:
    Stackp();
    void Pushp(Point p);
    Point Pop();
    Point getTop();
    int getLength();
    bool isEmpty();
    Point getSecond();
  private:
    int length = 0;
    vector<Point> v;
};

#endif
