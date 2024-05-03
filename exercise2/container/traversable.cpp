#include "traversable.hpp"
namespace lasd {

/* ************************************************************************** */

//Specific Methods - TraversableContainer
template <typename Data>
template <typename Accumulator>
Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> func, Accumulator acc) const {
    Traverse(
        [func, &acc](const Data& currData){
            acc = func(currData, acc);
        }
    );
    return acc;
}
//Override Methods - TraversableContainer
template <typename Data>
bool TraversableContainer<Data>::Exists(const Data& data) const noexcept {
    bool exists = false;
    Traverse(
        [data, &exists](const Data& currData){
            exists |= (data == currData);
        }
    );
    return exists;
}

/* ************************************************************************** */

//Specific Methods - PreOrderTraversableContainer
template <typename Data>
template <typename Accumulator>
Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun <Accumulator> func, Accumulator acc) const {
    PreOrderTraverse(
        [func, &acc](const Data& currData){
            acc = func(currData, acc);
        }
    );
    return acc;
}


template<typename Data>
void PreOrderTraversableContainer<Data>::Traverse(TraverseFun func) const{
    PreOrderTraverse(func);
}

/* ************************************************************************** */

//Specific Methods - PostOrderTraversableContainer
template<typename Data>
template<typename Accumulator>
Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun <Accumulator> fun, Accumulator acc) const{
    PostOrderTraverse(
        [fun, &acc](const Data &data){
            acc = fun(data, acc);
        }
    );

    return acc;
}


template<typename Data>
void PostOrderTraversableContainer<Data>::Traverse(TraverseFun func) const{
    PostOrderTraverse(func);
}

/* ************************************************************************** */

//Specific Methods - InOrderTraversableContainer
template<typename Data>
template<typename Accumulator>
Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> func, Accumulator acc) const{
    InOrderTraverse(
            [func, &acc](const Data& currData){
                acc = func(currData, acc);
            }
    );
    return acc;
}

template<typename Data>
void InOrderTraversableContainer<Data>::Traverse(TraverseFun func) const{
    OrderTraverse(func);
}
/* ************************************************************************** */

//Specific Methods - BreadthTraversableContainer
template<typename Data>
template<typename Accumulator>
Accumulator BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> func, Accumulator acc) const{
    BreadthTraverse(
            [func, &acc](const Data& data){
                acc = func(data, acc);
            }
    );
    return acc;
}

template<typename Data>
void BreadthTraversableContainer<Data>::Traverse(TraverseFun func) const{
    BreadthTraverse(func);
}

}