#include "htclsadr.hpp"
namespace lasd {

/* ************************************************************************** */

// Default Constructors - HashTableClsAdr

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() {
    table = Vector<List<Data>> (MIN_SIZE_CLS);
    tablesize = MIN_SIZE_CLS;
}

/* ************************************************************************** */

// Specific Constructors - HashTableClsAdr

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize) {
    if(givenSize < MIN_SIZE_CLS) {
        givenSize = MIN_SIZE_CLS;
    }
    else if(givenSize >= MAX_SIZE_CLS) {
        givenSize = MAX_SIZE_CLS;
    }
    else{
        givenSize = FindNextPrime(givenSize);   
    }
    tablesize = givenSize;
    table.Resize(givenSize);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& container){
    unsigned long givenSize = 0;
    if(container.Size() < MIN_SIZE_CLS) {
        givenSize = MIN_SIZE_CLS;
    }
    else if(container.Size() >= MAX_SIZE_CLS) {
        givenSize = MAX_SIZE_CLS;
    }
    else{
        givenSize = FindNextPrime(container.Size());   
    }
    tablesize = givenSize;
    table.Resize(givenSize);
    InsertAll(container);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize, const TraversableContainer<Data>& container){
    if(givenSize < MIN_SIZE_CLS) {
        givenSize = MIN_SIZE_CLS;
    }
    else if(givenSize >= MAX_SIZE_CLS) {
        givenSize = MAX_SIZE_CLS;
    }
    else{
        givenSize = FindNextPrime(givenSize);   
    }
    tablesize = givenSize;
    table.Resize(givenSize);
    InsertAll(container);
}


template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& container){
    unsigned long givenSize = 0;
    if(container.Size() < MIN_SIZE_CLS) {
        givenSize = MIN_SIZE_CLS;
    }
    else if(container.Size() >= MAX_SIZE_CLS) {
        givenSize = MAX_SIZE_CLS;
    }
    else{
        givenSize = FindNextPrime(container.Size());   
    }
    tablesize = givenSize;
    table.Resize(givenSize);
    InsertAll(std::move(container));
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize, MappableContainer<Data>&& container){
    if(givenSize < MIN_SIZE_CLS) {
        givenSize = MIN_SIZE_CLS;
    }
    else if(givenSize >= MAX_SIZE_CLS) {
        givenSize = MAX_SIZE_CLS;
    }
    else{
        givenSize = FindNextPrime(givenSize);   
    }
    tablesize = givenSize;
    table.Resize(givenSize);
    InsertAll(std::move(container));
}

/* ************************************************************************** */

// Copy and Move Constructors - HashTableClsAdr

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& ht) {
    size = ht.size;
    tablesize = ht.tablesize;
    a = ht.a;
    b = ht.b;
    table = ht.table;
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& ht) noexcept {
    std::swap(size, ht.size);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(table, ht.table);
}

/* ************************************************************************** */

// Copy and Move Assigments - HashTableClsAdr

template<typename Data>
HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& ht){
    HashTableClsAdr<Data>* tmpht = new HashTableClsAdr(ht);
    std::swap(*this, *tmpht);
    delete tmpht;
    return *this;
}

template<typename Data>
HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& ht) noexcept{
    std::swap(size, ht.size);
    std::swap(table, ht.table);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    return *this;
}

/* ************************************************************************** */

// Copy and Move Assigments - HashTableClsAdr

template<typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& ht) const noexcept{
    bool exists = true;
    if(size == ht.size){
        for(unsigned long i = 0; i < table.Size(); i++){
            for(unsigned long j = 0; j < table[i].Size() && table[i].Size() != 0; j++){
                for(unsigned long index = 0; index < ht.table.Size(); index ++){
                    exists &= ht.Exists(table[i].operator[](j));
                }     
            }
        }
        return exists;
    }
    return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& ht) const noexcept{
    return !(*this == ht);
}

/* ************************************************************************** */

// Specific Member Functions - HashTableClsAdr

template<typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data){
    unsigned long index = HashKey(data);
    if(table[index].Insert(data)){
        size++;
        return true;
    }
    return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data) noexcept{
    unsigned long index = HashKey(std::move(data));
    if(table[index].Insert(std::move(data))){
        size++;
        return true;
    }
    return false;
} 

template<typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data){
    unsigned long index = HashKey(data);
    if(table[index].Remove(data)){
        size--;
        return true;
    }
    return false;
}


template<typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept {
    unsigned long index = HashKey(data);
    return table[index].Exists(data);
}


template<typename Data>
void HashTableClsAdr<Data>::Resize(unsigned long newSize){
    if(newSize < MIN_SIZE_CLS){        
        newSize = MIN_SIZE_CLS;
    }
    else if(newSize > MAX_SIZE_CLS){
        newSize = MAX_SIZE_CLS;
    }
    else{
        newSize = FindNextPrime(newSize);
    }
    Vector<List<Data>> table2(table);
    table.Clear();
    table.Resize(newSize);
    tablesize = newSize;
    size = 0;
    for(unsigned long i = 0; i < table2.Size(); i++){
        for(unsigned long j = 0; j < table2[i].Size() && table2[i].Size() != 0; j++){
            Insert(table2[i].operator[](j));
        }
    }
}


template<typename Data>
void HashTableClsAdr<Data>::Clear() {
    table.Clear();
    table.Resize(MIN_SIZE_CLS);
    tablesize = MIN_SIZE_CLS;
    size = 0;
}


template <typename Data>
unsigned long HashTableClsAdr<Data>::FindNextPrime(unsigned long val) const noexcept {
    for (ulong i = 2; i <= val/2; ++i) {
        if (val % i == 0) {
            val+=1;
            i = 2;
        }
    }
    return val;
}

/* ************************************************************************** */

}
