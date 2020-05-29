#include <iostream>
#include "vector.hpp"
#include "slae.hpp"

int main() {
	// Получение входных данных
	int n;
	std::cout << "Input dimension" << std::endl;
	std::cin >> n;
	SLAE A(n);
	Vector<double> b = Vector<double>(n);
	double tmp;
	std::cout << "Input matrix" << std::endl;
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n; ++j) 
		{
			std::cout << "A[" << i << "][" << j << "] = ";
			std::cin >> A[i][j];
			std::cout << std::endl;
		}
	}
	std::cout << "Input right vector " << b.size() <<  std::endl;
	for (int i = 0; i < n; ++i) 
	{
		std::cout << "b[" << i << "] = ";
		std::cin >> b[i];
		std::cout << std::endl;
	}
	
	// Решение системы и вывод результата
	Vector<double> result = A.solve_Gauss_method(b);
	std::cout << "Answer:" << std::endl << "{ ";
	for(int i = 0; i < n; ++i) 
	{
		std::cout << result[i] << ' ';
	}
	std::cout << "}" << std::endl;
	
	return 0;
}
