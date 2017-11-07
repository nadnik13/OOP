#include "Tree.h"
#include <iostream>
#include <memory>
#include <queue>
#include "TIterator.h"

template <class T> Tree<T>::Tree()
{
    root = nullptr;
};

template <class T> Tree<T>::Tree(std::shared_ptr<TreeItem<T>> tr)
{
    root = tr;
}
template <class T> Tree<T>::Tree(const Tree &orig)
{
    this->root = orig.root;
};

template <class T> void Tree<T>::PushRoot(std::shared_ptr<T> elem)
{
    std::shared_ptr<TreeItem<T>> newPtrElem(new TreeItem<T>(elem));
    root = newPtrElem;
}

template <class T> void Tree<T>::Push(std::shared_ptr<T> from, std::shared_ptr<T> elem)
{
    std::shared_ptr<TreeItem<T>> fr = Search(from, root);
    if (fr != nullptr)
    {
        if (fr->GetSon())
        {
            fr = fr->GetSon();
            while (fr->GetBrother())
            {
                fr = fr->GetBrother();
            }
            std::shared_ptr<TreeItem<T>> newPtrElem(new TreeItem<T>(fr, elem));
            fr->SetBrother(newPtrElem);
            return;
        }
        else
        {
            std::shared_ptr<TreeItem<T>> newPtrElem(new TreeItem<T>(fr, elem));
            fr->SetSon(newPtrElem);
            return;
        }
    }
    else
    {
        std::cout << "Not Found" << std::endl;
        return;
    }
};

template <class T> bool Tree<T>::Empty(){
    bool check = false;
    if (root == nullptr) check=true;
    if (check) std::cout<<"Tree is empty"<<std::endl;
    return check;
}

template <class T>void Tree<T>::Print()
{

    size_t b = 0;
    Empty();
    PrintTree(root, b);
}

template <class T> void Tree<T>::PrintTree(std::shared_ptr<TreeItem<T>> cur , size_t buf)
{
    if (cur != nullptr)
    {
        for (size_t i = 0; i < buf; i++)
        {
            std::cout << "    ";
        }
        std::cout << *cur << std::endl;

       PrintTree(cur->GetSon(), buf + 2);
       PrintTree(cur->GetBrother(), buf);
    }
}

template <class T> void Tree<T>::Delete(std::shared_ptr<T> elem)
{
    std::shared_ptr<TreeItem<T>> fr = Search(elem, root);
    if (fr->GetParent()->GetSon() == fr)
    {
        fr->GetParent()->SetSon(nullptr);
    }
    else
    {
        fr->GetParent()->SetBrother(nullptr);
    }
    fr->SetBrother(nullptr);
    fr->SetSon(nullptr);
}

template <class T> std::shared_ptr<TreeItem<T>> Tree<T>::Search(std::shared_ptr<T> poly, std::shared_ptr<TreeItem<T>> currentElem)
{
    if (currentElem == nullptr)
    {
        return nullptr;
    }
    if (*(currentElem->figure) == *(poly))
    {
        return currentElem;
    }
    else
    {
        std::shared_ptr<TreeItem<T>> find = nullptr;
        find = Search(poly, currentElem->GetSon());
        if (find == nullptr)
            find = Search(poly, currentElem->GetBrother());
        return find;
    }
}

template <class T> void Tree<T>::Destroy(){
    root=nullptr;
    std::cout<<"i am die 0_0"<<std::endl;

}

template <class A> std::ostream& operator<<(std::ostream& os, const Tree<A>& tree){
    std::shared_ptr<Tree<A>> tr;
    tr->PrintTree(tree.root,0);
    return os;
}

template <class T> TIterator<TreeItem<T>,T> Tree<T>::begin(){
    return TIterator<TreeItem<T>,T>(root);
}

template <class T> TIterator<TreeItem<T>,T> Tree<T>::end(){
    return TIterator<TreeItem<T>,T>(nullptr);
}
template <class T> Tree<T>::~Tree(){
    std::cout<<"i am die";
}

#include "IPolygon.h"
template class Tree<Polygon>;
template std::ostream& operator<<(std::ostream& os, const Tree<Polygon>& tree);
