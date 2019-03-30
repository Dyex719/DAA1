#ifndef Util_H
#define Util_H
#include<bits/stdc++.h>
#include "Point.h"
#include "Hull.h"

using namespace std;

class Util
{
  public:
    int findLeft(vector<Point> points);
    double findEuclideanDistance(Point a,Point b);
    int findOrientation(Point a,Point b,Point c);
    void sortPolar(vector<Point> points);
    static int compare(Point a, Point b);
    void swapPoints(Point &a, Point &b);
    int findBottom(vector<Point> points);
    void printAllPoints(vector<Point> points);
    vector<Point> getInput(string input_path);
};

#endif
