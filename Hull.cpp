/**
 * @file Hull.cpp
 * @author your name (you@domain.com)
 * @brief This contains all the implementations of the convex hull algorithms
 * @version 0.1
 * @date 2019-03-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Point.h"
#include "Hull.h"
#include "Util.h"
#include "Stack.h"
using namespace std;
Util u;
Stack s;

/**
 * @brief This is a comparator function used in Graham Scan to sort the points according to their polar angle wrt to the first point
 * 
 * @param vp1 const void pointer of type Point
 * @param vp2 const void pointer of type Point
 * @return int 
 */
int compare(const void *vp1, const void *vp2)
{
  Point *p1 = (Point *)vp1;
  Point *p2 = (Point *)vp2;

  int o = u.findOrientation(p0, *p1, *p2);
  if (o == 0)
   return (u.findEuclideanDistance(p0, *p2) >= u.findEuclideanDistance(p0, *p1))? -1 : 1;

  return (o == -1)? -1: 1;
}

/**
 * @brief Uses the Graham Scan Algorithm to bulid a convex hull
 * 
 * @param points 
 */
void Hull::GS(vector<Point> points)
{
  /**
   * @brief Firstly, find the point with min y co-ordinate
   * 
   */
  int n = points.size();
  int ymin = points[0].getY(), min = 0;
  for (int i = 1; i < n; i++)
  {
    int y = points[i].getY();

    /**
     * @brief In case of a tie, choose the one with lower x co-ordinate
     * 
     */

    if ((y < ymin) || (ymin == y &&
        points[i].getX() < points[min].getX()))
       ymin = points[i].getY(), min = i;
  }

   /**
    * @brief Put the point with lowest y co-ordinate in the first position
    * 
    */
   u.swapPoints(points[0], points[min]);

   /**
    * @brief Sort all the following points with respect to the y_min point
    * 
    */
   p0 = points[0];

   int size = points.size();
   Point p[size];
   for(int i=0;i<size;i++)
   {
     p[i] = points[i];
   }

   qsort(&p[1], n-1, sizeof(Point), compare);

   for(int i=0;i<size;i++)
   {
     points[i] = p[i];
   }

   /**
    * @brief If there is more than one point that makes the same angle with y_min, then only take the point that is the furthest way. 
    * 
    */
   int m = 1; 
   for (int i=1; i<n; i++)
   {

       while (i < n-1 && u.findOrientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;


       points[m] = points[i];
       m++;  
   }

   /**
    * @brief A convex hull must have at least 3 points
    * 
    */
   if (m < 3) return;

   s.Push(points[0]);
   s.Push(points[1]);
   s.Push(points[2]);
 
   /**
    * @brief Only choose the points when the top of the stack, second element in the stack and a point in the points vector make a left turn
    * 
    */
   for (int i = 3; i < m; i++)
   {
      while (u.findOrientation(s.getSecond(), s.Top(), points[i]) != -1)
      {
        s.Pop();
      }
      s.Push(points[i]);

 }
   /**
    * @brief Output to file 
    * 
    */
   ofstream myfile;
   myfile.open ("./outputs/testg.txt");
   while (!s.isEmpty())
   {
       Point p = s.Top();
       p.printPoint();
        myfile << p.getX() << ", " << p.getY() << endl;
       s.Pop();
   }
   myfile.close();
}

/**
 * @brief Uses the Jarvis March Algorithm to bulid a convex hull
 * 
 * @param points 
 */
void Hull::JM(vector<Point> points)
{
  /**
   * @brief Get the point with the least x co-ordinate
   * 
   */
  int left_idx = u.findLeft(points);
  int current,follow;
  int size = points.size();
  vector<Point> convex;
  current = left_idx;

  /**
   * @brief Starting from left_idx, choose each subsequent point which makes the orientation counter-clockwise for all the remaining points. 
   * 
   */
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

  /**
   * @brief Write to file
   * 
   */
  ofstream myfile;
  myfile.open ("./outputs/testj.txt");
  for (int i = 0; i < convex.size(); i++)
  {
    myfile << convex[i].getX() << ", " << convex[i].getY() << endl;
  }
  myfile.close();

}
