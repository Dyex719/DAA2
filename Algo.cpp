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

    vector<double> sum_xx(size,0.0);
    vector<double> sum_xy(size,0.0);
    vector<double> sum_x(size,0.0);
    vector<double> sum_y(size,0.0);

    for(int i =0;i<points.size();i++)
    {
        sum_xx[i] = sum_xx[i-1] + points[i].getX()*points[i].getX();
        sum_xy[i] = sum_xy[i-1] + points[i].getX()*points[i].getY();
        sum_x[i] = sum_x[i-1] + points[i].getX();
        sum_y[i] = sum_y[i-1] + points[i].getY();
    }

    u.leastSquareError(points,sum_xx,sum_xy,sum_y,sum_x,error);


    for(int i = 0;i<size;i++ )
    {
        for(int j =0;j<size;j++)
        {
            cout << error[i][j] << " ";
        }
        cout << endl;
    }

    // double opt[100];
    // opt[0] = 0;

        




}
