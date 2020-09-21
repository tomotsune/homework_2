#pragma once

#include <iostream>
#include <tuple>

/**
 * 动态线性表
 * @tparam T
 */
template<typename T>
class Set {
private:
    static const int DEFAULT_SIZE{100};
    T *head;
    int length{};
    int size{};
public:
    Set();

    explicit Set(int size);

    Set(const Set &s);

    ~Set();

    void add(const T &data);

    void insert(const T &data, const int &pos);

    void removeByPos(const int &pos);

    void removeByData(const T &data);

    void clear();

    bool isEmpty() const;

    int getLength() const;

    int getsize() const;

    inline const T &operator[](const int &pos) const;

    Set<T> operator+(const Set<T> &s) const;

    Set<T> operator*(const Set<T> &s) const;

    Set<T> operator-(const Set<T> &s) const;

    bool operator<(const Set &rhs) const;

    bool operator>(const Set &rhs) const;

    bool operator<=(const Set &rhs) const;

    bool operator>=(const Set &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Set<T> &Set) {
        for (int i = 0; i < Set.length; ++i) {
            os << Set.head[i] << " ";
        }
        return os;
    }

    bool operator==(const Set &rhs) const;

    bool operator!=(const Set &rhs) const;

};

template<typename T>
inline Set<T>::Set():size(DEFAULT_SIZE) {
    head = new T[DEFAULT_SIZE];
}

template<typename T>
Set<T>::Set(int size):size(size) {
    head = new T[size];
}

template<typename T>
inline Set<T>::~Set() {
    delete[] head;
}

template<typename T>
void Set<T>::add(const T &data) {
    head[length++] = data;
}

template<typename T>
inline void Set<T>::insert(const T &data, const int &pos) {
    if (pos < 0 || pos > length)return;
    for (int i = 0; i < length; ++i) {
        if (data == head[i])return;
    }
    if (++length > size) {
        size += 8;
        auto temp = new T[size];
        for (int i = 0; i < length; ++i) {
            temp[i] = head[i];
        }
        delete head;
        head = temp;
    }
    for (int i = length; i > pos; --i) {
        head[i] = head[i - 1];
    }
    head[pos] = data;
}

template<typename T>
inline void Set<T>::removeByPos(const int &pos) {
    if (pos < 0 || pos > length - 1)return;
    for (int i = pos; i < length; ++i) {
        head[i] = head[i + 1];
    }
    --length;
}


template<typename T>
int Set<T>::getsize() const {
    return size;
}


template<typename T>
int Set<T>::getLength() const {
    return length;
}


template<typename T>
Set<T> Set<T>::operator+(const Set <T> &s) const {
    auto sum{*this};
    for (int i = 0; i < s.length; ++i) {
        int num{};
        for (int j = 0; j < length; ++j) {
            if (head[j] != s.head[i])++num;
        }
        if (num == length)sum.add(s.head[i]);
    }
    return sum;
}

template<typename T>
Set<T> Set<T>::operator*(const Set <T> &s) const {
    Set<T> product{};
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < s.length; ++j) {
            if (head[i] == s.head[j])product.add(s.head[j]);
        }
    }
    return product;
}

template<typename T>
Set<T>::Set(const Set &s):Set(s.size) {
    length = s.length;
    for (int i = 0; i < s.length; ++i) {
        head[i] = s.head[i];
    }
}

template<typename T>
const T &Set<T>::operator[](const int &pos) const {
    return head[pos];
}

template<typename T>
bool Set<T>::operator==(const Set &rhs) const {
    int num{};
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if (head[i] == rhs.head[j]) {
                ++num;
            }
        }
    }
    return num == length;
}

template<typename T>
bool Set<T>::operator!=(const Set &rhs) const {
    return rhs != *this;
}


template<typename T>
bool Set<T>::operator<=(const Set &rhs) const {
    return *this * rhs == *this;
}

template<typename T>
bool Set<T>::operator>=(const Set &rhs) const {
    return *this * rhs == rhs;
}

template<typename T>
Set<T> Set<T>::operator-(const Set <T> &s) const {
    auto difference{*this};
    Set<T> product{*this * s};
    for (int i = 0; i < product.length; ++i) {
        difference.removeByData(product.head[i]);
    }
    return difference;
}

template<typename T>
void Set<T>::removeByData(const T &data) {
    int pos{};
    for (int i = 0; i < length; ++i) {
        if (head[i] == data) {
            pos = i;
            break;
        }
    }
    removeByPos(pos);
}

template<typename T>
bool Set<T>::isEmpty() const {
    return length == 0;
}

template<typename T>
void Set<T>::clear() {
    delete[] head;
    length = 0;
}





