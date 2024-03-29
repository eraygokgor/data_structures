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
    bool isEmpty() const {return first() == NULL;}

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


// element inserter
template <class T>
void List<T>::insert(const T &data, Node<T> *p) {
    Node<T>* newNode = new Node<T>(data, p->next);
    p->next = newNode;
}

// element finder
template <class T>
Node<T>* List<T>::find(const T& data) {
    Node<T>* p = first();
    while (p) {
        if (p->element == data){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// previous finder
template <class T>
Node<T>* List<T>::findPrevious(const T& data) {
    Node<T>* p = zeroth();
    while (p->next) {
        if (p->next->element==data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// remove element found first
template <class T>
void List<T>::remove(const T &data) {
    Node<T>* p = findPrevious(data);

    if (p) {
        Node<T>* tmp = p->next;
        p->next = tmp->next;
        delete tmp;
    }
}

// print all elements
template <class T>
void List<T>::print() const {
    const Node<T>* p = first();

    while (p){
        std::cout<<p->element<<std::endl;
        p = p->next;
    }
}

// empty list
template <class T>
void List<T>::makeEmpty() {
    while (!isEmpty()){
        remove(first()->element);
    }
}

template<class T>
List<T>::~List() {
    makeEmpty();

    delete dummyHead;
}

// assignment operator
template <class T>
List<T>& List<T>::operator=(const List& rhs) {
    if (this != &rhs) {
        makeEmpty();
        const Node<T>* r = rhs.first();
        Node<T>* p = zeroth();

        while (r) {
            insert(r->element, p);
            r = r->next;
            p = p->next;
        }
    }
    return *this;
}

// copy constructor
template <class T>
List<T>::List(const List& rhs) {
    dummyHead = new Node<T>(T(), NULL);

    *this = rhs; // use operator
}



#endif //LINKED_LIST_LINKEDLIST_H
