#include <iostream>
#include <vector>

using namespace std;

bool is_in_vector(vector<int>& v, int num) {
	int i;
	for (i = 0; i < v.size(); i++) {
		if (v[i] == num)
			return true;
	}

	return false;
}

int main() {
	int x, y;
	int i;

	cout << "Enter the first integer:" << endl;
	cin >> x;
	cout << "Enter the second integer:" << endl;
	cin >> y;

	int gcf = -1, lcm = -1;

	//GCF
	vector<int> xfactorlist;
	for (i = 1; i <= x; i++) {
		if (x % i == 0)
			xfactorlist.push_back(i);
	}

	vector<int> yfactorlist;
	for (i = 1; i <= y; i++) {
		if (y % i == 0)
			yfactorlist.push_back(i);
	}

	for (i = xfactorlist.size() - 1; i >= 0; i--) {
		if (is_in_vector(yfactorlist, xfactorlist[i])) {
			gcf = xfactorlist[i];
			break;
		}
	}

	//LCM
	if (x < y) {
		int temp;
		for (i = 0; i < yfactorlist.size(); i++) {
			temp = x * yfactorlist[i];
			if (temp % y == 0) {
				lcm = temp;
				break;
			}
		}
	}
	else if (x > y) {
		int temp;
		for (i = 0; i < xfactorlist.size(); i++) {
			temp = y * xfactorlist[i];
			if (temp % x == 0) {
				lcm = temp;
				break;
			}
		}
	}
	else
		lcm = x;

	if (lcm == -1)
		lcm = x * y;

	cout << "The greatest common factor is " << gcf << endl;
	cout << "The Least Common Multiple is " << lcm << endl;

	return 0;
}
