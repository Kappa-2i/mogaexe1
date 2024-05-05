#include "binarytree.hpp"
namespace lasd {

/* ************************************************************************** */

// Comparison Operator - Node
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& other) const noexcept {
    if(this->Element() != other.Element()){
        return false;
    }

    bool thisHasLeft = this->HasLeftChild();
    bool otherHasLeft = other.HasLeftChild();
    bool thisHasRight = this->HasRightChild();
    bool otherHasRight = other.HasRightChild();

    if ((thisHasLeft && !otherHasLeft) || (!thisHasLeft && otherHasLeft)){
        return false;
    }
    if ((thisHasRight && !otherHasRight) || (!thisHasRight && otherHasRight)){
        return false;
    }
    if (thisHasLeft && this->LeftChild() != other.LeftChild()){
        return false;
    }
    if (thisHasRight && this->RightChild() != other.RightChild()){
        return false;
    }
    return true;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& other) const noexcept {
    return !(*this == other);
}


/* ************************************************************************** */

// Comparison Operator - BinaryTree

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& bt) const noexcept {
    if(size != bt.size){
        return false;
    }
    if(size == 0){
        return true;
    }
    return (Root() == bt.Root());
}

template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& bt) const noexcept {
    return !(*this == bt);
}

/* ************************************************************************** */

// Specific function inherited from Traversable - BinaryTree

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun){
    if(size > 0){
        PreOrderTraverse(fun, &root);
    }
}


/* ************************************************************************** */

// Specific Constructor - BTPreOrderIterator

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& bt){
    if(bt.Size() != 0){
        root = curr = &bt.Root();
    }
}

/* ************************************************************************** */

// Copy and Move constructor - BTPreOrderIterator

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& it){
    root = it.root;
    curr = it.curr;
    stk = it.stk;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& it){
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(stk, it.stk);
}

/* ************************************************************************** */

// Copy and Move assignment - BTPreOrderIterator

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& it){
    root = it.root;
    curr = it.curr;
    stk = it.stk;
    return *this; 
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& it){
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(stk, it.stk);
    return *this;
}

/* ************************************************************************** */

// Specific member function - BTPreOrderIterator

template <typename Data>
const Data& BTPreOrderIterator<Data>::operator*() const {
    if(curr != nullptr) {
        return curr->Element();
    } 
    else {
        throw std::out_of_range("EXC - Iterator Terminated!");
    }
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{
    return (curr == nullptr);
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("Iterator terminated!");
    }
    if(curr->HasRightChild()) {
        stk.Push(&(curr->RightChild()));
    }
    if(curr->HasLeftChild()) {
        stk.Push(&(curr->LeftChild()));
    }
    if(stk.Empty()) {
        curr = nullptr;
    } else {
        curr = stk.TopNPop();
    }
    return *this;
}

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept{
    stk.Clear();
    curr = root;
}

/* ************************************************************************** */

}
