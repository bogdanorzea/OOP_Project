#pragma once
#include <stdio.h>
#include <iostream>

#define	SIGN(x) ((x < 0) ? ("-") : ("+"))

using namespace std;

#pragma region Declaration
template <class T>
class Complex
{
	T real, imaginary;
	Complex();

public:

	Complex(T, T = (T)0);

	T Real();
	T Imaginary();

	Complex<T> operator+(Complex<T>);
	Complex<T> operator+(T);
	Complex<T> operator+();
	Complex<T> operator-(Complex<T>);
	Complex<T> operator-(T);
	Complex<T> operator-();
	Complex<T>& operator=(Complex<T>);
	Complex<T> operator*(Complex<T>);
	Complex<T> operator*(T);
	Complex<T> operator/(Complex<T>);
	Complex<T> operator/(T);

	Complex<T> operator^(int);

	bool operator==(Complex<T>);
	bool operator<(Complex<T>);
	bool operator<=(Complex<T>);
	bool operator>(Complex<T>);
	bool operator>=(Complex<T>);

	Complex<T> Conjugate();

	double Modulus();

	~Complex();
};
#pragma endregion

#pragma region Implementation

template <class T>
Complex<T>::Complex()
{
	cout << "Complex number is " << real << SIGN(imaginary) << imaginary << "*i" << endl;
}

template <class T>
Complex<T>::Complex(T _real, T _imag = (T)0)
{
	real = _real;
	imaginary = _imag;

	cout << "Complex number is " << real << SIGN(imaginary) << imaginary << "*i" << endl;
}

template <class T>
Complex<T>::~Complex()
{
}

template <class T>
inline T Complex<T>::Real()
{
	return real;
}

template <class T>
inline T Complex<T>::Imaginary()
{
	return imaginary;
}

template<class T>
Complex<T> Complex<T>::operator+(Complex<T> _complex)
{
	T _real = real + _complex.Real();
	T _imag = imaginary + _complex.Imaginary();

	return Complex<T>(_real, _imag);
}

template<class T>
Complex<T> Complex<T>::operator+(T _number)
{
	return Complex<T>(real + _number, imaginary);
}

template<class T>
Complex<T> Complex<T>::operator+()
{
	return Complex<T>(real, imaginary);
}

template<class T>
Complex<T> Complex<T>::operator-(Complex<T> _complex)
{
	T _real = real - _complex.Real();
	T _imag = imaginary - _complex.Imaginary();

	return Complex<T>(_real, _imag);
}

template<class T>
Complex<T> Complex<T>::operator-(T _number)
{
	return Complex<T>(real - _number, imaginary);
}

template<class T>
Complex<T> Complex<T>::operator-()
{
	T _real = (-1)*real;
	T _imag = (-1)*imaginary;

	return Complex<T>(_real, _imag);
}

template<class T>
Complex<T>& Complex<T>::operator=(Complex<T> _complex)
{
	imaginary = _complex.Imaginary();
	real = _complex.Real();

	return *this;
}

template<class T>
bool Complex<T>::operator==(Complex<T> _complex)
{
	if (this->Modulus() == _complex.Modulus())
	{
		return true;
	}
	
	return false;
}

template<class T>
bool Complex<T>::operator<(Complex<T> _complex)
{
	if (this->Modulus() < _complex.Modulus())
	{
		return true;
	}
	
	return false;
}

template<class T>
bool Complex<T>::operator<=(Complex<T> _complex)
{
	if (this->Modulus() <= _complex.Modulus())
	{
		return true;
	}
	
	return false;
}

template<class T>
bool Complex<T>::operator>(Complex<T> _complex)
{
	if (this->Modulus() > _complex.Modulus())
	{
		return true;
	}
	
	return false;
}

template<class T>
bool Complex<T>::operator>=(Complex<T> _complex)
{
	if (this->Modulus() >= _complex.Modulus())
	{
		return true;
	}
	
	return false;
}

template<class T>
Complex<T> Complex<T>::Conjugate()
{
	return Complex<T>(real, (-1)*imaginary);
}

template<class T>
double Complex<T>::Modulus()
{
	return (double)((real * real) + (imaginary * imaginary));
}

template<class T>
Complex<T> Complex<T>::operator*(Complex<T> _complex)
{
	T _real = real *  _complex.Real() - imaginary * _complex.Imaginary();
	T _imag = real * _complex.Imaginary() + imaginary * _complex.Real();

	return Complex<T>(_real, _imag);
}

template<class T>
Complex<T> Complex<T>::operator*(T _multiplier)
{
	T _real = real * _multiplier;
	T _imag = imaginary * _multiplier;

	return Complex<T>(_real, _imag);
}

template<class T>
Complex<T> Complex<T>::operator/(Complex<T> _complex)
{
	T _den = (_complex.Conjugate() * _complex).Real();
	return ((*this) * (_complex.Conjugate())) / (_den);
}

template<class T>
Complex<T> Complex<T>::operator/(T _divisor)
{
	T _real = real / _divisor;
	T _imag = imaginary / _divisor;

	return Complex<T>(_real, _imag);
}

template<class T>
Complex<T> Complex<T>::operator^(int _power)
{
	Complex <T> retComplex = Complex<T>(real, imaginary);
	if (0 == _power)
	{
		return Complex<T>(1);
	}
	else if (_power > 0)
	{
		for (int i = 1; i < _power; i++)
		{
			retComplex = retComplex * retComplex;
		}
		return retComplex;
	}
	else {
		for (int i = -1; i > _power; i--)
		{
			retComplex = retComplex * retComplex;
		}
		return Complex<T>(1) / retComplex;
	}
}
#pragma endregion
