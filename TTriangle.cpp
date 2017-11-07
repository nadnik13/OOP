#include "TTriangle.h"
#include <iostream>

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    pointsCount = 6;
    coordinates.resize(pointsCount);
    coordinates[0] = x1;
    coordinates[1] = y1;
    coordinates[2] = x2;
    coordinates[3] = y2;
    coordinates[4] = x3;
    coordinates[5] = y3;
};
Triangle::Triangle(std::istream &is)
{
    pointsCount = 6;
    coordinates.resize(pointsCount);
    for (int i = 0; i < 6; i++)
    {
        is >> coordinates[i];
    }
};
Triangle::Triangle(const Triangle &original)
{
    this->coordinates = original.coordinates;
};

Triangle::~Triangle()
{
    std::cout << "Triangle deleted" << std::endl;
};

void Triangle::Print()
{
    for (int i = 0; i < 6; i++)
    {
        std::cout << this->coordinates[i] << " ";
    }
    std::cout << std::endl;
};

double Triangle::Square(){
    std::cout << "Triangle square" << std::endl;
    double p = x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3;
    p= abs(p)/2;
    return p;
};

bool Triangle::operator==(const Triangle &other)
{
    bool ans = true;
    for (int i = 0; i < 6; i++)
    {
        if (this->coordinates[i] != other.coordinates[i])
        {
            ans = false;
            break;
        }
    }
    return ans;
};

Triangle &Triangle::operator=(const Triangle &other)
{
    this->coordinates = other.coordinates;
    return *this;
}
