/**
 * @file Hull.h
 * @author your name (you@domain.com)
 * @brief Header file for Hull.cpp
 * @version 0.1
 * @date 2019-03-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef HULL_H
#define HULL_H
#include "Point.h"
#include<vector>
using namespace std;

extern Point p0;
class Hull
{
	public:
		void JM(vector<Point> points);
		void GS(vector<Point> points);
};

#endif
