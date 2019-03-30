// #include <iostream>
#include "Point.h"
#include "Hull.h"
#include "Util.h"
#include "Stack.h"
// #include <utility>
#include<bits/stdc++.h>
using namespace std;

Util u;
// Hull::Hull()
// {
//
// }
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

// Hull::Hull(vector<Point> points)
// {
//   int min_y  = u.getBottom(points);
//   u.swapPoints(points[0],points[min_y]);
//   Point p0 = points[0];
//   int n = points.size();
//   qsort(&points[1], n-1, sizeof(Point), compare);
//
//   // points = u.sortPolar(points);
//   // u.printAllPoints(points);
//
//   int m =1;
//     // p0.printPoint();
//   // u.printAllPoints(points);
//   for (int i=1; i<n; i++)
//   {
//         // points[i].printPoint();
//       // Keep removing i while angle of i and i+1 is same
//       // with respect to p0
//       while (i < n-1 && u.getOrientation(p0, points[i],
//                                    points[i+1]) == 0)
//          i++;
//
//
//       points[m] = points[i];
//       m++;  // Update size of modified array
//   }
//
//   // for(int i =0;i<m;i++)
//   // {
//   //   points[i].printPoint();
//   // }
//   // cout << endl;
//
//   if (m < 3)
//   {
//     cout << "Convex hull not possible with 3 points";
//     exit(0);
//   }
//
//   // u.printAllPoints(points);
//
//
//    Stack s;
//    s.Push(points[0]);
//    s.Push(points[1]);
//    s.Push(points[2]);
//
//    // Process remaining n-3 points
//    for (int i = 3; i < m; i++)
//    {
//       // Keep removing top while the angle formed by
//       // points next-to-top, top, and points[i] makes
//       // a non-left turn
//       while (u.getOrientation(s.getSecond(), s.getTop(), points[i]) != -1)
//          s.Pop();
//       s.Push(points[i]);
//    }
//
//
//    // Now stack has the output points, print contents of stack
//    ofstream myfile;
//    myfile.open ("./outputs/1g.txt");
//    while (!s.isEmpty())
//    {
//        Point p = s.getTop();
//        p.printPoint();
//         myfile << p.getX() << ", " << p.getY() << endl;
//        s.Pop();
//    }
//    myfile.close();
//
//
//   // u.printAllPoints(points);
//
//
// }

void Hull::JM(vector<Point> points)
{
  int left_idx = u.getLeft(points);
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
      // cout << u.getOrientation(points[p],points[i],points[q]);
      if(u.getOrientation(points[p],points[i],points[q])==-1)
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
