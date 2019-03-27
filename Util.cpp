#include<bits/stdc++.h>
#include "Util.h"
using namespace std;

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

//Change & split the files
// int Util::compare(const void *vp1, const void *vp2)
// {
//    Point *p1 = (Point *)vp1;
//    Point *p2 = (Point *)vp2;
//
//    // Find orientation
//    int o = getOrientation(this->p0, *p1, *p2);
//    if (o == 0)
//      return (getEuclideanDistance(this->p0, *p2) >= getEuclideanDistance(this->p0, *p1))? -1 : 1;
//
//    return (o == -1)? -1: 1;
// }
//
// vector<Point> Util::sortPolar(vector<Point> points)
// {
//   sort(points.begin(), points.end(), compare);
//   return points;
// }
