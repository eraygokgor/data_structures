#ifndef AVLTree_h
#define AVLTree_h
#include <iostream>


template <class T>
class AvlNode
{
public:
    T element;
    AvlNode *left;
    AvlNode *right;
    int height;

    AvlNode(const T & theElement, AvlNode *lt = NULL, AvlNode *rt = NULL, int h = 0):
        element(theElement), left(lt), right(rt), height(h) {}
    
    int getHeight(const AvlNode<T> *t);
    void rotateWithLeftChild(AvlNode<T> *& k2);
    void rotateWithRightChild(AvlNode<T> *& k2);
    void doubleWithLeftChild(AvlNode<T> *& k3);
    void doubleWithRightChild(AvlNode<T> *& k3);
    void insert(const T& x, AvlNode<T> *& t);
    void preorderTraverse(AvlNode<T> *& t);
    void inorderTraverse(AvlNode<T> *& t);
    void postorderTraverse(AvlNode<T> *& t);
};

template<class T>
int AvlNode<T>::getHeight(const AvlNode<T> *t)
{
    return t == NULL ? -1 : t->height;
}

template<class T>
void AvlNode<T>::rotateWithLeftChild(AvlNode<T> *& k2){
    AvlNode<T> *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = std::max(getHeight(k2->left), getHeight(k2->right))+1;
    k1->height = std::max(getHeight(k1->left), k2->height) + 1;
    k2 = k1;
}

template<class T>
void AvlNode<T>::rotateWithRightChild(AvlNode<T> *& k2){
    AvlNode<T> *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = std::max(getHeight(k2->right), getHeight(k2->left))+1;
    k1->height = std::max(getHeight(k1->right), k2->height) + 1;
    k2 = k1;
}

template<class T>
void AvlNode<T>::doubleWithLeftChild(AvlNode<T> *& k3){
   rotateWithRightChild(k3->left);
   rotateWithLeftChild(k3);
}

template<class T>
void AvlNode<T>::doubleWithRightChild(AvlNode<T> *& k3){
   rotateWithLeftChild(k3->right);
   rotateWithRightChild(k3);
}

template<class T>
void AvlNode<T>::insert(const T& x, AvlNode<T> *& t){
    if(t == NULL) {
        t = new AvlNode<T>(x);
    }
    else if(x < t->element){
        insert(x, t->left);
        if(getHeight(t->left) - getHeight(t->right) == 2){
            if(x < t->left->element) {
                rotateWithLeftChild(t);
            }
            else {
                doubleWithLeftChild(t);
            }
        }
    }
    else if(t->element < x){
        insert(x, t->right);
        if(getHeight(t->right) - getHeight(t->left) == 2){
            if(t->right->element < x) {
                rotateWithRightChild(t);
            }
            else {
                doubleWithRightChild(t);
            }
        }
    }
    else {
        ;
    }
    t->height = std::max(getHeight(t->left), getHeight(t->right)) + 1;
}

template<class T>
void AvlNode<T>::preorderTraverse(AvlNode<T> *& t){
    if (t!=NULL){
        std::cout<<t->element<<std::endl;
        preorderTraverse(t->left);
        preorderTraverse(t->right);
    }
}

template<class T>
void AvlNode<T>::inorderTraverse(AvlNode<T> *& t){
    if (t!=NULL){
        inorderTraverse(t->left);
        std::cout<<t->element<<std::endl;
        inorderTraverse(t->right);
    }
}

template<class T>
void AvlNode<T>::postorderTraverse(AvlNode<T> *& t){
    if (t!=NULL){
        postorderTraverse(t->left);
        postorderTraverse(t->right);
        std::cout<<t->element<<std::endl;
    }
}



#endif /* AVLTree_h */
