#include "Point.h"
// #include <iostream>
#include "Util.h"
#include "Stackp.h"
#include "Graham.h"
#include<bits/stdc++.h>

using namespace std;

Util helper;
// Graham g;
// Point p0; // Include the first point in grahams scan thing

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


// Testing stack
// Stackp st;
// Point p1(10,20);
// st.Pushp(points[0]);
// st.Pushp(points[1]);
// cout << st.getLength();
// Point a  = st.getTop();
// a.printPoint();
// Point b  = st.getSecond();
// b.printPoint();
// a= st.Pop();
// cout << st.getLength();
// cout << st.isEmpty();
// b= st.Pop();
// cout << st.getLength();
// cout << st.isEmpty();

Graham g(points);

// helper.sortPolar(points);
// sort(points.begin(), points.end(), comparepolar);

// for(int i =0;i<points.size();i++)
// {
//   points[i].printPoint();
// }
// cout << endl;

// Graham g(vector<Point> points);



}
