#include "vector.hpp"
namespace lasd {

/* ************************************************************************** */

//Specific constructors - Vector
    template <typename Data>
    Vector<Data>::Vector(const unsigned long newSize){
        try{
            size = newSize;
            elements = new Data[size];
        }
        catch (std::bad_alloc& exception){
            std::cerr << "EXC - Cannot allocate memory for vector: " << exception.what();
        }
    }

    template <typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data>& container) {
        try{
            size = container.Size();
            elements = new Data[size];

            unsigned long index = 0;
            container.Traverse(
                [this, &index](const Data& data){
                    elements[index++] = data;
                }
            );
        }catch(std::bad_alloc& exception){
            std::cerr << "EXC - Cannot allocate memory for vector: " << exception.what();
        }
    }

    template <typename Data>
    Vector<Data>::Vector(MappableContainer<Data>&& container) {
        try{
            size = container.Size();
            elements = new Data[size];

            unsigned long index = 0;
            container.Map(
                [this, &index](Data& data){
                    elements[index++] = std::move(data);
                }
            );
        }catch(std::bad_alloc& exception){
            std::cerr << "EXC - Cannot allocate memory for vector: " << exception.what();
        }
    }
/* ************************************************************************** */

//Copy and Move constructor - Vector
    template <typename Data>
    Vector<Data>::Vector(const Vector<Data>& vec){
        try{
            size = vec.size;
            elements = new Data[size];

            std::copy(vec.elements, vec.elements+size, elements);
        }catch(std::bad_alloc& exception){
            std::cerr << "EXC - Cannot allocate memory for Vector: " << exception.what();
        }
    }

    template<typename Data>
    Vector<Data>::Vector(Vector<Data>&& vec) noexcept{
        std::swap(elements, vec.elements);
        std::swap(size, vec.size);
    }

/* ************************************************************************** */

//Destructor - Vector
    template <typename Data>
    Vector<Data>::~Vector(){
        delete[] elements;
    }

/* ************************************************************************** */

//Copy and Move assignment - Vector
    template <typename Data>
    Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vec){
        Vector<Data> temp{vec};
        std::swap(temp, *this);
        return* this;
    }

    template <typename Data>
    Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vec) noexcept{
        std::swap(elements, vec.elements);
        std::swap(size, vec.size);
        return* this;
    }



/* ************************************************************************** */

//Comparison operators - Vector
    template <typename Data>
    bool Vector<Data>::operator==(const Vector<Data>& vec) const noexcept {
        if(size != vec.size){
            return false;
        }

        for(unsigned long i=0; i<size; i++){
            if(elements[i] != vec[i]){
                return false;
            }
        }
        return true;
    }

    template <typename Data>
    bool Vector<Data>::operator!=(const Vector<Data>& vec)const noexcept{
        return !(*this == vec);
    }
/* ************************************************************************** */

//Specific function inherited from ClearableContainer - Vector
    template <typename Data>
    void Vector<Data>::Clear() {
        delete[] elements;
        elements = nullptr;
        size = 0;
    }

//Specifc function inherited from ResizableContainer - Vector
    template <typename Data>
    void Vector<Data>::Resize(const unsigned long newSize) {
        if(newSize == 0){
            Clear();
            return;
        }
        if(newSize == size){
            return;
        }
        try{
            Data* temp = new Data[newSize];
            unsigned long min = (size < newSize) ? size : newSize;
            for(unsigned long i = 0; i<min; i++){
                std::swap(elements[i], temp[i]);
            }
            std::swap(elements, temp);
            size = newSize;
            delete[] temp;
        }catch(std::bad_alloc& exception){
            std::cerr << "EXC - Cannot resize Vector: " << exception.what();
        }
    }

/* ************************************************************************** */

//Specific function inherited from LinearContainer - Vector
    template <typename Data>
    const Data& Vector<Data>::operator[](const unsigned long i) const{
        if(i >= size){
            throw std::out_of_range("EXC - Index out of range");
        }
        return elements[i];
    }

    template <typename Data>
    Data& Vector<Data>::operator[](const unsigned long i) {
        if(i >= size){
            throw std::out_of_range("EXC - Index out of range");
        }
        return elements[i];
    }

    template <typename Data>
    const Data& Vector<Data>::Front() const{
        if(size != 0){
            return elements[0];
        }
        throw std::length_error("EXC - Vector is empty");
    }

    template <typename Data>
    Data& Vector<Data>::Front() {
        if(size != 0){
            return elements[0];
        }
        throw std::length_error("EXC - Vector is empty");
    }

    template <typename Data>
    const Data& Vector<Data>::Back() const{
        if(size != 0){
            return elements[size-1];
        }
        throw std::length_error("EXC - Vector is empty");
    }

    template <typename Data>
    Data& Vector<Data>::Back() {
        if(size != 0){
            return elements[size-1];
        }
        throw std::length_error("EXC - Vector is empty");
    }
/* ************************************************************************** */

//Specific constructor - SortableVector
    template <typename Data>
    SortableVector<Data>::SortableVector(const unsigned long newSize):Vector<Data>(newSize) {}

    template <typename Data>
    SortableVector<Data>::SortableVector(const TraversableContainer<Data>& container):Vector<Data>(container) {}

    template <typename Data>
    SortableVector<Data>::SortableVector(MappableContainer<Data>&& container):Vector<Data>(std::move(container)){}

/* ************************************************************************** */

//Copy and Move constructor - SortableVector
    template<typename Data>
    SortableVector<Data>::SortableVector(const SortableVector &vec):Vector<Data>(vec){}

    template<typename Data>
    SortableVector<Data>::SortableVector(SortableVector &&vec) noexcept :Vector<Data>(std::move(vec)){}

/* ************************************************************************** */

//Copy and Move assignment - SortableVector
    template <typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data>& vec) {
        Vector<Data>::operator=(vec);
        return* this;
    }

    template<typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(SortableVector &&vec) noexcept{
        Vector<Data>::operator=(std::move(vec));
        return *this;
    }
}



