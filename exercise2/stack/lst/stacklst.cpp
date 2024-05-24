#include "stacklst.hpp"
namespace lasd {

/* ************************************************************************** */

//Copy and Move assignment - StackLst
    template <typename Data>
    StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stackLst){
        List<Data>::operator=(stackLst);
        return *this;
    }

    template<typename Data>
    StackLst<Data>& StackLst<Data>::operator=(StackLst<Data> &&stackLst) noexcept{
        List<Data>::operator=(std::move(stackLst));
        return *this;
    }


/* ************************************************************************** */

//Comparison operators - StackLst
    template<typename Data>
    bool StackLst<Data>::operator==(const StackLst<Data> &stackLst) const noexcept{
        if(this == &stackLst){
            return true;
        }
        
        return List<Data>::operator==(stackLst);
    }

    template<typename Data>
    bool StackLst<Data>::operator!=(const StackLst<Data> &stackLst) const noexcept{
        return List<Data>::operator!=(stackLst);
    }

/* ************************************************************************** */

//Specific function - StackLst
    template<typename Data>
    const Data& StackLst<Data>::Top() const{
        return List<Data>::Front();
    }

    template<typename Data>
    Data& StackLst<Data>::Top(){
        return List<Data>::Front();
    }

    template<typename Data>
    void StackLst<Data>::Pop(){
        return List<Data>::RemoveFromFront();
    }

    template<typename Data>
    Data StackLst<Data>::TopNPop(){
        return List<Data>::FrontNRemove();
    }

    template<typename Data>
    void StackLst<Data>::Push(const Data& data){
        return List<Data>::InsertAtFront(data);
    }
    template<typename Data>
    void StackLst<Data>::Push(Data &&data) noexcept{
        return List<Data>::InsertAtFront(std::move(data));
    }
}