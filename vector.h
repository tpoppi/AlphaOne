#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class vector
{
private:
  T* a;
  unsigned int size;
  unsigned int capacity;
  T* copy() const;
public:
    vector(unsigned int s =0 ,const T& x =T()); //in pezzi non è presente pezzi()
    vector(const vector& v);
    vector& operator=(const vector& v);
    ~vector();
    unsigned int getSize() const;
    unsigned int getCapacity() const;
    T& operator[](unsigned int i) const;
    void push_back(const T& p);
    T popBack();
    bool operator==(const vector& r) const;
    vector operator+(const vector& v);
    class const_iterator;
    class iterator{
        friend class vector::const_iterator;
        private:
            T* ptr;
        public:
            iterator(T* n);
            iterator(const iterator& n);
            iterator& operator=(const iterator& p);
            iterator& operator++();
            iterator operator++(int);
            iterator& operator--();
            iterator operator--(int);
            T& operator*() const;
            T& operator[](iterator i);
            bool operator==(const iterator& x);
            bool operator!=(const iterator& x);
        };
        class const_iterator{
        private:
            const T* ptr;
        public:
            const_iterator(const T* n);
            const_iterator(const const_iterator& n);
            const_iterator(const iterator& n);
            const_iterator& operator++();
            const_iterator operator++(int);
            const_iterator& operator--();
            const_iterator operator--(int);
            const T& operator*() const;
            const T& operator[](const_iterator i);
            bool operator==(const const_iterator& x);
            bool operator!=(const const_iterator& x);
        };
        iterator begin() const;
        iterator end() const;
};

#endif // VECTOR_H
