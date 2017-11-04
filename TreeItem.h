#ifndef TREE_ITEM_H
#define TREE_ITEM_H

#include "IPolygon.h"
#include <memory>


class TreeItem {
public:
	TreeItem(const std::shared_ptr<Polygon>& figure);
	TreeItem(std::shared_ptr<TreeItem> par, const std::shared_ptr<Polygon>& figure);
    TreeItem(const TreeItem& original) ;
    virtual ~TreeItem() ;
    
    friend std::ostream& operator<<(std::ostream& os, const TreeItem& obj) ;

    std::shared_ptr<TreeItem> SetBrother(std::shared_ptr<TreeItem> bro) ;
    std::shared_ptr<TreeItem> GetBrother() ;
    std::shared_ptr<TreeItem> SetParent(std::shared_ptr<TreeItem> par) ;
    std::shared_ptr<TreeItem> GetParent();

    std::shared_ptr<TreeItem> SetSon(std::shared_ptr<TreeItem> son) ;
    std::shared_ptr<TreeItem> GetSon() ;

    std::shared_ptr<IFigure> GetFigure()const ;
    std::shared_ptr<Polygon> figure;
private:

    std::shared_ptr<TreeItem> son;
    std::shared_ptr<TreeItem> brother;  
    std::shared_ptr<TreeItem> parent;
    
};

#endif //TREE_ITEM_H
