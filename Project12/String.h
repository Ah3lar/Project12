#pragma once
class String {
private:
    char* data;

public:
    String() : data(nullptr) {}

    String(const char* str) {
        if (str) {
            int length = 0;
            while (str[length] != '\0') {
                ++length;
            }
            data = new char[length + 1];
            for (int i = 0; i <= length; ++i) {
                data[i] = str[i];
            }
        }
        else {
            data = nullptr;
        }
    }

    String(const String& other) {
        if (other.data) {
            int length = 0;
            while (other.data[length] != '\0') {
                ++length;
            }
            data = new char[length + 1];
            for (int i = 0; i <= length; ++i) {
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }
    }

    String(String&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    ~String() {
        delete[] data;
    }

    const char* getData() const {
        return data;
    }

    int length() const {
        int len = 0;
        while (data[len] != '\0') {
            ++len;
        }
        return len;
    }
};
