#include "..\FractionProgram\FractionClass.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest)
	{
	public:

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
		
		TEST_METHOD(AddingFractions) {
			Fraction<int> fract1 = Fraction<int>(3, 2);
			Fraction<int> fract2 = Fraction<int>(1, 2);
			Assert::AreEqual((fract1 + fract2).Numerator(), 2);
			Assert::AreEqual((fract1 + fract2).Denominator(), 1);


			Fraction<int> fract3 = Fraction<int>(5, 99);
			Fraction<int> fract4 = Fraction<int>(40, 21);
			Assert::AreEqual((fract3 + fract4).Numerator(), 1355);
			Assert::AreEqual((fract3 + fract4).Denominator(), 693);
			Assert::AreEqual((-fract3 + -fract4).Numerator(), -1355);
			Assert::AreEqual((-fract3 + -fract4).Denominator(), 693);
		}

		TEST_METHOD(UnaryAddingFractions) {
			Fraction<int> fract1 = Fraction<int>(-3, 2);
			Assert::AreEqual((+fract1).Numerator(), -3);
			Assert::AreEqual((+fract1).Denominator(), 2);

			Fraction<double> fract2 = Fraction<double>(5.0, 99.0);
			Assert::AreEqual((+fract2).Numerator(), +5.0);
			Assert::AreEqual((+fract2).Denominator(), 99.0);
		}

		TEST_METHOD(SubstractingFractions) {
			Fraction<int> fract1 = Fraction<int>(3, 2);
			Fraction<int> fract2 = Fraction<int>(1, 2);
			Assert::AreEqual((fract1 - fract2).Numerator(), 1);
			Assert::AreEqual((fract1 - fract2).Denominator(), 1);
			Assert::AreEqual((-fract1 - fract2).Numerator(), -2);
			Assert::AreEqual((-fract1 - fract2).Denominator(), 1);

			Fraction<int> fract3 = Fraction<int>(5, 99);
			Fraction<int> fract4 = Fraction<int>(40, 21);
			Assert::AreEqual((fract3 - fract4).Numerator(), -1285);
			Assert::AreEqual((fract3 - fract4).Denominator(), 693);
			Assert::AreEqual((-fract3 - -fract4).Numerator(), 1285);
			Assert::AreEqual((-fract3 - -fract4).Denominator(), 693);
		}

		TEST_METHOD(UnarySubstractionFractions) {
			Fraction<int> fract1 = Fraction<int>(3, 2);
			Assert::AreEqual((-fract1).Numerator(), -3);
			Assert::AreEqual((-fract1).Denominator(), 2);

			Fraction<double> fract2 = Fraction<double>(5.0, 99.0);
			Assert::AreEqual((-fract2).Numerator(), -5.0);
			Assert::AreEqual((-fract2).Denominator(), 99.0);
		}

		TEST_METHOD(AssigningToFractions) {
			Fraction<int> fract1 = Fraction<int>(3, 2);
			Fraction<int> fract2 = Fraction<int>(1, 2);
			fract2 = fract1;
			Assert::AreEqual((fract2).Numerator(), 3);
			Assert::AreEqual((fract2).Denominator(), 2);


			Fraction<double> fract3 = Fraction<double>(5.1, 99.88);
			Fraction<double> fract4 = Fraction<double>(-40.56, 21.88976);

			fract3 = fract4;
			Assert::AreEqual(fract3.Numerator(), -40.56);
			Assert::AreEqual(fract3.Denominator(), 21.88976);

		}

		TEST_METHOD(MultiplingFractions) {
			Fraction<int> fract1 = Fraction<int>(3, 2);
			Fraction<int> fract2 = Fraction<int>(1, 2);
			Assert::AreEqual((fract1 * fract2).Numerator(), 3);
			Assert::AreEqual((fract1 * fract2).Denominator(), 4);


			Fraction<int> fract3 = Fraction<int>(5, 99);
			Fraction<int> fract4 = Fraction<int>(40, 21);
			Assert::AreEqual((fract3 * fract4).Numerator(), 5 * 40);
			Assert::AreEqual((fract3 * fract4).Denominator(), 99 * 21);
		}

		TEST_METHOD(DividingFractions) {
			Fraction<int> fract1 = Fraction<int>(3, 2);
			Fraction<int> fract2 = Fraction<int>(1, 2);
			Assert::AreEqual((fract1 / fract2).Numerator(), 3);
			Assert::AreEqual((fract1 / fract2).Denominator(), 1);


			Fraction<int> fract3 = Fraction<int>(5, 99);
			Fraction<int> fract4 = Fraction<int>(40, 21);
			Assert::AreEqual((fract3 / fract4).Numerator(), 7);
			Assert::AreEqual((fract3 / fract4).Denominator(), 264);
		}

		TEST_METHOD(SimplifyFraction) {
			Fraction<int> fract1 = Fraction<int>(3, 2);
			fract1.Simplify();
			Assert::AreEqual(fract1.Numerator(), 3);
			Assert::AreEqual(fract1.Denominator(), 2);

			Fraction<int> fract2 = Fraction<int>(8, 2);
			fract2.Simplify();
			Assert::AreEqual(fract2.Numerator(), 4);
			Assert::AreEqual(fract2.Denominator(), 1);

			Fraction<int> fract3 = Fraction<int>(33, 99);
			fract3.Simplify();
			Assert::AreEqual(fract3.Numerator(), 1);
			Assert::AreEqual(fract3.Denominator(), 3);

			Fraction<int> fract4 = Fraction<int>(49, 14);
			fract4.Simplify();
			Assert::AreEqual(fract4.Numerator(), 7);
			Assert::AreEqual(fract4.Denominator(), 2);

			Fraction<double> fract5 = Fraction<double>(2.0, 2.0);
			fract5.Simplify();
			Assert::AreEqual(fract5.Numerator(), 2.0);
			Assert::AreEqual(fract5.Denominator(), 2.0);

			Fraction<float> fract6 = Fraction<float>(2.0f, 2.0f);
			fract6.Simplify();
			Assert::AreEqual(fract6.Numerator(), 2.0f);
			Assert::AreEqual(fract6.Denominator(), 2.0f);
		}

		TEST_METHOD(FractionToDouble) {
			Fraction<int> fract1 = Fraction<int>(3, 2);
			Assert::AreEqual(fract1.ToDouble(), 1.5);

			Fraction<double> fract2 = Fraction<double>(3.0);
			Assert::AreEqual(fract2.ToDouble(), 3.0);
		}

		TEST_METHOD(RaizeToPowerFraction) {
			Fraction<int> fract1 = Fraction<int>(3, 2);
			fract1 = fract1 ^ 2;
			Assert::AreEqual(fract1.Numerator(), 9);
			Assert::AreEqual(fract1.Denominator(), 4);

			Fraction<int> fract1r = Fraction<int>(3, 2);
			fract1r = fract1r ^ -2;
			Assert::AreEqual(fract1r.Numerator(), 4);
			Assert::AreEqual(fract1r.Denominator(), 9);

			Fraction<double> fract2 = Fraction<double>(2.0, 3.0);
			fract2 = fract2 ^ 2.0;
			Assert::AreEqual(fract2.Numerator(), 4.0);
			Assert::AreEqual(fract2.Denominator(), 9.0);

			Fraction<double> fract3 = Fraction<double>(1.0, 3.0);
			fract3 = fract3 ^ -1.0;
			Assert::AreEqual(fract3.Numerator(), 3.0);
			Assert::AreEqual(fract3.Denominator(), 1.0);

			Fraction<double> fract4 = Fraction<double>(1.0, 3.0);
			fract3 = fract3 ^ -0.0;
			Assert::AreEqual(fract3.Numerator(), 1.0);
			Assert::AreEqual(fract3.Denominator(), 1.0);
		}

		TEST_METHOD(CheckEqualityFractions) {
			Fraction<int> fract1 = Fraction<int>(3, 2);
			Fraction<int> fract2 = Fraction<int>(3, 2);
			Assert::AreEqual(fract1 == fract2, true);

			Fraction<double> fract3 = Fraction<double>(1.0, 3.0);
			Fraction<double> fract4 = Fraction<double>(2.0, 3.0);
			Assert::AreEqual(fract3 == fract4, false);

			Fraction<int> fract5 = Fraction<int>(3, 2);
			Fraction<int> fract6 = Fraction<int>(12, 8);
			Assert::AreEqual(fract1 == fract2, true);
		}
	};
}