#ifndef HashTable_h
#define HashTable_h

template <class T>
class HashTable
{
  public:
    HashTable(const T & notFound, int size=101);
    HashTable(const HashTable & rhs)
      : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND), theLists(rhs.theLists) { }

    const T & find(const T & x) const;

    void makeEmpty();
    void insert(const T & x);
    void remove(const T & x);

    const HashTable & operator=(const HashTable & rhs);
  private:
    std::vector<T> theLists;  // The array of Lists
    const T ITEM_NOT_FOUND;
};
int hash(const std::string & key, int tableSize);
int hash(int key, int tableSize);


template <class T>
void HashTable<T>::insert(const T & x)
{
   HashTable<T> & whichList = theLists[hash(x, theLists.size())];
    T* p = whichList.find(x);

   if(p == NULL)
     whichList.insert(x, whichList.zeroth());
}


template <class T>
void HashTable<T>::remove(const T & x)
{
   theLists[hash(x, theLists.size())].remove(x);
}

template <class T>
const T & HashTable<T>::find(const T & x) const
{
   T * itr;
   itr = theLists[hash( x, theLists.size())].find(x);
   if(itr==NULL)
     return ITEM_NOT_FOUND;
   else
     return *itr;
}

#endif /* HashTable_h */
