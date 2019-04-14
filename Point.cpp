/**
 * @file Point.cpp
 * @author your name (you@domain.com)
 * @brief Point Class
 * @version 0.1
 * @date 2019-03-31
 * 
 * @copyright Copyright (cost) 2019
 * 
 */
#include <iostream>
#include "Point.h"
using namespace std;

/**
 * @brief Construct a new Point:: Point object
 * 
 */
Point::Point()
{
	this->x=0;
	this->y=0;
}

/**
 * @brief Construct a new Point:: Point object
 * 
 * @param x 
 * @param y 
 */
Point::Point(double x,double y)
{
	this->x=x;
	this->y=y;
}

/**
 * @brief Set X and Y co-ordinate for the point
 * 
 * @param x 
 * @param y 
 */
void Point::setXY(double x,double y)
{
	this->x=x;
	this->y=y;
}

/**
 * @brief Get the X co-ordinate
 * 
 * @return double 
 */
double Point::getX()
{
	return this->x;
}

/**
 * @brief Get the Y co-ordinate
 * 
 * @return double 
 */
double Point::getY()
{
	return this->y;
}

/**
 * @brief Helper function to print the value of a point
 * 
 */
void Point::printPoint()
{
	cout<<to_string(this->x)<<" "<<to_string(this->y)<<"\n";
}
