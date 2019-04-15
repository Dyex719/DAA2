/**
 * @file Util.cpp
 * @author your name (you@domain.com)
 * @brief Util Class which contains all the helper functions used in the convex hull algorithms.
 * @version 0.1
 * @date 2019-03-31
 * 
 * @copyright Copyright (cost) 2019
 * 
 */
#include "Util.h"
#include <math.h>
#include <algorithm>
#include <vector>
#define INF numeric_limits<double>::infinity()
using namespace std;

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

/**
 * @brief Comparator function that compares points by their X co-ordinate
 * 
 * @param p1 
 * @param p2 
 * @return true 
 * @return false 
 */
bool comparator(Point p1, Point p2)
{
    return (p1.getX() < p2.getX() || (p1.getX() == p2.getX() && p1.getY() < p2.getY()));
}

/**
 * @brief Function that sorts points by the increasing X co-ordinate
 * 
 * @param points 
 * @return vector<Point> 
 */
vector<Point> Util::sortByX(vector<Point> points)
{
    sort(points.begin(), points.end(), comparator);
    return points;
}

/**
 * @brief Function that calculates the error matrix used to segment the lines
 * 
 * @param points 
 * @param sum_xx 
 * @param sum_xy 
 * @param sum_y 
 * @param sum_x 
 * @param error 
 * @param a 
 * @param b 
 */
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

/**
 * @brief debugging function to print the values inside a matrix
 * 
 * @param matrix 
 * @param size 
 */
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

/**
 * @brief Helper function to find the values used in error calculation beforehand to speed up calculation
 * 
 * @param points 
 * @param sum_xx 
 * @param sum_xy 
 * @param sum_y 
 * @param sum_x 
 */
void Util::precalculation(vector<Point> points,vector<double> &sum_xx,vector<double> &sum_xy,vector<double> &sum_y,vector<double> &sum_x)
{
  for(int i =0;i<points.size();i++)
  {
      sum_xx[i] = sum_xx[i-1] + points[i].getX()*points[i].getX();
      sum_xy[i] = sum_xy[i-1] + points[i].getX()*points[i].getY();
      sum_x[i] = sum_x[i-1] + points[i].getX();
      sum_y[i] = sum_y[i-1] + points[i].getY();
  }
}

/**
 * @brief Function that finds the line segments by backtracking through the error function
 * 
 * @param cost 
 * @param size 
 * @param error 
 * @param res 
 * @param segments 
 */
void Util::backtrack(int cost,int size,vector<vector<double>> &error,vector<double> &res,vector<double> &segments)
{
      for(int j =1;j<=size;j++)
    {
        double temp = INF;
        int index;
        for(int i=1;i<=j;i++)
        {
            if(temp > error[i][j] + cost + res[i-1])
            {
                temp = error[i][j] + cost + res[i-1];
                index = i;
            }
        }
        res[j] = temp;
        segments[j] = index;
    }
}

/**
 * @brief Function that prints the line segments to a file from where it can be used for visualisation
 * 
 * @param points 
 * @param segments 
 * @param a 
 * @param b 
 */
void Util::printToFile(vector<Point> points, vector<double> &segments, vector<vector<double>> &a,vector<vector<double>> &b)
{

    int size = points.size();
    int i =size;
    int j = segments[size];

    ofstream myfile;
    myfile.open("./outputs/2.txt");
    while(i>0)
    {
        myfile << points[j-1].getX() << " " << points[j-1].getX()*a[j-1][i-1]+b[j-1][i-1] << " " << points[i-1].getX() << " " << points[i-1].getX()*a[j-1][i-1]+b[j-1][i-1] << endl;
        // cout << i << " " << j << " ";
        // cout << a[j-1][i-1] << " " << b[j-1][i-1] << endl;
        cout << points[j-1].getX() << " " << points[j-1].getX()*a[j-1][i-1]+b[j-1][i-1] << " " << points[i-1].getX() << " " << points[i-1].getX()*a[j-1][i-1]+b[j-1][i-1]<< endl;
        cout << points[j-1].getY() << " " << points[j-1].getY()*a[j-1][i-1]+b[j-1][i-1] << " " << points[i-1].getY() << " " << points[i-1].getY()*a[j-1][i-1]+b[j-1][i-1]<< endl;


        i = j-1;
        j = segments[i];
    }
    myfile.close();
}








