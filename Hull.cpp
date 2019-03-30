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


int compare(const void *vp1, const void *vp2)
{
  Point *p1 = (Point *)vp1;
  Point *p2 = (Point *)vp2;

  int turn = u.findOrientation(p0, *p1, *p2);
  if (turn == 0)
  	return (u.findEuclideanDistance(p0, *p2) >= u.findEuclideanDistance(p0, *p1))? -1 : 1;
  else if(turn==-1)
    return -1;
  else
    return 1;
}

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
  int size = points.size();
  vector<Point> copy = points;
  qsort(&points[1], size-1, sizeof(Point), compare);
  // u.printAllPoints(points);

  // sort(copy.begin()+2, copy.end(), comparep);
  // u.printAllPoints(copy);


  int new_size =1;
    // p0.printPoint();
  // u.printAllPoints(points);
  for (int i=1; i<size; i++)
  {
        // points[i].printPoint();
      // Keep removing i while angle of i and i+1 is same
      // with respect to p0
      while (i < size-1 && u.findOrientation(p0, points[i], points[i+1]) == 0)
         i++;


      points[new_size] = points[i];
      new_size++;  // Update size of modified array
      // if(u.findOrientation(p0, points[i], points[i+1]) == 0) points.erase(points.begin()+i);

  }
  // new_size = points.size();
// u.printAllPoints(points);

  if (new_size < 3)
  {
    cout << "Convex hull not possible with 3 points";
    exit(0);
  }

  // u.printAllPoints(points);


   // Stack s;
   s.Push(points[0]);
   s.Push(points[1]);
   s.Push(points[2]);

   // Process remaining size-3 points
   for (int i = 3; i < new_size; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (u.findOrientation(s.getSecond(), s.Top(), points[i]) != -1)
         s.Pop();
      s.Push(points[i]);
   }


   // Now stack has the output points, print contents of stack
   ofstream myfile;
   myfile.open ("./outputs/1g.txt");
   while (!s.isEmpty())
   {
       Point p = s.Top();
       // p.printPoint();
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
  myfile.open ("./outputs/1j.txt");
  for (int i = 0; i < convex.size(); i++)
  {
    myfile << convex[i].getX() << ", " << convex[i].getY() << endl;
  }
  myfile.close();


}
