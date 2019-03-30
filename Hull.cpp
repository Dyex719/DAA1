// #include <iostream>
#include "Point.h"
#include "Hull.h"
#include "Util.h"
#include "Stack.h"
// #include <utility>
#include<bits/stdc++.h>
using namespace std;

Util u;
Stack s;
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
// ********
// int compare(const void *vp1, const void *vp2)
// {
// Point *p1 = (Point *)vp1;
// Point *p2 = (Point *)vp2;
//
// // Find orientation
// int o = u.findOrientation(p0, *p1, *p2);
// if (o == 0)
// 	return (u.findEuclideanDistance(p0, *p2) >= u.findEuclideanDistance(p0, *p1))? -1 : 1;
//
// return (o == -1)? -1: 1;
// }

// int compare(const void *vp1, const void *vp2)
// {
//   Point *p1 = (Point *)vp1;
//   Point *p2 = (Point *)vp2;
//
//   int turn = u.findOrientation(p0, *p1, *p2);
//   if (turn == 0)
//   	return (u.findEuclideanDistance(p0, *p2) >= u.findEuclideanDistance(p0, *p1))? -1 : 1;
//   else if(turn==-1)
//     return -1;
//   else
//     return 1;
// }

// int comparep(Point p1, Point p2)
// {
// // Find orientation
// // p1.printPoint();
// // cout << " ";
// // p2.printPoint();
// // cout << endl;
// int turn = u.findOrientation(p0, p1, p2);
// if (turn == 0)
// 	return (u.findEuclideanDistance(p0, p2) >= u.findEuclideanDistance(p0, p1))? -1 : 1;
//
// return (turn == -1)? -1: 1;
// }

void Hull::GS(vector<Point> points)
{
  int min_y  = u.findBottom(points);
  u.swapPoints(points[0],points[min_y]);
  Point p0 = points[0];
  // u.printAllPoints(points);
  int size = points.size();
  Point p[size];
  for(int i=0;i<size;i++)
  {
    p[i] = points[i];
  }
  // cout << "size" << sizeof(Point);
  int n = size;
  qsort(&points[1], n-1, sizeof(Point), compare);

  // qsort(&p[1], size-1, sizeof(Point), compare);
  for(int i=0;i<size;i++)
  {
    p[i].printPoint();
  }
  cout << endl;

  // u.printAllPoints(points);

  // sort(copy.begin()+2, copy.end(), comparep);
  // u.printAllPoints(copy);


  int new_size =1;
  vector<Point> copy;
    // p0.printPoint();
  // u.printAllPoints(points);
  for (int i=1; i<size; i++)
  {
  	// Keep removing i while angle of i and i+1 is same
  	// with respect to p0
  	while (i < size-1 && u.findOrientation(p0, points[i],
  									points[i+1]) == 0)
  		i++;

      copy.push_back(points[i]);
  	points[new_size] = points[i];
  	new_size++; // Update size of modified array
  }
  // new_size = points.size();
// u.printAllPoints(points);
  // cout << new_size << endl;

  if (new_size < 3)
  {
    cout << "Convex hull not possible with 3 points";
    exit(0);
  }

  // u.printAllPoints(points);
  // cout << new_size<< endl;
  // cout << points.size()<<endl;
  // u.printAllPoints(copy);



   // Stack s;
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
   for (int i = 3; i < new_size; i++)
   {
      // cout << s.getLength();
      // points[i].printPoint();
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (u.findOrientation(s.getSecond(), s.Top(), points[i]) != -1)
      {
        s.Pop();
      }
      s.Push(points[i]);
      // Point getX() = s.Top();
      // getX().printPoint();
 }

//    stack<Point> S;
// S.push(points[0]);
// S.push(points[1]);
// S.push(points[2]);
//
//
// // Process remaining n-3 points
// for (int i = 3; i < new_size; i++)
// {
//   cout << S.size()<< endl;
//
// 	// Keep removing top while the angle formed by
// 	// points next-to-top, top, and points[i] makes
// 	// a non-left turn
// 	while (u.findOrientation(nextToTop(S), S.top(), points[i]) != -1)
// 		S.pop();
// 	S.push(points[i]);
// }
//   cout << S.size()<< endl;
//
// // Now stack has the output points, print contents of stack
// while (!S.empty())
// {
// 	Point p = S.top();
//   p.printPoint();
// 	S.pop();
// }




   // Now stack has the output points, print contents of stack
   // cout << s.getLength()<<endl;
   ofstream myfile;
   myfile.open ("./outputs/3g.txt");
   while (!s.isEmpty())
   {
       Point p = s.Top();
       p.printPoint();
        myfile << p.getX() << ", " << p.getY() << endl;
       s.Pop();
   }
   myfile.close();


  // u.printAllPoints(points);


}

void Hull::JM(vector<Point> points)
{
  int left_idx = u.findLeft(points);
  int current,follow;
  int size = points.size();
  vector<Point> convex;
  current = left_idx;

  do
  {
    follow = (current+1)%size;
    convex.push_back(points[current]);
    for(int i=0;i<size;i++)
    {
      if(u.findOrientation(points[current],points[i],points[follow])==-1)
      {
        follow = i;
      }
    }
    current = follow;
  }
  while(current!=left_idx);

  ofstream myfile;
  myfile.open ("./outputs/3j.txt");
  for (int i = 0; i < convex.size(); i++)
  {
    myfile << convex[i].getX() << ", " << convex[i].getY() << endl;
  }
  myfile.close();


}
