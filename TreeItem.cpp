#include "TreeItem.h"
#include <memory>
#include <iostream>

TreeItem::TreeItem(const std::shared_ptr<Polygon> &figure)
{
    this->figure = figure;
    this->son = nullptr;
    this->brother = nullptr;
    this->parent = nullptr;
};
TreeItem::TreeItem(std::shared_ptr<TreeItem> par, const std::shared_ptr<Polygon> &figure)
{
    this->figure = figure;
    this->son = nullptr;
    this->brother = nullptr;
    this->parent = par;
};
TreeItem::TreeItem(const TreeItem &original)
{
    this->figure = original.figure;
    this->son = original.son;
    this->brother = original.brother;
    this->parent = original.parent;
};
TreeItem::~TreeItem()
{
    std::cout << "Tree Item destructed" << std::endl;
};

std::ostream &operator<<(std::ostream &os, const TreeItem &obj)
{
    std::shared_ptr<Polygon> ply = obj.figure;
    ply->Print();
    return os;
};

std::shared_ptr<TreeItem> TreeItem::SetBrother(std::shared_ptr<TreeItem> bro)
{
    std::shared_ptr<TreeItem> old = this->brother;
    this->brother = bro;
    return old;
};
std::shared_ptr<TreeItem> TreeItem::GetBrother()
{
    return this->brother;
};
std::shared_ptr<TreeItem> TreeItem::SetParent(std::shared_ptr<TreeItem> par)
{
    std::shared_ptr<TreeItem> old = this->parent;
    this->parent = parent;
    return old;
};
std::shared_ptr<TreeItem> TreeItem::GetParent()
{
    return this->parent;
};

std::shared_ptr<TreeItem> TreeItem::SetSon(std::shared_ptr<TreeItem> son)
{
    std::shared_ptr<TreeItem> old = this->son;
    this->son = son;
    return old;
};
std::shared_ptr<TreeItem> TreeItem::GetSon()
{
    return this->son;
};

std::shared_ptr<IFigure> TreeItem::GetFigure() const
{
    return this->figure;
};
