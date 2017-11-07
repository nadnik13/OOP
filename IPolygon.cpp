#include "IPolygon.h"
#include <vector>


bool Polygon::operator==(const Polygon &other)
{
    if (this->pointsCount != other.pointsCount)
        return false;
    bool ans = true;
    for (int i = 0; i < other.pointsCount; i++)
    {
        if (this->coordinates[i] != other.coordinates[i])
        {
            ans = false;
            break;
        }
    }
    return ans;
};
