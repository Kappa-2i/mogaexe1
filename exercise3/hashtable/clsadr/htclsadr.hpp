
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

#define MAX_TABLESIZE 9973
#define MIN_TABLESIZE 128

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
#include "../../bst/bst.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : virtual public HashTable<Data>{
// Must extend HashTable<Data>

private:


protected:


public:
  using HashTable<Data>::size;
  using HashTable<Data>::tablesize;
  using HashTable<Data>::enchash;
  using HashTable<Data>::a;
  using HashTable<Data>::b;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::Insert;
  using HashTable<Data>::InsertAll;
  Vector<List<Data>> table;


public:

  // Default constructor
  HashTableClsAdr();

  /* ************************************************************************ */

  // Specific constructors
  HashTableClsAdr(unsigned long); // A hash table of a given size
  HashTableClsAdr(const TraversableContainer<Data>&); // A hash table obtained from a TraversableContainer
  HashTableClsAdr(unsigned long, const TraversableContainer<Data>&); // A hash table of a given size obtained from a TraversableContainer
  HashTableClsAdr(MappableContainer<Data>&&); // A hash table obtained from a MappableContainer
  HashTableClsAdr(unsigned long, MappableContainer<Data>&&); // A hash table of a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableClsAdr(const HashTableClsAdr<Data>&);

  // Move constructor
  HashTableClsAdr(HashTableClsAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTableClsAdr& operator=(const HashTableClsAdr<Data>&);

  // Move assignment
  HashTableClsAdr& operator=(HashTableClsAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableClsAdr<Data>&) const noexcept;
  bool operator!=(const HashTableClsAdr<Data>&) const noexcept;


  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value)
  bool Insert(Data&&) noexcept override; // Override DictionaryContainer member (Move of the value)
  bool Remove(const Data&) override; // Override DictionaryContainer members
  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  void Resize(unsigned long) override; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  void Clear() override; // Override Container member

protected:
  unsigned long FindNextPrime(unsigned long) const noexcept;

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
