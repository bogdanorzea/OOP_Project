#include "..\FractionProgram\FractionClass.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(Fractions_CreateWithOneArgument)
		{
			// Integer fraction type
			Assert::AreEqual(Fraction<int>(2).Numerator(), 2);
			Assert::AreEqual(Fraction<int>(2).Denominator(), 1);

			// Long fraction type
			Assert::AreEqual(Fraction<long>(2L).Numerator(), 2L);
			Assert::AreEqual(Fraction<long>(2L).Denominator(), 1L);

			// Double fraction type
			Assert::AreEqual(Fraction<double>(2.0).Numerator(), 2.0);
			Assert::AreEqual(Fraction<double>(2.0).Denominator(), 1.0);

			// Float fraction type
			Assert::AreEqual(Fraction<float>(2.f).Numerator(), 2.f);
			Assert::AreEqual(Fraction<float>(2.f).Denominator(), 1.f);
		}

		TEST_METHOD(Fractions_CreateWithTwoArguments)
		{
			// Integer fraction type
			Assert::AreEqual(Fraction<int>(2, 3).Numerator(), 2);
			Assert::AreEqual(Fraction<int>(2, 3).Denominator(), 3);

			// Long fraction type
			Assert::AreEqual(Fraction<long>(2L, 3L).Numerator(), 2L);
			Assert::AreEqual(Fraction<long>(2L, 3L).Denominator(), 3L);

			// Double fraction type
			Assert::AreEqual(Fraction<double>(2.0, 3.0).Numerator(), 2.0);
			Assert::AreEqual(Fraction<double>(2.0, 3.0).Denominator(), 3.0);

			// Float fraction type
			Assert::AreEqual(Fraction<float>(2.f, 3.f).Numerator(), 2.f);
			Assert::AreEqual(Fraction<float>(2.f, 3.f).Denominator(), 3.f);
		}

		TEST_METHOD(Fractions_CreateWithNegativeArguments) {
			// Negative Integer fraction type
			Assert::AreEqual(Fraction<int>(-2, 3).Numerator(), -2);
			Assert::AreEqual(Fraction<int>(-2, 3).Denominator(), 3);

			// Negative Integer fraction type
			Assert::AreEqual(Fraction<int>(2, -3).Numerator(), -2);
			Assert::AreEqual(Fraction<int>(2, -3).Denominator(), 3);

			// Negative Integer fraction type
			Assert::AreEqual(Fraction<int>(-2, -3).Numerator(), 2);
			Assert::AreEqual(Fraction<int>(-2, -3).Denominator(), 3);
		}

		TEST_METHOD(Fractions_OperatorAddition) {
			Fraction<int> temp1 = Fraction<int>(3, 2);
			Fraction<int> temp2 = Fraction<int>(1, 2);
			Assert::AreEqual((temp1 + temp2).Numerator(), 2);
			Assert::AreEqual((temp1 + temp2).Denominator(), 1);


			Fraction<int> temp3 = Fraction<int>(5, 99);
			Fraction<int> temp4 = Fraction<int>(40, 21);
			Assert::AreEqual((temp3 + temp4).Numerator(), 1355);
			Assert::AreEqual((temp3 + temp4).Denominator(), 693);
			Assert::AreEqual((-temp3 + -temp4).Numerator(), -1355);
			Assert::AreEqual((-temp3 + -temp4).Denominator(), 693);
		}

		TEST_METHOD(Fractions_OperatorAdditionUnary) {
			Fraction<int> temp1 = Fraction<int>(-3, 2);
			Assert::AreEqual((+temp1).Numerator(), -3);
			Assert::AreEqual((+temp1).Denominator(), 2);

			Fraction<double> temp2 = Fraction<double>(5.0, 99.0);
			Assert::AreEqual((+temp2).Numerator(), +5.0);
			Assert::AreEqual((+temp2).Denominator(), 99.0);
		}

		TEST_METHOD(Fractions_OperatorSubstraction) {
			Fraction<int> temp1 = Fraction<int>(3, 2);
			Fraction<int> temp2 = Fraction<int>(1, 2);
			Assert::AreEqual((temp1 - temp2).Numerator(), 1);
			Assert::AreEqual((temp1 - temp2).Denominator(), 1);
			Assert::AreEqual((-temp1 - temp2).Numerator(), -2);
			Assert::AreEqual((-temp1 - temp2).Denominator(), 1);

			Fraction<int> temp3 = Fraction<int>(5, 99);
			Fraction<int> temp4 = Fraction<int>(40, 21);
			Assert::AreEqual((temp3 - temp4).Numerator(), -1285);
			Assert::AreEqual((temp3 - temp4).Denominator(), 693);
			Assert::AreEqual((-temp3 - -temp4).Numerator(), 1285);
			Assert::AreEqual((-temp3 - -temp4).Denominator(), 693);
		}

		TEST_METHOD(Fractions_OperatorSubstractionUnary) {
			Fraction<int> temp1 = Fraction<int>(3, 2);
			Assert::AreEqual((-temp1).Numerator(), -3);
			Assert::AreEqual((-temp1).Denominator(), 2);

			Fraction<double> temp2 = Fraction<double>(5.0, 99.0);
			Assert::AreEqual((-temp2).Numerator(), -5.0);
			Assert::AreEqual((-temp2).Denominator(), 99.0);
		}

		TEST_METHOD(Fractions_OperatorAssignment) {
			Fraction<int> temp1 = Fraction<int>(3, 2);
			Fraction<int> temp2 = Fraction<int>(1, 2);
			temp2 = temp1;
			Assert::AreEqual((temp2).Numerator(), 3);
			Assert::AreEqual((temp2).Denominator(), 2);


			Fraction<double> temp3 = Fraction<double>(5.1, 99.88);
			Fraction<double> temp4 = Fraction<double>(-40.56, 21.88976);

			temp3 = temp4;
			Assert::AreEqual(temp3.Numerator(), -40.56);
			Assert::AreEqual(temp3.Denominator(), 21.88976);

		}

		TEST_METHOD(Fractions_OperatorMultiplcation) {
			Fraction<int> temp1 = Fraction<int>(3, 2);
			Fraction<int> temp2 = Fraction<int>(1, 2);
			Assert::AreEqual((temp1 * temp2).Numerator(), 3);
			Assert::AreEqual((temp1 * temp2).Denominator(), 4);


			Fraction<int> temp3 = Fraction<int>(5, 99);
			Fraction<int> temp4 = Fraction<int>(40, 21);
			Assert::AreEqual((temp3 * temp4).Numerator(), 5 * 40);
			Assert::AreEqual((temp3 * temp4).Denominator(), 99 * 21);
		}

		TEST_METHOD(Fractions_OperatorDivision) {
			Fraction<int> temp1 = Fraction<int>(3, 2);
			Fraction<int> temp2 = Fraction<int>(1, 2);
			Assert::AreEqual((temp1 / temp2).Numerator(), 3);
			Assert::AreEqual((temp1 / temp2).Denominator(), 1);


			Fraction<int> temp3 = Fraction<int>(5, 99);
			Fraction<int> temp4 = Fraction<int>(40, 21);
			Assert::AreEqual((temp3 / temp4).Numerator(), 7);
			Assert::AreEqual((temp3 / temp4).Denominator(), 264);
		}

		TEST_METHOD(Fractions_DivideByZero)
		{
			bool exceptionThrown = false;
			Fraction<int> _fraction = Fraction<int>(2, 1);
			Fraction<int> _fractionZero = Fraction<int>(0, 1);

			try
			{
				_fraction / _fractionZero;
			}
			catch (const std::overflow_error e)
			{
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown);

		}

		TEST_METHOD(Fractions_SimplifyFraction) {
			Fraction<int> temp1 = Fraction<int>(3, 2);
			temp1.Simplify();
			Assert::AreEqual(temp1.Numerator(), 3);
			Assert::AreEqual(temp1.Denominator(), 2);

			Fraction<int> temp2 = Fraction<int>(8, 2);
			temp2.Simplify();
			Assert::AreEqual(temp2.Numerator(), 4);
			Assert::AreEqual(temp2.Denominator(), 1);

			Fraction<int> temp3 = Fraction<int>(33, 99);
			temp3.Simplify();
			Assert::AreEqual(temp3.Numerator(), 1);
			Assert::AreEqual(temp3.Denominator(), 3);

			Fraction<int> temp4 = Fraction<int>(49, 14);
			temp4.Simplify();
			Assert::AreEqual(temp4.Numerator(), 7);
			Assert::AreEqual(temp4.Denominator(), 2);

			Fraction<double> fract5 = Fraction<double>(2.0, 2.0);
			fract5.Simplify();
			Assert::AreEqual(fract5.Numerator(), 2.0);
			Assert::AreEqual(fract5.Denominator(), 2.0);

			Fraction<float> fract6 = Fraction<float>(2.0f, 2.0f);
			fract6.Simplify();
			Assert::AreEqual(fract6.Numerator(), 2.0f);
			Assert::AreEqual(fract6.Denominator(), 2.0f);
		}

		TEST_METHOD(Fractions_CastToDouble) {
			Fraction<int> temp1 = Fraction<int>(3, 2);
			Assert::AreEqual((double)temp1, 1.5);
			Assert::AreEqual(temp1.ToDouble(), 1.5);

			Fraction<double> temp2 = Fraction<double>(3.0);
			Assert::AreEqual((double)temp2, 3.0);
			Assert::AreEqual(temp2.ToDouble(), 3.0);
		}

		TEST_METHOD(Fractions_OperatorExponentiation) {
			Fraction<int> temp1 = Fraction<int>(3, 2);
			temp1 = temp1 ^ 2;
			Assert::AreEqual(temp1.Numerator(), 9);
			Assert::AreEqual(temp1.Denominator(), 4);

			Fraction<int> fract1r = Fraction<int>(3, 2);
			fract1r = fract1r ^ -2;
			Assert::AreEqual(fract1r.Numerator(), 4);
			Assert::AreEqual(fract1r.Denominator(), 9);

			Fraction<double> temp2 = Fraction<double>(2.0, 3.0);
			temp2 = temp2 ^ 2.0;
			Assert::AreEqual(temp2.Numerator(), 4.0);
			Assert::AreEqual(temp2.Denominator(), 9.0);

			Fraction<double> temp3 = Fraction<double>(1.0, 3.0);
			temp3 = temp3 ^ -1.0;
			Assert::AreEqual(temp3.Numerator(), 3.0);
			Assert::AreEqual(temp3.Denominator(), 1.0);

			Fraction<double> temp4 = Fraction<double>(1.0, 3.0);
			temp3 = temp3 ^ -0.0;
			Assert::AreEqual(temp3.Numerator(), 1.0);
			Assert::AreEqual(temp3.Denominator(), 1.0);
		}

		TEST_METHOD(Fractions_OperatorComparations) {
			Assert::AreEqual(Fraction<double>(1.0, 3.0) == Fraction<double>(2.0, 3.0), false);
			Assert::AreEqual(Fraction<int>(3, 2) == Fraction<int>(12, 8), true);
			Assert::AreEqual(Fraction<int>(3, 2) == Fraction<int>(3, 2), true);
			Assert::AreEqual(Fraction<double>(3.0, 2.0) == Fraction<double>(3.0, 2.0), true);
			Assert::AreEqual(Fraction<int>(3, 2) == Fraction<int>(3, 3), false);
			Assert::AreEqual(Fraction<double>(3.0, 2.0) == Fraction<double>(3.0, 3.0), false);

			Assert::AreEqual(Fraction<int>(3, 2) < Fraction<int>(5, 2), true);
			Assert::AreEqual(Fraction<double>(3.0, 2.0) < Fraction<double>(5.0, 2.0), true);
			Assert::AreEqual(Fraction<int>(3, 2) < Fraction<int>(3, 2), false);
			Assert::AreEqual(Fraction<int>(3, 2) <= Fraction<int>(3, 2), true);

			Assert::AreEqual(Fraction<int>(3, 2) > Fraction<int>(5, 2), false);
			Assert::AreEqual(Fraction<double>(3.0, 2.0) > Fraction<double>(1.0, 2.0), true);
			Assert::AreEqual(Fraction<int>(3, 2) > Fraction<int>(3, 2), false);
			Assert::AreEqual(Fraction<int>(3, 2) >= Fraction<int>(3, 2), true);
		}

		//TEST_METHOD(CastToFractions) {
		//	
		//}
	};
}