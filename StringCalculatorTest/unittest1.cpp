#include "stdafx.h"
#include "CppUnitTest.h"

#include "../StringCalculator/StringCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringCalculatorTest
{
	TEST_MODULE_INITIALIZE(ModuleStartup)
	{
		Logger::WriteMessage(L"☺ Iniciando el test....");
	}

	TEST_MODULE_CLEANUP(ModuleFinalize)
	{
		Logger::WriteMessage(L"☺ Se acabaron los test.");
	}

	TEST_CLASS(StringCalculatorTest)
	{
	public:

		BEGIN_TEST_CLASS_ATTRIBUTE()
			TEST_CLASS_ATTRIBUTE(L"Owner", L"Santiago Suárez Díaz")
			TEST_CLASS_ATTRIBUTE(L"Descrioption", L"String Calculator")
		END_TEST_CLASS_ATTRIBUTE()
		
		BEGIN_TEST_METHOD_ATTRIBUTE(TestDevuelveCero)
			TEST_OWNER(L"Santiago Suárez Díaz")
			TEST_DESCRIPTION(L"Cuando se le pasa la cadena vacía debe devolver un 0.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestDevuelveCero)
		{
			Assert::AreEqual(0, CStringCalculator::calc(""));
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestDevuelveNumero)
			TEST_OWNER(L"Santiago Suárez Díaz")
			TEST_DESCRIPTION(L"Si el string tiene un número debe devolver su valor.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestDevuelveNumero)
		{
			Assert::AreEqual(1, CStringCalculator::calc("1"),L"☹");
			Assert::AreEqual(4, CStringCalculator::calc("4"));
			Assert::AreEqual(35, CStringCalculator::calc("35"));
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestSumaDosNumeros)
			TEST_OWNER(L"Santiago Suárez Díaz")
			TEST_DESCRIPTION(L"Devuelve la suma de los dos números.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestSumaDosNumeros)
		{
			Assert::AreEqual(8, CStringCalculator::calc("1,7"), L"☹");
			Assert::AreEqual(69, CStringCalculator::calc("26,43"), L"☹");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestSumaCadenaDeNumeros)
			TEST_OWNER(L"Santiago Suárez Díaz")
			TEST_DESCRIPTION(L"Devuelve la suma de una cadena de números.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestSumaCadenaDeNumeros)
		{
			Assert::AreEqual(10, CStringCalculator::calc("1,7,2"), L"☹");
			Assert::AreEqual(100, CStringCalculator::calc("26,31,43"), L"☹");
		}
	};
}