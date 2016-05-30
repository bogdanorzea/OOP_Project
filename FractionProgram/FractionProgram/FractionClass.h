#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

#pragma region Declaration
template <class T>
class Fraction
{
	T numerator, denominator;

public:
	Fraction();
	Fraction(T);
	Fraction(T, T);

	T Numerator();
	T Denominator();

	Fraction<T> operator+(Fraction<T>);

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
Fraction<T>::Fraction(T _num)
{
	numerator = _num;
	denominator = (T)1;
	cout << "Fraction is " << _num << endl;
}

template <class T>
Fraction<T>::Fraction(T _num, T _den)
{
	numerator = _num;
	denominator = _den;
	cout << "Fraction is " << _num << "/" << _den << endl;
}

template <class T>
Fraction<T>::~Fraction()
{
}

template <class T>
T Fraction<T>::Numerator()
{
	return numerator;
}

template <class T>
T Fraction<T>::Denominator()
{
	return denominator;
}

template<class T>
Fraction<T> Fraction<T>::operator+(Fraction<T> _fraction)
{
	T _den = LCM(denominator, _fraction.Denominator());
	T _num = numerator * _den / _fraction.Denominator() + _fraction.Numerator() * _den / denominator;

	Fraction<T> retFraction = Fraction<T>(_num, _den);
	return retFraction;
}

template<class T>
double Fraction<T>::ToDouble()
{
	return (double)numerator / denominator;
}

#pragma endregion

template<class T>
T LCM(T first, T second) {
	return (T)(first / GCD(first, second) * second);
}

template<class T>
T GCD(T first, T second) {
	if (second == 0) return first;
	else return GCD(second, first % second);
}