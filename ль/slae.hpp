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

	SLAE(int dimension) : Square_matrix<double>(dimension) { }

	SLAE(std::initializer_list<Vector<double>> m) : Square_matrix<double>(m) { }

	SLAE(const SLAE& m) : Square_matrix<double>(m) { }

	~SLAE() = default;

	/*
	 * Переставляет местами строки с индексами first_row и second_row */
	void swap_rows(int first_row, int second_row) 
	{
		for (int i = 0; i < count; ++i) 
		{
			std::swap(matrix[first_row], matrix[second_row]);
		}
	}

	/*
	 * Переставляет местами столбцы с индексами first_column и second_column */
	void swap_columns(int first_column, int second_column) 
	{
		for (int i = 0; i < count; ++i) 
		{
			std::swap(matrix[i][first_column], matrix[i][second_column]);
		}
	}

	int get_max_row_element_index(int row_index) 
	{
		double max_element = 0;
		int max_index = -1;
		for (int i = 0; i < count; ++i) 
		{
			if (fabs(matrix[row_index][i] > max_element)) 
			{
				max_element = fabs(matrix[row_index][i]);
				max_index = i;
			}
		}
		return max_index;
	}

	void print() 
	{
		for (int i = 0; i < count; ++i) 
		{
			for (int j = 0; j < count; ++j) 
			{
				std::cout << matrix[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	/*
	 * Решает систему линейных алгебраических уравнений модифицированным методом Гаусса */
	Vector<double> solve_Gauss_method(Vector<double> b) 
	{
		SLAE A(*this);

		// Прямой ход метода Гаусса
		for (int i = 0; i < count; ++i) 
		{
			for (int j = i + 1; j < count; ++j) 
			{
				double coefficient = A[j][i] / A[i][i];
				for (int k = i; k < count; ++k) 
				{
					A[j][k] = A[j][k] - coefficient * A[i][k];
				}
				b[j] = b[j] - coefficient * b[i];
			}
		}

		// Обратный ход метода Гаусса
		for (int i = count - 1; i >= 0; --i) 
		{
			for (int j = i - 1; j >= 0; --j) 
			{
				double coefficient = A[j][i] / A[i][i];
				for (int k = count - 1; k >= i; --k) 
				{
					A[j][k] = A[j][k] - coefficient * A[i][k];
				}
				b[j] = b[j] - coefficient * b[i];
			}
			b[i] /= A[i][i];
		}

		return b;
	}
};
