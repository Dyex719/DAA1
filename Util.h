#ifndef Util_H
#define Util_H
#include<bits/stdc++.h>
#include "Point.h"
#include "Graham.h"

using namespace std;

class Util
{
  public:
    int getLeft(vector<Point> points);
    double getEuclideanDistance(Point a,Point b);
    int getOrientation(Point a,Point b,Point c);
    vector<Point> sortPolar(vector<Point> points);
    static int compare(Point a, Point b);
    // Point p0;


};

#endif
