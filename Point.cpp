// #include <iostream>
#include "Point.h"
// #include <utility>
#include<bits/stdc++.h>
using namespace std;


Point::Point()
{
	this->x=0;
	this->y=0;
	this->p = make_pair(0,0);
}

Point::Point(double x,double y)
{
	this->x=x;
	this->y=y;
  this->p = make_pair(x,y);
}

void Point::setXY(double x,double y)
{
	this->p = make_pair(x,y);
	// return p;

}

double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}

void Point::printPoint()
{
	cout<<this->p.first<<" "<<this->p.second<<"\n";
}
