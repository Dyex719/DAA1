// A C++ program to find convex hull of a set of points. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for explanation of orientation()
#include <iostream>
#include "Stack.h"
#include <stdlib.h>
using namespace std;
#include<bits/stdc++.h>
#include "Point.h"
#include "Util.h"

// A global point needed for  sorting points with reference
// to  the first point Used in compare function of qsort()
// Point p0;
Stack s;
Util u;
// A utility function to find next to Top in a stack


// A utility function to swap two points
int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return square of distance
// between p1 and p2
int distSq(Point p1, Point p2)
{
    return (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) +
          (p1.getY() - p2.getY())*(p1.getY() - p2.getY());
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
              (q.getX() - p.getX()) * (r.getY() - q.getY());

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;

   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n points.
void convexHull(Point points[], int n)
{
  // Find the bottommost point
  int ymin = points[0].getY(), min = 0;
  for (int i = 1; i < n; i++)
  {
    int y = points[i].getY();

    // Pick the bottom-most or chose the left
    // most point in case of tie
    if ((y < ymin) || (ymin == y &&
        points[i].getX() < points[min].getX()))
       ymin = points[i].getY(), min = i;
  }

   // Place the bottom-most point at first position
   swap(points[0], points[min]);

   // Sort n-1 points with respect to the first point.
   // A point p1 comes before p2 in sorted ouput if p2
   // has larger polar angle (in counterclockwise
   // direction) than p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);

   // If two or more points make same angle with p0,
   // Remove all but the one that is farthest from p0
   // Remember that, in above sorting, our criteria was
   // to keep the farthest point at the end when more than
   // one points have same angle.
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;


       points[m] = points[i];
       m++;  // Update size of modified array
   }

   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3) return;

   // Create an empty stack and push first three points
   // to it.
   s.Push(points[0]);
   s.Push(points[1]);
   s.Push(points[2]);

   // points[0].printPoint();
   // cout << s.getLength() << endl;
   // Point getX() = s.Top();
   // getX().printPoint();
   // Point getY() = s.getSecond();
   // getY().printPoint();
   // cout << s.getSecond()<< endl;

   // Process remaining size-3 points
   for (int i = 3; i < m; i++)
   {
      // cout << s.getLength();
      // points[i].printPoint();
      // Keep removing Top while the angle formed by
      // points next-to-Top, Top, and points[i] makes
      // a non-left turn
      while (u.findOrientation(s.getSecond(), s.Top(), points[i]) != -1)
      {
        s.Pop();
      }
      s.Push(points[i]);
      // Point getX() = s.Top();
      // getX().printPoint();
 }

   // Now stack has the output points, print contents of stack
   while (!s.isEmpty())
   {
       Point p = s.Top();
       cout << "(" << p.getX() << ", " << p.getY() <<")" << endl;
       s.Pop();
   }
}

// Driver program to test above functions
int main()
{

  string input_path = "./inputs/3.txt";


                      ifstream input(input_path);
                      double x, y;
                      char comma;
                      vector<Point> points;
                      while (input >> x >> comma >> y)
                      {
                          points.push_back(Point(x,y));
                      }

                      int size = points.size();
                      Point p[size];
                      for(int i=0;i<size;i++)
                      {
                        p[i] = points[i];
                      }

    int n = sizeof(p)/sizeof(p[0]);
    convexHull(p, n);
    return 0;
}
