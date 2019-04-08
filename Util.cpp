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
#define INF numeric_limits<double>::infinity()
using namespace std;
Point p0;

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

void Util::leastSquareError(vector<Point> points,vector<double> sum_xx,vector<double> sum_xy,vector<double> sum_y,vector<double> sum_x,vector<vector<double>> &error,vector<vector<double>> &a,vector<vector<double>> &b)
{
    int size = points.size();

    for(int j = 0;j<size;j++ )
    {
        for(int i=0;i<=j;i++)
        {
          int interval = j - i + 1;
          double x = sum_x[j] - sum_x[i-1];
          double y = sum_y[j] - sum_y[i-1];
          double xy = sum_xy[j] - sum_xy[i-1];
          double xx = sum_xx[j] - sum_xx[i-1];
          
          double num = interval * xy - x * y;
          double den = interval * xx - x * x;

          if(num==0) a[i][j] = 0; 
          else
          {
            if (den==0) den = INF;
            else  a[i][j] = num/double(den);
          }

          b[i][j] = (y - a[i][j] * x) / double(interval);
          // cout << a[i][j] << b[i][j] <<endl;

          for (int k = i;k <= j; k++)	{
              double tmp = points[k].getY() - a[i][j] * points[k].getX() - b[i][j];
              // cout << i << " " << j << " " << tmp << endl;
              error[i+1][j+1] += tmp * tmp;
            }
        }
    }

}

void Util::printMatrix(vector<vector<double>> &matrix,int size)
{
  for(int i = 0;i<size;i++ )
  {
    for(int j =0;j<size;j++)
    {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}






