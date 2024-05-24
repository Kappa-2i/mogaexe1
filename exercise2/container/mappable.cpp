#include "mappable.hpp"
namespace lasd {

/* ************************************************************************** */
//Specific Methods - PreOrderMappableContainer
template <typename Data>
void PreOrderMappableContainer<Data>::Map(MapFun func){
    PreOrderMap(func);
}

//Specific Methods - PostOrderMappableContainer
template <typename Data>
void PostOrderMappableContainer<Data>::Map(MapFun func){
    PostOrderMap(func);
}

//Specific Methods - InOrderMappableContainer
template <typename Data>
void InOrderMappableContainer<Data>::Map(MapFun func){
    InOrderMap(func);
}

//Specific Methods - BreadthOrderMappableContainer
template <typename Data>
void BreadthMappableContainer<Data>::Map(MapFun func){
    BreadthMap(func);
}
/* ************************************************************************** */

}