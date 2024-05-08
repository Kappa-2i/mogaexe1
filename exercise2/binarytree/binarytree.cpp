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
void BinaryTree<Data>::Traverse(TraverseFun fun) const{
    if(size > 0){
        PreOrderTraverse(fun, &Root());
    }
}

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const{
    if(size > 0){
        PreOrderTraverse(fun, &Root());
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const{
    if(size > 0){
        PostOrderTraverse(fun, &Root());
    }
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const{
    if(size > 0){
        InOrderTraverse(fun, &Root());
    }
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const{
    if(size > 0){
        BreadthTraverse(fun, &Root());
    }
}

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun, const Node* node) const{
    if(node == nullptr){
        return;
    }

    fun(node->Element());

    if(node->HasLeftChild()){
        PreOrderTraverse(fun, &node->LeftChild());
    }

    if(node->HasRightChild()){
        PreOrderTraverse(fun, &node->RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun, const Node* node) const{
    if(node == nullptr){
        return;
    }

    if(node->HasLeftChild()){
        PostOrderTraverse(fun, &node->LeftChild());
    }

    if(node->HasRightChild()){
        PostOrderTraverse(fun, &node->RightChild());
    }

    fun(node->Element());
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun, const Node* node) const{
    if(node == nullptr){
        return;
    }

    if(node->HasLeftChild()){
        InOrderTraverse(fun, &node->LeftChild());
    }

    fun(node->Element());

    if(node->HasRightChild()){
        InOrderTraverse(fun, &node->RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun, const Node* node) const{
    if(node == nullptr){
        return;
    }

    QueueVec<const Node*> que;
    if(node != nullptr){
        que.Enqueue(node);
    }

    while (!que.Empty()){
        fun(que.Head()->Element());

        if(que.Head()->HasLeftChild()){
            que.Enqueue(&que.Head()->LeftChild());
        }

        if(que.Head()->HasRightChild()){
            que.Enqueue(&que.Head()->RightChild());
        }

        que.Dequeue();
    }
}


/* ************************************************************************** */

// Specific Function - MutableBinaryTree 

template <typename Data>
void MutableBinaryTree<Data>::Map(MapFun fun) {
    if(size>0) {
        PreOrderMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun) {
    if(size>0) {
        PreOrderMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun) {
    if(size>0) {
        PostOrderMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun) {
    if(size > 0) {
        InOrderMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun) {
    if(size > 0) {
        BreadthMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, MutableNode* node) {
    if(node != nullptr) {
        fun(node->Element());

        if(node->HasLeftChild()) {
            PreOrderMap(fun, &node->LeftChild());
        }

        if(node->HasRightChild()) {
            PreOrderMap(fun, &node->RightChild());
        }
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, MutableNode* node) {
    if(node != nullptr) {
        if(node->HasLeftChild()) {
            PostOrderMap(fun, &node->LeftChild());
        }
        if(node->HasRightChild()) {
            PostOrderMap(fun, &node->RightChild());
        }
        fun(node->Element());
    }    
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun, MutableNode* node) {
    if(node != nullptr) {
        if(node->HasLeftChild()) {
            InOrderMap(fun, &node->LeftChild());
        }

        fun(node->Element());

        if(node->HasRightChild()) {
            InOrderMap(fun, &node->RightChild());
        }
    }      
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun, MutableNode* node) {
    lasd::QueueVec<MutableNode*> que;
    if(node != nullptr) {
        que.Enqueue(node);
    }
    while (!que.Empty()) {
        fun(que.Head()->Element());
        
        if (que.Head()->HasLeftChild()) {
            que.Enqueue(&(que.Head()->LeftChild()));
        }
        
        if (que.Head()->HasRightChild()) {
            que.Enqueue(&(que.Head()->RightChild()));
        }
        que.Dequeue();
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
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& it) noexcept{
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(stk, it.stk);
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
        throw std::out_of_range("EXC - Iterator terminated!");
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
    return* this;
}

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept{
    stk.Clear();
    curr = root;
}

/* ************************************************************************** */

// Specific Constructor - BTPreOrderMutableIterator

template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(MutableBinaryTree<Data>& bt) : BTPreOrderIterator<Data>(bt) {}
/* ************************************************************************** */

// Copy and Move Constructor - BTPreOrderMutableIterator
template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator& it) : BTPreOrderIterator<Data>(it) {}

template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator&& it) noexcept : BTPreOrderIterator<Data>(std::move(it)) {}

/* ************************************************************************** */

// Specific Member Function - BTPreOrderMutableIterator

template <typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*(){
    if(curr != nullptr) {
      return const_cast<Data&>(curr->Element());
    } 
    else {
      throw std::out_of_range("EXC - Iterator Terminated!");
    }
}

/* ************************************************************************** */

// Specific Constructor - BTPostOrderIterator

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& bt) {
    if(bt.Size() != 0) {
        curr = root = &bt.Root();
        LeftMostLeaf();
    }
}


/* ************************************************************************** */

// Copy and Move Constructor - BTPostOrderIterator
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& it){
    root = it.root;
    curr = it.curr;
    stk = it.stk;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& it) noexcept {
    std::swap(root, it.root); 
    std::swap(curr, it.curr);
    std::swap(stk, it.stk);
}


/* ************************************************************************** */

// Specific Member Function - BTPostOrderIterator

template <typename Data>
void BTPostOrderIterator<Data>::LeftMostLeaf() {
    while(curr->HasLeftChild()) {
        stk.Push(curr);
        curr = &curr->LeftChild();
    }
    if(curr->HasRightChild()) {
        stk.Push(curr);
        curr = &curr->RightChild();
        LeftMostLeaf();
    }
}

template <typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const {
    if(curr != nullptr) {
      return curr->Element();
    } 
    else {
      throw std::out_of_range("EXC - Iterator terminated!");
    }
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept{
    return (curr == nullptr);
}


template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("EXC - Iterator Terminated!");
    }
    if(stk.Empty()) {
        curr = nullptr;
    } else {
        if(stk.Top()->HasRightChild() && !(&stk.Top()->RightChild() == curr)) {
            curr = &stk.Top()->RightChild();
            LeftMostLeaf();
        } else {
            curr = stk.TopNPop();
        }
    }
    return* this;
}


template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    stk.Clear();
    curr = root;
    if(curr != nullptr){
        LeftMostLeaf();
    }
}


/* ************************************************************************** */

// Specific Constructor - BTPostOrderMutableIterator
template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(MutableBinaryTree<Data>& bt) : BTPostOrderIterator<Data>(bt) {}

/* ************************************************************************** */

// Copy and Move Constructor - BTPostOrderMutableIterator

template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data>& it) : BTPostOrderIterator<Data>(it) {}

template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data>&& it) noexcept : BTPostOrderIterator<Data>(std::move(it)) {}


/* ************************************************************************** */

// Specific Member Function - BTPostOrderMutableIterator
template <typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*(){
    if(curr != nullptr) {
      return const_cast<Data&>(curr->Element());
    }
    else {
      throw std::out_of_range("EXC - Iterator terminated!");
    }
}


/* ************************************************************************** */

// Specific Constructor - BTInOrderIterator

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& bt) {
    if(bt.Size()!=0) {
        curr = root = &bt.Root();
        LeftMostNode();
    }
}

/* ************************************************************************** */

// Copy and Move constructors - BTInOrderIterator
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& it){
    root = it.root;
    curr = it.curr;
    stk = it.stk;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& it) noexcept{
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(stk, it.stk);
}

/* ************************************************************************** */

// Specific Member Function - BTInOrderIterator


template <typename Data>
void BTInOrderIterator<Data>::LeftMostNode() {
    if(curr == nullptr) {
        return;
    }
    while(curr->HasLeftChild()) {
        stk.Push(curr);
        curr = &curr->LeftChild();
    }
}

template <typename Data>
const Data& BTInOrderIterator<Data>::operator*() const{
    if(curr != nullptr) {
      return curr->Element();
    } 
    else {
      throw std::out_of_range("EXC - Iterator terminated!");
    }
}


template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept{
    return (curr == nullptr);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("EXC - Iterator Terminated!");
    }
    if(curr->HasRightChild()) {
        curr = &(curr->RightChild());
        LeftMostNode();
    } 
    else {
        if(stk.Empty()) {
            curr = nullptr;
        } 
        else {
            curr = stk.TopNPop();
        }

    }
    return* this;
}


template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    stk.Clear();
    curr = root;
    LeftMostNode();
}


/* ************************************************************************** */

// Specific Constructor - BTInOrderMutableIterator
template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(MutableBinaryTree<Data>& bt) : BTInOrderIterator<Data>(bt) {}

/* ************************************************************************** */

// Copy and Move constructors - BTInOrderMutableIterator
template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator<Data>& it) : BTInOrderIterator<Data>(it) {}

template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator<Data>&& it) noexcept : BTInOrderIterator<Data>(std::move(it)) {}

/* ************************************************************************** */

// Specific Member Function - BTInOrderMutableIterator
template <typename Data>
Data& BTInOrderMutableIterator<Data>::operator*(){
    if(curr != nullptr) {
      return const_cast<Data&>(curr->Element());
    } 
    else {
      throw std::out_of_range("EXC - Iterator terminated!");
    }
}





/* ************************************************************************** */

// Specific Constructor - BTBreadthIterator
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& bt){
    if(bt.Size() != 0) {
      curr = root = &bt.Root();
    }
}

/* ************************************************************************** */

// Copy and Move Constructors - BTBreadthIterator

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator& it){
    root = it.root;
    curr = it.curr;
    que = it.que;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& it) noexcept{
    std::swap(root, it.root);
    std::swap(curr, it.curr);
    std::swap(que, it.que);  
} 


/* ************************************************************************** */

// Specific Member Function - BTBreadthIterator
template <typename Data>
const Data& BTBreadthIterator<Data>::operator*() const{
    if(curr != nullptr) {
      return curr->Element();
    } 
    else {
      throw std::out_of_range("EXC - Iterator terminated!");
    }
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{
    return (curr == nullptr);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if(Terminated()) {
        throw std::out_of_range("EXC - Iterator Terminated!");
    }
    if(curr->HasLeftChild()) {
        que.Enqueue(&(curr->LeftChild()));
    }
    if(curr->HasRightChild()) {
        que.Enqueue(&(curr->RightChild()));
    }
    if(que.Empty()) {
        curr = nullptr;
    } else {
        curr = que.HeadNDequeue();
    }
    return* this;
}
 
template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    curr = root;
    que.Clear();
}


/* ************************************************************************** */

// Specific Constructor - BTBreadthMutableIterator
template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(MutableBinaryTree<Data>& bt) : BTBreadthIterator<Data>(bt) {}
    

/* ************************************************************************** */

// Copy and Move Constructors - BTBreadthMutableIterator
template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator& it) : BTBreadthIterator<Data>(it) {}

template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator&& it) noexcept : BTBreadthIterator<Data>(std::move(it)) {}



/* ************************************************************************** */

// Specific member Function - BTBreadthMutableIterator
template <typename Data>
Data& BTBreadthMutableIterator<Data>::operator*(){
    if (curr != nullptr) {
      return const_cast<Data&>(curr->Element());
    } 
    else {
      throw std::out_of_range("EXC - Iterator terminated!");
    }
}


}
