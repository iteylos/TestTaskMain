#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template<typename T>
class Vector {
private:

    void AddMemory() {       //Memory allocation
        cap *= 2;
        T* tmp = arr;
        arr = new T[cap];
        for (size_t i = 0; i < size; ++i) arr[i] = tmp[i];
        delete[] tmp;
    }

    T* arr;         //Pointer to memory area, for a vector
    size_t size{};  //Vector size
    size_t cap{};  //Maximum vector size

public:
    Vector() {           //Class constructor
        arr = new T[1];
        cap = 1;    }
    Vector(Vector& other) {              //Constructors with move semantics
        if (this != &other) {
            delete[] arr;
            arr = other.arr;
            size = other.size;
            cap = other.cap;
            other.arr = nullptr;
            other.size = other.cap = 0;
        }
    }
    Vector(Vector&& other)  noexcept {
        if (this != &other) {
            delete[] arr;
            arr = other.arr;
            size = other.size;
            cap = other.cap;
            other.arr = nullptr;
            other.size = other.cap = 0;
        }
    }
    Vector& operator=(Vector& other) {    //Assignment operators
        if (this != &other) {
            delete[] arr;
            arr = other.arr;
            size = other.size;
            cap = other.cap;
            other.arr = nullptr;
            other.size = other.cap = 0;
        }
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] arr;
            arr = other.arr;
            size = other.size;
            cap = other.cap;
            other.arr = nullptr;
            other.size = other.cap = 0;
        }
        return *this;
    }

    ~Vector() {         //Destructor
        delete[] arr;
    }
public:
    [[nodiscard]] bool IsEmpty() const {  //Checking "if the list is empty"
        return size == 0;
    }

    [[nodiscard]] size_t Size() const {  //Getting the vector size
        return size;
    }

    [[nodiscard]] size_t Capacity() {   //Getting the maximum vector size
        return cap;
    }

    void Reserve(size_t n) {  //Memory reservation
        if (n <= cap) return;
        cap = n;
    }

    void Clean() {            //Vector cleaning
        while (size > 0) {
            --size;
            (arr + size)->~T();
        }
    }

    void Push_Back(const T& value) {      //Adding an item
        if (size >= cap) AddMemory();
        arr[size++] = value;
    }

    void Erase(size_t index) {            //Deleting an item
        for (size_t i = index + 1; i < size; ++i) {
            arr[i - 1] = arr[i];
        }
        --size;
    }
     
public:                      //Iterators
    T* begin() {
        return &arr[0];
    }

    T* end() {
        return &arr[size];
    }
    const T* begin() const {
        return &arr[0];
    }

    const T* end() const {
        return &arr[size];
    }
public:
    T& operator[](size_t index) {   //Operator for returning a normal reference to an element
        return arr[index];
    }

    const T& operator[](size_t index) const {  //Operator for returning a constant reference to an element
        return arr[index];
    }
};

template<typename T>     //Stream recording operator
inline std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    for (const T& val : vec) os << val << " ";
    return os;
}

#endif
