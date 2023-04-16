template <typename T, unsigned chunk_size>
deque<T, chunk_size>::deque()
    : data {new T*[1]},
      capacity {1},
      chunk_count {0},
      count {0},
      start {0}
{}

template <typename T, unsigned chunk_size>
deque<T, chunk_size>::deque(deque<T, chunk_size> const& other)
    : deque{}
{
    //?
    for(unsigned i{0}; i < other.size(); i++) {
        push_back(other[i]);
    }
}

template <typename T, unsigned chunk_size>
deque<T, chunk_size>::deque(deque<T, chunk_size>&& other)
    : deque{}
{
    *this = std::move(other);
}

template <typename T, unsigned chunk_size>
deque<T, chunk_size>::~deque()
{
    for(unsigned i{}; i < chunk_count; i++) {
        delete[] data[i];
    }
    delete[] data;
}

template <typename T, unsigned chunk_size>
void deque<T, chunk_size>::push_front(T const& val) {
    if(start > 0) {
        start--;
    }
    else {
        add_chunk_front();
        start = chunk_size - 1;
    }
    data[0][start] = val;
    count++;
}

template <typename T, unsigned chunk_size>
void deque<T, chunk_size>::push_back(T const& val) {
    int next_chunk = (start+count)/chunk_size;
    int next_index = (start+count)%chunk_size;
    // need to add a chunk
    if(next_index == 0) {
        add_chunk_back();
    }
    data[next_chunk][next_index] = val;
    count++;
}

template <typename T, unsigned chunk_size>
void deque<T, chunk_size>::pop_front() {
    if(count > 0) {
        ++start;
        remove_chunk_front();
        --count;
    }
    else {
        throw std::out_of_range("Can not pop from an empty deque");
    }
}

template <typename T, unsigned chunk_size>
void deque<T, chunk_size>::pop_back() {
    if(count > 0) {
        remove_chunk_back();
        --count;
    }
    else {
        throw std::out_of_range("Can not pop from an empty deque");
    }
}

template <typename T, unsigned chunk_size>
T& deque<T, chunk_size>::operator[](int i) {
    return const_cast<T&>(static_cast<deque const*>(this)->operator[](i));
}

template <typename T, unsigned chunk_size>
T const& deque<T, chunk_size>::operator[](int i) const{
    return data[(i + start) / chunk_size][(i + start) % chunk_size];
}

template <typename T, unsigned chunk_size>
T& deque<T, chunk_size>::at(int i) {
    return const_cast<T&>(static_cast<deque const*>(this)->at(i));
}

template <typename T, unsigned chunk_size>
T const& deque<T, chunk_size>::at(int i) const{
    if((i < 0) || (i >= count)) {
        throw std::out_of_range("Deque exceed the range!");
    }
    return operator[](i);
}

template <typename T, unsigned chunk_size>
deque<T, chunk_size>& deque<T, chunk_size>::operator=(deque<T, chunk_size> const& other) {
    //?
    return *this = std::move(deque{other});
}

template <typename T, unsigned chunk_size>
deque<T, chunk_size>& deque<T, chunk_size>::operator=(deque<T, chunk_size>&& other) {
    std::swap(this->capacity, other.capacity);
    std::swap(this->data, other.data);
    std::swap(this->chunk_count, other.chunk_count);
    std::swap(this->count, other.count);
    std::swap(this->start, other.start);
    //?
    return *this;
}

template <typename T, unsigned chunk_size>
int deque<T, chunk_size>::size() const {
    return count;
}

template <typename T, unsigned chunk_size>
void deque<T, chunk_size>::reallocate_chunk_array()
{
    // allocate new space for array
    if (chunk_count >= capacity)
    {
        capacity *= 2;
        T** new_array {new T*[capacity]{}};
        std::copy(data, data + chunk_count, new_array);
        
        delete[] data;
        data = new_array;
    }
}

template <typename T, unsigned chunk_size>
void deque<T, chunk_size>::add_chunk_back() {
    reallocate_chunk_array();
    data[chunk_count++] = new T[chunk_size] {};
}

template <typename T, unsigned chunk_size>
void deque<T, chunk_size>::add_chunk_front() {
    reallocate_chunk_array();
    std::move(data, data+chunk_count, data+1);
    data[0] = new T[chunk_size] {};
    chunk_count++;
}

template <typename T, unsigned chunk_size>
void deque<T, chunk_size>::remove_chunk_front() {
    if(start >= chunk_size) {
        start = 0;
        delete[] data[0];
        std::move_backward(data + 1, data + chunk_count, data + chunk_count - 1);
        --chunk_count;
    }
}

template <typename T, unsigned chunk_size>
void deque<T, chunk_size>::remove_chunk_back() {
    if((count + start - 1) % chunk_size == 0) {
        delete[] data[chunk_count];
        --chunk_count;
    }
}