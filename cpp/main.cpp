#include <iostream>

using namespace std;

int main() {

    // Node
    template <class T>
    class Node {
    public:
        Node(const T& e = T(), Node *n = NULL):
            element(e), next(n) { }
        T element;
        Node *next;
    };

    class List {
    private:
        Node<T> *head;
    public:
        List(): head(NULL) { }
        bool isEmpty() const;
        Node<T>* first();
    };

    bool List<T>::isEmpty() const {
        return head == NULL;
    };

    Node<T>* List<T>::first() {
        return head;
    };


    return 0;
}
