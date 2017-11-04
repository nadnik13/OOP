#ifndef Hexagon_H
#define Hexagon_H

#include "IPolygon.h"
#include <iostream>

class Hexagon : public Polygon
{
  public:
	Hexagon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6);
	Hexagon(std::istream &is);
	Hexagon(const Hexagon &original);

	virtual ~Hexagon() override;
	void Print() override;

	double Square() override;

	bool operator==(const Hexagon &other);

	Hexagon &operator=(const Hexagon &other);

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
};
#endif //Hexagon_H