#include <iostream>
class Complex
{
public:
	Complex(double _re, double _im)
	{
		re = _re;
		im = _im;
	}

	Complex()
	{
		re = 0;
		im = 0;
	};

	Complex& operator=(const Complex& other)
	{
		re=other.re; 
		im = other.im;
		return*this;
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
		return *this;// или return Complex(re - rsh.re,im - rsh.im);
	}
	Complex operator*(const Complex& rsh)
	{

		re = re * rsh.re - im * rsh.im;
		im = re * rsh.im + rsh.re * im;
		
		return Complex(re * rsh.re - im * rsh.im, re * rsh.im + rsh.re * im);
	}
	Complex operator/(const Complex& rsh)
	{
		double  k1, k2;
		k1 = (re * rsh.re + im * rsh.im) / (rsh.re * rsh.re + rsh.im * rsh.im);
		k2 = (rsh.re * im - re * rsh.im) / (rsh.re * rsh.re + rsh.im * rsh.im);
		re = k1;
		im = k2;
		return *this;
	}
	Complex& operator+=(const Complex& rsh)
	{
		double _rre = re + rsh.re;
		double _imm = im + rsh.im;
		re = _rre;
		im = _imm;
		return *this;
	}
	bool operator==(const Complex& rsh)
	{
		if ((re == rsh.re) && (im == rsh.im))
			return true;
		else
			return false;
	}
	bool operator != (const Complex& rsh)
	{
		if (re != rsh.re || im != rsh.im)//if (this->re != rsh.re || this->im != rsh.im)//
			return !(*this == rsh);
	}
	bool operator < (const Complex& rsh)
	{
		if (re < rsh.re)//if (this->re < rsh.re)
		return true;
		else 
			if (re == rsh.re && im < rsh.im)//if (this->re == rsh.re && this->im < rsh.im)
		return true;
		else
		return false;
		

	}
	bool operator > (const Complex& rsh)
	{
		if (re > rsh.re)//if (this->re > rsh.re)//
			return true;
		else 
			if (re == rsh.re && im > rsh.im)//if (this->re == rsh.re && this->im > rsh.im)//
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& os, const Complex& rsh);
	friend istream& operator<<(istream& is, const Complex& rsh);

	void print();

	friend Complex operator+(const double& Ihs, const Complex& rsh);
	//friend Complex operator+(const Complex& rsh, const double& Ihs);//
	friend Complex operator*(const double& a, const Complex& rsh);
	friend Complex operator*(const Complex& rsh, const double& a );

private:
	double re, im;




};
