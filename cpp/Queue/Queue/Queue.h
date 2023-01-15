#ifndef Queue_h
#define Queue_h
#include <iostream>

template<class T>
class queueNode {
public:
    queueNode(const T& e=T(), queueNode* n=NULL):
    element(e), next(n) {}
    
    T element;
    queueNode* next;
};

template<class T>
class Queue {
public:
    Queue();
    Queue(const Queue& rhs);
    ~Queue();
    Queue& operator=(const Queue & rhs);

    bool isEmpty() const;
    void enqueue(const T& newItem);
    void dequeue();
    void dequeue(T& queueFront);
    void getFront(T& queueFront) const;
private:
    queueNode<T> *backPtr;
    queueNode<T> *frontPtr;
};

template<class T>
Queue<T>::Queue() : backPtr(NULL), frontPtr(NULL){}

template<class T>
Queue<T>::~Queue() {
   while (!isEmpty())
      dequeue();
}

template<class T>
bool Queue<T>::isEmpty() const{
   return backPtr == NULL;
}

template<class T>
void Queue<T>::enqueue(const T& newItem) {
    queueNode<T>* newNode = new queueNode<T>(newItem, NULL);
    if (isEmpty()){
        frontPtr = newNode;
    }
    else {
        backPtr->next = newNode;
    }
    backPtr = newNode;
}

template<class T>
void Queue<T>::dequeue() {
    if (!isEmpty()){
        queueNode<T>* tmp = frontPtr;
        if (frontPtr == backPtr) {
            frontPtr = NULL;
            backPtr = NULL;
        }
        else {
            frontPtr = frontPtr->next;
        }
        tmp->next = NULL;
        delete tmp;
    }
}

template<class T>
void Queue<T>::dequeue(T& queueFront) {
   if (!isEmpty()) {      // queue is not empty; retrieve front
      queueFront = frontPtr->element;
      dequeue();
   }
}

template<class T>
void Queue<T>::getFront(T& queueFront) const {
    if(!isEmpty()) {
        queueFront = frontPtr->element;
    }
}

#endif /* Queue_h */
