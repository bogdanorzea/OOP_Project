#include "..\FractionProgram\FractionClass.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(CreateWithTwoArguments)
		{
			// Integer fraction type
			Fraction<int> iFraction = Fraction<int>(2, 3);
			Assert::AreEqual(iFraction.Numerator(), 2);
			Assert::AreEqual(iFraction.Denominator(), 3);

			// Long fraction type
			Fraction<long> lFraction = Fraction<long>(2L, 3L);
			Assert::AreEqual(lFraction.Numerator(), 2L);
			Assert::AreEqual(lFraction.Denominator(), 3L);

			// Double fraction type
			Fraction<double> dFraction = Fraction<double>(2.0, 3.0);
			Assert::AreEqual(dFraction.Numerator(), 2.0);
			Assert::AreEqual(dFraction.Denominator(), 3.0);

			// Float fraction type
			Fraction<float> fFraction = Fraction<float>(2.f, 3.f);
			Assert::AreEqual(fFraction.Numerator(), 2.f);
			Assert::AreEqual(fFraction.Denominator(), 3.f);
		}

		TEST_METHOD(CreateWithOneArgument)
		{
			// Integer fraction type
			Fraction<int> iFraction = Fraction<int>(2);
			Assert::AreEqual(iFraction.Numerator(), 2);
			Assert::AreEqual(iFraction.Denominator(), 1);

			// Long fraction type
			Fraction<long> lFraction = Fraction<long>(2L);
			Assert::AreEqual(lFraction.Numerator(), 2L);
			Assert::AreEqual(lFraction.Denominator(), 1L);

			// Double fraction type
			Fraction<double> dFraction = Fraction<double>(2.0);
			Assert::AreEqual(dFraction.Numerator(), 2.0);
			Assert::AreEqual(dFraction.Denominator(), 1.0);

			// Float fraction type
			Fraction<float> fFraction = Fraction<float>(2.f);
			Assert::AreEqual(fFraction.Numerator(), 2.f);
			Assert::AreEqual(fFraction.Denominator(), 1.f);
		}

		TEST_METHOD(FractionToDouble) {
			Fraction<int> fract = Fraction<int>(3, 2);
			Assert::AreEqual(fract.ToDouble(), 1.5);

			Fraction<double> fract2 = Fraction<double>(3.0);
			Assert::AreEqual(fract2.ToDouble(), 3.0);
		}

		TEST_METHOD(AddingFractions) {
			Fraction<int> fract1 = Fraction<int>(3, 2);
			Fraction<int> fract2 = Fraction<int>(1, 2);

			Assert::AreEqual((fract1 + fract2).Numerator(), 4);
			Assert::AreEqual((fract1 + fract2).Denominator(), 2);
			
			
			Fraction<int> fract3 = Fraction<int>(3, 99);
			Fraction<int> fract4 = Fraction<int>(40, 21);

			Assert::AreEqual((fract3 + fract4).Numerator(), 149);
			Assert::AreEqual((fract3 + fract4).Denominator(), 77);
		}

	};
}