/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief This is the base file from which the algorithm is called
 * @version 0.1
 * @date 2019-03-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Point.h"
#include "Util.h"
#include "Algo.h"
#include <chrono> 
using namespace std::chrono; 
using namespace std;
Algo a;
Util f;

int main(void)
{
  string input_path = "./inputs/2.txt";
  vector<Point> points = f.getInput(input_path);
  auto start = high_resolution_clock::now(); 
  a.segmentedLeastSquares(points);
  auto stop = high_resolution_clock::now(); 
  auto duration = duration_cast<microseconds>(stop - start); 
  cout << "The time taken to run the segmented least squares algorithm is " << duration.count() << " microseconds" <<  endl; 

}
