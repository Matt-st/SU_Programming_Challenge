#include <iostream>
#include <vector>
#include <string>

using namespace std;

char alpha[] = "abcdefghijklmnopqrstuvwxyz";

int main() {

	int padsize;
	int loop, temp;

	vector<int> pad;

	cout << "Enter pad size: " << endl;
	cin >> padsize;
	cout << "Enter pad: " << endl;
	for (loop = 0; loop < padsize; loop++) {
		cin >> temp;
		pad.push_back(temp);
	}

	vector<string> words;
	string word;
	int totalwordlen = 0;
	cout << "Enter words (-1 to terminate): " << endl;
	do {
		cin >> word;
		if (atoi(word.c_str()) == -1)
			break;
		words.push_back(word);
		totalwordlen += word.size();
	} while(1);

	if (totalwordlen > padsize) {
		cout << "Change pad size (" << padsize << ") to be larger than word length (" << totalwordlen << ")" << endl;
		return 0;
	}

	int wordindex, charindex;
	int padindex = 0;

	cout << "Output: " << endl;

	for (wordindex = 0; wordindex < words.size(); wordindex++) {
		for (charindex = 0; charindex < words[wordindex].size(); charindex++) {
			int letter = words[wordindex][charindex] - 'a';
			letter += pad[padindex];
			letter %= 26;
			cout << alpha[letter];
			padindex++;
		}
		cout << endl;
	}
	
	cout << endl;

	return 0;
}