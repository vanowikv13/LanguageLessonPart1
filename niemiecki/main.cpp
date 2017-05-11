// niemiecki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;
struct word {
	string polish;
	string germany;
};
void PutFromFile(vector<word>& wsk,string fileName) {
	fstream file;
	file.open(fileName, ios::in);
	string xd;
	word x;
	while (getline(file, xd)) {
		bool helper = false;
		for (int i = 0; i < xd.size(); i++) {
			if (!helper && xd[i] != '-') {
				x.germany += xd[i];
			}
			else {
				helper = true;
				if (xd[i] != '-') {
					x.polish += xd[i];
				}
			}
		}

		wsk.push_back(x);
		x.germany = ""; x.polish = "";
	}
}

void test(vector<word> arr, int size) {
	string answer;
	int point=0, index;
	srand(time(nullptr));
	bool *tab = new bool[arr.size()];
	for (int i = 0; i < arr.size(); i++) tab[i] = false;

	for (int i = 0; i < size; i++) {
		while (1)
			if (tab[index = rand() % arr.size()] == false) {
				tab[index] = true;
				break;
			}
		cout << arr[index].polish <<" : ";
		getline(cin,answer);
		if (answer == arr[index].germany)
			point++;
	}
	cout << point <<"/"<<size<< endl;


}


int main()
{
	vector<word> words;
	PutFromFile(words, "word.txt");
	test(words, 5);
	system("pause");
    return 0;
}

