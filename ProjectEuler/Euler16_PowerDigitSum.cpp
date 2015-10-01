#include <iostream>
using namespace std;

// Return the sum of all digits of the result of (base) power by (power)
int PowerDigitSum(const long& base, const long& power)
{
	const size_t len = 99999; //maximum length
	unsigned long result[len] = { 0 }; //to save the result
	result[0] = base;
	size_t maxDigitIndex = 0; //the max index used to store valid digit

	for (long k = 1; k < power; ++k)
	{
		for (size_t i = 0; i <= maxDigitIndex; ++i)
		{
			if (result[i] != 0)
				result[i] *= base;
		}
		//carry over
		for (size_t i = 0; i < len - 1; ++i)
		{
			if (result[i] >= 10)
			{
				result[i + 1] += result[i] / 10;
				result[i] = result[i] % 10;
				if (maxDigitIndex < i + 1)
					maxDigitIndex = i + 1;
			}
			else if (i > maxDigitIndex && result[i] == 0)
				break;
		}

		//check if it reach the array's extend
		if (result[len - 1] >= 10)
		{
			cout << "Overflow!" << endl;
			return -1;
		}
	}

	long powerDigitsSum = 0;
	cout << "result length = " << maxDigitIndex << endl << "result = ";
	int i = maxDigitIndex;
	for (; i >= 0; --i)
	{
		cout << static_cast<unsigned int>(result[i]);
		powerDigitsSum += result[i];
	}
	cout << endl;

	return powerDigitsSum;
}

void main()
{
	cout << "PowerDigitSum = " << PowerDigitSum(2, 1000) << endl;
	cout << "PowerDigitSum = " << PowerDigitSum(256, 125) << endl;
	cout << "PowerDigitSum = " << PowerDigitSum(4096, 8192) << endl;
}