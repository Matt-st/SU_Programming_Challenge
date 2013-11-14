#include <iostream>
#include <vector>

using namespace std;

void oddeven(vector<int>& arr) {
	int even = 0, odd = 0;
	int j = 0;
	while (j < arr.size()) {
		cout << arr[j] << " ";

		//even
		if (arr[j] % 2 == 0)
			even += arr[j];
		//odd
		else
			odd += arr[j];

		j++;
	}

	cout << endl;

	cout << "The sum of the even value terms " << even << endl;
	cout << "The sum of odd terms is " << odd << endl;
}


int main() {
	int i = 2;
	vector<int> arr;

	arr.push_back(1);
	arr.push_back(2);
	
	while (1) {
		int j = i;
		int num1 = arr[--j];
		int num2 = arr[--j];
		int fib = num1+num2;
		if (fib > 4000000)
			break;
		arr.push_back(fib);
		i++;
	}

	oddeven(arr);

	return 0;
}
