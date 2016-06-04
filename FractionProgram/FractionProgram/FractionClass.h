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
	Fraction<T> operator^(T);

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
	cout << "Fraction is " << numerator << "/" << denominator << endl;
}

template <class T>
Fraction<T>::Fraction(T _num, T _den = (T)1)
{
	numerator = _num;
	if (0 == _den)
	{
		throw std::overflow_error("Divide by zero exception");
	}
	denominator = _den;
	Simplify();

	cout << "Fraction is " << _num << "/" << _den << endl;
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
	// TODO will not work for floats	
	T _den = LCM(denominator, _fraction.Denominator());
	T _num = numerator * _den / denominator + _fraction.Numerator() * _den / _fraction.Denominator();

	Fraction<T> retFraction = Fraction<T>(_num, _den);
	return retFraction;
}

template<class T>
Fraction<T> Fraction<T>::operator+(T _number)
{
	return Fraction<T>(numerator, denominator) + Fraction<T>(_number);
}

template<class T>
Fraction<T> Fraction<T>::operator+()
{
	T _num = numerator;
	T _den = denominator;

	Fraction<T> retFraction = Fraction<T>(_num, _den);
	return retFraction;
}

template<class T>
Fraction<T> Fraction<T>::operator-(Fraction<T> _fraction)
{
	T _den = LCM(denominator, _fraction.Denominator());
	T _num = numerator * _den / denominator - _fraction.Numerator() * _den / _fraction.Denominator();

	Fraction<T> retFraction = Fraction<T>(_num, _den);
	return retFraction;
}

template<class T>
Fraction<T> Fraction<T>::operator-(T _number)
{
	return Fraction<T>(numerator, denominator) - Fraction<T>(_number);
}

template<class T>
Fraction<T> Fraction<T>::operator-()
{
	T _num = (-1)*numerator;
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
Fraction<T> Fraction<T>::operator^(T _power)
{
	T _num = numerator;
	T _den = denominator;

	if (_power < 0) {
		T temp = _num;
		_num = _den;
		_den = temp;
		_power = std::abs(_power);
	}

	_num = (T)std::pow(_num, _power);
	_den = (T)std::pow(_den, _power);

	Fraction<T> retFraction = Fraction<T>(_num, _den);
	return retFraction;
}

template<class T>
Fraction<T>& Fraction<T>::Simplify()
{
	// Ensures that denominator is always positive
	if (denominator < 0)
	{
		denominator *= (-1);
		numerator *= (-1);
	}

	if (typeid(int).name() == typeid(T).name())
	{
		T divizor = GCD(denominator, std::abs(numerator));
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
	if (second == 0) {
		return first;
	}
	else {
		return GCD(second, (T)std::fmod(first, second));
	}
}
#pragma endregion
