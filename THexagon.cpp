#include "THexagon.h"
#include <iostream>


Hexagon::Hexagon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6) {
    	pointsCount = 12;
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

    };
    Hexagon::Hexagon(std::istream &is) {
    	pointsCount = 6;
    	coordinates.resize(pointsCount);
    	for(int i = 0; i < 12; i++) {
    		is >> coordinates[i];
    	}
    };
    Hexagon::Hexagon(const Hexagon &original) {
    	this->coordinates = original.coordinates;
    };

     Hexagon::~Hexagon()  {
    	std::cout << "Hexagon deleted" << std::endl;
    };

    void Hexagon::Print()  {
    	for(int i = 0; i < 12; i++) {
    		std::cout << this->coordinates[i] << " ";
    	}
    	//std::cout << std::endl;
    };
    
    double Hexagon::Square()
    {
        double q = a_x * b_y + b_x * c_y + c_x * d_y + d_x * e_y + e_x * f_y + f_x * a_y - a_y * b_x - b_y * c_x - c_y * d_x - d_y * e_x - e_y * f_x - f_x * a_y;
        q = 1 / 2 * abs(q);
        return q;
    }

    bool Hexagon::operator==(const Hexagon& other){
    	bool ans = true;
    	for(int i = 0; i < 12; i++) {
    		if(this->coordinates[i] != other.coordinates[i]) {
    			ans = false;
    			break;
    		}
    	}
    	return ans;
    };

    Hexagon& Hexagon::operator=(const Hexagon& other) {
	this->coordinates = other.coordinates;
	return *this;
    }
