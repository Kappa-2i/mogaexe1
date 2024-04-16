#include "dictionary.hpp"
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& container){
    bool all = true;
    container.Traverse(
        [this, &all](const Data& currData){
            all &= Insert(currData);
        }
    );
    return all;
}


template <typename Data>
inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& container) {
    bool all = true;
    container.Map(
        [this, &all](Data& currData){
            all &= Insert(std::move(currData));
        }
    );
    return all;
}


template <typename Data>
inline bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data> &container) {
    bool all = true;
    container.Traverse(
            [this, &all](const Data& currData){
                all &= Remove(currData);
            }
    );
    return all;
}


template <typename Data>
inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& container) {
    bool some = false;
    container.Map(
        [this, &some](Data& currData){
            some |= Insert(std::move(currData));
        }
    );
    return some;
}

template <typename Data>
inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& container) {
    bool some = false;
    container.Map(
        [this, &some](Data& currData){
            some |= Insert(std::move(currData));
        }
    );
    return some;
}


template <typename Data>
inline bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& container) {
    bool some = false;
    container.Traverse(
        [this, &some](const Data& currData){
            some |= Remove(currData);
        }
    );
    return some;
}
/* ************************************************************************** */

}
