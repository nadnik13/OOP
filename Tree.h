
#include "TreeItem.h"
#include "IPolygon.h"

class Tree {
public:
	Tree();
	Tree(std::shared_ptr<TreeItem> tr);
	Tree(const Tree& orig);

	void PushRoot(std::shared_ptr<Polygon> elem) ;
	void Push(std::shared_ptr<Polygon> from, std::shared_ptr<Polygon> elem);
	void Print() ;
	bool Empty();
	void PrintTree(std::shared_ptr<TreeItem> cur, size_t buf);
	void Delete(std::shared_ptr<Polygon> elem);
	void Destroy();
	virtual ~Tree();
	
private:
	std::shared_ptr<TreeItem> Search(std::shared_ptr<Polygon> poly, std::shared_ptr<TreeItem> currentElem);
	std::shared_ptr<TreeItem> root;
};
