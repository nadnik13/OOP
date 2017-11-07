#ifndef POLYGON_H
#define POLYGON_H

#include "IFigure.h"
#include <vector>

class Polygon : public IFigure {
public:
	virtual void Print() = 0;
	virtual double Square() = 0;
	virtual bool operator==(const Polygon& other);
protected:
	std::vector <int> coordinates;
	int pointsCount;
};

#endif //POLYGON_H