#include<bits/stdc++.h>
#include "Util.h"
#include "Hull.h"
using namespace std;
Point p0;

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

double Util::findEuclideanDistance(Point a,Point b)
{
  double distance = sqrt(pow(a.getY()-b.getY(),2)+pow(a.getX()-b.getX(),2));
  return distance;
}

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

void Util::swapPoints(Point &a, Point &b)
{
  Point temp;
  temp = a;
  a = b;
  b = temp;
}

void Util::printAllPoints(vector<Point> points)
{
  for(int i =0;i<points.size();i++)
  {
    points[i].printPoint();
  }
  cout << endl;
}

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
