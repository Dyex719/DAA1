#include "Point.h"
// #include <iostream>
#include "Util.h"
#include "Stack.h"
#include "Hull.h"
#include<bits/stdc++.h>

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
