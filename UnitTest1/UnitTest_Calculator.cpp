#include "Calc.cpp"      // Inclui o arquivo de implementa��o da calculadora
#include "CppUnitTest.h"       // Inclui a biblioteca do CppUnitTestFramework

using namespace Microsoft::VisualStudio::CppUnitTestFramework; // Espa�o de nomes para asser��es do Visual Studio

namespace UnitTestCalculator // Namespace para os testes da calculadora
{
	TEST_CLASS(Soma) // Classe de testes para a fun��o de soma
	{
	public:
		TEST_METHOD(Zero)                     // M�todo de teste para a soma com valores zero
		{
			Assert::IsTrue(soma(0, 0) == 0);  // Verifica se a soma de 0 + 0 � igual a 0
			Assert::IsTrue(soma(0, 1) == 1);  // Verifica se a soma de 0 + 1 � igual a 1
		}
		TEST_METHOD(B�sico)                   // M�todo de teste para somas b�sicas
		{
			Assert::IsTrue(soma(2, 5) == 7);  // Verifica se a soma de 2 + 5 � igual a 7
			Assert::IsTrue(soma(-2, 5) == 3); // Verifica se a soma de -2 + 5 � igual a 3

			Assert::AreEqual(soma(2, 5), 7);  // Verifica se a soma de 2 + 5 � igual a 7
			Assert::AreEqual(soma(-2, 5), 3); // Verifica se a soma de -2 + 5 � igual a 3
		}
		TEST_METHOD(Comutativa)               // M�todo de teste para a propriedade comutativa da soma
		{
			Assert::AreEqual(soma(2, 5), soma(5, 2)); // Verifica se a soma de 2 + 5 � igual � soma de 5 + 2
		}
		TEST_METHOD(Fal)                 // M�todo de teste para verificar falso
		{
			Assert::IsFalse(soma(0, 0) == 1); // Verifica se a soma de 0 + 0 n�o � igual a 1
		}

	};

	TEST_CLASS(Subitra��o) // Classe de testes para a fun��o de subtra��o
	{
	public:
		TEST_METHOD(Zero)                    // M�todo de teste para subtra��es com valor zero
		{
			Assert::IsTrue(sub(0, 0) == 0);  // Verifica se a subtra��o de 0 - 0 � igual a 0
			Assert::AreEqual(sub(0, 5), -5); // Verifica se a subtra��o de 0 - 5 � igual a -5
		}

		TEST_METHOD(B�sico)                  // M�todo de teste para subtra��es b�sicas
		{
			Assert::IsTrue(sub(3, 4) == -1); // Verifica se a subtra��o de 3 - 4 � igual a -1
			Assert::IsTrue(sub(-2, 5) == -7);// Verifica se a subtra��o de -2 - 5 � igual a -7
		}

		TEST_METHOD(False)                // M�todo de teste para verificar falso
		{
			Assert::IsFalse(sub(0, 0) == 1); // Verifica se a subtra��o de 0 - 0 n�o � igual a 1
		}

		TEST_METHOD(SelfSub)                // M�todo de teste para subtra��o consigo mesmo
		{
			Assert::IsTrue(sub(2, 2) == 0); // Verifica se a subtra��o de 2 - 2 � igual a 0
		}
	};

	TEST_CLASS(Multipica��o) // Classe de testes para a fun��o de multiplica��o
	{
	public:

		TEST_METHOD(Zero)                    // M�todo de teste para multiplica��es com valor zero
		{
			Assert::IsTrue(mult(0, 0) == 0); // Verifica se a multiplica��o de 0 * 0 � igual a 0
			Assert::IsTrue(mult(0, 5) == 0); // Verifica se a multiplica��o de 0 * 5 � igual a 0
		}
		TEST_METHOD(B�sico)                  // M�todo de teste para multiplica��es b�sicas
		{
			Assert::IsTrue(mult(3, 4) == 12);   // Verifica se a multiplica��o de 3 * 4 � igual a 12
			Assert::IsTrue(mult(-2, 5) == -10); // Verifica se a multiplica��o de -2 * 5 � igual a -10
		}
		TEST_METHOD(Comutativa)              // M�todo de teste para a propriedade comutativa da multiplica��o
		{
			Assert::AreEqual(mult(2, 5), mult(5, 2)); // Verifica se a multiplica��o de 2 * 5 � igual � multiplica��o de 5 * 2
		}
		TEST_METHOD(False)                    // M�todo de teste para verificar falso
		{
			Assert::IsFalse(mult(0, 0) == 1); // Verifica se a multiplica��o de 0 * 0 n�o � igual a 1
		}
	};
	TEST_CLASS(Divis�o) // Classe de testes para a fun��o de divis�o
	{
	public:
		TEST_METHOD(divi)                       // M�todo de teste da divis�o b�sica
		{
			Assert::AreEqual(divide(10, 5), 2); // Compara o resultado da divis�o com o valor esperado
		}
		TEST_METHOD(zero)                      // M�todo de teste para a divis�o por zero
		{
			// Tenta chamar a fun��o de divis�o com um segundo argumento igual a zero
			try {                 
				
				divide(10, 0);                 // Chama a fun��o de divis�o com um segundo argumento igual a zero

				Assert::Fail();                // Se a fun��o n�o lan�ar uma exce��o, o teste falha
			}
			// Se a fun��o lan�ar uma exce��o, verifica se a mensagem da exce��o � a esperada
			catch (std::invalid_argument const& e) {
				Assert::AreEqual(e.what(), "Divis�o por zero.");
			}
		}
	};
}