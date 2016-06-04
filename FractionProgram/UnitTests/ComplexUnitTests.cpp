#include "..\FractionProgram\ComplexClass.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(Complex_CreateWithOneArgument)
		{
			// Integer fraction type
			Assert::AreEqual(Complex<int>(2).Real(), 2);
			Assert::AreEqual(Complex<int>(2).Imaginary(), 0);

			// Long fraction type
			Assert::AreEqual(Complex<long>(2L).Real(), 2L);
			Assert::AreEqual(Complex<long>(2L).Imaginary(), 0L);

			// Double fraction type
			Assert::AreEqual(Complex<double>(2.0).Real(), 2.0);
			Assert::AreEqual(Complex<double>(2.0).Imaginary(), 0.0);

			// Float fraction type
			Assert::AreEqual(Complex<float>(2.f).Real(), 2.f);
			Assert::AreEqual(Complex<float>(2.f).Imaginary(), 0.f);
		}

		TEST_METHOD(Complex_CreateWithTwoArguments)
		{
			// Integer fraction type
			Assert::AreEqual(Complex<int>(2, 3).Real(), 2);
			Assert::AreEqual(Complex<int>(2, 3).Imaginary(), 3);

			// Long fraction type
			Assert::AreEqual(Complex<long>(2L, 3L).Real(), 2L);
			Assert::AreEqual(Complex<long>(2L, 3L).Imaginary(), 3L);

			// Double fraction type
			Assert::AreEqual(Complex<double>(2.0, 3.0).Real(), 2.0);
			Assert::AreEqual(Complex<double>(2.0, 3.0).Imaginary(), 3.0);

			// Float fraction type
			Assert::AreEqual(Complex<float>(2.f, 3.f).Real(), 2.f);
			Assert::AreEqual(Complex<float>(2.f, 3.f).Imaginary(), 3.f);
		}

		TEST_METHOD(Complex_CreateWithNegativeArguments) {
			// Negative Integer fraction type
			Assert::AreEqual(Complex<int>(-2, 3).Real(), -2);
			Assert::AreEqual(Complex<int>(-2, 3).Imaginary(), 3);

			// Negative Integer fraction type
			Assert::AreEqual(Complex<int>(2, -3).Real(), 2);
			Assert::AreEqual(Complex<int>(2, -3).Imaginary(), -3);

			// Negative Integer fraction type
			Assert::AreEqual(Complex<int>(-2, -3).Real(), -2);
			Assert::AreEqual(Complex<int>(-2, -3).Imaginary(), -3);
		}

		TEST_METHOD(Complex_OperatorAddition) {
			Complex<int> temp1 = Complex<int>(3, 2) + Complex<int>(1, 2);
			Assert::AreEqual(temp1.Real(), 4);
			Assert::AreEqual(temp1.Imaginary(), 4);

			Complex<long> temp2 = Complex<long>(3L, 2L) + Complex<long>(99L, 2L);
			Assert::AreEqual(temp2.Real(), 102L);
			Assert::AreEqual(temp2.Imaginary(), 4L);

			Complex<double> temp3 = Complex<double>(3.0, 2.0) + Complex<double>(1.0, 2.9);
			Assert::AreEqual(temp3.Real(), 4.0);
			Assert::AreEqual(temp3.Imaginary(), 4.9);

			Complex<double> temp4 = Complex<double>(3.0, 2.0) + 1.0;
			Assert::AreEqual(temp4.Real(), 4.0);
			Assert::AreEqual(temp4.Imaginary(), 2.0);
		}

		TEST_METHOD(Complex_OperatorAdditionUnary) {
			Complex<int> temp1 = Complex<int>(-3, 2);
			Assert::AreEqual((+temp1).Real(), -3);
			Assert::AreEqual((+temp1).Imaginary(), 2);

			Complex<double> temp2 = Complex<double>(5.0, 99.0);
			Assert::AreEqual((+temp2).Real(), +5.0);
			Assert::AreEqual((+temp2).Imaginary(), 99.0);
		}

		TEST_METHOD(Complex_OperatorSubstraction) {
			Complex<int> temp1 = Complex<int>(3, 2);
			Complex<int> temp2 = Complex<int>(1, 2);
			Assert::AreEqual((temp1 - temp2).Real(), 2);
			Assert::AreEqual((temp1 - temp2).Imaginary(), 0);
			Assert::AreEqual((-temp1 - temp2).Real(), -4);
			Assert::AreEqual((-temp1 - temp2).Imaginary(), -4);

			Complex<int> temp3 = Complex<int>(5, 99);
			Complex<int> temp4 = Complex<int>(40, 21);
			Assert::AreEqual((temp3 - temp4).Real(), -35);
			Assert::AreEqual((temp3 - temp4).Imaginary(), 78);
			Assert::AreEqual((-temp3 - -temp4).Real(), 35);
			Assert::AreEqual((-temp3 - -temp4).Imaginary(), -78);

			Complex<double> temp5 = Complex<double>(3.0, 2.0) - 1.0;
			Assert::AreEqual(temp5.Real(), 2.0);
			Assert::AreEqual(temp5.Imaginary(), 2.0);
		}

		TEST_METHOD(Complex_OperatorSubstractionUnary) {
			Complex<int> temp1 = Complex<int>(3, 2);
			Assert::AreEqual((-temp1).Real(), -3);
			Assert::AreEqual((-temp1).Imaginary(), -2);

			Complex<double> temp2 = Complex<double>(5.0, 99.0);
			Assert::AreEqual((-temp2).Real(), -5.0);
			Assert::AreEqual((-temp2).Imaginary(), -99.0);
		}

		TEST_METHOD(Complex_OperatorAssignment) {
			Complex<int> temp1 = Complex<int>(3, 2);
			Complex<int> temp2 = Complex<int>(1, 2);
			temp2 = temp1;
			Assert::AreEqual((temp2).Real(), 3);
			Assert::AreEqual((temp2).Imaginary(), 2);

			Complex<double> temp3 = Complex<double>(5.1, 99.88);
			Complex<double> temp4 = Complex<double>(-40.56, 21.88976);
			temp3 = temp4;
			Assert::AreEqual(temp3.Real(), -40.56);
			Assert::AreEqual(temp3.Imaginary(), 21.88976);

		}

		TEST_METHOD(Complex_OperatorMultiplcation) {
			Complex<int> temp1 = Complex<int>(3, 2);
			Complex<int> temp2 = Complex<int>(1, 2);
			Assert::AreEqual((temp1 * temp2).Real(), -1);
			Assert::AreEqual((temp1 * temp2).Imaginary(), 8);


			Complex<int> temp3 = Complex<int>(5, 99);
			Complex<int> temp4 = Complex<int>(40, 21);
			Assert::AreEqual((temp3 * temp4).Real(), -1879);
			Assert::AreEqual((temp3 * temp4).Imaginary(), 4065);

			Complex<double> temp5 = Complex<double>(3.0, 2.0) * 4.0;
			Assert::AreEqual(temp5.Real(), 12.0);
			Assert::AreEqual(temp5.Imaginary(), 8.0);
		}

		TEST_METHOD(Complex_OperatorDivision) {
			Complex<int> temp1 = Complex<int>(3, 2);
			Complex<int> temp2 = Complex<int>(1, 2);
			Assert::AreEqual((temp1 / temp2).Real(), 1);
			Assert::AreEqual((temp1 / temp2).Imaginary(), 0);

			Complex<double> temp3 = Complex<double>(5.56, 91.77);
			Complex<double> temp4 = Complex<double>(4.80, 2.781);
			Assert::AreEqual((temp3 / temp4).Real(), 9.16, 0.01);
			Assert::AreEqual((temp3 / temp4).Imaginary(), 13.81, 0.01);

			Complex<double> temp5 = Complex<double>(3.0, 2.0) / 4.0;
			Assert::AreEqual(temp5.Real(), 0.75);
			Assert::AreEqual(temp5.Imaginary(), 0.5);
		}

		TEST_METHOD(Complex_OperatorExponentiation) {
			Complex<int> temp1 = Complex<int>(3, 2);
			temp1 = temp1 ^ 2;
			Assert::AreEqual(temp1.Real(), 5);
			Assert::AreEqual(temp1.Imaginary(), 12);

			Complex<double> temp2 = Complex<double>(2.0, 3.0);
			temp2 = temp2 ^ 2;
			Assert::AreEqual(temp2.Real(), -5.0);
			Assert::AreEqual(temp2.Imaginary(), 12.0);

			Complex<double> temp3 = Complex<double>(1.0, 3.0);
			temp3 = temp3 ^ -1;
			Assert::AreEqual(temp3.Real(), (double)1 / 10);
			Assert::AreEqual(temp3.Imaginary(), (double)-3 / 10);

			Complex<double> temp4 = Complex<double>(1.0, 3.0);
			temp3 = temp3 ^ 0;
			Assert::AreEqual(temp3.Real(), 1.0);
			Assert::AreEqual(temp3.Imaginary(), 0.0);

			Complex<int> temp5 = Complex<int>(3, 2);
			temp5 = temp5 ^ -2;
			Assert::AreEqual(temp5.Real(), 5 / 169);
			Assert::AreEqual(temp5.Imaginary(), 12 / 169);
		}

		TEST_METHOD(Complex_OperatorComparations) {
			Assert::AreEqual(Complex<double>(1.0, 3.0) == Complex<double>(2.0, 3.0), false);
			Assert::AreEqual(Complex<int>(3, 2) == Complex<int>(12, 8), false);
			Assert::AreEqual(Complex<int>(3, 2) == Complex<int>(3, 2), true);
			Assert::AreEqual(Complex<double>(3.0, 2.0) == Complex<double>(3.0, 2.0), true);
			Assert::AreEqual(Complex<int>(3, 2) == Complex<int>(3, 3), false);
			Assert::AreEqual(Complex<double>(3.0, 2.0) == Complex<double>(3.0, 3.0), false);

			Assert::AreEqual(Complex<int>(3, 2) < Complex<int>(5, 2), true);
			Assert::AreEqual(Complex<double>(3.0, 2.0) < Complex<double>(5.0, 2.0), true);
			Assert::AreEqual(Complex<int>(3, 2) < Complex<int>(3, 2), false);
			Assert::AreEqual(Complex<int>(3, 2) <= Complex<int>(3, 2), true);

			Assert::AreEqual(Complex<int>(3, 2) > Complex<int>(5, 2), false);
			Assert::AreEqual(Complex<double>(3.0, 2.0) > Complex<double>(1.0, 2.0), true);
			Assert::AreEqual(Complex<int>(3, 2) > Complex<int>(3, 2), false);
			Assert::AreEqual(Complex<int>(3, 2) >= Complex<int>(3, 2), true);
		}

	};
}