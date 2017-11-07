#ifndef TITERATOR_H
#define TITERATOR_H
#include<iostream>
#include<memory>
#include<queue>
#include "IFigure.h"

template <class node ,class T> class TIterator{
   public:
    TIterator(std::shared_ptr<node> n){
        node_ptr = n;
        //tQueue.push(n);
    }

    std::shared_ptr<T> operator * (){
        return node_ptr->GetValue();
    }

    void operator ++(){
      /* node_ptr = tQueue.front();
       if(node_ptr != nullptr){
            node_ptr = node_ptr->GetSon();
           tQueue.push(node_ptr);

         while (node_ptr->GetBrother()!= nullptr){
                std::cout<<"brother";
                node_ptr = node_ptr->GetBrother();
                tQueue.push(node_ptr);
            }
         node_ptr = tQueue.front();
         tQueue.pop();
       }*/

        node_ptr=node_ptr->GetNext();

    }

    TIterator operator++(int){
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator == (TIterator const& i){
        return node_ptr == i.node_ptr;
    }

    bool operator !=(TIterator const& i){
        return !(*this == i);
    }

private:
    std::shared_ptr<node> node_ptr;
   // std::queue<std::shared_ptr<node>> tQueue;

};

#endif // TITERATOR_H
