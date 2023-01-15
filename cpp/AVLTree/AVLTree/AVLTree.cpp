#include <iostream>
#include "AVLTree.h"

int main() {
    // Some tests for AVL Tree ADT
    
    
    AvlNode<int> avl(3);
    AvlNode<int> *root = &avl;
    
    avl.insert(2, root);
    avl.insert(1, root);
    for (int i=4; i<8; i++){
        avl.insert(i, root);
    }
    
    std::cout<<"Preorder Traverse: "<<std::endl;
    avl.preorderTraverse(root);
    std::cout<<"Inorder Traverse: "<<std::endl;
    avl.inorderTraverse(root);
    std::cout<<"Postorder Traverse: "<<std::endl;
    avl.postorderTraverse(root);
    
    std::cout << "Hello, World!\n";
    return 0;
}

