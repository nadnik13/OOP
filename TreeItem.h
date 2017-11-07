#ifndef TREE_ITEM_H
#define TREE_ITEM_H

#include "IPolygon.h"
#include"queue"
#include <memory>


template<class T> class TreeItem {
public:
    TreeItem(const std::shared_ptr<T>& figure);
    TreeItem(std::shared_ptr<TreeItem<T>> par, const std::shared_ptr<T>& figure);
    TreeItem(const TreeItem<T>& original) ;
    virtual ~TreeItem() ;
    
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TreeItem<A>& obj) ;

    std::shared_ptr<TreeItem<T>> SetBrother(std::shared_ptr<TreeItem<T>> bro) ;
    std::shared_ptr<TreeItem<T>> GetBrother() ;
    std::shared_ptr<TreeItem<T>> SetParent(std::shared_ptr<TreeItem<T>> par) ;
    std::shared_ptr<TreeItem<T>> GetParent();

    std::shared_ptr<TreeItem<T>> SetSon(std::shared_ptr<TreeItem<T>> son) ;
    std::shared_ptr<TreeItem<T>> GetSon() ;

    std::shared_ptr<TreeItem<T>> GetNext();

    //std::shared_ptr<IFigure> GetFigure()const ;
    std::shared_ptr<T> GetValue() const;

    std::shared_ptr<T> figure;
private:

    std::shared_ptr<TreeItem<T>> son;
    std::shared_ptr<TreeItem<T>> brother;
    std::shared_ptr<TreeItem<T>> parent;

    
};

#endif //TREE_ITEM_H
