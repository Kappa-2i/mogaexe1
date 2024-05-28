
namespace lasd {

/* ************************************************************************** */

/* ************************************************************************** */

// Specific Constructors - HashTableClsAdr

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize) {
    if(givenSize < 127) {
        givenSize = MIN_TABLESIZE;
    }
    if(givenSize >= 10000) {
        givenSize = MAX_TABLESIZE;
    }
    if(givenSize != MIN_TABLESIZE && givenSize != MAX_TABLESIZE) {
        givenSize = FindNextPrime(givenSize);   
    }
    tablesize = givenSize;
    table = new Vector<BST<Data>>{};
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& container){
    //se minore la dimensione della tabella non cambia
    if(container.Size() > tablesize){
        table.Resize(container.Size());
        tablesize = container.Size();
    }
    InsertAll(container);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize, const TraversableContainer<Data>& container){
    table.Resize(givenSize);
    std::swap(tablesize, givenSize);
    InsertAll(container);
}


template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& container){
    if(container.Size() > tablesize){
        table.Resize(container.Size());
        tablesize = container.Size();
    }
    InsertAll(std::move(container));
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long givenSize, MappableContainer<Data>&& container){
    table.Resize(givenSize);
    std::swap(tablesize, givenSize);
    InsertAll(std::move(container));
}

/* ************************************************************************** */

// Copy and Move Constructors - HashTableClsAdr

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& ht) : HashTable<Data>(ht) {
    table.Resize(ht.tablesize);
    for (unsigned long i = 0; i < ht.tablesize; i++){
        table[i] = ht.table[i];
    }
    size = ht.size;
    tablesize = ht.tablesize;
    a = ht.a;
    b = ht.b;
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& ht) noexcept : HashTable<Data>(std::move(ht)) {
    table.Resize(ht.tablesize);
    std::swap(table, ht.table);
    std::swap(size, ht.size);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
}

/* ************************************************************************** */

// Copy and Move Assigments - HashTableClsAdr

template<typename Data>
HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator = (const HashTableClsAdr<Data>& ht){
    HashTableClsAdr<Data>* tmpht = new HashTableClsAdr(ht);
    std::swap(*this, *tmpht);
    delete tmpht;
    return *this;
}

template<typename Data>
HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator = (HashTableClsAdr<Data>&& ht) noexcept{
    std::swap(size, ht.size);
    std::swap(table, ht.table);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    return *this;
}

/* ************************************************************************** */

// Copy and Move Assigments - HashTableClsAdr

template<typename Data>
bool HashTableClsAdr<Data>::operator == (const HashTableClsAdr<Data>& ht) const noexcept{
    if(size == ht.size){
        for (unsigned long i = 0; i < tablesize; i++){
            BTPreOrderIterator it(ht.table[i]);
            
            for (; !it.Terminated(); ++it){
                unsigned long index = HashKey(*it);
                if(!table[index].Exists(*it)){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::operator != (const HashTableClsAdr<Data> & ht) const noexcept{
    return !(*this == ht);
}

/* ************************************************************************** */

// Specific Member Functions - HashTableClsAdr

template<typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data){
    unsigned long index = HashKey(data);
    if(table[index].Insert(data)){
        size++;
        return true;
    }
    return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data) noexcept{
    unsigned long index = HashKey(std::move(data));
    if(table[index].Insert(std::move(data))){
        size++;
        return true;
    }
    return false;
} 

template<typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data){
    unsigned long index = HashKey(data);
    if(table[index].Remove(data)){
        size--;
        return true;
    }
    return false;
}


template<typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept {

    for(unsigned long i = 0; i < tablesize; ++i){
        const BST<Data>& bst = table[i];
        BTPreOrderIterator it(bst);
        for (; !it.Terminated(); ++it) {
            unsigned long index = HashKey(*it);
            if(table[index].Exists(data)){
                return true;
            }
        }
    }
    return false;
}


template<typename Data>
void HashTableClsAdr<Data>::Resize(unsigned long newSize){
    if(newSize < 128){        
        newSize = MIN_TABLESIZE;
    }
    Vector<BST<Data>> table2(table);
    table.Clear();
    table.Resize(newSize);
    tablesize = newSize;
    size = 0;
    for (unsigned long i = 0; i < table2.Size(); i++){
        BTPreOrderIterator<Data> it(table2[i]);
        for (; !it.Terminated(); ++it){
            Insert(*it);
        }
    }
}


template<typename Data>
void HashTableClsAdr<Data>::Clear() {
    table.Clear();
    table.Resize(MIN_TABLESIZE);
    tablesize = MIN_TABLESIZE;
    size = 0;
}


template <typename Data>
unsigned long HashTableClsAdr<Data>::FindNextPrime(unsigned long val) const noexcept {
    for (ulong i = 2; i <= val/2; ++i) {
        if (val % i == 0) {
            val+=1;
            i = 2;
        }
    }
    return val;
}

/* ************************************************************************** */

}
