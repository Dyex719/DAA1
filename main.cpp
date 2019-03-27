#include "Point.h"
// #include <iostream>
#include "Util.h"
#include "Stackp.h"
#include<bits/stdc++.h>

using namespace std;

Util helper;

Point p0; // Include the first point in grahams scan thing

int comparepolar(Point p1, Point p2)
{

// Find orientation
int o = helper.getOrientation(p0, p1, p2);
if (o == 0)
	return (helper.getEuclideanDistance(p0, p2) >= helper.getEuclideanDistance(p0, p1))? -1 : 1;

return (o == 2)? -1: 1;
}

void JM(vector<Point> points)
{
  int left_idx = helper.getLeft(points);
  int p,q,r;
  int size = points.size();
  vector<Point> convex;
  p = left_idx;

  do
  {
    q = (p+1)%size;
    convex.push_back(points[p]);
    for(int i=0;i<size;i++)
    {
      // cout << helper.getOrientation(points[p],points[i],points[q]);
      if(helper.getOrientation(points[p],points[i],points[q])==-1)
      {
        q = i;
      }
    }
    p = q;
  }
  while(p!=left_idx);

  for (int i = 0; i < convex.size(); i++)
      cout << "(" << convex[i].getX() << ", "
            << convex[i].getY() << ")\n";

}



int main(void)
{
    // Point p1();
    // p1.printPoint();
    // p1.setXY(10,15);

    // Access values assigned by constructor
    // cout << "p1.getX() = " << p1.getX() << ", p1.getY() = " << p1.getY();
    // p1.printPoint();
    // ***************************************

    ifstream input("points.txt");
    double x, y;
    char comma;
    vector<Point> points;
    while (input >> x >> comma >> y)
    {
        points.push_back(Point(x,y));
    }

  // for(int i =0;i<points.size();i++)
  // {
  //   points[i].printPoint();
  // }

// JM(points);

// Stackp st;
// Point p1(10,20);
// st.Pushp(p1);
// Point a  = st.Pop();
// a.printPoint();

// helper.sortPolar(points);
sort(points.begin(), points.end(), comparepolar);

for(int i =0;i<points.size();i++)
{
  points[i].printPoint();
}




}
