#include "stackvec.hpp"
namespace lasd {

/* ************************************************************************** */

//Specific Constructor - StackVec
    template<typename Data>
    StackVec<Data>::StackVec(const TraversableContainer<Data>& container){
        try{
            index = 0;
            size = container.Size();
            elements = new Data[size];

            container.Traverse(
                [this](const Data &data){
                    Push(data);
                }
            );
        }catch(std::bad_alloc& exception){
            std::cerr << "EXC - Cannot allocate memory for stack: " <<  exception.what();
        }
    };

    template<typename Data>
    StackVec<Data>::StackVec(MappableContainer<Data>&& container){
        try{
            index = 0;
            size = container.Size();
            elements = new Data[size];

            container.Traverse(
                [this](Data &data){
                    Push(std::move(data));
                }
            );
        }catch(std::bad_alloc& exception){
            std::cerr << "EXC - Cannot allocate memory for stack: " <<  exception.what();
        }
    };
/* ************************************************************************** */

//Copy and Move assignement - StackVec
    template<typename Data>
    StackVec<Data>& StackVec<Data>::operator=(const StackVec& stackVec){
        if(this != &stackVec){
            index = stackVec.index;
            Vector<Data>::operator=(stackVec);
        }
        return *this;
    }

    template<typename Data>
    StackVec<Data>& StackVec<Data>::operator=(StackVec&& stackVec) noexcept{
        if(this != &stackVec){
            index = stackVec.index;
            Vector<Data>::operator=(std::move(stackVec));
        }
        return *this;
    }

/* ************************************************************************** */

//Comparison operators - StackVec
    template<typename Data>
    bool StackVec<Data>::operator==(const StackVec& stackVec) const noexcept{
        if(this == &stackVec){
            return true;
        }
        return Vector<Data>::operator==(stackVec);
    }

    template<typename Data>
    bool StackVec<Data>::operator!=(const StackVec& stackVec) const noexcept{
        return !(*this == stackVec);
    }


/* ************************************************************************** */

//Specific Function - StackVec
    template<typename Data>
    const Data& StackVec<Data>::Top() const{
        if(index == 0){
            throw std::length_error("EXC - Empty stack");
        }
        return elements[index - 1];
    }

    template<typename Data>
    Data& StackVec<Data>::Top(){
        if(index == 0){
            throw std::length_error("EXC - Empty stack");
        }
        return elements[index - 1];
    }

    template<typename Data>
    void StackVec<Data>::Pop(){
        if(index == 0){
            throw std::length_error("EXC - Empty stack");
        }
        Reduce();
        index--;
    }

    template <typename Data>
    Data StackVec<Data>::TopNPop(){
        if(index == 0){
            throw std::length_error("EXC - Empty stack");
        }
        Reduce();
        return std::move(elements[--index]);
    }

    template <typename Data>
    void StackVec<Data>::Push(const Data& data){
        Expand();
        elements[index++] = data;
    }

    template <typename Data>
    void StackVec<Data>::Push(Data&& data) noexcept{
        Expand();
        elements[index++] = std::move(data);
    }

/* ************************************************************************** */

//Specific Function inherited from Container - StackVec
    template <typename Data>
    bool StackVec<Data>::Empty()const noexcept{
        return (index  == 0);
    }

    template <typename Data>
    unsigned long StackVec<Data>::Size() const noexcept{
        return index;
    }

/* ************************************************************************** */

//Specific Function inherited from ClearableContainer - StackVec
    template <typename Data>
    void StackVec<Data>::Clear(){
        index = 0;
        Vector<Data>::Resize(1);
    }

/* ************************************************************************** */

//Auxiliary Function - StackVec
    template <typename Data>
    void StackVec<Data>::Expand(){
        if(index == size){
            Vector<Data>::Resize(size*2);
        }
    }

    template <typename Data>
    void StackVec<Data>::Reduce(){
        if(index == (size/4)){
            Vector<Data>::Resize(size/2);
        }
    }
}