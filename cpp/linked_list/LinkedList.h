#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H
#include <iostream>

// Node
template <class T>
class Node {
public:
    Node(const T& e = T(), Node *n = NULL):
            element(e), next(n) { }
    T element;
    Node *next;
};

template <class T>
class List {
private:
    Node<T> *dummyHead;
public:
    List() {
        dummyHead = new Node<T>(T(), NULL);
    }
    Node<T>* zeroth() {
        return dummyHead;
    }
    Node<T>* first() {
        return dummyHead->next;
    }
    const Node<T>* first() const {
        return dummyHead->next;
    }
    bool isEmpty() const {first() == NULL;}

    void insert(const T& data, Node<T>* p);
    Node<T>* find(const T& data);
    Node<T>* findPrevious(const T& data);
    void remove(const T& data);
    void print() const;
    void makeEmpty();
    ~List();
    List& operator=(const List& rhs);
    List(const List& rhs);
};

#endif //LINKED_LIST_LINKEDLIST_H
