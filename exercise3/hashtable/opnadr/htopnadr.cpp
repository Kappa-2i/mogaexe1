
namespace lasd {

/* ************************************************************************** */

// Default constructor - HashTableOpnAdr
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() {
    tablesize = MIN_SIZE;
    size = 0;
    a = 2*(dista(generator))+1;
    b = 2*(distb(generator));
    table.Resize(tablesize);
    statusVec.Resize(tablesize);
    for(unsigned long i=0; i<tablesize; i++) {
        statusVec[i] = 'E'; // Empty, Full, Removed
    }
    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
}

/* ************************************************************************** */

// Specific constructor - HashTableOpnAdr
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long siz) {
    size = 0;
    a = 2*(dista(generator))+1;
    b = 2*(distb(generator));
    tablesize = FindNext2Pow(siz);
    table.Resize(tablesize);
    statusVec.Resize(tablesize);
    for(unsigned long i=0; i<tablesize; i++) {
        statusVec[i] = 'E'; // Empty, Full, Removed
    }
    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& con) : HashTableOpnAdr() {
    InsertAll(con);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long siz, const TraversableContainer<Data>& con) : HashTableOpnAdr(siz) {
    InsertAll(con);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& con) : HashTableOpnAdr() {
    InsertAll(std::move(con));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long siz, MappableContainer<Data>&& con) : HashTableOpnAdr(siz) {
    InsertAll(std::move(con));
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
    capacity = ht.capacity;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& ht) noexcept {
    std::swap(size, ht.size);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(table, ht.table);
    std::swap(statusVec, ht.statusVec);
    std::swap(capacity, ht.capacity);
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
    std::swap(capacity, ht.capacity);
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

}
