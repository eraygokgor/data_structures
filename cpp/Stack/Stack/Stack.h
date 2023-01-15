#ifndef Stack_h
#define Stack_h
#include <iostream>

template<class T>
class stackNode {
public:
    stackNode(const T &e=T(), stackNode *n=NULL):
    element(e), next(n) {}
    
    T element;
    stackNode* next;
};


template<class T>
class Stack {
public:
    Stack();
    Stack(const Stack& rhs);
    ~Stack();
    Stack& operator=(const Stack& rhs);
    
    bool isEmpty() const;
    void push(const T& newItem);
    void pop();
    void topAndPop(T& stackTop);
    void getTop(T& stackTop) const;
private:
    stackNode<T> *topPtr;
};

template<class T>
Stack<T>::Stack(): topPtr(NULL) {}

template<class T>
bool Stack<T>::isEmpty() const {
    return topPtr == NULL;
}

template<class T>
void Stack<T>::push(const T& newItem){
    stackNode<T>* newNode = new stackNode<T>(newItem, NULL);
    
    newNode->next = topPtr;
    topPtr = newNode;
}

template<class T>
void Stack<T>::pop() {
    if (!isEmpty()){
        stackNode<T>* tmp = topPtr;
        topPtr = topPtr->next;
        delete tmp;
    }
}

template<class T>
void Stack<T>::topAndPop(T& stackTop) {
    if (!isEmpty()){
        stackTop = topPtr->element;
        stackNode<T> *tmp = topPtr;
        topPtr = topPtr->next; // update the stack top
        delete tmp;
    }
}

template<class T>
void Stack<T>::getTop(T& stackTop) const{
    if (!isEmpty()){
        stackTop = topPtr->element;
    }
}

template<class T>
Stack<T>::~Stack(){
    while (!isEmpty()){
        pop();
    }
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& rhs) {
    if (this != &rhs) {
        if (!rhs.topPtr)
            topPtr = NULL;
        else {
            topPtr = new stackNode<T>;
            topPtr->element = rhs.topPtr->element;
            stackNode<T>* q = rhs.topPtr->next;
            stackNode<T>* p = topPtr;
            while (q) {
                p->next = new stackNode<T>;
                p->next->element = q->element;
                p = p->next;
                q = q->next;
            }
            p->next = NULL;
        }
    }
    return *this;
}

template <class T>
Stack<T>::Stack(const Stack& rhs) {
    *this = rhs;
}

#endif /* Stack_h */
