#ifndef Util_H
#define Util_H
#include<bits/stdc++.h>
#include "Point.h"
#include "Hull.h"

using namespace std;

class Util
{
  public:
    int getLeft(vector<Point> points);
    double getEuclideanDistance(Point a,Point b);
    int getOrientation(Point a,Point b,Point c);
    vector<Point> sortPolar(vector<Point> points);
    static int compare(Point a, Point b);
    void swapPoints(Point &a, Point &b);
    int getBottom(vector<Point> points);
    void printAllPoints(vector<Point> points);


    // Point p0;


};

#endif
