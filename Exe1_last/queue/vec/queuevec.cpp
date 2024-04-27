
namespace lasd {

/* ************************************************************************** */

//Specific Constructor - QueueVec
    template <typename Data>
    QueueVec<Data>::QueueVec(const TraversableContainer<Data>& container){
        try{
            head = 0;
            size = container.Size();
            elements = new Data[size];

            container.Traverse(
                [this](const Data& data){
                    Enqueue(data);
                }
            );
        }catch(std::bad_alloc& exception){
            std::cerr << "EXC - Cannot allocate memory for queue: " << exception.what();
        }
    }


    template <typename Data>
    QueueVec<Data>::QueueVec(MappableContainer<Data> &&container){
        try{
            head = 0;
            size = container.Size();
            elements = new Data[size];

            container.Map(
                [this](Data &data){
                    Enqueue(std::move(data));
                }
            );
        }catch(std::bad_alloc &exception){
            std::cerr << "EXC - Cannot allocate memory for queue: " <<  exception.what();
        }
    }


/* ************************************************************************** */

//Copy and Move Assignment - QueueVec
    template <typename Data>
    QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& queueVec){
        if(this != &queueVec){
            head = queueVec.head;
            tail = queueVec.tail;
            Vector<Data>::operator=(queueVec);
        }
        return *this;
    }   
    
    template <typename Data>  
    QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& queueVec) noexcept{
        if(this != &queueVec){
            std::swap(head, queueVec.head);
            std::swap(tail, queueVec.tail);
            Vector<Data>::operator=(std::move(queueVec));
        }

        return *this;
    }

/* ************************************************************************** */

//Comparison operators - QueueVec
    template <typename Data>
    bool QueueVec<Data>::operator==(const QueueVec& queueVec) const noexcept{
        if(this == &queueVec){
            return true;
        }

        if(Size() != queueVec.Size()){
            return false;
        }

        unsigned long idx1 = head;
        unsigned long idx2 = queueVec.head;

        while(idx1 < Size()){
            if(elements[idx1] != queueVec.elements[idx2]){
                return false;
            }

            ++idx1 %= size;
            ++idx2 %= size;
        }

        return true;
    }

    template <typename Data>
    bool QueueVec<Data>::operator!=(const QueueVec &queueVec) const noexcept{
        return !(*this == queueVec);
    }

/* ************************************************************************** */

//Specific Functions - QueueVec
    template <typename Data>
    const Data& QueueVec<Data>::Head()const{
        if(head == tail){
            throw std::length_error("EXC - Empty queue");
        }

        return elements[head];
    }

    template <typename Data>
    Data& QueueVec<Data>::Head(){
        if(head == tail){
            throw std::length_error("EXC - Empty queue");
        }

        return elements[head];
    }

    template <typename Data>
    void QueueVec<Data>::Dequeue(){
        if(head == tail){
            throw std::length_error("EXC - Empty queue");
        }

        Reduce();    
        ++head %= size;
    } 

    template <typename Data>
    Data QueueVec<Data>::HeadNDequeue(){
        if(head == tail){
            throw std::length_error("[EXCEPTION] Queue is empty");
        }

        Reduce();
        Data data(std::move(elements[head]));
        
        ++head %= size;
        return data;
    } 

    template <typename Data>
    void QueueVec<Data>::Enqueue(const Data& data){
        Expand();
        elements[tail++] = data;
        
        tail %= size;
    } 

    template <typename Data>
    void QueueVec<Data>::Enqueue(Data&& data) noexcept{
        Expand();
        elements[tail++] = std::move(data);
        
        tail %= size;
    }

/* ************************************************************************** */

//Specific Function inherited from Container - QueueVec
template <typename Data>
bool QueueVec<Data>::Empty() const noexcept{
    return (head == tail);
}

template <typename Data>
unsigned long QueueVec<Data>::Size() const noexcept{
    return (((size + tail) - head) % size);
}

/* ************************************************************************** */
//Specific Functions inherited from ClearableContainer - QueueVec

    template <typename Data>
    void QueueVec<Data>::Clear(){
        Vector<Data>::Resize(5);
        head = 0;
        tail = 0;
    }

/* ************************************************************************** */

//Auxiliary Functions - QueueVec
    template<typename Data>
    void QueueVec<Data>::Expand(){
        unsigned long length = Size();
        if(length + 1 == size){
            Resize(size * 2, length);
        }
    }

    template<typename Data>
    void QueueVec<Data>::Reduce(){
        unsigned long length = Size();
        if(length + 1 == (size / 4)){
            Resize(size/2, length);
        }
    }

    template<typename Data>
    void QueueVec<Data>::Resize(unsigned long newSize, unsigned long length){
        try{
            Data *tmp = new Data[newSize];
        
            unsigned long max = (length <= newSize) ? length : newSize;

            unsigned long index1 = head;
            unsigned long index2 = 0;
            while (index2 < max){
                std::swap(elements[index1], tmp[index2]);

                ++index1 %= size;
                index2++;
            }

            std::swap(elements, tmp);
            delete[] tmp;
            
            head = 0;
            tail = length;
            size = newSize;
        }catch(std::bad_alloc& exception){
            std::cerr << "EXC - Cannot allocate memory for queue: " <<  exception.what();
        }
    }

}
