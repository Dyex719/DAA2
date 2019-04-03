/**
 * @brief Header file for Point Class
 * 
 */
#ifndef POINT_H
#define POINT_H
using namespace std;

class Point
{
	public:
		Point();
		Point(double x,double y);
		double getX();
		double getY();
		void setXY(double x,double y);
		void printPoint();
	private:
		double x;
		double y;
};

#endif
