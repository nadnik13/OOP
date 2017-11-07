
#include "TreeItem.h"
#include "IPolygon.h"
#include "TIterator.h"

template <class T> class Tree {
public:
	Tree();
    Tree(std::shared_ptr<TreeItem<T>> tr);
    Tree(const Tree<T>& orig);

    void PushRoot(std::shared_ptr<T> elem) ;
    void Push(std::shared_ptr<T> from, std::shared_ptr<T> elem);
    void Print() ;
    template <class A> friend std::ostream& operator<<(std::ostream& os,const Tree<A>& tree);
	bool Empty();
    void PrintTree(std::shared_ptr<TreeItem<T>> cur, size_t buf);
    void Delete(std::shared_ptr<T> elem);
	void Destroy();

    TIterator<TreeItem<T>,T> begin();
    TIterator<TreeItem<T>,T> end();

	virtual ~Tree();
	
private:
    std::shared_ptr<TreeItem<T>> Search(std::shared_ptr<T> poly, std::shared_ptr<TreeItem<T>> currentElem);
    std::shared_ptr<TreeItem<T>> root;
};
