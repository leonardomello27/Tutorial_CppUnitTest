#include "Calc.cpp"      // Inclui o arquivo de implementação da calculadora
#include "CppUnitTest.h"       // Inclui a biblioteca do CppUnitTestFramework

using namespace Microsoft::VisualStudio::CppUnitTestFramework; // Espaço de nomes para asserções do Visual Studio

namespace UnitTestCalculator // Namespace para os testes da calculadora
{
	TEST_CLASS(Soma) // Classe de testes para a função de soma
	{
	public:
		TEST_METHOD(Zero)                     // Método de teste para a soma com valores zero
		{
			Assert::IsTrue(soma(0, 0) == 0);  // Verifica se a soma de 0 + 0 é igual a 0
			Assert::IsTrue(soma(0, 1) == 1);  // Verifica se a soma de 0 + 1 é igual a 1
		}
		TEST_METHOD(Básico)                   // Método de teste para somas básicas
		{
			Assert::IsTrue(soma(2, 5) == 7);  // Verifica se a soma de 2 + 5 é igual a 7
			Assert::IsTrue(soma(-2, 5) == 3); // Verifica se a soma de -2 + 5 é igual a 3

			Assert::AreEqual(soma(2, 5), 7);  // Verifica se a soma de 2 + 5 é igual a 7
			Assert::AreEqual(soma(-2, 5), 3); // Verifica se a soma de -2 + 5 é igual a 3
		}
		TEST_METHOD(Comutativa)               // Método de teste para a propriedade comutativa da soma
		{
			Assert::AreEqual(soma(2, 5), soma(5, 2)); // Verifica se a soma de 2 + 5 é igual à soma de 5 + 2
		}
		TEST_METHOD(Fal)                 // Método de teste para verificar falso
		{
			Assert::IsFalse(soma(0, 0) == 1); // Verifica se a soma de 0 + 0 não é igual a 1
		}

	};

	TEST_CLASS(Subitração) // Classe de testes para a função de subtração
	{
	public:
		TEST_METHOD(Zero)                    // Método de teste para subtrações com valor zero
		{
			Assert::IsTrue(sub(0, 0) == 0);  // Verifica se a subtração de 0 - 0 é igual a 0
			Assert::AreEqual(sub(0, 5), -5); // Verifica se a subtração de 0 - 5 é igual a -5
		}

		TEST_METHOD(Básico)                  // Método de teste para subtrações básicas
		{
			Assert::IsTrue(sub(3, 4) == -1); // Verifica se a subtração de 3 - 4 é igual a -1
			Assert::IsTrue(sub(-2, 5) == -7);// Verifica se a subtração de -2 - 5 é igual a -7
		}

		TEST_METHOD(False)                // Método de teste para verificar falso
		{
			Assert::IsFalse(sub(0, 0) == 1); // Verifica se a subtração de 0 - 0 não é igual a 1
		}

		TEST_METHOD(SelfSub)                // Método de teste para subtração consigo mesmo
		{
			Assert::IsTrue(sub(2, 2) == 0); // Verifica se a subtração de 2 - 2 é igual a 0
		}
	};

	TEST_CLASS(Multipicação) // Classe de testes para a função de multiplicação
	{
	public:

		TEST_METHOD(Zero)                    // Método de teste para multiplicações com valor zero
		{
			Assert::IsTrue(mult(0, 0) == 0); // Verifica se a multiplicação de 0 * 0 é igual a 0
			Assert::IsTrue(mult(0, 5) == 0); // Verifica se a multiplicação de 0 * 5 é igual a 0
		}
		TEST_METHOD(Básico)                  // Método de teste para multiplicações básicas
		{
			Assert::IsTrue(mult(3, 4) == 12);   // Verifica se a multiplicação de 3 * 4 é igual a 12
			Assert::IsTrue(mult(-2, 5) == -10); // Verifica se a multiplicação de -2 * 5 é igual a -10
		}
		TEST_METHOD(Comutativa)              // Método de teste para a propriedade comutativa da multiplicação
		{
			Assert::AreEqual(mult(2, 5), mult(5, 2)); // Verifica se a multiplicação de 2 * 5 é igual à multiplicação de 5 * 2
		}
		TEST_METHOD(False)                    // Método de teste para verificar falso
		{
			Assert::IsFalse(mult(0, 0) == 1); // Verifica se a multiplicação de 0 * 0 não é igual a 1
		}
	};
	TEST_CLASS(Divisão) // Classe de testes para a função de divisão
	{
	public:
		TEST_METHOD(divi)                       // Método de teste da divisão básica
		{
			Assert::AreEqual(divide(10, 5), 2); // Compara o resultado da divisão com o valor esperado
		}
		TEST_METHOD(zero)                      // Método de teste para a divisão por zero
		{
			// Tenta chamar a função de divisão com um segundo argumento igual a zero
			try {                 
				
				divide(10, 0);                 // Chama a função de divisão com um segundo argumento igual a zero

				Assert::Fail();                // Se a função não lançar uma exceção, o teste falha
			}
			// Se a função lançar uma exceção, verifica se a mensagem da exceção é a esperada
			catch (std::invalid_argument const& e) {
				Assert::AreEqual(e.what(), "Divisão por zero.");
			}
		}
	};
}