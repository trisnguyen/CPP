#pragma once
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

using namespace std; 

#define FUNCTION_UNDER_TEST __declspec(dllexport)

//Test01
FUNCTION_UNDER_TEST string rotateStringLeft(string pS, int pN);

//Test02
FUNCTION_UNDER_TEST int calculateDiv7NotDiv3(int min, int max); //O(1)
FUNCTION_UNDER_TEST int countDiv7NotDiv3(int min, int max); //O(n)

//Test04
typedef bool(*ConditionFunctionPtr)(string);
typedef vector<ConditionFunctionPtr> ConditionVector;
FUNCTION_UNDER_TEST bool IsValidCustomerNumber(string number, ConditionVector conditions);
FUNCTION_UNDER_TEST bool ContainsValidCustomerNumber(string s, ConditionVector conditions);
FUNCTION_UNDER_TEST bool IsCorrectLength(string number);
FUNCTION_UNDER_TEST bool IsCorrectInitial(string number);
FUNCTION_UNDER_TEST bool IsDigitSumDivisibleBy10(string number);

//Test05
FUNCTION_UNDER_TEST char getWinner(int boardSize, char** board);
