#include "TOctergon.h"
#include <iostream>

Octergon::Octergon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, int x7, int y7, int x8, int y8)
{
    pointsCount = 16;
    coordinates.resize(pointsCount);
    coordinates[0] = x1;
    coordinates[1] = y1;
    coordinates[2] = x2;
    coordinates[3] = y2;
    coordinates[4] = x3;
    coordinates[5] = y3;
    coordinates[6] = x4;
    coordinates[7] = y4;
    coordinates[8] = x5;
    coordinates[9] = y5;
    coordinates[10] = x6;
    coordinates[11] = y6;
    coordinates[12] = x7;
    coordinates[13] = y7;
    coordinates[14] = x8;
    coordinates[15] = y8;
};
Octergon::Octergon(std::istream &is)
{
    pointsCount = 6;
    coordinates.resize(pointsCount);
    for (int i = 0; i < 15; i++)
    {
        is >> coordinates[i];
    }
};
Octergon::Octergon(const Octergon &original)
{
    this->coordinates = original.coordinates;
};

Octergon::~Octergon()
{
    std::cout << "Octergon deleted" << std::endl;
};

void Octergon::Print()
{
    for (int i = 0; i < 15; i++)
    {
        std::cout << this->coordinates[i] << " ";
    }
    //std::cout << std::endl;
};

double Octergon::Square()
{
    double q = a_x * b_y + b_x * c_y + c_x * d_y + d_x * e_y + e_x * f_y + f_x * g_y + g_x * h_y + h_x * a_y - a_y * b_x - b_y * c_x - c_y * d_x - d_y * e_x - e_y * f_x - f_x * a_y - f_y * g_x - g_y * h_x + h_y * a_x;
    q = 1 / 2 * abs(q);
    return q;
}

bool Octergon::operator==(const Octergon &other)
{
    bool ans = true;
    for (int i = 0; i < 15; i++)
    {
        if (this->coordinates[i] != other.coordinates[i])
        {
            ans = false;
            break;
        }
    }
    return ans;
};

Octergon &Octergon::operator=(const Octergon &other)
{
    this->coordinates = other.coordinates;
    return *this;
}