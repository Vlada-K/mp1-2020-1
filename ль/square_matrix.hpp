#pragma once

#include <iostream>
#include "vector.hpp"

template <class T>
class Square_matrix 
{
protected:
	// Эти поля передадутся классам-наследникам
	Vector<Vector<T>> matrix;
	int count = 0;
public:
	Square_matrix<T>() = default;

	/*
	 * Создаёт матрицу dimension x dimension, заполненную нулями */
	Square_matrix<T>(int dimension) 
	{
		if (dimension > 0) 
		{
			count = dimension;
			matrix = Vector<Vector<T>>(count);
			for (int i = 0; i < count; ++i) 
			{
				matrix[i] = Vector<T>(count); // Строки матрицы будут заполнены нулями автоматически
			}
		}
	}

	/*
	 * Конструктор создания матрицы из списка инициализаторов */
	// Square_matrix<int> a = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	// Поле matrix заполняется с помощью конструктора для вектора, так как это поле - вектор(от вектора)
	// Поле count копирует m.size()
	Square_matrix<T>(std::initializer_list<Vector<T>> m) : matrix(m), count(m.size()) { }

	/*
	 * Конструктор копирования */
	Square_matrix<T>(const Square_matrix<T>& m) 
	{
		count = m.count;
		if (count > 0) 
		{
			matrix = Vector<Vector<T>>(count);
			for (int i = 0; i < count; ++i) 
			{
				matrix[i] = Vector<T>(count);
				for (int j = 0; j < count; ++j) 
				{
					matrix[i][j] = m[i][j];
				}
			}
		}
	}

	~Square_matrix<T>() = default;

	Vector<T>& operator[](int index) 
	{
		return matrix[index];
	}

	Vector<T> operator[](int index) const 
	{
		return matrix[index];

	// get-метод для получения размерности квадратной матрицы
	}
	int dimension() 
	{
		return count;
	}
};
