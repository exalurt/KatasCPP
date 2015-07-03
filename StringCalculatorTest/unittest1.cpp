#include "stdafx.h"
#include "CppUnitTest.h"

#include "../StringCalculator/StringCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringCalculatorTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestDevuelveCero)
		{
			// TODO: Your test code here
			Assert::AreEqual(0, CStringCalculator::calc(""));
		}

	};
}