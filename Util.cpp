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

int Util::getBottom(vector<Point> points)
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



double Util::getEuclideanDistance(Point a,Point b)
{
  double distance = sqrt(pow(a.getY()-b.getY(),2)+pow(a.getX()-b.getX(),2));
  return distance;
}

//sortpolar is wrong
int Util::getOrientation(Point a,Point b,Point c)
{
  int cross_product = ((b.getY()-a.getY())*(c.getX()-b.getX()))-((b.getX()-a.getX())*(c.getY()-b.getY()));
  // cout << cross_product << endl;
  if(cross_product==0)
      return 0;
  else if(cross_product>0)
      return 1;
  else
      return -1;
}

int comparepolar(Point p1, Point p2)
{
// p0.printPoint();
// cout << endl;
// Find orientation
Util helper;
int o = helper.getOrientation(p0, p1, p2);
// cout << o << endl;
if (o == 0){
 // p0.printPoint();
 // p1.printPoint();
 // p2.printPoint();
 // cout << helper.getEuclideanDistance(p0, p2);
 // cout << helper.getEuclideanDistance(p0, p1);
 // cout << endl;
	return (helper.getEuclideanDistance(p0, p2) >= helper.getEuclideanDistance(p0, p1))? -1 : 1;
}
return (o ==-1)? -1: 1;
}

void Util::swapPoints(Point &a, Point &b)
{
  Point temp;
  temp = a;
  a = b;
  b = temp;
}

vector<Point> Util::sortPolar(vector<Point> points)
{
  // p0.printPoint();
  // cout << endl;
  sort(points.begin(), points.end(), comparepolar);
  // printAllPoints(points);
  return points;
}

void Util::printAllPoints(vector<Point> points)
{
  for(int i =0;i<points.size();i++)
  {
    points[i].printPoint();
  }
  cout << endl;
}
