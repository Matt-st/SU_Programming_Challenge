#include <iostream>
#include <string>
using namespace std;

int todigit(char c) {
	int i = c - '0';
	if (i < 0 || i > 9)
		return -1;
	return i;
}

int main() {

	int carry = 0;
	int numcarries = 0;
	string num1, num2;
	int i1, i2;
	int i;
	int d1, d2;

	do {
		cout << "Please enter 2 numbers (-999 for either to end): ";
		cin >> num1 >> num2;

		carry = 0;
		numcarries = 0;

		i1 = atoi(num1.c_str());
		i2 = atoi(num2.c_str());

		//check for sentinel
		if (i1 == -999 || i2 == -999)
			break;

		int maxlen = max(num1.length(), num2.length());

		for (i = 0; i < maxlen; i++) {
			d1 = (i >= num1.length()) ? 0 : todigit(num1[i]);
			d2 = (i >= num2.length()) ? 0 : todigit(num2[i]);

			if ((d1 + d2 + carry) >= 10) {
				carry = 1;
				//don't add carry if it's the last digit
				if (i != maxlen - 1)
					numcarries++;
			}
			else {
				carry = 0;
			}
		}

		cout << "Number of carries: " << numcarries << endl;
		
	} while(1);

	return 0;

}


