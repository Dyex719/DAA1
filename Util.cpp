/**
 * @file Util.cpp
 * @author your name (you@domain.com)
 * @brief Util Class which contains all the helper functions used in the convex hull algorithms.
 * @version 0.1
 * @date 2019-03-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Util.h"
#include "Hull.h"
#include <math.h>
using namespace std;
Point p0;

/**
 * @brief Find the index of the point which has the least X co-ordinate
 * 
 * @param points vector<Point>
 * @return int index
 */
int Util::findLeft(vector<Point> points)
{
  int num = points.size();
  int min_x = 0;
  for(int i =0;i<num;i++)
  {
    if((points[i].getX()<points[min_x].getX()) || (points[i].getX()==points[min_x].getX() && points[i].getY()<points[min_x].getY()))
    {
      min_x = i;
    }
  }
  return min_x;
}

/**
 * @brief Find the index of the point which has the least y co-ordinate
 * 
 * @param points vector<Point>
 * @return int index
 */
int Util::findBottom(vector<Point> points)
{
  int num = points.size();
  int min_y = 0;
  for(int i =0;i<num;i++)
  {
    if((points[i].getY()<points[min_y].getY()) || (points[i].getY()==points[min_y].getY() && points[i].getX()<points[min_y].getX()))
    {
      min_y = i;
    }
  }
  return min_y;
}

/**
 * @brief Find the Euclidean distace between two points
 * 
 * @param a Point
 * @param b Point
 * @return double 
 */
double Util::findEuclideanDistance(Point a,Point b)
{
  double distance = sqrt(pow(a.getY()-b.getY(),2)+pow(a.getX()-b.getX(),2));
  return distance;
}

/**
 * @brief Find whether the points passed in make a clockwise turn or an anti-clockwise turn
 * 
 * @param a Point
 * @param b Point
 * @param c Point
 * @return int 
 * 0 -> Colinear
 * 1 -> Clockwise
 * -1 -> Counterclockwise
 */
int Util::findOrientation(Point a,Point b,Point c)
{
  int cross_product = ((b.getY()-a.getY())*(c.getX()-b.getX()))-((b.getX()-a.getX())*(c.getY()-b.getY()));
  if(cross_product==0)
      return 0;
  else if(cross_product>0)
      return 1;
  else
      return -1;
}

/**
 * @brief Swap the values of two points
 * 
 * @param a Point
 * @param b Point
 */
void Util::swapPoints(Point &a, Point &b)
{
  Point temp;
  temp = a;
  a = b;
  b = temp;
}

/**
 * @brief Helper function that prints out the values of all the points in a vector of Points
 * 
 * @param points 
 */
void Util::printAllPoints(vector<Point> points)
{
  for(int i =0;i<points.size();i++)
  {
    points[i].printPoint();
  }
  cout << endl;
}

/**
 * @brief Reads input of co-ordinates from a file and stores them in a vector
 * 
 * @param input_path Location of the input file
 * @return vector<Point> vector in which the input is stored
 */
vector<Point> Util::getInput(string input_path)
{
  ifstream input(input_path);
  double x, y;
  char comma;
  vector<Point> points;
  while (input >> x >> comma >> y)
  {
      points.push_back(Point(x,y));
  }
  return points;
}

// int compare(const void *vp1, const void *vp2)
// {
//   Util u;
//   Point *p1 = (Point *)vp1;
//   Point *p2 = (Point *)vp2;
//
//   int o = u.findOrientation(p0, *p1, *p2);
//   if (o == 0)
//   	return (u.findEuclideanDistance(p0, *p2) >= u.findEuclideanDistance(p0, *p1))? -1 : 1;
//
//   return (o == -1)? -1: 1;
// }
//
//
//
// void Util::sortPolar(vector<Point> points)
// {
//   // p0.printPoint();
//   // cout << endl;
//   int n = points.size();
//
//   qsort(&points[1], n-1, sizeof(Point), compare);
// }
