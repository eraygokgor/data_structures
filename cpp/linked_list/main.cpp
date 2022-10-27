#include <iostream>

using namespace std;

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
    Node<T*> findPrevious(const T& data);
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
Node<T*> List<T>::findPrevious(const T& data) {
    Node<T>* p = zeroth();
    while (p->next) {
        if (p->next->element==data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}



int main() {

    return 0;
}
