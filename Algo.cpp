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
#include "Algo.h"
#include "Util.h"
#include <math.h>
#include<algorithm>
#include<vector>
using namespace std;
Util u;

void Algo::segmentedLeastSquares(vector<Point> points)
{
    points = u.sortByX(points);
    // u.printAllPoints(points);
    int size = points.size();
    vector<vector<double>> error(double(size+1),vector<double> (double(size+1), 0.0));
    vector<vector<double>> a(double(size+1),vector<double> (double(size+1), 0.0));
    vector<vector<double>> b(double(size+1),vector<double> (double(size+1), 0.0));
    vector<double> sum_xx(size,0.0);
    vector<double> sum_xy(size,0.0);
    vector<double> sum_x(size,0.0);
    vector<double> sum_y(size,0.0);
    vector<double> res(size+1,0.0);
    double c = 0;
    // printf("Enter the additional cost of creating a new segment : ");
	// scanf("%lf", &c);
    vector<double> segments(size+1,0.0);

    u.precalculation(points,sum_xx,sum_xy,sum_y,sum_x);
    u.leastSquareError(points,sum_xx,sum_xy,sum_y,sum_x,error,a,b);
    u.backtrack(c,size,error,res,segments);
    u.printToFile(points,segments,a,b);






    

    
}
