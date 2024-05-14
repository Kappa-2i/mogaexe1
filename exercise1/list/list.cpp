#include "list.hpp"
namespace lasd {

/* ************************************************************************** */

//Specific Constructor - Node
    template <typename Data>
    List<Data>::Node::Node(const Data& data){
        element = data;
        next = nullptr;
    }

    template <typename Data>
    List<Data>::Node::Node(Data&& data) noexcept {
        std::swap(element, data);
        next = nullptr;
    }

/* ************************************************************************** */

//Copy and Move Constructor - Node
    template <typename Data>
    List<Data>::Node::Node(const Node& node){
        element = node.element;
        next = nullptr;
    }

    template <typename Data>
    List<Data>::Node::Node(Node&& node) noexcept {
        std::swap(element, node.element);
        std::swap(next, node.next);
    }

/* ************************************************************************** */

//Copy and Move Assignment - Node
    template <typename Data>
    typename List<Data>::Node& List<Data>::Node::operator=(const Node& node) {
        if(this != node){
            element = node.element;
            next = node.next;
        }
        return* this;
    }

    template<typename Data>
    typename List<Data>::Node& List<Data>::Node::operator=(Node &&node) noexcept{
        if(this != &node){
        std::swap(element, node.element);
        std::swap(next, node.next);
        }
        return *this;
    }
/* ************************************************************************** */

//Destructor - Node
    template <typename Data>
    List<Data>::Node::~Node(){
        delete next;
    }

/* ************************************************************************** */

//Comparison operator - Node
    template <typename Data>
    bool List<Data>::Node::operator==(const Node& node) const noexcept{
        return (element == node.element) &&
                ((next == nullptr && node.next == nullptr) ||
                ((next != nullptr && node.next != nullptr) && *next == *(node.next)));
    }

    template<typename Data>
    bool List<Data>::Node::operator!=(const Node &node)const noexcept{
        return !(*this == node);
    }

/* ************************************************************************** */

//Specific Constructor - List
    template <typename Data>
    List<Data>::List(const TraversableContainer<Data>& container){
        head = nullptr;
        tail = nullptr;
        container.Traverse(
            [this](const Data& data){
                InsertAtBack(data);
            }
        );
    }

    template <typename Data>
    List<Data>::List(MappableContainer<Data>&& container){
        head = nullptr;
        tail = nullptr;
        container.Map(
            [this](Data& data){
                InsertAtBack(std::move(data));
            }
        );
    }

/* ************************************************************************** */

//Copy and Move Constructor - List
    template <typename Data>
    List<Data>::List(const List& list){
        if(this != &list){
            if(list.head != nullptr){
                for (Node* curr=list.head; curr!=nullptr ; curr=curr->next) {
                    InsertAtBack(curr->element);
                }
            }
        }
    }

    template <typename Data>
    List<Data>::List(List&& list) noexcept{
        if(this != &list){
            std::swap(head, list.head);
            std::swap(tail, list.tail);
            std::swap(size, list.size);
        }
    }
/* ************************************************************************** */

//Copy and Move assignment - List
    template <typename Data>
    List<Data>& List<Data>::operator=(const List<Data>& list) {
        if(this != &list){
            try{
                List<Data>* temp = new List<Data>(list);
                std::swap(*temp, *this);
                delete temp;
            }catch(std::bad_alloc& exception){
                std::cerr << "EXC - Cannot allocate memory for lis :" << exception.what();
            }
        }
        return* this;
    }

    template<typename Data>
    List<Data>& List<Data>::operator=(List<Data> &&list) noexcept{
        if(this != &list){
            std::swap(head, list.head);
            std::swap(tail, list.tail);
            std::swap(size, list.size);
        }
        return *this;
    }

/* ************************************************************************** */

//Destructor - List
    template <typename Data>
    List<Data>::~List(){
        delete head;
        head = tail = nullptr;
        size = 0;
    }

/* ************************************************************************** */

//Comparison operator - List
    template<typename Data>
    bool List<Data>::operator==(const List<Data> &list) const noexcept{
        if(this == &list){
            return true;
        }

        if(size != list.size){
            return false;
        }

        return (size == list.size) &&
        ((head == nullptr && list.head == nullptr) ||
        ((head != nullptr && list.head != nullptr) && (*head == *(list.head))));
    }

    template<typename Data>
    bool List<Data>::operator!=(const List<Data> &list) const noexcept{
        return !(*this == list);
    }

/* ************************************************************************** */

//Specific Function - List
    template <typename Data>
    void List<Data>::InsertAtFront(const Data& data) {
        try{
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
            if(tail == nullptr){
                tail = newNode;
            }
            size++;
        }catch (std::bad_alloc& exception){
            std::cerr << "EXC - Cannot allocate memory for list: " << exception.what();
        }
    }

    template <typename Data>
    void List<Data>::InsertAtFront(Data&& data) noexcept {
        try{
            Node* newNode = new Node(std::move(data));
            newNode->next = head;
            head = newNode;
            if(tail == nullptr){
                tail = newNode;
            }
            size++;
        }catch (std::bad_alloc& exception){
            std::cerr << "EXC - Cannot allocate memory for list: " << exception.what();
        }
    }

    template <typename Data>
    void List<Data>::RemoveFromFront(){
        if(head == nullptr){
            throw std::length_error("EXC - Empty list");
        }
        Node* temp = head;
        if(head == tail){
            head = tail = nullptr;
        }
        else{
            head = head->next;
        }
        size--;
        temp->next = nullptr;
        delete temp;
    }

    template<typename Data>
    Data List<Data>::FrontNRemove(){
        if(head == nullptr){
            throw std::length_error("EXC - Empty list");
        }

        Data data = head->element;
        List<Data>::RemoveFromFront();

        return data;
    }

    template <typename Data>
    void List<Data>::InsertAtBack(const Data& data) {
        try{
            Node* newNode =  new Node(data);
            if(tail == nullptr){
                head = newNode;
            }
            else{
                tail->next = newNode;
            }
            tail = newNode;
            size++;
        }catch (std::bad_alloc& exception){
            std::cerr << "EXC - Cannot allocate memory for list: " << exception.what();
        }
    }

    template<typename Data>
    void List<Data>::InsertAtBack(Data &&data) noexcept {
        try{
            Node * newNode = new Node(std::move(data));
            if(head == nullptr){
                head = newNode;
            }
            else{
                tail->next = newNode;
            }
            tail = newNode;
            size++;
        }catch(std::bad_alloc &exception){
            std::cerr << "[EXCEPTION] Cannot allocate memory for List: " <<  exception.what();
        }
    }
/* ************************************************************************** */

//Specific Function inherited from ClearableContainer - List
    template<typename Data>
    void List<Data>::Clear(){
        size = 0;
        delete head;
        head = tail = nullptr;
    }

/* ************************************************************************** */

//Specific Function inherited from DictionaryContainer - List
    template <typename Data>
    bool List<Data>::Insert(const Data& data){
        for(Node* temp=head; temp!=nullptr; temp = temp->next){
            if(temp->element == data){
                return false;
            }
        }
        InsertAtBack(data);
        return true;
    }

    template <typename Data>
    bool List<Data>::Insert(Data&& data){
        for(Node* temp = head; temp  != nullptr; temp = temp->next){
            if(temp->element == data){
                return false;
            }
        }
        InsertAtBack(std::move(data));
        return true;
    }

    template <typename Data>
    bool List<Data>::Remove(const Data& data){
        if(head == nullptr){
            return false;
        }
        if(head->element == data){
            RemoveFromFront();
            return true;
        }
        Node* prev = head;
        Node* curr = head->next;
        while(curr != nullptr && curr->element != data){
            prev = curr;
            curr = curr->next;
        }
        if(curr != nullptr){
            Node* temp = curr;
            prev->next = curr->next;
            if(tail == curr){
                tail = prev;
            }
            temp->next = nullptr;
            delete temp;
            size--;
            return true;
        }
        return false;
    }
/* ************************************************************************** */

//Specific Function inherited from LinearContainer - List
    template<typename Data>
    const Data& List<Data>::operator[](const unsigned long int index) const {
        if(index >= size){
            throw std::out_of_range("EXC - Index out of range");
        }

        if(index == size - 1){
            return tail->element;
        }

        Node *curr = head;
        for(unsigned long i = 0; i < index ; i++, curr = curr->next){}

        return curr->element;
    }

    template<typename Data>
    Data& List<Data>::operator[](const unsigned long int index) {
        if(index >= size){
            throw std::out_of_range("EXC - Index out of range");
        }

        if(index == size - 1){
            return tail->element;
        }

        Node *curr = head;
        for(unsigned long i = 0; i < index ; i++, curr = curr->next){}

        return curr->element;
    }

    template<typename Data>
    const Data& List<Data>::Front() const{
        if(head != nullptr){
            return head->element;
        }

        throw std::length_error("EXC - Empty list");
    }

    template<typename Data>
    Data& List<Data>::Front(){
        if(head != nullptr){
            return head->element;
        }

        throw std::length_error("EXC - Empty list");
    }

    template<typename Data>
    const Data& List<Data>::Back() const{
        if(tail != nullptr){
            return tail->element;
        }

        throw std::length_error("EXC - Empty list");
    }

    template<typename Data>
    Data& List<Data>::Back(){
        if(tail != nullptr){
            return tail->element;
        }

        throw std::length_error("EXC - Empty list");
    }
/* ************************************************************************** */

//Specific Function inherited from TraversableContainer - List
    template<typename Data>
    void List<Data>::Traverse(TraverseFun fun) const{
        PreOrderTraverse(fun, head);
    }

    template<typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun) const{
        PreOrderTraverse(fun, head);
    }

    template<typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun fun) const{
        PostOrderTraverse(fun, head);
    }

/* ************************************************************************** */

//Specific Function inherited from MappableContainer - List
    template<typename Data>
    void List<Data>::Map(MapFun fun){
        PreOrderMap(fun, head);
    }

    template<typename Data>
    void List<Data>::PreOrderMap(MapFun fun){
        PreOrderMap(fun, head);
    }

    template<typename Data>
    void List<Data>::PostOrderMap(MapFun fun){
        PostOrderMap(fun, head);
    }

/* ************************************************************************** */
//Auxiliary Function - List
    template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun, Node* node) const{
        if(node != nullptr){
            fun(node->element);
            PreOrderTraverse(fun, node->next);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun fun, Node* node) const{
        if(node != nullptr){
            PostOrderTraverse(fun, node->next);
            fun(node->element);
        }
    }


    template <typename Data>
    void List<Data>::PreOrderMap(MapFun fun, Node* node) const {
        if(node != nullptr){
            fun(node->element);
            PreOrderMap(fun, node->next);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderMap(MapFun fun, Node* node) const{
        if(node != nullptr){
            PostOrderMap(fun, node->next);
            fun(node->element);
        }
    }
}
