
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  unsigned long operator()(const Data&) const noexcept; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer,
                  virtual public DictionaryContainer<Data>{
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  using DictionaryContainer<Data>::size;

  ulong a = 1;
  ulong b = 0;
  static const ulong prime =  17; //127312343; //Big Prime

  std::default_random_engine gen = std::default_random_engine(std::random_device{}());
  std::uniform_int_distribution<unsigned long> dista = std::uniform_int_distribution<unsigned long>(1, prime-1);
  std::uniform_int_distribution<unsigned long> distb = std::uniform_int_distribution<unsigned long>(0, prime-1);

  static const Hashable<Data> enchash;

  unsigned long tablesize = 128;
  
public:

  // Destructor
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTable&) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.
  bool operator!=(const HashTable&) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.

protected:

  // Auxiliary member functions

  // Default Constructor
  HashTable(){
    a = dista(gen);
    b = distb(gen);
  }

  //Copy Constructor
  HashTable(const HashTable& ht){
    size = ht.size;
    a = ht.a;
    b = ht.b;
    tablesize = ht.tablesize;
  }

  // Move Constructor
  HashTable(HashTable&& ht){
    std::swap(size, ht.size);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(tablesize, ht.tablesize);
  }

  // Copy Assignment
  HashTable& operator=(const HashTable& ht){
    size = ht.size;
    a = ht.a;
    b = ht.b;
    tablesize = ht.tablesize;
    return* this;
  }

  // Move Assignment
  HashTable& operator=(HashTable&& ht){
    std::swap(size, ht.size);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(tablesize, ht.tablesize);
    return* this;
  }

  virtual unsigned long HashKey(const Data&) const noexcept;

  virtual unsigned long HashKey(unsigned long) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
