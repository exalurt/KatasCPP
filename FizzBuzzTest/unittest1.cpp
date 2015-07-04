#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\FizzBuzz\FizzBuzz.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FizzBuzzTest
{		
	TEST_CLASS(FizzBuzzTest)
	{
	public:
		BEGIN_TEST_CLASS_ATTRIBUTE()
			TEST_CLASS_ATTRIBUTE(L"Owner", L"Santiago Suárez Díaz")
			TEST_CLASS_ATTRIBUTE(L"Description", L"String Calculator")
		END_TEST_CLASS_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestDivisiblePor3)
			TEST_DESCRIPTION(L"Si es divisible entre 3 devuelve Fizz.")
		END_TEST_METHOD_ATTRIBUTE()
		
		TEST_METHOD(TestDivisiblePor3)
		{
			std::string expected{ "Fizz" };
			Assert::AreEqual(expected, CFizzBuzz::FizzBuzz(21));
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestDivisiblePor5)
			TEST_DESCRIPTION(L"Si es divisible entre 5 devuelve Fizz.")
			END_TEST_METHOD_ATTRIBUTE()

			TEST_METHOD(TestDivisiblePor5)
		{
			std::string expected{ "Buzz" };
			Assert::AreEqual(expected, CFizzBuzz::FizzBuzz(25));
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNoEsDivisible)
			TEST_DESCRIPTION(L"Si no es divisible por ninguno devuelve el número.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestNoEsDivisible)
		{
			std::string expected{ "7" };
			Assert::AreEqual(expected, CFizzBuzz::FizzBuzz(7));
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestDivisiblePorLosDos)
			TEST_DESCRIPTION(L"Si es divisible por los dos devuelve FizzBuzz.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestDivisiblePorLosDos)
		{
			std::string expected{ "FizzBuzz" };
			Assert::AreEqual(expected, CFizzBuzz::FizzBuzz(15));
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestTieneUn3)
			TEST_DESCRIPTION(L"Si tiene un 3 devuelve Fizz.")
		END_TEST_METHOD_ATTRIBUTE()

			TEST_METHOD(TestTieneUn3)
		{
			std::string expected{ "Fizz" };
			Assert::AreEqual(expected, CFizzBuzz::FizzBuzz(13));
		}

	};
}