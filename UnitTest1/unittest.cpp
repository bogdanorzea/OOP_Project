#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Project\Fraction.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Creation)
		{
			Fraction<int> fract = Fraction<int>(2,3);
			Assert::AreEqual(fract.Numerator(),2);
			Assert::AreEqual(fract.Denominator(),3);
		}

	};
}