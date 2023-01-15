#include <iostream>
#include "LinkedList.h"


int main() {
    // Testing
    // Create
    List<int> list;
    list.insert(0, list.zeroth());
    Node<int>* p = list.first();

    // Insertion
    for (int i = 1; i <= 10; ++i)
    {
        list.insert(i, p);
        p = p->next;
    }
    // Print
    std::cout << "printing original list" << std::endl;
    list.print();

    // Remove
    for (int i = 0; i <= 10; ++i)
    {
        if (i % 2 == 0)
            list.remove(i);
    }

    std::cout << "printing odd number list" << std::endl;
    list.print();

    // Assignment
    List<int> list2 = list;
    std::cout << "printing copy constructed list" << std::endl;
    list2.print();

    List<int> list3;
    list3 = list;
    std::cout << "printing assigned list" << std::endl;
    list3.print();

    // Empty
    list.makeEmpty();
    std::cout << "printing emptied list" << std::endl;
    list.print();

    // Find
    for (int i = 0; i <= 10; ++i) {
        if (i % 2 == 0) {
            if (list2.find(i) == NULL)
                std::cout << "could not find element " << i << std::endl;
        }
        else {
            if (list2.find(i) != NULL)
                std::cout << "found element " << i << std::endl;
        }
    }

    return 0;
}
