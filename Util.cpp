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
#include <math.h>
#include<algorithm>
#include<vector>
using namespace std;
Point p0;

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
  cout << endl;
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

vector<Point> Util::sortByX(vector<Point> points)
{
    sort(points.begin(), points.end(), leftl);
    return points;
}

double Util::leastSquareError(vector<Point> points,int i,int j)
{
  int n = points.size();

  double num11 = 0;
  double num12 = 0;
  double num13 = 0;
  double den11 = 0;

  for(int k =i;k<j;k++)
  {
    num11 += points[k].getX()*points[k].getY();
    num12 += points[k].getX();
    num13 += points[k].getY();
    den11 += pow(points[k].getX(),2);
  }

  int a = (n*num11 - num12*num13) / (n*den11 - (pow(num12,2)));
  int b = (num13 - a*num12) / (n);

  double error = 0;
  for(int k =i;k<j;k++)
  {
    error += pow((points[k].getY() - (a*points[k].getX()) - b),2);
  }

  return error;
}

