#include "TTriangle.h"
#include "THexagon.h"
#include "TOctergon.h"
#include "Tree.h"
#include "TreeItem.h"
#include "TIterator.h"
#include <iostream>
#include <memory>

int main() {
	
    Tree<Polygon> tree;
	int n = 0;
	std::cin >> n;
	std::shared_ptr<Polygon> pt1(new Triangle(1, 1, 1, 1, 1, 1));
	std::shared_ptr<Polygon> pt2(new Triangle(2, 2, 2, 2, 2, 2));
	std::shared_ptr<Polygon> pt3(new Triangle(3, 3, 3, 3, 3, 3));
	std::shared_ptr<Polygon> pt4(new Triangle(4, 4, 4, 4, 4, 4));

	std::shared_ptr<Polygon> pt5(new Hexagon(3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3));
	std::shared_ptr<Polygon> pt6(new Hexagon(4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4));



    while(n != 9) {
		switch(n) {
			case 1:
				tree.PushRoot(std::shared_ptr<Polygon>(new Triangle(1, 1, 1, 1, 1, 1)));
				break;
			
			case 2:
				tree.Push(pt1, pt5);
				
				break;
			case 3:
                tree.Print();
				break;
			case 4:
				tree.Push(pt1, pt3);
				break;
			case 5:
				tree.Push(pt5, pt2);
				break;
			case 6:
				tree.Delete(pt2);
				break;
			case 7:
				tree.Destroy();
				break;
            case 8:{
                for (auto i: tree)
                {
                    i->Print();
                   std::cout<<std::endl;
                  }

                break;
                }
			default:
                std::cout << "Try again" << std::endl;

				break;
		}
		std::cin >> n;
	}
}
