
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : public virtual MutableBinaryTree<Data> {
  // Must extend MutableBinaryTree<Data>

private:


  // ...

public:

  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;
  
protected:

  using Container::size;

  struct NodeLnk : virtual MutableNode { // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    Data elem;
    NodeLnk* left = nullptr;
    NodeLnk* right = nullptr;

    //Default constructor
    NodeLnk() = default;

    //Specific constructors
    NodeLnk(const Data&);

    NodeLnk(Data&&) noexcept;

    //Copy constructor
    NodeLnk(const NodeLnk&);

    //Move constructor
    NodeLnk(NodeLnk&&) noexcept;

    //Destructor
    virtual ~NodeLnk();

    //Copy assignment
    NodeLnk& operator=(const NodeLnk&);

    //Move assignment
    NodeLnk& operator=(NodeLnk&&) noexcept;

    //Comparison operators
    bool operator==(const NodeLnk&) const noexcept;
    bool operator!=(const NodeLnk&) const noexcept;

    //Specific Member Functions
    const Data& Element() const noexcept override;
    Data& Element() noexcept override;

    bool IsLeaf() const noexcept override;
    bool HasRightChild() const noexcept override;
    bool HasLeftChild() const noexcept override;

    virtual const Node& RightChild() const override;
    virtual const Node& LeftChild() const override;
    virtual MutableNode& RightChild() override;
    virtual MutableNode& LeftChild() override;
  };

  NodeLnk* root = nullptr;
  

public:


  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const TraversableContainer<Data>&); // A binary tree obtained from a TraversableContainer
  BinaryTreeLnk(MappableContainer<Data>&&); // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk& operator=(const BinaryTreeLnk&);

  // Move assignment
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeLnk&) const noexcept;
  bool operator!=(const BinaryTreeLnk&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  const Node& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  MutableNode& Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member


  NodeLnk* BTLCopy(NodeLnk*);
};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
