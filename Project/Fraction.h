#pragma once

// Declaration
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

	~Fraction();
};

// Implementation
template <class T>
Fraction<T>::Fraction()
{
	cout << "Fraction is " << numerator << "/" << denominator << endl;
}

template <class T>
Fraction<T>::Fraction(T _num)
{
	numerator = _num;
	//denominator = 1;
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