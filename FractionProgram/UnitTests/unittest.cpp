#include "..\FractionProgram\FractionClass.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(CreateInt)
		{
			Fraction<int> fract = Fraction<int>(2, 3);
			Assert::AreEqual(fract.Numerator(), 2);
			Assert::AreEqual(fract.Denominator(), 3);
		}

	};
}