
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : public virtual MutableBinaryTree<Data> {
  // Must extend MutableBinaryTree<Data>

private:

  // ...

public:

  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:

  using MutableBinaryTree<Data>::size;

  struct NodeVec : virtual MutableNode { // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    Data elem;
    unsigned long curr = 0;
    Vector<NodeVec*>* vecptr = nullptr; 

    //Default Constructors
    NodeVec() = default;

    //Specific Constructor
    NodeVec(const Data&, unsigned long, Vector<NodeVec*>*);

    //Destructor
    virtual ~NodeVec() = default;

    //Copy Assignment
    NodeVec& operator=(const NodeVec&);

    //Move Assignment
    NodeVec& operator=(NodeVec&&) noexcept;

    //Comparison Operators
    bool operator==(const NodeVec& node) const noexcept;

    bool operator!=(const NodeVec& node) const noexcept;

    //Specifc Member Functions
    const Data& Element() const noexcept;
    Data& Element() noexcept ;

    bool IsLeaf() const noexcept ;
    bool HasRightChild() const noexcept ;
    bool HasLeftChild() const noexcept ;

    virtual const Node& RightChild() const override;
    virtual const Node& LeftChild() const override;
    virtual MutableNode& RightChild() override;
    virtual MutableNode& LeftChild() override;

  };

  Vector<NodeVec*>* vec = nullptr;

public:

  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const TraversableContainer<Data>&); // A binary tree obtained from a TraversableContainer
  BinaryTreeVec(MappableContainer<Data>&&) noexcept; // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec&);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeVec&) const noexcept;
  bool operator!=(const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  const Node& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  MutableNode& Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  using typename BreadthTraversableContainer<Data>::TraverseFun;

  void BreadthTraverse(TraverseFun) const override; // Override BreadthTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  using typename BreadthMappableContainer<Data>::MapFun;

  void BreadthMap(MapFun) override; // Override BreadthMappableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
