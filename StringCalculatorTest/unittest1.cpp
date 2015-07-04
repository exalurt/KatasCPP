#include "stdafx.h"
#include "CppUnitTest.h"

#include "../StringCalculator/StringCalculator.h"

#include <iostream>
#include <string>
#include <regex>


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
			TEST_CLASS_ATTRIBUTE(L"Description", L"String Calculator")
		END_TEST_CLASS_ATTRIBUTE()
		
		BEGIN_TEST_METHOD_ATTRIBUTE(TestDevuelveCero)
			TEST_DESCRIPTION(L"Cuando se le pasa la cadena vacía debe devolver un 0.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestDevuelveCero)
		{
			Assert::AreEqual(0, CStringCalculator::calc(""), L"☹");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestDevuelveNumero)
			TEST_DESCRIPTION(L"Si el string tiene un número debe devolver su valor.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestDevuelveNumero)
		{
			Assert::AreEqual(1, CStringCalculator::calc("1"),L"☹");
			Assert::AreEqual(4, CStringCalculator::calc("4"), L"☹");
			Assert::AreEqual(35, CStringCalculator::calc("35"), L"☹");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestSumaDosNumeros)
			TEST_DESCRIPTION(L"Devuelve la suma de los dos números.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestSumaDosNumeros)
		{
			Assert::AreEqual(8, CStringCalculator::calc("1,7"), L"☹");
			Assert::AreEqual(69, CStringCalculator::calc("26,43"), L"☹");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestSumaCadenaDeNumeros)
			TEST_DESCRIPTION(L"Devuelve la suma de una cadena de números.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestSumaCadenaDeNumeros)
		{
			Assert::AreEqual(10, CStringCalculator::calc("1,7,2"), L"☹");
			Assert::AreEqual(100, CStringCalculator::calc("26,31,43"), L"☹");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestSumaCadenaDeNumerosSaltoDeLinea)
			TEST_DESCRIPTION(L"Devuelve la suma de una cadena de números con salto de línea.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestSumaCadenaDeNumerosSaltoDeLinea)
		{
			Assert::AreEqual(10, CStringCalculator::calc("1\n7,2"), L"☹");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestCambiaSeparador)
			TEST_DESCRIPTION(L"Se puede cambiar el separador de los números.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestCambiaSeparador)
		{
			Assert::AreEqual(3, CStringCalculator::calc("//;\n1;2"), L"☹");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNumerosNegativosNoSoportados)
			TEST_DESCRIPTION(L"Lanza una excepción cuando recibe algún número negativo.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestNumerosNegativosNoSoportados)
		{
			Assert::ExpectException<std::exception>([]()
			{
				CStringCalculator::calc("17,-2");
			}, L"☹");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestIgnoraNumerosMayoresDe1000)
			TEST_DESCRIPTION(L"Los números mayores de 1000 son ignorados.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestIgnoraNumerosMayoresDe1000)
		{
			Assert::AreEqual(2, CStringCalculator::calc("2,1001"), L"☹");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestDelimitadorDeCualquierLongitud)
			TEST_DESCRIPTION(L"Los números mayores de 1000 son ignorados.")
		END_TEST_METHOD_ATTRIBUTE()

		TEST_METHOD(TestDelimitadorDeCualquierLongitud)
		{
			

			/*std::string sy("//[***]\n1***2***3");
			std::regex ex("//\[(.*)\]\n");   // matches words beginning by "sub"


			std::regex_iterator<std::string::iterator> rit(sy.begin(), sy.end(), ex);
			std::regex_iterator<std::string::iterator> rend;
			//std::match_results

			Logger::WriteMessage(rit->str().c_str());
			while (rit != rend) {
				Logger::WriteMessage(rit->str().c_str());
				++rit;
			}*/
			Logger::WriteMessage(L"Vale mi problema es que no sé como son las expresiones regulares:");
			std::string s("1,23");
			std::smatch m;
			std::regex e{ R"_(//\[(.*)\]\n(.*))_"};

			std::regex_match(s, m, e);
			if (std::regex_search(s, m, e))
			{
				Logger::WriteMessage(L"vale la lista es:");
				Logger::WriteMessage(m[2].str().c_str());
				Logger::WriteMessage(L"vale el patrón es:");
				Logger::WriteMessage(m[1].str().c_str());
				std::string as = m[2].str();
				std::string lo = ":";
				std::string sss = "1***2***3";
				if (lo != ":"){
					while (sss.find(lo) != std::string::npos)
						sss.replace(sss.find(lo), lo.length(), ":");
				}
				Logger::WriteMessage(sss.c_str());
				Logger::WriteMessage(L"Y así vale el cambio");
			}

			Logger::WriteMessage("matches:");
			for (std::string it : m) {
				Logger::WriteMessage(it.c_str());
			}
			Logger::WriteMessage("Iterators:");
			std::regex_iterator<std::string::iterator> rit(s.begin(), s.end(), e);
			std::regex_iterator<std::string::iterator> rend;
			//std::match_results

			Logger::WriteMessage(rit->str().c_str());
			while (rit != rend) {
				Logger::WriteMessage(rit->str().c_str());
				++rit;
			}



			Assert::AreEqual(3, CStringCalculator::calc("//[***]\n1***2***3"), L"☹");
		}
	};
}