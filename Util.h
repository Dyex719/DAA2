/**
 * @file Util.h
 * @author your name (you@domain.com)
 * @brief Header file for Util Class
 * @version 0.1
 * @date 2019-03-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef Util_H
#define Util_H
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include "Point.h"
using namespace std;

class Util
{
  public:
    double findEuclideanDistance(Point a,Point b);
    vector<Point> getInput(string input_path);
    vector<Point> sortByX(vector<Point> points);
    void printAllPoints(vector<Point> points);
    void leastSquareError(vector<Point> points,vector<double> sum_xx,vector<double> sum_xy,vector<double> sum_y,vector<double> sum_x,vector<vector<double>> &error);


};

#endif
