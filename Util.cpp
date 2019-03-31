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
  // cout << endl;
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
bool leftl(Point p1, Point p2)
{
    return (p1.getX() < p2.getX() || (p1.getX() == p2.getX() && p1.getY() < p2.getY()));
}

bool rightl(Point p1, Point p2)
{
    return (p1.getX() > p2.getX() || (p1.getX() == p2.getX() && p1.getY() < p2.getY()));
}

Point Util::leftmostPointl(vector<Point> points)
{
    sort(points.begin(), points.end(), leftl);
    return points[0];
}


Point rightmostPointlUtil(vector<Point> points)
{
    sort(points.begin(), points.end(), rightl);
    return points[0];
}
Point leftmostPointlUtil(vector<Point> points)
{
    sort(points.begin(), points.end(), leftl);
    return points[0];
}


Point Util::rightmostPointl(vector<Point> points)
{
    sort(points.begin(), points.end(), rightl);
    return points[0];
}

int partitiond(vector<double> &points,int l,int r,double x)
{
    int i;
    for (i=l; i<r; i++)
        if (points[i] == x)
           break;
    swapd(&points[i],&points[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (points[j] <= x)
        {
            swapd(&points[j], &points[i]);
            i++;
        }
    }
    swapd(&points[i], &points[r]);
    return i;
}

pair<Point,Point> lowerBridge(vector<Point> S,int num_points,Point L)
{
	if(S.size()==2)
  {
    if(S[0].getX() <= S[1].getX())
		return make_pair(S[0],S[1]);
    else
    return make_pair(S[1],S[0]);
  }
  vector<Point> candidates;
  vector<pair<Point,Point>> pairs;

  random_shuffle(S.begin(), S.end());
	
	// for(int i =0;i< S.size();i++)
	// S[i].printPoint();

  if(num_points%2==1)
  {
	{
		candidates.push_back(S[num_points-1]);
	}
  
  for(int i=0;i<num_points-1;i=i+2)
	{
    if(S[i].getX() <= S[i+1].getX())
		pairs.push_back(make_pair(S[i],S[i+1]));
    else
    pairs.push_back(make_pair(S[i+1],S[i]));
	}
  }
  else
  {
    
	  for(int i=0;i<num_points;i=i+2)
	{
		if(S[i].getX() <= S[i+1].getX())
		pairs.push_back(make_pair(S[i],S[i+1]));
    else
    pairs.push_back(make_pair(S[i+1],S[i]));
	}
  }

	//map<pair<Point, Point>, double> K;
  vector<double> kmom; //Simplifies implementation of medianofmedians
	for(int i=0;i<pairs.size();i++)
	{	
		
		if(pairs[i].first.getX()==pairs[i].second.getX())  //Slope is 0
		{
			if(pairs[i].first.getY()<pairs[i].second.getY())
				candidates.push_back(pairs[i].first);
			else
				candidates.push_back(pairs[i].second);
			//K.push_back(make_pair(0, make_pair(pairs[i].first, pairs[i].second)));
      //K.insert(make_pair(make_pair(pairs[i].first,pairs[i].second), 0));
      kmom.push_back(0);
		}
		else
		{
      double slope = (pairs[i].first.getY()-pairs[i].second.getY())/(pairs[i].first.getX()-pairs[i].second.getX());
			//K.insert(make_pair(make_pair(pairs[i].first,pairs[i].second), slope));
      kmom.push_back(slope);
			//cout<<K[i]<<endl;
		}
	}

  vector<double> kmomc;
  kmomc = kmom;
	//  for(int i =0;i< kmom.size();i++)
	//  {
	// 	//  cout << kmom[i] << endl;
	// 	//  pairs[i].first.printPoint();
	// 	// pairs[i].second.printPoint();
		
	//  }
 // need to define another medianofmedians for the double values called momd(below). Should be a copy/paste
  double k = momd(kmomc,0,kmom.size()-1,kmom.size()/2); 
  vector<pair<Point,Point>> SMALL;
  vector<pair<Point,Point>> EQUAL;
  vector<pair<Point,Point>> LARGE;
// cout<<"mean slope ="<<k<<endl;
  for(int i=0;i<pairs.size();i++)
  { 
    // cout <<i<< "  "<<kmom[i]<<endl;
    if(k < kmom[i])
    {
      //  cout<<i<<" LSARGE "<<k<<" "<<kmom[i]<<endl;
    LARGE.push_back(make_pair(pairs[i].first,pairs[i].second));
    }
    else if(k == kmom[i])
    {
      // cout<<i<<" equal "<<k<<" "<<kmom[i]<<endl;
    EQUAL.push_back(make_pair(pairs[i].first,pairs[i].second));
    
    }
    else
    {
      // cout<<i<<" small "<<k<<" "<<kmom[i]<<endl;
    SMALL.push_back(make_pair(pairs[i].first,pairs[i].second));
    }
  }

  int min = 10000;
  vector<Point> MIN;
  int y_intersection[num_points];
  for(int i=0;i<num_points;i++)
  {
    y_intersection[i] = S[i].getY() - k*S[i].getX();
    if(y_intersection[i] < min)
    {
      min = y_intersection[i];

    }
  }
  // cout<<"min::"<<min<<endl;

  for(int i=0;i<num_points;i++)
  {
    if(y_intersection[i] == min)
    MIN.push_back(S[i]);
  }
  // cout<<"max size"<<MIN.size()<<endl;
  // for(int i=0;i<MIN.size();i++)
  // {cout<<i<<"max";
  //   MIN[i].printPoint();
  // }
  Point pk = leftmostPointlUtil(MIN);
  Point pm = rightmostPointlUtil(MIN);
  // pk.printPoint();
  // pm.printPoint();
  if(pk.getX() <= L.getX() && pm.getX() > L.getX())
  {
  // cout<<"pk is :";
  // pk.printPoint();
  // cout<<"pm is :";
  // pm.printPoint();
  // cout<<endl;
  return make_pair(pk,pm);

  }
 if(pm.getX() <= L.getX())
  {
    for(int i=0;i<LARGE.size();i++)
    {
        candidates.push_back(LARGE[i].first);
        candidates.push_back(LARGE[i].second);
    }
    

    for(int i=0;i<EQUAL.size();i++)
    candidates.push_back(EQUAL[i].second);

    for(int i=0;i<SMALL.size();i++)
    {
     
      candidates.push_back(SMALL[i].second);
    }

  }

  if(pk.getX() > L.getX())
  {
    for(int i=0;i<LARGE.size();i++)
    {
      candidates.push_back(LARGE[i].first);
      
    }
    for(int i=0;i<EQUAL.size();i++)
    candidates.push_back(EQUAL[i].first);

    for(int i=0;i<SMALL.size();i++)
    {
      candidates.push_back(SMALL[i].first);
      candidates.push_back(SMALL[i].second);
    }

  }

  // cout << "Hello\n"<<candidates.size();
  // for(int i =0;i< candidates.size();i++)
	// candidates[i].printPoint();
  //sort(candidates.begin(),candidates.end(),leftpu);
  return lowerBridge(candidates,candidates.size(),L);

}

void swapd(double* a,double* b){
	double t;
	t = *a;
	*a=*b;
	*b=t; 
  }
  void swap(Point* a,Point* b){
	Point t;
	t = *a;
	*a=*b;
	*b=t;
  }
  int partition(vector<Point> &points,int l,int r,Point x)
{
    int i;
    for (i=l; i<r; i++)
        if (points[i].getX() == x.getX() && points[i].getY() == x.getY())
           break;
    swap(&points[i],&points[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (points[j].getX() <= x.getX())
        {
            swap(&points[j], &points[i]);
            i++;
        }
    }
    swap(&points[i], &points[r]);
    return i;
}

vector<Point> Util::Lowerhull(Point pmin,Point pmax,vector<Point> points)
{   
    if(pmin.getX() == pmax.getX() && pmax.getX() == pmax.getY())
    {
      vector<Point> res;
      res.push_back(pmin);
      return res;
    }
    int num_points = points.size();
    Point a = mom(points,0,num_points-1,num_points/2);

    vector<Point> TL,TR;
    for(int i=0;i<num_points;i++)
  	{
  		if(points[i].getX()<a.getX())
  		{
  			TL.push_back(points[i]);
  		}
  		else if(points[i].getX()>=a.getX())
  		{
  			TR.push_back(points[i]);
  		}
  	}

    pair<Point,Point> lb = lowerBridge(points,num_points,a);
    Point pl,pr;
    pl = lb.first;
    pr = lb.second;
    // pl.printPoint();
    // pr.printPoint();
    vector<Point> Tl,Tr;
	Tl.push_back(pl);
	Tr.push_back(pr);

    //Need to add points to Tl and Tr as given in slides. Please Check This (copied from gfg). Do we need to add points on that line?
	if(pl.getX() != pmin.getX() && pl.getY() != pmin.getY())
  {
  for(int i=0;i<TL.size();i++)
	{
		if(TL[i].getX() != pl.getX() || TL[i].getY() != pl.getY()) //since pl is already added
	    {
			if(directionOfPoint(pmin,pl,TL[i]) == -1)
			Tl.push_back(TL[i]);
		}
	}
  }
	
	for(int i=0;i<TR.size();i++)
	{
		if(TR[i].getX() != pr.getX() || TR[i].getY() != pr.getY()) //since pr is already added
		{
			if(directionOfPoint(pmax,pr,TR[i]) == 1)
			Tr.push_back(TR[i]);
		}
	}
  // cout << "Tl" << endl;
  // for(int i=0;i<Tl.size();i++)
    // Tl[i].printPoint();

  // cout << "Tr" << endl;
  // for(int i=0;i<Tr.size();i++)
    // Tr[i].printPoint();

  // cout << "End of Tr" << endl;

	
    vector<Point> Lh1,Lh2;

    vector<Point> ansHull;

    if(Tl.size() >= 2)
    Lh1 = Lowerhull(pmin,pl,Tl);

    if(Tr.size() >= 2)
    Lh2 = Lowerhull(pr,pmax,Tr);

    ansHull.push_back(pmin);
    for(int i=0;i<Lh1.size();i++)
    ansHull.push_back(Lh1[i]);

    ansHull.push_back(pl);
    ansHull.push_back(pr);

    for(int i=0;i<Lh2.size();i++)
    ansHull.push_back(Lh2[i]);

    ansHull.push_back(pmax);
     //Concatenating the two vectors

    return ansHull;



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
