#include "TreeItem.h"
#include <memory>
#include <iostream>

template <class T> TreeItem<T>::TreeItem(const std::shared_ptr<T> &figure)
{
    this->figure = figure;
    this->son = nullptr;
    this->brother = nullptr;
    this->parent = nullptr;
};
template <class T> TreeItem<T>::TreeItem(std::shared_ptr<TreeItem<T>> par, const std::shared_ptr<T> &figure)
{
    this->figure = figure;
    this->son = nullptr;
    this->brother = nullptr;
    this->parent = par;
};
template <class T> TreeItem<T>::TreeItem(const TreeItem<T> &original)
{
    this->figure = original.figure;
    this->son = original.son;
    this->brother = original.brother;
    this->parent = original.parent;
};
template <class T> TreeItem<T>::~TreeItem()
{
    std::cout << "Tree Item destructed" << std::endl;
};

template <class A> std::ostream &operator<<(std::ostream &os, const TreeItem<A>& obj)
{

    std::shared_ptr<A> ply = obj.figure;
    //os<<"asd";
    ply->Print();
    return os;
};

template <class T> std::shared_ptr<TreeItem<T>> TreeItem<T>::SetBrother(std::shared_ptr<TreeItem<T>> bro)
{
    std::shared_ptr<TreeItem<T>> old = this->brother;
    this->brother = bro;
    return old;
};
template <class T> std::shared_ptr<TreeItem<T>> TreeItem<T>::GetBrother()
{
    return this->brother;
};
template <class T> std::shared_ptr<TreeItem<T>> TreeItem<T>::SetParent(std::shared_ptr<TreeItem<T>> par)
{
    std::shared_ptr<TreeItem<T>> old = this->parent;
    this->parent = parent;
    return old;
};
template <class T> std::shared_ptr<TreeItem<T>> TreeItem<T>::GetParent()
{
    return this->parent;
};

template <class T> std::shared_ptr<TreeItem<T>> TreeItem<T>::SetSon(std::shared_ptr<TreeItem<T>> son)
{
    std::shared_ptr<TreeItem<T>> old = this->son;
    this->son = son;
    return old;
};
template <class T> std::shared_ptr<TreeItem<T>> TreeItem<T>::GetSon()
{
    return this->son;
};

template <class T> std::shared_ptr<TreeItem<T>> TreeItem<T>::GetNext()
{
    if (this->son != nullptr){
        return this->son;
    }
    return this->brother;
}

/*template <class T> std::shared_ptr<IFigure> TreeItem<T>::GetFigure() const
{
    return this->figure;
};
*/
template <class T> std::shared_ptr<T> TreeItem<T>::GetValue() const
{
    return this->figure;
};


#include "IPolygon.h"
template class TreeItem<Polygon>;
template std::ostream& operator<<(std::ostream &os, const TreeItem<Polygon>& obj);
