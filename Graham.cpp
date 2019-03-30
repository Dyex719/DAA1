// #include <iostream>
#include "Point.h"
#include "Graham.h"
#include "Util.h"
#include "Stackp.h"
// #include <utility>
#include<bits/stdc++.h>
using namespace std;

Util u;

int compare(const void *vp1, const void *vp2)
{
Point *p1 = (Point *)vp1;
Point *p2 = (Point *)vp2;

// Find orientation
int o = u.getOrientation(p0, *p1, *p2);
if (o == 0)
	return (u.getEuclideanDistance(p0, *p2) >= u.getEuclideanDistance(p0, *p1))? -1 : 1;

return (o == -1)? -1: 1;
}
Graham::Graham(vector<Point> points)
{
  int min_y  = u.getBottom(points);
  u.swapPoints(points[0],points[min_y]);
  Point p0 = points[0];
  int n = points.size();
  qsort(&points[1], n-1, sizeof(Point), compare);

  // points = u.sortPolar(points);
  u.printAllPoints(points);

  int m =1;
    // p0.printPoint();
  // u.printAllPoints(points);
  for (int i=1; i<n; i++)
  {
        // points[i].printPoint();
      // Keep removing i while angle of i and i+1 is same
      // with respect to p0
      while (i < n-1 && u.getOrientation(p0, points[i],
                                   points[i+1]) == 0)
         i++;


      points[m] = points[i];
      m++;  // Update size of modified array
  }

  // for(int i =0;i<m;i++)
  // {
  //   points[i].printPoint();
  // }
  // cout << endl;

  if (m < 3)
  {
    cout << "Convex hull not possible with 3 points";
    exit(0);
  }

  // u.printAllPoints(points);


   Stackp s;
   s.Pushp(points[0]);
   s.Pushp(points[1]);
   s.Pushp(points[2]);

   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (u.getOrientation(s.getSecond(), s.getTop(), points[i]) != -1)
         s.Pop();
      s.Pushp(points[i]);
   }


   // Now stack has the output points, print contents of stack
   while (!s.isEmpty())
   {
       Point p = s.getTop();
       p.printPoint();
       s.Pop();
   }


  // u.printAllPoints(points);


}
