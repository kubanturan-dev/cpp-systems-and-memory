#include <iostream>
#include <string>

template <typename T>
class MyVector {
private:
    T *pData = nullptr;
    unsigned int size;
    unsigned int capacity;

    void reallocate() {
        capacity *= 2;
        T *NewpData = new T[capacity];
        for (unsigned int i = 0; i < size; i++) {
            NewpData[i] = pData[i]; 
        }
        delete[] pData;
        pData = NewpData;
    } 

public:
    MyVector() {
        size = 0;
        capacity = 2;
        pData = new T[capacity];
    }

    MyVector(const MyVector& vector) {
        this->capacity = vector.capacity;
        this->size = vector.size;
        T *NewData = new T[vector.capacity];
        for (unsigned int i = 0; i < size; i++) {
            NewData[i] = vector.pData[i];
        }
        pData = NewData;
    }
        
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] pData; 
            capacity = other.capacity;
            size = other.size;
            pData = new T[capacity];
            for (unsigned int i = 0; i < size; i++) {
                pData[i] = other.pData[i];
            }
        }
        return *this;
    }

    void push_back(T element) {
        if (size == capacity) {
            reallocate(); 
        }
        pData[size] = element;
        size += 1;
    }

    T& operator[](unsigned int index) {
        return pData[index];
    }

    unsigned int getSize() const {
        return size;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    ~MyVector() {
        delete[] pData;
    }
};

