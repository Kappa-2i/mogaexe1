#include "bst.hpp"

namespace lasd {

/* ************************************************************************** */

// Specific Constructor - BST

template <typename Data>
BST<Data>::BST(const TraversableContainer<Data>& con) {
    con.Traverse([this](const Data& data) {
        Insert(data);
    });
}

template <typename Data>
BST<Data>::BST(MappableContainer<Data>&& con) noexcept {
    con.Map([this](Data& data) {
        Insert(std::move(data));
    });
}

// Comparison Operators - BST
template <typename Data>
bool BST<Data>::operator==(const BST<Data>& bst) const noexcept {
    if(size != bst.Size()) {
        return false;
    } else {
        if(size == 0) {
            return true;
        }
        BTInOrderIterator<Data> it1(*this);
        BTInOrderIterator<Data> it2(bst);
        while(!it1.Terminated() && !it2.Terminated()) {
            if(*it1 != *it2) {
                return false;
            }
            ++it1;
            ++it2;
        }
        if(it1.Terminated() && it2.Terminated()) {
            return true;
        }
        return false;
    }
}

template <typename Data>
bool BST<Data>::operator!=(const BST<Data>& bst) const noexcept {
    return !(*this == bst);
}

// Specific Functions - BST

template <typename Data>
const Data& BST<Data>::Min() const {
    if(root != nullptr) {
        return FindPointerToMin(root)->elem;
    } else {
        throw std::length_error("EXC - Empty BST!");
    }
}


template <typename Data>
Data BST<Data>::MinNRemove() {
    if(root != nullptr) {
       return DataNDelete(DetachMin(root));
    } else {
        throw std::length_error("EXC - Empty BST!");
    }
}


template <typename Data>
void BST<Data>::RemoveMin() {
    if(root != nullptr) {
        delete DetachMin(root);
    } else {
        throw std::length_error("EXC - Empty BST!");
    }
}


template <typename Data>
const Data& BST<Data>::Max() const {
    if(root != nullptr) {
        return FindPointerToMax(root)->elem;
    } else {
        throw std::length_error("EXC - Empty BST!");
    }
}


template <typename Data>
Data BST<Data>::MaxNRemove() {
    if(root != nullptr) {
        return DataNDelete(DetachMax(root));
    } else {
        throw std::length_error("EXC - Empty BST!");
    }
}


template <typename Data>
void BST<Data>::RemoveMax() {
    if(root != nullptr) {
        delete DetachMax(root);
    } else {
        throw std::length_error("EXC - Empty BST!");
    }
}


template <typename Data>
const Data& BST<Data>::Predecessor(const Data& data) const {
    NodeLnk* const * tmp = FindPointerToPredecessor(root, data);
    if(tmp != nullptr) {
        return (*tmp)->elem;
    } else {
        throw std::length_error("EXC - Element Not found!");
    }
}


template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& data) {
    NodeLnk** tmp = FindPointerToPredecessor(root, data);
    if(tmp != nullptr) {
        return DataNDelete(Detach(*tmp));
    } else {
        throw std::length_error("EXC - Element Not found!");
    }
}


template <typename Data>
void BST<Data>::RemovePredecessor(const Data& data) {
    NodeLnk** tmp = FindPointerToPredecessor(root, data);
    if(tmp != nullptr) {
        delete Detach(*tmp);
    } else {
        throw std::length_error("EXC - Element Not found!");
    }
}


template <typename Data>
const Data& BST<Data>::Successor(const Data& data) const {
    NodeLnk* const * tmp = FindPointerToSuccessor(root, data);
    if(tmp != nullptr) {
        return (*tmp)->elem;
    } else {
        throw std::length_error("EXC - Element Not found!");
    }
}


template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& data) {
    NodeLnk** tmp = FindPointerToSuccessor(root, data);
    if(tmp != nullptr) {
        return DataNDelete(Detach(*tmp));
    } else {
        throw std::length_error("EXC - Element Not found!");
    }
}


template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& data) {
    NodeLnk** tmp = FindPointerToSuccessor(root, data);
    if(tmp != nullptr) {
        delete Detach(*tmp);
    } else {
        throw std::length_error("EXC - Element Not found!");
    }
}


template <typename Data>
bool BST<Data>::Insert(const Data& data) {
    NodeLnk*& tmp = FindPointerTo(root, data);
    if(tmp == nullptr) {
        tmp = new NodeLnk(data);
        size++;
        return true;
    } else {
        return false;
    }
}


template <typename Data>
bool BST<Data>::Insert(Data&& data) noexcept {
    NodeLnk*& tmp = FindPointerTo(root, data);
    if(tmp == nullptr) {
        tmp = new NodeLnk(std::move(data));
        size++;
        return true;
    } else {
        return false;
    }
}


template <typename Data>
bool BST<Data>::Remove(const Data& data) {
    NodeLnk*& tmp = FindPointerTo(root, data);
    if(tmp != nullptr) {
        delete Detach(tmp);
        return true;
    } else {
        return false;
    }
}


template <typename Data>
bool BST<Data>::Exists(const Data& data) const noexcept {
    return (FindPointerTo(root, data) != nullptr);
}

template <typename Data>
void BST<Data>::Clear() { 
    BinaryTreeLnk<Data>::Clear();
}


template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* node) {
    Data data {};
    std::swap(data, node->elem);
    delete node;
    return data;
}


template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& node) noexcept {
    if(node != nullptr) {
        if(node->left == nullptr) {
            return Skip2Right(node);
        } else if(node->right == nullptr) {
            return Skip2Left(node);
        } else {
            NodeLnk* tmp = DetachMax(node->left);
            std::swap(node->elem, tmp->elem);
            return tmp;
        }
    }
    return nullptr;
}


template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& node) noexcept {
    return Skip2Right(FindPointerToMin(node));
}


template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& node) noexcept {
    return Skip2Left(FindPointerToMax(node));
}


template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& node) noexcept {
    NodeLnk* tmp = nullptr;
    if(node != nullptr) {
        std::swap(tmp, node->left);
        std::swap(tmp, node);
        size--;
    }
    return tmp;
}


template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& node) noexcept {
    NodeLnk* tmp = nullptr;
    if(node != nullptr) {
        std::swap(tmp, node->right);
        std::swap(tmp, node);
        size--;
    }
    return tmp;
}


template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerToMin(node));
}


template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMin(NodeLnk* const & node) const noexcept {
    NodeLnk* const * tmp = &node;
    NodeLnk* cur = node;
    if(cur != nullptr) {
        while(cur->left != nullptr) {
            tmp = &cur->left;
            cur = cur->left;
        }
    }
    return *tmp;
}


template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerToMax(node));
}


template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMax(NodeLnk* const & node) const noexcept {
    NodeLnk* const * tmp = &node;
    NodeLnk* cur = node;
    if(cur != nullptr) {
        while(cur->right != nullptr) {
            tmp = &cur->right;
            cur = cur->right;
        }
    }
    return *tmp;
}


template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerTo(node, data));
}


template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerTo(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * tmp = &node;
    if(*tmp != nullptr) {
        if(node->elem == data) {
            return *tmp;
        }
        else if(node->elem < data) {
            tmp = &(FindPointerTo(node->right, data));
        }
        else {
            tmp = &(FindPointerTo(node->left, data));
        }
    }
    return *tmp;
}


template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk* *>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(node, data));
}


template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToPredecessor(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * cur = &node;
    NodeLnk* const * tmp = nullptr;
    while(*cur != nullptr && (*cur)->elem != data) {
        if((*cur)->elem < data) {
            tmp = cur; 
            cur = &((*cur)->right);
        }
        else if((*cur)->elem > data) {
            cur = &((*cur)->left);
        }
    }
    if(*cur != nullptr && (*cur)->HasLeftChild()) {
        return &FindPointerToMax((*cur)->left);
    }
    return tmp;
}


template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToSuccessor(NodeLnk*& node, const Data& data) noexcept {
    return const_cast<NodeLnk* *>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(node, data));
}


template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToSuccessor(NodeLnk* const & node, const Data& data) const noexcept {
    NodeLnk* const * cur = &node;
    NodeLnk* const * tmp = nullptr;
    while(*cur != nullptr && (*cur)->elem != data) {
        if((*cur)->elem > data) {
            tmp = cur;
            cur = &((*cur)->left);
        }
        else if((*cur)->elem < data) {
            cur = &((*cur)->right);
        }
    }
    if(*cur != nullptr && (*cur)->HasRightChild()) {
        return &FindPointerToMin((*cur)->right);
    }
    return tmp;
}

/* ************************************************************************** */

}
