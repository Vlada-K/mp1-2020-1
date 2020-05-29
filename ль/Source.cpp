#include <iostream>
#include"Header.h"

void Complex::print()
{
std:: cout << re << " +" << im << "i";
}

Complex operator+(const double& Ihs, const Complex& rsh)
{
	return Complex(Ihs + rsh.re, rsh.im);
 }

//Complex operator+(const Complex& rsh, const double& Ihs)
{
	return Complex(rsh.im,  a+rsh.re);//
}
 Complex operator*(const double& a, const Complex& rsh);
 {
	 return Complex(rsh.re * a, rsh.im * a);
 }

 Complex operator*(const Complex& rsh, const double& a);
 {
	 return Complex(rsh.im * a, rsh.re * a);
 }

 ostream& operator<< (ostream& os, const Complex& rsh)
 {
	 if (rsh.im < 0)
		 os << rsh.re << "+i(" << rsh.im << ")\n";
	 else
		 os << rsh.re << "+i" << rsh.im << "\n";
	 return os;
 }

 istream& operator>>(istream& is, const Complex& rsh)
 {
	 std::cout << "¬ведите действительную часть комплексного числа ";
	 is >> rsh.re;
	 std::cout << "¬ведите мнимую часть комплексного числа ";
	 is >> rsh.im;
	 return is;
 }

 //void main()
 {
	 setlocale(0, "rus");
	 Complex rsh;// or Complex(1.3, 2.4)
	 std::cin >> rsh;
	 std::cout << rsh << std::endl;
 }//


