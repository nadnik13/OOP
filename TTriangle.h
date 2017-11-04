#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "IPolygon.h"
#include <iostream>


class Triangle : public Polygon {
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    Triangle(std::istream &is);
    Triangle(const Triangle &original);

    virtual ~Triangle() override ;

    void Print();

    double Square() override;

    bool operator==(const Triangle& other);

	Triangle& operator=(const Triangle& other);

private:
	int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;	

};
#endif //TRIANGLE_H