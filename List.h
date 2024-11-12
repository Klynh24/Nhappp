#include<iostream>
template <typename T>
class List {
private:
    long size;
    Node<T>* head;
    Node<T>* tail;

public:
    List();
    List(long);
    ~List();
    void Erase();
    T& operator[](int index);  
    const T& operator[](int index) const;
    int GetSize() const;
    void Insert(T value, int index);
    void Remove(int index);
    void InsertFirst(T value);
    void InsertLast(T value);
    friend ostream& operator<<(ostream&, const List<T>&);
    void Show();
};
