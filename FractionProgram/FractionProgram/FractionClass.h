#pragma once
#include <stdio.h>
#include <iostream>
#include <typeinfo>

using namespace std;

#pragma region Declaration
template <class T>
class Fraction
{
	T numerator, denominator;
	Fraction();

public:
	Fraction(T, T = (T)1);

	T Numerator();
	T Denominator();

	Fraction<T> operator+(Fraction<T>);
	Fraction<T> operator+(T);
	Fraction<T> operator+();
	Fraction<T> operator-(Fraction<T>);
	Fraction<T> operator-(T);
	Fraction<T> operator-();
	Fraction<T>& operator=(Fraction<T>);
	Fraction<T> operator*(Fraction<T>);
	Fraction<T> operator*(T);
	Fraction<T> operator/(Fraction<T>);
	Fraction<T> operator/(T);
	Fraction<T> operator^(int);

	bool operator==(Fraction<T>);
	bool operator<(Fraction<T>);
	bool operator<=(Fraction<T>);
	bool operator>(Fraction<T>);
	bool operator>=(Fraction<T>);

	operator double();

	Fraction<T>& Simplify();

	double ToDouble();

	~Fraction();
};
#pragma endregion

#pragma region Implementation

template <class T>
Fraction<T>::Fraction()
{
	//cout << "Fraction is " << numerator << "/" << denominator << endl;
}

template <class T>
Fraction<T>::Fraction(T _num, T _den = (T)1)
{
	numerator = _num;
	if (_den == (T)0)
	{
		throw std::overflow_error("Divide by zero exception");
	}
	denominator = _den;
	Simplify();

	//cout << "Fraction is " << _num << "/" << _den << endl;
}

template <class T>
Fraction<T>::~Fraction()
{
}

template <class T>
inline T Fraction<T>::Numerator()
{
	return numerator;
}

template <class T>
inline T Fraction<T>::Denominator()
{
	return denominator;
}

template<class T>
Fraction<T> Fraction<T>::operator+(Fraction<T> _fraction)
{
	T _num = numerator * _fraction.Denominator() + _fraction.Numerator() * denominator;
	T _den = denominator * _fraction.Denominator();

	return Fraction<T>(_num, _den);
}

template<class T>
Fraction<T> Fraction<T>::operator+(T _number)
{
	return Fraction<T>(numerator, denominator) + Fraction<T>(_number);
}

template<class T>
Fraction<T> Fraction<T>::operator+()
{
	return Fraction<T>(numerator, denominator);
}

template<class T>
Fraction<T> Fraction<T>::operator-(Fraction<T> _fraction)
{
	T _num = numerator * _fraction.Denominator() - _fraction.Numerator() * denominator;
	T _den = denominator * _fraction.Denominator();

	return Fraction<T>(_num, _den);
}

template<class T>
Fraction<T> Fraction<T>::operator-(T _number)
{
	return Fraction<T>(numerator, denominator) - Fraction<T>(_number);
}

template<class T>
Fraction<T> Fraction<T>::operator-()
{
	T _num = numerator * (-1);
	T _den = denominator;

	Fraction<T> retFraction = Fraction<T>(_num, _den);
	return retFraction;
}

template<class T>
Fraction<T>& Fraction<T>::operator=(Fraction<T> _fraction)
{
	denominator = _fraction.Denominator();
	numerator = _fraction.Numerator();

	return *this;
}

template<class T>
bool Fraction<T>::operator==(Fraction<T> _fraction)
{
	if (this->ToDouble() == _fraction.ToDouble())
	{
		return true;
	}

	return false;
}

template<class T>
bool Fraction<T>::operator<(Fraction<T> _fraction)
{
	if (this->ToDouble() < _fraction.ToDouble())
	{
		return true;
	}

	return false;
}

template<class T>
bool Fraction<T>::operator<=(Fraction<T> _fraction)
{
	if (this->ToDouble() <= _fraction.ToDouble())
	{
		return true;
	}

	return false;
}

template<class T>
bool Fraction<T>::operator>(Fraction<T> _fraction)
{
	if (this->ToDouble() > _fraction.ToDouble())
	{
		return true;
	}

	return false;
}

template<class T>
bool Fraction<T>::operator>=(Fraction<T> _fraction)
{
	if (this->ToDouble() >= _fraction.ToDouble())
	{
		return true;
	}

	return false;
}

template<class T>
Fraction<T>::operator double()
{
	return (double)numerator / denominator;
}

template<class T>
Fraction<T> Fraction<T>::operator*(Fraction<T> _fraction)
{
	T _den = denominator * _fraction.Denominator();
	T _num = numerator *  _fraction.Numerator();

	Fraction<T> retFraction = Fraction<T>(_num, _den);
	return retFraction;
}

template<class T>
Fraction<T> Fraction<T>::operator*(T _multiplicator)
{
	return Fraction<T>(numerator * _multiplicator, denominator);
}

template<class T>
Fraction<T> Fraction<T>::operator/(Fraction<T> _fraction)
{
	T _num = numerator * _fraction.Denominator();
	T _den = denominator * _fraction.Numerator();

	Fraction<T> retFraction = Fraction<T>(_num, _den);
	return retFraction;
}

template<class T>
Fraction<T> Fraction<T>::operator/(T _divisor)
{
	return Fraction<T>(numerator, denominator * _divisor);
}

template<class T>
Fraction<T> Fraction<T>::operator^(int _power)
{
	T _num = numerator;
	T _den = denominator;

	if (_power == 0)
	{
		return Fraction<T>((T)1);
	}
	else if (_power < 0) {
		T temp = _num;
		_num = _den;
		_den = temp;
		_power = (_power) * (-1);
	}

	T temp_num = _num;
	T temp_den = _den;

	for (int i = 1; i < _power; i++)
	{
		_num *= temp_num;
		_den *= temp_den;
	}

	return Fraction<T>(_num, _den);
}

template<class T>
Fraction<T>& Fraction<T>::Simplify()
{
	if (denominator < 0)
	{
		denominator *= (-1);
		numerator *= (-1);
	}

	if (typeid(int).name() == typeid(T).name() || typeid(long).name() == typeid(T).name())
	{
		T abs_num = numerator;
		if ((T)0 > abs_num)
		{
			abs_num *= (-1);
		}
		T divizor = GCD(denominator, abs_num);
		numerator /= divizor;
		denominator /= divizor;
	}
	return *this;
}

template<class T>
double Fraction<T>::ToDouble()
{
	return (double)numerator / denominator;
}

#pragma endregion

#pragma region HelperFunctions
template<class T>
T LCM(T first, T second) {
	return (T)(first / GCD(first, second) * second);
}

template<class T>
T GCD(T first, T second) {
	if (second == 0) return first;
	while (first != second)
	{
		if (first > second) first -= second;
		else second -= first;
	}
	return first;
}
#pragma endregion
