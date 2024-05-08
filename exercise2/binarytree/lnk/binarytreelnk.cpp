#include "binarytreelnk.hpp"
namespace lasd {

/* ************************************************************************** */

// Specific Constructors - NodeLnk

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& data) {
    elem = data;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& data) noexcept {
    std::swap(elem, data);
}


/* ************************************************************************** */

// Copy and Move constructors - NodeLnk

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& node) {
    elem = node.elem;
    if(node.left != nullptr) {
        left = new NodeLnk(*node.left);
    }
    if(node.right != nullptr) {
        right = new NodeLnk(*node.right);
    }
};

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& node) noexcept {
    std::swap(elem, node.elem);
    std::swap(left, node.left);
    std::swap(right, node.right);
};



/* ************************************************************************** */

// Destructor - NodeLnk
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    delete left;
    delete right;
}

/* ************************************************************************** */

// Copy and Move Assignment - NodeLnk

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& node) {
    NodeLnk* tmp = new NodeLnk(node.info);
    if(node.HasLeftChild()) {
        left = node.left;
    }
    if(node.HasRightChild()) {
        right = node.right;
    }
    return* tmp;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& node) noexcept {
    std::swap(elem, node.info);
    std::swap(left, node.left);
    std::swap(right, node.right);
    return* this;
}


/* ************************************************************************** */

// Comparison Operators - NodeLnk

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk& other) const noexcept {
    
    if (elem != other.elem){
        return false;
    }

    bool hasLeftThis = HasLeftChild();
    bool hasRightThis = HasRightChild();
    bool hasLeftOther = other.HasLeftChild();
    bool hasRightOther = other.HasRightChild();

    if (hasLeftThis != hasLeftOther || hasRightThis != hasRightOther){
        return false;
    }
    if (!hasLeftThis && !hasRightThis){
        return true;
    }
    if (hasLeftThis && hasRightThis) {
        return LeftChild() == other.LeftChild() && RightChild() == other.RightChild();
    }
    
    return false;
}


template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk& node) const noexcept {
    return !(*this == node);
}

/* ************************************************************************** */

// Specific Function - NodeLnk

template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
    return elem;
}


template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return elem;
}


template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept{
    return !(HasLeftChild() || HasRightChild());
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    return (right != nullptr);
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
    return (left != nullptr);
}

template <typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if(right == nullptr) {
        throw std::out_of_range("Right child does not exists");
    } else {
        return* right;
    }
}

template <typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if(left == nullptr) {
        throw std::out_of_range("Left child does not exists");    
    } else {
        return* left;
    }
}

template <typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild() {
    if(right == nullptr) {
        throw std::out_of_range("Right child does not exists");
    } else {
        return* right;
    }
}

template <typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
    if(left == nullptr) {
        throw std::out_of_range("Left child does not exists"); 
    } else {
        return* left;
    }
}





/* ************************************************************************** */

// Specific Constructors - BinaryTreeLnk

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& con) {
    size = con.Size();
    QueueVec<NodeLnk**> que;
    que.Enqueue(&root);
    con.Traverse([&que](const Data& data) {
        NodeLnk*& tmp = *que.HeadNDequeue();
        tmp = new NodeLnk(data);
        que.Enqueue(&tmp->left);
        que.Enqueue(&tmp->right);
    });
}


template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& con) {
    size = con.Size();
    QueueVec<NodeLnk**> que;
    que.Enqueue(&root);
    con.Map([&que](const Data& data) {
        NodeLnk*& tmp = *que.HeadNDequeue();
        tmp = new NodeLnk(std::move(data));
        que.Enqueue(&tmp->left);
        que.Enqueue(&tmp->right);
    });
}

/* ************************************************************************** */

// Copy and Move Constructors - BinaryTreeLnk
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& btlnk) {
    size = btlnk.Size();
    if(btlnk.Size() > 0) {
        root = BTLCopy(btlnk.root);
    }
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& btl) noexcept : BinaryTreeLnk<Data>() {
    std::swap(size, btl.size);
    std::swap(root, btl.root);
}


/* ************************************************************************** */

// Destructor - BinaryTreeLnk
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
    Clear();
}

/* ************************************************************************** */

// Copy and Move Assignment - BinaryTreeLnk

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& btlnk) {
    if(btlnk.Size() > 0) {
        BinaryTreeLnk<Data>* tmp = new BinaryTreeLnk<Data>(btlnk);
        std::swap(*tmp, *this);
        delete tmp;
    } else {
        Clear();
    }
    return* this;
}


template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& btlnk) noexcept {
    std::swap(root, btlnk.root);
    std::swap(size, btlnk.size);
    return* this;
}

/* ************************************************************************** */

// Comparison Operators - BinaryTreeLnk

template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk& btlnk) const noexcept {
    return BinaryTree<Data>::operator==(btlnk);
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk& btlnk) const noexcept {
    return !(*this == btlnk);
}

/* ************************************************************************** */

// Specific Function - BinaryTreeLnk

template <typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeLnk<Data>::Root() const {
    if(root == nullptr) {
        throw std::length_error("Empty Tree!");
    } else {
        return* root;
    }
}

template <typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::Root() {
    if(root == nullptr) {
        throw std::length_error("Empty Tree!");
    } else {
        return* root;
    }
}

template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    delete root;
    size = 0;
    root = nullptr;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::BTLCopy(NodeLnk* node) {
    NodeLnk* tmp = nullptr;

    if(node != nullptr) {
        tmp = new NodeLnk(node->elem);
    }
    if(node->left != nullptr) {
        tmp->left = BTLCopy(node->left);
    }
    if(node->right != nullptr) {
        tmp->right = BTLCopy(node->right);
    }
    return tmp;
}
/* ************************************************************************** */

}
