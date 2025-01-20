#pragma once
class Array {
private:
    int* data;
    size_t size;

public:
    Array() : data(nullptr), size(0) {}

    Array(size_t size) : size(size), data(new int[size]) {}

    Array(const Array& other) : size(other.size), data(new int[other.size]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    Array(Array&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    ~Array() {
        delete[] data;
    }

    size_t getSize() const {
        return size;
    }

    int& operator[](size_t index) {
        return data[index];
    }

    const int& operator[](size_t index) const {
        return data[index];
    }
};
