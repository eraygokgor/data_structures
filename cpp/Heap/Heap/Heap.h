#ifndef Heap_h
#define Heap_h

template <class T>
class BinaryHeap
{
  public:
    BinaryHeap(int capacity = 100);
    bool isEmpty() const;
    const T & findMin() const;

    void insert(const T & x);
    void deleteMin();
    void deleteMin(T & minItem);
    void makeEmpty();

  private:
    int theSize;  // Number of elements in heap
    std::vector<T> array;   // The heap array
    void buildHeap();
    void percolateDown(int hole);
};


template <class T>
void BinaryHeap<T>::insert(const T & x)
{
    array[0] = x;   // initialize sentinel
    if(theSize + 1 == array.size())
        array.resize(array.size() * 2 + 1);

    // Percolate up
    int hole = ++theSize;
    for( ; x < array[hole / 2]; hole /= 2)
        array[hole] = array[hole / 2];
    array[hole] = x;
}

template <class T>
void BinaryHeap<T>::deleteMin()
{
    // if(isEmpty())
        // throw UnderflowException();
    if (not isEmpty()){
        array[1] = array[theSize--];
        percolateDown( 1);
    }
}

template <class T>
void BinaryHeap<T>::percolateDown(int hole)
{
  int child;
  T tmp = array[hole];

  for(; hole * 2 <= theSize; hole = child)
  {
    child = hole * 2;
    if(child != theSize && array[child + 1] < array[child])
       child++;
    if(array[ child ] < tmp)
       array[hole] = array[ child];
    else
       break;
  }
  array[hole] = tmp;
}


template <class T>
void BinaryHeap<T>::buildHeap()
{
    for(int i = theSize / 2; i > 0; i--)
        percolateDown(i);
}




#endif /* Heap_h */
