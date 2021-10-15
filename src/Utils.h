#pragma once

#include <iostream>
#include <string>

// Bad practice but fine for university tasks
using namespace std;

double PI = 3.14159265358979323846;

void awaitInput() {
	_getch();
}

void clearScr() {
	system("cls");
}

template<typename T>
T iread(
	string promt,
	bool allowEmpty,
	bool (*converter)(string, T&)
) {
	string raw;
	T res;

	while (true) {
		cout << promt;
		getline(std::cin, raw);
		if (raw.empty() && !allowEmpty) {
			cout << "Input should not be empty!" << endl;
		}
		else {
			if (converter(raw, res)) {
				return res;
			}
		}
		awaitInput();
		clearScr();
	}
}

string ireadS(string promt, bool allowEmpty = false) {
	return iread<string>(promt, allowEmpty, [](string raw, string& res) {
		res = raw;
		return true;
	});
}

float ireadF(string promt) {
	return iread<float>(promt, false, [](string raw, float& res) {
		try {
			res = stof(raw);
			return true;
		}
		catch (invalid_argument e) {
			cout << "Invalid input! Expected float number";
		}
		catch (out_of_range e) {
			cout << "Input is out of range! Use float number";
		}
		return false;
	});
}

int ireadI(string promt) {
	return iread<int>(promt, false, [](string raw, int& res) {
		try {
			res = stoi(raw);
			return true;
		}
		catch (invalid_argument e) {
			cout << "Invalid input! Expected float number";
		}
		catch (out_of_range e) {
			cout << "Input is out of range! Use float number";
		}
		return false;
	});
}