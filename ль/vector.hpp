#pragma once

#include <iostream>

template<class T>
class Vector {
protected:
    T *array = nullptr;
    int count = 0;
public:
    Vector<T>() = default;

    /*
     * Создаёт вектор длины size, заполненный нулями */
    explicit Vector<T>(int size) {
        if ( size > 0 ) {
            count = size;
            array = new T[count];
            for (int i = 0; i < count; ++i) {
                array[i] = T(size);
            }
        }
    }

    Vector<T>(const Vector<T> &v) {
        count = v.count;
        if ( count > 0 ) {
            array = new T[count];
            for (int i = 0; i < count; ++i) {
                array[i] = v[i];
            }
        }
    }

    /*
     * get-метод для получения размера вектора */
    int size() {
        return count;
    }

    T &operator[](int index) {
        return array[index % count];
    }

    T operator[](int index) const {
        return array[index % count];
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector<T> &v) {
        os << "{ ";
        for (int i = 0; i < v.count; ++i) {
            os << v.array[i] << ' ';
        }
        os << "}" << std::endl;
        return os;
    }

    Vector<T> &operator=(const Vector<T> &v) {
        if (&v == this) {
            return *this;
        }

        if ( v.count > 0 ) {
            count = v.count;
            array = new T[count];
            for (int i = 0; i < count; ++i) {
                array[i] = v[i];
            }
        } else {
            count = 0;
            array = nullptr;
        }
        return *this;
    }
};
