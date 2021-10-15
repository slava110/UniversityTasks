#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <map>
//#include <limits>

#include "Utils.h"


// Bad practice but fine for university tasks
using namespace std;

// Create map with tasks
typedef void (*TaskFunc)();
map<string, TaskFunc> tasks;


//========== Actual code ==========

streamsize defaultPrecision = cout.precision();

bool inputInvalid(string type) {
	if (!cin) {
		cout << "Invalid input, use valid " << type << " instead please";
		cin.clear();
		return true;
	}
	return false;
}

void task1_1() {
	cout << "Sviatoslav Popov";
}

void task1_2() {
	float a, b;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Res: " << endl;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	b != 0 ? cout << to_string(a / b) : cout << "Division by zero restricted. We're sorry :c";
}

// Function to calculate 'bx + c = 0'
void calcBXC(float b, float c) {
	(b != 0) ? cout << "Result: " << (-c / b) : cout << "Division by zero restricted. We're sorry :c";
}

void task1_3() {
	float b, c;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	calcBXC(b, c);
}

void task1_4() {
	float a, b, c, d;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	// ax^2 + bx + c = 0

	if (a == 0) {
		calcBXC(b, c);
		cout << endl;
		return;
	}

	d = b * b - 4 * a * c;

	cout << "Result: ";

	if (d > 0) {
		cout << (sqrt(d) - b) / 2 * a;
		cout << " and ";
		cout << (-b - sqrt(d)) / 2 * a;
	} else if (d == 0) {
		cout << -b / 2 * a;
	} else {
		cout << "Nah";
	}
}

void task1_5() {
	bool day, curtains_open, lamp;

	cout << "Is it day? ";
	cin >> day;
	cout << "Curtains are open? ";
	cin >> curtains_open;
	cout << "Lamp is on? ";
	cin >> lamp;

	(day && curtains_open) || lamp ? cout << "There is light!" : cout << "Hello, darkness, my old friend...";
}



void task2_1() {
	float h, R, r, l;
	cout << "Enter h: ";
	cin >> h;

	if (h == 0) {
		cout << "Don't use 0 as height";
		return;
	}

	cout << "Enter R: ";
	cin >> R;
	cout << "Enter r: ";
	cin >> r;

	if (h < 0 || R < 0 || r < 0) {
		cout << "Please don't use numbers lower than 0. Length should be more than 0, you know";
		return;
	}

	if (r >= R) {
		cout << "r < R, you know?";
		return;
	}

	l = sqrt(h * h + (R - r) * (R - r));

	cout << "Volume: " << (PI * h * (R * R + R * r + r * r)) / 3 << endl;
	cout << "Surface: " << (PI * (R * R + (R + r) * l + r * r));
}

void task2_2() {
	float x, a;
	cout << "Enter x: ";
	cin >> x;

	if (x == 0) {
		cout << "Please don't use x = 0";
		return;
	}

	cout << "Enter a: ";
	cin >> a;

	if (a < 0) {
		cout << "Please don't use a lower than 0. Idk why but it will return NAN or INF. So... Yeah";
		return;
	}

	float forSq = a - x * x;

	if (forSq < 0) {
		cout << "x^2 should be >= a";
		return;
	}

	cout << "Result: ";

	if (abs(x) < 1) {
		cout << (a * log(abs(x)));
	} else {
		cout << (sqrt(forSq));
	}
}

void task2_3() {
	float x, y, b;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	cout << "Enter b: ";
	cin >> b;

	if ((b - y) <= 0 || (b - x) < 0) {
		cout << "Please don't use numbers lower than 0";
		return;
	}

	cout << (log(b - y) * sqrt(b - x));

	cout << endl;
	system("pause");
}

void task2_4() {
	int num;
	cin >> num;
	for (int i = num; i < num + 10; i++)
		cout << i << " ";
}

void task2_5() {
	for (double x = -4; x < 4; x += 0.5) {
		double res = (x * x - 2 * x + 2) / (x - 1);
		if (!isnan(res) && !isinf(res)) {
			cout << res << endl;
		} else {
			cout << "Nope" << endl;
		}
	}
}


// Function to calculate 'm' using homework task formula
double calcZaemFormula(double S, double n, double p) {
	double r = p / 100;
	return ((S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1)));
}

void task3_1() { // 1000000 15 20     <20000
	float S, n, p;

	cout << "Enter S: ";
	cin >> S;

	if (S == 0) {
		cout << "Please don't use 0 as S. Idk why but it will return NAN or INF. So... Yeah";
		return;
	}

	cout << "Enter n: ";
	cin >> n;

	if (n == -1) {
		cout << "Please don't use -1 as n. Idk why but it will return NAN or INF. So... Yeah";
		return;
	}

	cout << "Enter p: ";
	cin >> p;

	if (p == 0) {
		cout << "Please don't use 0 as p. Idk why but it will return NAN or INF. So... Yeah";
		return;
	}

	cout << "Res: " << calcZaemFormula(S, n, p);
	return;
}

void task3_2() { // 100000 1000 2 года | [1, 100]
	double S, n, m, p;

	cout << "Enter S: ";
	cin >> S;

	if (S == 0) {
		cout << "Please don't use 0 as S. Idk why but it will return NAN or INF. So... Yeah";
		return;
	}

	cout << "Enter m: ";
	cin >> m;

	if (m <= 0) {
		cout << "Please don't use 0 as m. Idk why but it will return NAN or INF. So... Yeah";
		return;
	}

	cout << "Enter n: ";
	cin >> n;

	if (n == -1) {
		cout << "Please don't use -1 as n. Idk why but it will return NAN or INF. So... Yeah";
		return;
	}

	double temp;
	p = 1;
	double step = 1;

	while ((temp = calcZaemFormula(S, n, p)) != m) {
		if (isnan(temp) || isinf(temp)) {
			cout << "Unable to find exact value due to C++ limitations" << endl;
			cout << "Found closest p" << endl;
			break;
		}
		if (temp > m) {
			p -= step;
			step *= 0.1;
		}
		p += step;
		//cout << "p = " << p << " | temp = " << temp << endl;
	}

	
	cout.precision(14);
	cout << "P = " << fixed << p;
	cout.precision(defaultPrecision);
}

void task3_3() {
	cout << ifstream("text.txt").rdbuf();
}

void task3_4() {
	char ch;
	fstream fin("text.txt", fstream::in);

	if (!fin.good()) {
		cout << "File not found!";
		return;
	}

	while (fin >> noskipws >> ch) {
		if((ch >= '0' && ch <= '9') || ch == '\n')
			cout << ch;
	}
}

void task3_5() {
	int i, j, temp, size;
	char str[30];

	cout << "Enter a string: ";
	cin.getline(str, 30);

	size = strlen(str);

	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (str[i] > str[j]) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	cout << "Res: " << str;
}

void task4_1() {
	cout << "Enter 10 numbers:" << endl;

	string input;
	ofstream out("4_1.txt");
	for (int i = 0; i < 10; i++) {
		int input;
		cin >> input;
		if (inputInvalid("integer")) {
			out.close();
			remove("4_1.txt");
			return;
		}
		out << input << "\n";
	}
	out.close();

	ifstream in("4_1.txt");

	int sum = 0;
	string line;
	while (getline(in, line)) {
		sum += stoi(line);
	}

	in.close();

	cout << "Sum: " << sum << endl;

	cout << "Press enter to delete file" << endl;

	system("pause");
	remove("4_1.txt");
}

int getSign(int num) {
	if (num == 0)
		return 0;
	return num / abs(num);
}

void task4_2() {
	cout << "Enter number: ";

	int num;
	cin >> num;

	if (inputInvalid("integer"))
		return;

	cout << "Sign: " << getSign(num);
}

float recSq(float a, float b) {
	return a * b;
}

float triSq(float a, float h) {
	if (a == 0 || h == 0)
		return 0;
	return (a * h) / 2;
}

float cirSq(float r) {
	return PI * r * r;
}

void task4_3() {
	float a, b, h, r;

	cout << "What do you want to calculate?" << endl;
	cout << "Options: 1 (rectangle), 2 (triangle), 3 (circle)" << endl;
	cout << "> ";
	int input;
	cin >> input;

	if (inputInvalid("integer"))
		return;

	switch (input) {
		case 1:
			cout << "Enter a: ";
			cin >> a;

			if (inputInvalid("float"))
				return;

			cout << "Enter b: ";
			cin >> b;

			if (inputInvalid("float"))
				return;

			cout << "Res: " << recSq(a, b);
			
			break;
		case 2:
			cout << "Enter a: ";
			cin >> a;

			if (inputInvalid("float"))
				return;

			cout << "Enter h: ";
			cin >> h;

			if (inputInvalid("float"))
				return;

			cout << "Res: " << triSq(a, h);
			break;
		case 3:
			cout << "Enter r: ";
			cin >> r;

			if (inputInvalid("float"))
				return;

			cout << "Res: " << cirSq(r);
			break;
		default:
			cout << "Function not found!";
	}
}

void task4_4() {
	cout << "Былую славу 1912 года";
}

// Thanks to StackOverflow
void task4_5() {
	int size = 80, height = 21;

	// Start with an empty chart (lots of spaces and a line in the middle)
	vector<string> chart(height, string(size, ' '));
	chart[height / 2] = string(size, '-');

	// Then just put x-es where the function should be plotted
	for (int i = 0; i < size; ++i) {
		chart[static_cast<int>(round(10 * sin(i / 4.5) + 10))][i] = 'x';
	}

	// and print the whole shebang
	for (auto&& s : chart) {
		cout << s << '\n';
	}
}

void task4_6() {
	int num = 0;
	string input;

	cin >> input;

	int sign = 1;

	for (char& c : input) {
		switch (c) {
			case 'I':
				num += 1 * sign;
				break;
			case 'V':
				num += 5 * sign;
				break;
			case 'X':
				num += 10 * sign;
				break;
			case 'L':
				num += 50 * sign;
				break;
			case 'C':
				num += 100 * sign;
				break;
			case 'D':
				num += 500 * sign;
				break;
			case 'M':
				num += 1000 * sign;
				break;
			case '-':
				sign = -1;
				continue;
		}
		if (sign < 0) {
			sign = 1;
		}
	}

	cout << "Res: " << num;
}

int recFormula(int m, int i, int c, int prevS) {
	return (m * prevS + i) % c;
}

void task4_7() {
	int m, i, c, s, amount;
	cout << "Random generator!" << endl;
	cout << "Enter m: ";
	cin >> m;

	if (inputInvalid("integer"))
		return;
	
	cout << "Enter i: ";
	cin >> i;

	if (inputInvalid("integer"))
		return;

	cout << "Enter c: ";
	cin >> c;

	if (inputInvalid("integer"))
		return;

	cout << "Enter amount: ";
	cin >> amount;

	if (inputInvalid("integer"))
		return;

	if (amount < 1) {
		cout << "Enter positive non-zero number as amount!" << endl;
		return;
	}

	s = 0;

	for (int n = 0; n < amount; n++) {
		cout << (s = recFormula(m, i, c, s)) << endl;
	}
}

void task4_8() {
	// I need to copy this from different branch
}

void task5_1() {
	int a, b, res;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	a = abs(a);
	b = abs(b);

	cout << "Substract or divide? (press s to use substraction method or d to use division)" << endl;
	switch (_getch()) {
	case 's':
	case 'S':
		while (a != 0 && b != 0) {
			if (a > b)
				a = a % b;
			else
				b = b % a;
		}
		res = a + b;
		break;
	case 'd':
	case 'D':
		while (a != b) {
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		res = a;
		break;
	default:
		cout << "I SAID PRESS S OR D LISTEN TO ME YOU...";
		return;
	}

	cout << "Res: " << res;
}

void task5_2() {
	int max;
	cout << "Enter max value: ";
	cin >> max;

	bool suc;

	for (int i = 0; i < max; i++) {
		suc = true;
		for (int num = 2; num < i; num++) {
			if (i % num == 0) {
				suc = false;
				break;
			}
		}
		if (suc) {
			cout << i << " ";
		}
		
	}
}

void task5_3() {
	ofstream out("5_3_a.txt");
	ifstream in("5_3_b.txt");

	out << "Cookies" << endl;
	out << "Yay" << endl;

	out.close();
	
	string line;

	while (getline(in, line)) {
		cout << line;
	}

	in.close();
}

void task5_4() {

}


// This is garbage language
// Why there's no reflection
// Pls let me code in Java/Kotlin
void setupTasks() {
	tasks["1.1"] = task1_1;
	tasks["1.2"] = task1_2;
	tasks["1.3"] = task1_3;
	tasks["1.4"] = task1_4;
	tasks["1.5"] = task1_5;

	tasks["2.1"] = task2_1;
	tasks["2.2"] = task2_2;
	tasks["2.3"] = task2_3;
	tasks["2.4"] = task2_4;
	tasks["2.5"] = task2_5;

	tasks["3.1"] = task3_1;
	tasks["3.2"] = task3_2;
	tasks["3.3"] = task3_3;
	tasks["3.4"] = task3_4;
	tasks["3.5"] = task3_5;

	tasks["4.1"] = task4_1;
	tasks["4.2"] = task4_2;
	tasks["4.3"] = task4_3;
	tasks["4.4"] = task4_4;
	tasks["4.5"] = task4_5;
	tasks["4.6"] = task4_6;
	tasks["4.7"] = task4_7;
	tasks["4.8"] = task4_8;

	tasks["5.1"] = task5_1;
	tasks["5.2"] = task5_2;
	tasks["5.3"] = task5_3;
}