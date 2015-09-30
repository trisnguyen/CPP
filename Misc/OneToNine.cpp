#include <iostream>
using namespace std;

/* A solution, for instance, 1 + 2 + 34 - 5 + 67 - 8 + 9, can be presented with power of tens, such as:
1*10^0 + 2*10^0 + 3*10^1 + 4*10^0 - 5*10^0 + 6*10^1 + 7*10^0 - 8*10^0 + 9*10^0
Calculated from the back, each position has three possible values:
- (if has a preceding) last position + 1, same sign
- 0, with positive sign
- 0, with negative sign (except 1, which must be positive)
The implemented algorithm is a recursive depth-first search.
*/

int counterResult = 0;
const int TARGET = 100;
const int MAX_POWER = 3;	//proven: for the target to be 100, this can't be larger than 1000

int result = 0;
bool isPositive[10];
unsigned int powerTen[10];

int getValueAtPosition(int position) {
	return position * pow(10, powerTen[position]) * (isPositive[position] ? 1 : -1);
}

void printResult() {
	if (result == TARGET) {
		cout << "1";
		for (int i = 2; i <= 9; ++i) {
			if (powerTen[i] == powerTen[i - 1] - 1)
				cout << i;
			else
				cout << (isPositive[i] ? " + " : " - ") << i;
		}
		cout << endl;
		counterResult++;
	}

}

//recursive func
void calculate(int position, int powerByTen, bool sign = true) {
	int currentResult = result;
	if (position == 0)
		printResult();
	else {
		if (powerByTen < MAX_POWER) {
			powerTen[position] = powerByTen + 1;
			isPositive[position] = sign;
			result = currentResult + getValueAtPosition(position);
			calculate(position - 1, powerTen[position], isPositive[position]);		// recursive call to next position
		}

		powerTen[position] = 0;
		isPositive[position] = true;
		result = currentResult + getValueAtPosition(position);
		calculate(position - 1, 0, true);
		
		if (position > 1) {	//not allow minus sign before 1
			powerTen[position] = 0;
			isPositive[position] = false;
			result = currentResult + getValueAtPosition(position);
			calculate(position - 1, 0, false);
		}
		result = currentResult;
	}
}

int main() {
	cout << "The results are: " << endl;
	//start with 9 and calculate backward
	int position = 9;

	result = 0;
	powerTen[9] = 0;
	isPositive[9] = true;
	result = getValueAtPosition(position);
	calculate(8, powerTen[9], true);

	result = 0;
	powerTen[9] = 0;
	isPositive[9] = false;
	result = getValueAtPosition(position);
	calculate(8, powerTen[9], false);

	cout << endl << "There are " << counterResult << " results." << endl;
	cin.get();
	return 0;
}