#include "..\FractionProgram\FractionClass.h"
#include "..\FractionProgram\ComplexClass.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(CF_Creation) {
			Fraction<Complex<int>> temp1 = Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1));
			Assert::IsTrue(temp1.Numerator() == Complex<int>(5, 3));
			Assert::IsTrue(temp1.Denominator() == Complex<int>(5, -1));

			Fraction<Complex<int>> temp2 = Fraction<Complex<int>>(Complex<int>(5, 3));
			Assert::IsTrue(temp2.Numerator() == Complex<int>(5, 3));
			Assert::IsTrue(temp2.Denominator() == Complex<int>(1, 0));

			Fraction<Complex<int>> temp3 = Fraction<Complex<int>>(Complex<int>(5));
			Assert::IsTrue(temp3.Numerator() == Complex<int>(5));
			Assert::IsTrue(temp3.Denominator() == Complex<int>(1));

			Assert::AreEqual((+Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1))).Numerator().Real(), 5);
			Assert::AreEqual((+Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1))).Denominator().Imaginary(), -1);
		}

		TEST_METHOD(CF_OperatorAddition) {
			Assert::IsTrue((+Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1))).Numerator() == Complex<int>(5, 3));
			Assert::IsTrue((+Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1))).Denominator() == Complex<int>(5, -1));

			Fraction<Complex<int>> temp1 = Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1));
			Fraction<Complex<int>> temp2 = Fraction<Complex<int>>(Complex<int>(6, 0), Complex<int>(-9, 7));
			Assert::IsTrue((temp1 + temp2).Numerator() == Complex<int>(-36, 2));
			Assert::IsTrue((temp1 + temp2).Denominator() == Complex<int>(-38, 44));
		}

		TEST_METHOD(CF_OperatorSubstraction) {
			Assert::IsTrue((-Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1))).Numerator() == Complex<int>(-5, -3));
			Assert::IsTrue((-Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1))).Denominator() == Complex<int>(5, -1));

			Fraction<Complex<int>> temp1 = Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1));
			Fraction<Complex<int>> temp2 = Fraction<Complex<int>>(Complex<int>(6, 0), Complex<int>(-9, 7));
			Assert::IsTrue((temp1 - temp2).Numerator() == Complex<int>(-96, 14));
			Assert::IsTrue((temp1 - temp2).Denominator() == Complex<int>(-38, 44));
		}

		TEST_METHOD(CF_OperatorMultiplication) {
			Fraction<Complex<int>> temp1 = Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1));
			Fraction<Complex<int>> temp2 = Fraction<Complex<int>>(Complex<int>(6, 0), Complex<int>(-9, 7));
			Assert::IsTrue((temp1 * temp2).Numerator() == Complex<int>(30, 18));
			Assert::IsTrue((temp1 * temp2).Denominator() == Complex<int>(-38, 44));
		}

		TEST_METHOD(CF_OperatorDivision) {
			Fraction<Complex<int>> temp1 = Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1));
			Fraction<Complex<int>> temp2 = Fraction<Complex<int>>(Complex<int>(6, 0), Complex<int>(-9, 7));
			Assert::IsTrue((temp1 / temp2).Numerator() == Complex<int>(-66, 8));
			Assert::IsTrue((temp1 / temp2).Denominator() == Complex<int>(30, -6));
		}

		TEST_METHOD(CF_OperatorExponentation) {
			Fraction<Complex<int>> temp1 = Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1));	
			Fraction<Complex<int>> result = temp1 ^ -1;
			Assert::IsTrue(result.Numerator() == Complex<int>(5, -1));
			Assert::IsTrue(result.Denominator() == Complex<int>(5, 3));

			result = temp1 ^ 3;
			Assert::IsTrue(result.Numerator() == Complex<int>(-10, 198));
			Assert::IsTrue(result.Denominator() == Complex<int>(110, -74));
			
			result = temp1 ^ -2;
			Assert::IsTrue(result.Numerator() == Complex<int>(24, -10));
			Assert::IsTrue(result.Denominator() == Complex<int>(16, 30));
		}

		TEST_METHOD(CF_OperatorComparations) {
			Fraction<Complex<int>> temp1 = Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1));
			Fraction<Complex<int>> temp2 = Fraction<Complex<int>>(Complex<int>(6, 0), Complex<int>(-9, 7));

			Assert::AreEqual(Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1)) == Fraction<Complex<int>>(Complex<int>(6, 0), Complex<int>(-9, 7)), false);
			Assert::AreEqual(Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1)) == Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1)), true);

			Assert::AreEqual(Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1)) > Fraction<Complex<int>>(Complex<int>(6, 0), Complex<int>(-9, 7)), true);
			Assert::AreEqual(Fraction<Complex<int>>(Complex<int>(5, 3), Complex<int>(5, -1)) < Fraction<Complex<int>>(Complex<int>(6, 0), Complex<int>(-9, 7)), false);
		}
	};
}
