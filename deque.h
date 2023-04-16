#ifndef DEQUE_H
#define DEQUE_H

#include <array>
#include <string>
#include <iostream>

template <typename T, unsigned chunk_size>
class deque
{
private:
    T** data;
    int capacity;
    int chunk_count;
    int count;
    int start;

    void add_chunk_front();
    void add_chunk_back();
    void reallocate_chunk_array();
    void remove_chunk_front();
    void remove_chunk_back();
public:
    /* default constructor */
    deque();
    deque(deque const& other);
    deque(deque&& other);
    /* deconstructor */
    ~deque();

    void push_front(T const& val);
    void push_back(T const& val);

    void pop_front();
    void pop_back();

    T&       operator[](int i);
    T const& operator[](int i) const;
    
    T&       at(int i);
    T const& at(int i) const;

    deque& operator=(deque const& other);
    deque& operator=(deque&& other);

    int size() const;
};

#include "deque.tcc"
#endif