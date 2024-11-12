#include "List.h"
#include<iostream>
using namespace std;
template <typename T>
List<T>::List() : size(0), head(nullptr), tail(nullptr) {}

template <typename T>
List<T>::List(long size) : size(size), head(nullptr), tail(nullptr) {
    assert(this->size >= 0);
}

template <typename T>
List<T>::~List() {
    Erase();
}

template <typename T>
void List<T>::Erase() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;
}

template <typename T>
T& List<T>::operator[](int index) {
    assert(index >= 0 && index < this->size);  
    Node<T>* current = head;
    for (int i = 0; i < index; ++i)
        current = current->next;  
    return current->data;        
}

template <typename T>
const T& List<T>:: operator[](int index) const {
        assert(index >= 0 && index < size);  
        Node<T>* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        return current->data;
    }

template <typename T>
int List<T>::GetSize() const {
    return this->size;
}

template <typename T>
void List<T>::Insert(T value, int index) {
    assert(index >= 0 && index <= this->size);  
    Node<T>* newNode = new Node<T>(value);       
    if (index == 0) {
        newNode->next = head;                    
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        if (tail == nullptr)
            tail = head;
    } else {
        Node<T>* current = head;
        for (int i = 0; i < index - 1; ++i)
            current = current->next;
        newNode->next = current->next;
        if (current->next != nullptr)
            current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
        if (newNode->next == nullptr)
            tail = newNode;  
    }
    ++size;
}

template <typename T>
void List<T>::InsertFirst(T value) {
    Insert(value, 0);  
}

template <typename T>
void List<T>::InsertLast(T value) {
    Insert(value, this->size);  
}

template <typename T>
void List<T>::Remove(int index) {
    assert(index >= 0 && index < this->size);  
    Node<T>* del = head;
    if (index == 0) {
        head = head->next;           
        if (head != nullptr)
            head->prev = nullptr;
        if (del == tail)
            tail = nullptr;
    } else {
        for (int i = 0; i < index; ++i)
            del = del->next;
        del->prev->next = del->next;
        if (del->next != nullptr)
            del->next->prev = del->prev;
        if (del == tail)
            tail = del->prev;        
    }
    delete del;  
    --size;
}

template <typename T>
ostream& operator<<(ostream& os, const List<T>& list) {
    os << "List = ";
    Node<T>* current = list.head;
    while (current != nullptr) {
        os << current->data << " ";  
        current = current->next;
    }
    os << endl;
    return os;
}

template <typename T>
void List<T>::Show() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->data << " ";  
        current = current->next;
    }
    cout << endl;
}
