/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief This is the base file from which all the functions are called
 * @version 0.1
 * @date 2019-03-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Point.h"
#include "Util.h"
#include "Stack.h"
#include "Hull.h"
using namespace std;
Hull h;
Util f;

int main(void)
{
  string input_path = "./inputs/2.txt";
  vector<Point> points = f.getInput(input_path);
  h.JM(points);
  h.GS(points);
}
