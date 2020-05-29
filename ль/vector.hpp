#pragma once

#include <iostream>

template <class T>
class Vector 
{
private:
	T *array = nullptr;
	int count = 0;
public:
	Vector<T>() = default;

	/*
	 * Создаёт вектор длины size, заполненный нулями */
	Vector<T>(int size) 
	{
		if (size > 0) 
		{
			count = size;
			array = new T[count];
			
			for (int i = 0; i < count; ++i) 
			{
				array[i] = (T) 0;
			}
		}
	}

	/*
	 * Создаёт вектор из списка инициализации */
	// Например, Vector<int> a = { 1, 2, 3 }; // Аналогично std::vector<int> a = { 1, 2, 3 };
	Vector<T>(std::initializer_list<T> v) 
	{
		if (v.size() > 0) 
		{
			count = v.size();
			array = new T[count];
			std::copy(v.begin(), v.end(), array);
		}
	}

	Vector<T>(const Vector<T> &v) 
	{
		count = v.count;
		if (count > 0) 
		{
			array = new T[count];
			for (int i = 0; i < count; ++i) 
			{
				array[i] = v[i];
			}
		}
	}
	
	/*
	 * get-метод для получения размера вектора */
	int size() 
	{
		return count;
	}

	void print() 
	{
		for (int i = 0; i < count; ++i) 
		{
			std::cout << array[i] << ' ';
		}
		std::cout << std::endl;
	}

	T& operator[](int index) 
	{
		return array[index % count];
	}

	T operator[](int index) const 
	{
		return array[index % count];
	}

	Vector<T>& operator=(const Vector<T>& v) 
	{
		if (v.count > 0) 
		{
			count = v.count;
			array = new T[count];
			for (int i = 0; i < count; ++i) 
			{
				array[i] = v[i];
			}
		} else 
		{
			count = 0;
			array = nullptr;
		}
		return *this;
	}
};
