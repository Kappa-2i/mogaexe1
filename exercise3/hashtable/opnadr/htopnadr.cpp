#include "htopnadr.hpp"
#include <iostream>
namespace lasd {

/* ************************************************************************** */

// For Vector of Flag
// E=Empty, F=Full, R=Removed

// Default constructor - HashTableOpnAdr
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() {
    size = 0;
    table.Resize(tablesize);
    statusVec.Resize(tablesize);
    for(unsigned long i=0; i<tablesize; i++) {
        statusVec[i] = 'E'; 
    }
}

/* ************************************************************************** */

// Specific constructor - HashTableOpnAdr
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long givenSize) {
    size = 0;
    if(givenSize > tablesize){
        givenSize = FindNext2Pow(givenSize);
        tablesize = givenSize;
        table.Resize(tablesize);
        statusVec.Resize(tablesize);
    }
    else{
        statusVec.Resize(tablesize);
    }
    for(unsigned long i=0; i<tablesize; i++) {
        statusVec[i] = 'E';
    }
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& container) : HashTableOpnAdr<Data>(container.Size()) {
    InsertAll(container);
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long givenSize, const TraversableContainer<Data>& container) : HashTableOpnAdr<Data> (givenSize) {
    InsertAll(container);
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& container) : HashTableOpnAdr<Data>(container.Size()){
    InsertAll(std::move(container));
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long givenSize, MappableContainer<Data>&& container) : HashTableOpnAdr<Data> (givenSize){
    InsertAll(std::move(container));
}

/* ************************************************************************** */

// Copy and Move Constructors - HashTableOpnAdr
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& ht) {
    size = ht.size;
    tablesize = ht.tablesize;
    a = ht.a;
    b = ht.b;
    table = ht.table;
    statusVec = ht.statusVec;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& ht) noexcept {
    std::swap(size, ht.size);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(table, ht.table);
    std::swap(statusVec, ht.statusVec);
}

/* ************************************************************************** */

// Copy and Move Assignments - HashTableOpnAdr
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& ht) {
    HashTableOpnAdr<Data>* tmpht = new HashTableOpnAdr(ht);
    std::swap(*this, *tmpht);
    delete tmpht;
    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& ht) noexcept {
    std::swap(size, ht.size);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(table, ht.table);
    std::swap(statusVec, ht.statusVec);
    return *this;
} 

/* ************************************************************************** */

// Comparison Operators - HashTableOpnAdr
template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& ht) const noexcept {
    if(size == ht.size) {
        for(unsigned long i = 0; i<tablesize; i++) {
            if(statusVec[i] == 'F'){
                if(!(ht.Exists(table[i]))) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& ht) const noexcept {
    return !(*this == ht);
}


/* ************************************************************************** */

// Specific Member Functions - HashTableOpnAdr
template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& data) {
    double capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
    if(capacity > 50) {
        Resize(2*tablesize);
    }
    if(!Exists(data)) {
        unsigned long index = FindEmpty(data, 0);
        if(index < tablesize) {
            unsigned long key = HashKey(data, index);
            if(statusVec[key] == 'E' || statusVec[key] == 'F'){
                table[key] = data;
                statusVec[key] = 'F';
                size++;
                return true;
            }
        }
    }
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& data) noexcept {
    double capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
    if(capacity > 50) {
        Resize(2*tablesize);
    }
    if(!Exists(data)) {
        unsigned long index = FindEmpty(data, 0);
        if(index < tablesize) {
            unsigned long key = HashKey(data, index);
            if(statusVec[key] == 'E' || statusVec[key] == 'F'){
                table[key] = std::move(data);
                statusVec[key] = 'F';
                size++;
                return true;
            }
        }
    }
    return false;
}


template <typename Data>
void HashTableOpnAdr<Data>::Resize(unsigned long siz) {
    unsigned long newSize;
    if(!IsResizable(siz)) {
        return;
    }

    if(siz >= MIN_SIZE && siz <= MAX_SIZE){
        newSize = siz;
    }
    else{
        newSize = MIN_SIZE;
    }

    if(newSize == tablesize) {
        return;
    }
    HashTableOpnAdr<Data>* tmpht = new HashTableOpnAdr<Data>(newSize);
    std::cout << tmpht->tablesize << std::endl;
    std::cout << "sto inserend gli elementi in tmpht" << std::endl;
    std::cout << tablesize << std::endl;
    std::cout << statusVec.Size() << std::endl;
    std::cout << table.Size() << std::endl;
    for(unsigned long i = 0; i < tablesize; i++) {
        if(statusVec[i] == 'F') {
            std::cout << "Sto facendo l'insert" << std::endl;
            tmpht->Insert(table[i]);
        }
    }
    std::cout << "Ho inserito gli elementi in tmpht" << std::endl;
    std::swap(*this, *tmpht);
    delete tmpht;
}


template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    tablesize = MIN_SIZE;
    size = 0;
    table.Clear();
    table.Resize(tablesize);
    statusVec.Resize(tablesize);
    for(unsigned long i = 0; i<tablesize; i++) {
        statusVec[i] = 'E';
    }
    
}


template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data) {
    double capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
    bool res = Remove(data, 0);
    std::cout << "Sto nella remove" << std::endl;
    if(capacity < 10) {
        Resize((tablesize/2));
    }
    return res;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& data) const noexcept {
    if(size > 0) {
        unsigned long index = Find(data, 0);   
        if(index < tablesize) {
            unsigned long pos = HashKey(data, index);
            if(statusVec[pos] == 'F' && table[pos] == data) {
                return true;
            }
        }
    }
    return false;
}



template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data& data, unsigned long index) const noexcept {
    unsigned long key = enchash(data);
    //return ((HashKey(key)+index)%tablesize); //linear probing
    return ((HashKey(key)+((index*index)+index)/2)%tablesize); //quadratic probing
}


template <typename Data>
unsigned long HashTableOpnAdr<Data>::Find(const Data& data, unsigned long index) const noexcept {
    unsigned long start = HashKey(data, index);
    while(index < tablesize) {
        if(table[start] == data) {
            return index;
        }
        if(statusVec[start] =='E') {
            return tablesize;
        }
        index++; 
        start = HashKey(data, index);
    }
    return index;
}


template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& data, unsigned long index) const noexcept {
    unsigned long start = HashKey(data, index);
    while(index < tablesize) {
        if(statusVec[start] == 'E' || statusVec[start] == 'R') {
            return index;
        }
        index++;
        start = HashKey(data, index);
    }
    return index;
}   

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data, unsigned long index) {
    if(size > 0) {
        unsigned long idx = Find(data, index);
        if(idx < tablesize) {
            unsigned long pos = HashKey(data, idx);  
                if(statusVec[pos] == 'F' && table[pos] == data) {
                    statusVec[pos] = 'R';
                    size--;
                return true;
            }
        }
    }
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::IsResizable(unsigned long siz) const noexcept {
    if(siz > tablesize) {
        return true;
    } else {
        if(siz == tablesize) {
            return false;
        }
        ulong cap = (static_cast<double>(size)/static_cast<double>(siz))*100;
        if(cap < 75) {
            return true;
        }
        return false;
    } 
}


template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindNext2Pow(unsigned long siz) const noexcept {
    unsigned long newSize = MIN_SIZE;
    while(newSize < siz) {
        if(newSize >= MAX_SIZE) {
            break;   
        }
        newSize = newSize << 1;
    }
    return newSize;
}




/* ************************************************************************** */

}
