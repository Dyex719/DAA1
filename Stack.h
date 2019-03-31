/**
 * @file Stack.h
 * @author your name (you@domain.com)
 * @brief Header file for Stack Class
 * @version 0.1
 * @date 2019-03-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef Stack_H
#define Stack_H
#include<vector>
using namespace std;
#include "Point.h"

class Stack
{
  public:
    void Push(Point p);
    Point Pop();
    Point Top();
    int getLength();
    bool isEmpty();
    Point getSecond();
  private:
    int length = 0;
    vector<Point> v;
};

#endif
