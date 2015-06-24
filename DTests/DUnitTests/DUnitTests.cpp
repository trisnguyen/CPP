#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\DTests\DTests.h"
#pragma comment(lib, "../Debug/DTests.lib")

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DUnitTest
{		
	TEST_CLASS(DUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod01)
		{
//      Assert::AreEqual(rotate("ABCDEF", 2), string("CDEFAB1"), L"Incorrect rotation 1", LINE_INFO());
      Assert::AreEqual(string("CDEFAB"), rotateStringLeft("ABCDEF", 2));
      Assert::AreEqual(string("ABCDEFGH"), rotateStringLeft("ABCDEFGH", 0));
      Assert::AreEqual(string(""), rotateStringLeft("", 7));
      Assert::AreEqual(string("A"), rotateStringLeft("A", 7));
      Assert::AreEqual(string("CAB"), rotateStringLeft("ABC", -7));
    }


    TEST_METHOD(TestMethod02)
    {
      Assert::AreEqual(1163, calculateDiv7NotDiv3(8, 12228));
      Assert::AreEqual(0, calculateDiv7NotDiv3(1, 2));
      Assert::AreEqual(0, calculateDiv7NotDiv3(66, 6));
      Assert::AreEqual(10, calculateDiv7NotDiv3(1, 99));
      Assert::AreEqual(10, calculateDiv7NotDiv3(1, 99));
      Assert::AreEqual(1, calculateDiv7NotDiv3(3, 12));

      Assert::AreEqual(0, calculateDiv7NotDiv3(6, 6));
      Assert::AreEqual(1, calculateDiv7NotDiv3(7, 7), L"something wrong");
      Assert::AreEqual(0, calculateDiv7NotDiv3(21, 21));

      srand((unsigned)time(0));
      for (int i = 0; i < 99; i++) {
        int min = rand();
        int max = rand();
        int count = countDiv7NotDiv3(min, max);
        int calculate = calculateDiv7NotDiv3(min, max);
        wchar_t assertMessage[255] = L"Original assert message.";
        swprintf_s(assertMessage, L"Range [%d, %d]; count = %d, calculate = %d", min, max, count, calculate);
        //wcout << "assertMessage: " << assertMessage << endl;
        Assert::AreEqual(count, calculate, assertMessage);

      }

    }

    TEST_METHOD(TestMethod04)
    {
      ConditionVector conditions;
      string number = "123456789";
      Assert::IsTrue(IsValidCustomerNumber(number, conditions));

      conditions.push_back(IsCorrectLength);
      number = "234567";
      Assert::IsTrue(IsValidCustomerNumber(number, conditions));

      conditions.push_back(IsCorrectInitial);
      Assert::IsFalse(IsValidCustomerNumber(number, conditions));
      number = "434567";
      Assert::IsTrue(IsValidCustomerNumber(number, conditions));

      conditions.push_back(IsDigitSumDivisibleBy10);
      Assert::IsFalse(IsValidCustomerNumber(number, conditions));
    }

    TEST_METHOD(TestMethod05)
    {

      const int boardSize = 3;
      char data00[boardSize][boardSize] = { { 0, 0, 0 },
                                            { 0, 0, 0 },
                                            { 0, 0, 0 } };
      char data01[boardSize][boardSize] = { { 1, 1, 1 },
                                            { 0, 2, 2 },
                                            { 2, 2, 1 } };
      char data02[boardSize][boardSize] = { { 1, 2, 2 },
                                            { 1, 2, 0 },
                                            { 2, 1, 0 } };

      char* board[boardSize];
      for (int i = 0; i < boardSize; i++) board[i] = data00[i];
      Assert::AreEqual(char(0), getWinner(boardSize, board));

      for (int i = 0; i < boardSize; i++) board[i] = data01[i];
      Assert::AreEqual((char)1, getWinner(boardSize, board));

      for (int i = 0; i < boardSize; i++) board[i] = data02[i];
      Assert::AreEqual((char)2, getWinner(boardSize, board));
    }

	};
}
