#pragma once

#include <cmath>
#include <iostream>
#include "square_matrix.hpp"
#include "vector.hpp"

class SLAE : public Square_matrix<double> {
// Наследуется квадратная матрица из элементов double
// со спецификатором доступа public (сохраняются только поля и методы public и protected).
// Конструкторы класса не копируются
public:
    SLAE() : Square_matrix<double>() { }

    explicit SLAE(int dimension) : Square_matrix<double>(dimension) { }

    SLAE(const SLAE &m) = default;

    ~SLAE() = default;

    /*
     * Переставляет местами столбцы с индексами first_column и second_column */
    void swap_columns(int first_column, int second_column) {
        for (int i = 0; i < count; ++i) {
            std::swap(array[i][first_column], array[i][second_column]);
        }
    }

    int get_max_row_element_index(int row_index) {
        double max_element = 0;
        int max_index = -1;
        for (int i = 0; i < count; ++i) {
            if ( fabs(array[row_index][i]) > max_element ) {
                max_element = fabs(array[row_index][i]);
                max_index = i;
            }
        }
        return max_index;
    }

    /*
     * Решает систему линейных алгебраических уравнений модифицированным методом Гаусса */
    Vector<double> solve_Gauss_method(Vector<double> b) {
        SLAE A(*this);

        Vector<int> order(count);
        for (int i = 0; i < count; ++i) {
            order[i] = i;
        }

        // Прямой ход метода Гаусса
        for (int i = 0; i < count; ++i) {
            int max_row_element = A.get_max_row_element_index(i);
            A.swap_columns(i, max_row_element);
            std::swap(b[i], b[max_row_element]);
            std::swap(order[i], order[max_row_element]);
            for (int j = i + 1; j < count; ++j) {
                double coefficient = A[j][i] / A[i][i];
                for (int k = i; k < count; ++k) {
                    A[j][k] = A[j][k] - coefficient * A[i][k];
                }
                b[j] = b[j] - coefficient * b[i];
            }
        }

        // Обратный ход метода Гаусса
        for (int i = count - 1; i >= 0; --i) {
            for (int j = i - 1; j >= 0; --j) {
                double coefficient = A[j][i] / A[i][i];
                for (int k = 0; k < count; ++k) {
                    A[j][k] = A[j][k] - coefficient * A[i][k];
                }
                b[j] = b[j] - coefficient * b[i];
            }
            b[i] /= A[i][i];
        }

        // Перестановка переменных
        for (int i = 0; i < count; ++i) {
            int j = 0;
            while (order[j] != i) {
                ++j;
            }
            std::swap(order[i], order[j]);
            std::swap(b[i], b[j]);
        }

        return b;
    }
};
