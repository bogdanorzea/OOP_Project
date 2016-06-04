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
	Fraction<T> operator-(Fraction<T>);
	Fraction<T> operator*(Fraction<T>);
	Fraction<T> operator/(Fraction<T>);
	Fraction<T>& operator^(T);

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
Fraction<T> Fraction<T>::operator-(Fraction<T> _fraction)
{
	T _den = LCM(denominator, _fraction.Denominator());
	T _num = numerator * _den / denominator - _fraction.Numerator() * _den / _fraction.Denominator();

	Fraction<T> retFraction = Fraction<T>(_num, _den);
	return retFraction;
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
Fraction<T> Fraction<T>::operator/(Fraction<T> _fraction)
{
	T _num = numerator * _fraction.Denominator();
	T _den = denominator * _fraction.Numerator();

	Fraction<T> retFraction = Fraction<T>(_num, _den);
	return retFraction;
}

template<class T>
Fraction<T>& Fraction<T>::operator^(T _power)
{
	if (_power < 0) {
		T temp = numerator;
		numerator = denominator;
		denominator = temp;
		_power = std::abs(_power);
	}

	numerator = (T)std::pow(numerator, _power);
	denominator = (T)std::pow(denominator, _power);

	return *this;
}

template<class T>
Fraction<T>& Fraction<T>::Simplify()
{
	if (typeid(int).name() == typeid(T).name())
	{
		T divizor = GCD(std::abs(denominator), std::abs(numerator));
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