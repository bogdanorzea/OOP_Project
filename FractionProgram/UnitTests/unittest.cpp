#include "..\FractionProgram\FractionClass.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(CreateTwoArguments)
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

		TEST_METHOD(CreateOneArgument)
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

	};
}