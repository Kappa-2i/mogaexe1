namespace lasd {

/* ************************************************************************** */

// Specific Constructor - NodeVec

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data & data, unsigned long idx, Vector<NodeVec*> *v) {
    elem = data;
    curr = idx;
    vecptr = v;
}

/* ************************************************************************** */

// Copy and Move Assignment - NodeVec

template<typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& node) {
  elem = node.elem;
  curr = node.curr;
  vecptr = node.vecptr;
  return* this;
}

// Move assignment
template<typename Data>
BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& node) noexcept {
  std::swap(elem, node.elem);
  std::swap(curr, node.curr);
  std::swap(vecptr, node.vecptr);
  return *this;
}

/* ************************************************************************** */

// Comparison Operators - NodeVec
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator==(const NodeVec& node) const noexcept{
    return BinaryTree<Data>::Node::operator==(node);
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::operator!=(const NodeVec& node) const noexcept{
    return BinaryTree<Data>::Node::operator!=(node);
}

/* ************************************************************************** */

// Specific Member Functions - NodeVec

template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return elem;
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return elem;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return (!HasLeftChild() && !HasRightChild());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return ((2*curr+2) < vecptr->Size());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return ((2*curr+1) < vecptr->Size());
}


template <typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if(HasRightChild()) {
        return *(vecptr->operator[](2*curr+2));
    } else {
        throw std::out_of_range("EXC - No Right Child!");
    }
}


template <typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if(HasLeftChild()) {
        return *(vecptr->operator[](2*curr+1));
    } else {
        throw std::out_of_range("EXC - No Left Child!");
    }
}

template <typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(HasRightChild()) {
        return *(vecptr->operator[](2*curr+2));
    } else {
        throw std::out_of_range("Right child does not exists!");
    }
}

template <typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(HasLeftChild()) {
        return *(vecptr->operator[](2*curr+1));
    } else {
        throw std::out_of_range("Left child does not exists!");
    }    
}




/* ************************************************************************** */

// Specific Constructor - BinaryTreeVec
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& con) {
    size = con.Size();
    if(size > 0) {
        vec = new Vector<NodeVec*>(size);
        unsigned long index = 0;
        con.Traverse([this, &index](const Data& data) {
            NodeVec* node = new NodeVec(data, index, vec);
            vec->operator[](index) = node;
            index++;
        });
    }
}


template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& con) noexcept {
    size = con.Size();
    if(size > 0) {
        vec = new Vector<NodeVec*>(size);
        unsigned long index = 0;
        con.Map([this, &index](Data& data) {
            NodeVec* node = new NodeVec(data, index, vec);
            vec->operator[](index) = node;
            index++;
        });
    } 
}

/* ************************************************************************** */

//Copy and Move Constructor - BinaryTreeVec

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& btv) {
    size = btv.Size();
    if(size > 0) {
        vec =  new Vector<NodeVec*>(size);
        for(unsigned long i=0; i<size; i++) {
            NodeVec* tmp = new NodeVec(btv.vec->operator[](i)->Element(), i, vec);
            vec->operator[](i) = tmp;
        }
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& btv) noexcept {
    std::swap(size, btv.size);
    std::swap(vec, btv.vec);
}

/* ************************************************************************** */

//Destructor - BinaryTreeVec

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {
    Clear();
    delete vec;
    vec = nullptr;
}


/* ************************************************************************** */

//Copy and Move Assignment - BinaryTreeVec

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& btvec) {
    BinaryTreeVec<Data>* tmp = new BinaryTreeVec<Data>(btvec);
    std::swap(*this, *tmp);
    delete tmp;
    return* this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& btvec) noexcept {
    std::swap(size, btvec.size);
    std::swap(vec, btvec.vec);
    return* this;
}

/* ************************************************************************** */

//Specific Member Function - BinaryTreeVec

template <typename Data>
const typename BinaryTree<Data>::Node& BinaryTreeVec<Data>::Root() const {
    if(size > 0) {
        return *(vec->operator[](0));
    } 
    else {
        throw std::length_error("EXC - Empty tree!");
    }
}

template <typename Data>
typename MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::Root() {
    if(size > 0) {
        return *(vec->operator[](0));
    } 
    else {
        throw std::length_error("EXC - Empty tree!");
    }
}

template <typename Data>
void BinaryTreeVec<Data>::Clear() {
    if(size > 0) {
        for(unsigned long i = 0; i < size; i++) {
            if(vec->operator[](i) != nullptr) {
                delete (*vec)[i];
            }
        }
        vec->Clear();
        size = 0;
    }
}


template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const {
    for(unsigned long i=0; i<size; i++) {
        if(vec->operator[](i) != nullptr) {
            fun(vec->operator[](i)->Element());
        }
        
    }
}


template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun fun) {
    for(unsigned long i=0; i<size; i++) {
        if(vec->operator[](i) != nullptr) {
            fun(vec->operator[](i)->Element());
        }
    }
}


/* ************************************************************************** */
}
