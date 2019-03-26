#ifndef Util_H
#define Util_H
#include<bits/stdc++.h>
#include "Point.h"
using namespace std;

class Util
{
  public:
    int getLeft(vector<Point> points);
    double getEuclideanDistance(Point a,Point b);
    int getOrientation(Point a,Point b,Point c);


};

#endif
