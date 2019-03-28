#include<bits/stdc++.h>
#include "Util.h"
#include "Graham.h"
using namespace std;
Point p0;

int Util::getLeft(vector<Point> points)
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

double Util::getEuclideanDistance(Point a,Point b)
{
  double distance = sqrt(pow(a.getY()-b.getY(),2)+pow(a.getX()-b.getX(),2));
  return distance;
}

int Util::getOrientation(Point a,Point b,Point c)
{
  double cross_product = (b.getY()-a.getY())*(c.getX()-b.getX())-(b.getX()-a.getX())*(c.getY()-b.getY());
  if(cross_product==0)
      return 0;
  else if(cross_product>0)
      return 1;
  else
      return -1;
}
int comparepolar(Point p1, Point p2)
{

// Find orientation
Util helper;
int o = helper.getOrientation(p0, p1, p2);
if (o == 0)
	return (helper.getEuclideanDistance(p0, p2) >= helper.getEuclideanDistance(p0, p1))? -1 : 1;

return (o == 2)? -1: 1;
}

// void Util::swapPoints(Point &a, Point &b)
// {
//   Point temp;
//   temp = Point a;
//   Point a = Point b;
//   Point b = temp;
// }

vector<Point> Util::sortPolar(vector<Point> points)
{
  sort(points.begin(), points.end(), comparepolar);
  return points;
}
