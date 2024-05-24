
namespace lasd {

/* ************************************************************************** */

//Copy and Move Assignment - QueueLst
    template<typename Data>
    QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& queueLst){
        List<Data>::operator=(queueLst);
        return *this;
    }

    template<typename Data>
    QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& queueLst) noexcept{
        List<Data>::operator=(std::move(queueLst));
        return *this;
    }

/* ************************************************************************** */

//Comparison Operators - QueueLst
    template<typename Data>
    bool QueueLst<Data>::operator==(const QueueLst<Data> &queueLst) const noexcept{
        return List<Data>::operator==(queueLst);
    }

    template<typename Data>
    bool QueueLst<Data>::operator!=(const QueueLst<Data> &queueLst) const noexcept{
        return List<Data>::operator!=(queueLst);
    }

/* ************************************************************************** */

//Specific Function - QueueLst
    template<typename Data>
    const Data& QueueLst<Data>::Head() const{
        return  List<Data>::Front();
    }

    template<typename Data>
    Data& QueueLst<Data>::Head(){
        return  List<Data>::Front();
    }

    template<typename Data>
    void QueueLst<Data>::Dequeue(){
        List<Data>::RemoveFromFront();
    }

    template<typename Data>
    Data QueueLst<Data>::HeadNDequeue(){
        return List<Data>::FrontNRemove();
    }

    template<typename Data>
    void QueueLst<Data>::Enqueue(const Data& data){
        List<Data>::InsertAtBack(data);
    }
    template<typename Data>
    void QueueLst<Data>::Enqueue(Data&& data){
        List<Data>::InsertAtBack(std::move(data));
    }
}