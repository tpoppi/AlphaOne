#include "vector.h"
#include "pezzi.h"
#include "alfiere.h"

template<class T>
T *vector<T>::copy() const
{
    T* b = !size ? nullptr : new T[size];
    for(unsigned int j=0; j<size; j++)
        b[j] = a[j];
    return b;
}

template<class T>
vector<T>::vector(unsigned int s, const T &x): a(s?new T[s*2]:0), size(s), capacity(s?s*2:0)
{
    for(unsigned int i=0; i<s; i++)
       a[i]=x;
}


template<class T>
vector<T>::vector(const vector &v): a(v.copy()), size(v.getSize()), capacity(v.getCapacity())
{

}



template<class T>
vector<T> &vector<T>::operator=(const vector &v)
{
       if(this != &v) {
           if(a)
              delete[] a;
           a = v.copy();
           size = v.size;
           capacity=v.capacity;
        }
        return *this;
}

template<class T>
vector<T>::~vector()
{
    if(a)
        delete[] a;
}

template<class T>
unsigned int vector<T>::getSize() const
{
    return size;
}

template<class T>
unsigned int vector<T>::getCapacity() const
{
    return capacity;
}

template<class T>
T &vector<T>::operator[](unsigned int i) const
{
    return a[i];
}

template<class T>
void vector<T>::push_back(const T &p)
{
    if(capacity==size){
        capacity=capacity?capacity*2 : 1;
        T* b=new T[capacity];
        for(unsigned int i=0;i<size; i++)
            b[i]=a[i];
        delete[] a;
        a=b;
    }
    a[size]=p;
    size++;
}

template<class T>
T vector<T>::popBack()
{
    if(size){
        T tmp=a[size];
        if(size<=(capacity/2))
            capacity=capacity/2;
       T* b= new T[capacity];
       for(unsigned int i=0;i<size-1; i++)
           b[i]=a[i];
       delete [] a;
       --size;
       a=b;
       return tmp;
     }
     else
        return 0;
}

template<class T>
bool vector<T>::operator==(const vector &r) const
{
    if(this==&r)
       return true;
     if(r.size!=size || r.capacity!=capacity)
        return false;
     for(unsigned int i=0; i<size; i++){
        if(a[i]!=r[i])
            return false;
     }
     return true;
}

template<class T>
vector<T> vector<T>::operator+(const vector &v)
{
    //int b=size+v.
    vector aux(size+v.getSize());
    unsigned int i=0;
    for( ;i<size; ++i)
        aux[i] = a[i];
    for( ;i<aux.getSize(); ++i)
        aux[i] = v[i-size];
    return aux;
}

template<class T>
typename vector<T>::iterator vector<T>::begin() const
{
    return iterator(&a[0]);
}

template<class T>
typename vector<T>::iterator vector<T>::end() const
{
    return iterator(&a[size]);
}









template<class T>
vector<T>::iterator::iterator(T* n): ptr(n) {}

template<class T>
typename vector<T>::iterator& vector<T>::iterator::operator++()
{
   if(ptr)
      ++ptr;
   return *this;
}

template<class T>
T &vector<T>::iterator::operator*() const
{
    return *ptr;
}

template<class T>
T &vector<T>::iterator::operator[](vector::iterator i)
{
    return *i.ptr;
}



template<class T>
bool vector<T>::iterator::operator==(const vector::iterator &x)
{
    return ptr==x.ptr;
}

template<class T>
bool vector<T>::iterator::operator!=(const vector::iterator &x)
{
    return ptr!=x.ptr;
}


template<class T>
vector<T>::iterator::iterator(const vector::iterator &n): ptr(n.ptr)
{

}

template<class T>
typename vector<T>::iterator vector<T>::iterator::operator++(int)
{
    iterator tmp(*this);
    operator++();
    return tmp;
}

template<class T>
typename vector<T>::iterator &vector<T>::iterator::operator--()
{
    if(ptr)
       --ptr;
    return *this;
}

template<class T>
typename vector<T>::iterator vector<T>::iterator::operator--(int)
{
    iterator tmp(*this);
    operator--();
    return tmp;
}

template<class T>
typename vector<T>::iterator &vector<T>::iterator::operator=(const vector::iterator &p)
{
    if(this!=&p){
        delete [] ptr;
        ptr=&p.ptr[0];
    }
    return *this;
}

template class vector<int>;
template class vector<Pezzi*>;
template class vector<Alfiere*>;

template<class T>
vector<T>::const_iterator::const_iterator(const T* n): ptr(n) {}

template<class T>
typename vector<T>::const_iterator& vector<T>::const_iterator::operator++()
{
   if(ptr)
      ++ptr;
   return *this;
}

template<class T>
const T &vector<T>::const_iterator::operator*() const
{
    return *ptr;
}

template<class T>
const T &vector<T>::const_iterator::operator[](vector::const_iterator i)
{
    return *i.ptr;
}



template<class T>
bool vector<T>::const_iterator::operator==(const vector::const_iterator &x)
{
    return ptr==x.ptr;
}

template<class T>
bool vector<T>::const_iterator::operator!=(const vector::const_iterator &x)
{
    return ptr!=x.ptr;
}


template<class T>
vector<T>::const_iterator::const_iterator(const vector::const_iterator &n): ptr(n.ptr)
{

}

template<class T>
typename vector<T>::const_iterator vector<T>::const_iterator::operator++(int)
{
    const_iterator tmp(*this);
    operator++();
    return tmp;
}

template<class T>
typename vector<T>::const_iterator &vector<T>::const_iterator::operator--()
{
    if(ptr)
       --ptr;
    return *this;
}

template<class T>
typename vector<T>::const_iterator vector<T>::const_iterator::operator--(int)
{
    const_iterator tmp(*this);
    operator--();
    return tmp;
}

template<class T>
vector<T>::const_iterator::const_iterator(const vector::iterator &n): ptr(n.ptr)
{

}

