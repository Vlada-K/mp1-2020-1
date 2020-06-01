#pragma once

#include <iostream>
#include "vector.hpp"

template<class T>
class Square_matrix : public Vector<Vector<T>> {
public:
    Square_matrix<T>() = default;

    /*
     * Создаёт матрицу dimension x dimension, заполненную нулями */
    explicit Square_matrix<T>(int dimension) : Vector<Vector<T>>(dimension) { }

    /*
     * Конструктор копирования */
    Square_matrix<T>(const Square_matrix<T> &m) : Vector<Vector<T>>(m) { }

    ~Square_matrix<T>() = default;
};
