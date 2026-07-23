#include <algorithm>

class DynamicArray {
private:
    int m_capacity;
    int m_size;
    int *m_data;

public:

    DynamicArray(int capacity) {
        m_size = 0;
        m_capacity = capacity;
        m_data = new int[m_capacity];
    }

    ~DynamicArray() {
        delete[] m_data;
    }

    int get(int i) {
        return m_data[i];
    }

    void set(int i, int n) {
        m_data[i] = n;
    }

    void pushback(int n) {
        if ( m_size == m_capacity )
            resize();
        m_data[m_size++] = n;
    }

    int popback() {
        return m_data[--m_size];
    }

    void resize() {
        int *arr = new int[m_capacity*2];
        copy(m_data, m_data+m_size, arr);
        delete[] m_data;
        m_data = arr;
        m_capacity *= 2;
    }

    int getSize() {
        return m_size;
    }

    int getCapacity() {
        return m_capacity;
    }
};
