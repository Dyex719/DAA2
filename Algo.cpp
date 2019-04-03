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
    double error[size][size] = {0};

    for(int i = 0;i<size;i++ )
    {
        for(int j =i+1;j<size;j++)
        {
            error[i][j] = u.leastSquareError(points,i,j);
        }
    }

    for(int i = 0;i<size;i++ )
    {
        for(int j =0;j<size;j++)
        {
            cout << error[i][j] << " ";
        }
        cout << endl;
    }



}
