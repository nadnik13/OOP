#ifndef Octergon_H
#define Octergon_H

#include "IPolygon.h"
#include <iostream>

class Octergon : public Polygon
{
  public:
	Octergon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, int x7, int y7, int x8, int y8);
	Octergon(std::istream &is);
	Octergon(const Octergon &original);
	virtual ~Octergon();
	void Print();
	double Square();
	bool operator==(const Octergon &other);
	Octergon &operator=(const Octergon &other);

  private:
	int a_x;
	int a_y;
	int b_x;
	int b_y;
	int c_x;
	int c_y;
	int d_x;
	int d_y;
	int e_x;
	int e_y;
	int f_x;
	int f_y;
	int g_x;
	int g_y;
	int h_x;
	int h_y;
};
#endif //Octergon_H