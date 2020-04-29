// ConsoleApplication21.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Complex
{

public:
	Complex() { re = 0; im = 0; };
	Complex(double _re, double _im) { re = _re; im = _im; }
	Complex(const Complex& rsh) { re = rsh.re; im = rsh.im; };
	Complex& operator = (Complex);
	Complex operator + (Complex);
	Complex operator - (Complex);
	Complex operator * (Complex&);
	Complex operator / (Complex&);
	Complex& operator += (Complex);
	Complex& operator -= (Complex);
	Complex& operator *= (Complex);
	Complex& operator /=(Complex);
	//friend std::istream& operator >>(std::istream&, Complex&);
	friend std::ostream& operator << (std::ostream&, const Complex&);//
	bool operator == (Complex& rsh);
	bool operator != (Complex& rsh);
	bool operator > (Complex& rsh);
	bool operator < (Complex& rsh);


	Complex& operator=(const Complex& rsh)
	{
		re = rsh.re;
		im = rsh.im;
		return *this;
	}
	bool operator > (const Сomplex& rsh)
	{
		if (this->re > rsh.re)
			return true;
		else if (this->re == rsh.re && this->im > rsh.im)
			return true;
		else
			return false;
	}

	bool operator < (const Сomplex& rsh)
	{
		if (this->re < rsh.re)
			return true;
		else if (this->re == rsh.re && this->im < rsh.im)
			return true;
		else
			return false;

	}

	bool operator != (const Complex& rsh)
	{
		if (this->re != rsh.re || this->im != rsh.im)
			return !(*this == rsh);



	}

	bool operator==(const Complex& rsh)
	{
		if ((re == rsh.re) && (im == rsh.im))
			return true;
		else
			return false;
	}



	Complex operator*(const Complex& rsh)
	{

		double _re = re * rsh.re - im * rsh.im;
		double _im = re * rsh.im + rsh.re * im;
		re = _re;
		im = _im;
		return *this;
	}

	Complex operator/(const Complex& rsh)
	{
		double  k;
		k = re * re + rsh.im * rsh.im;
		double _re = (re * rsh.re + im * rsh.im) / k;
		double _im = (rsh.re * im - re * rsh.im) / k;
		re = _re;
		im = _im;
		return *this;
	}



	Complex operator+(const Complex& rsh)
	{
		re = re + rsh.re;
		im = im + rsh.im;
		return *this;// или return Complex(re + rsh.re,im + rsh.im);
	}

	Complex operator-(const Complex& rsh)
	{
		re = re - rsh.re;
		im = im - rsh.im;
		return *this;
	}


	//std::ostream& operator << (std::ostream& out, const complex& com)
	{
		if (rsh.im < 0)
			out << rsh.re << "+i(" << rsh.im << ")\n";
		else
			out << rsh.re << "+i" << rsh.im << "\n";
		return out;
	}

	std::istream& operator >> (std::istream& in, complex& com)
	{
		std::cout << "Введите действительную часть комплексного числа ";
		in >> rsh.re;
		std::cout << "Введите мнимую часть комплексного числа ";
		in >> rsh.im;
		return in;
	}//

	Complex& operator+=( const Complex& rsh)
	{
		re += rsh.re;
		im += rsh.im;
		return *this;
	}

	Complex& operator-=(complex rsh)
	{
		re -= rsh.re;
		im -= rsh.im;
		return *this;
	}

	Complex& operator*=(complex rsh)
	{
		re *= rsh.re;
		im *= rsh.im;
		return *this;
	}

	Complex& operator/=(complex rsh)
	{
		re /= rsh.re;
		im /= rsh.im;
		return *this;
	}





private:
	double re, im;
};


int main()
{
			setlocale(0, "rus");
			Complex ;
			std::cin >> rsh;
			std::cout << rsh << std::endl;
		}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
