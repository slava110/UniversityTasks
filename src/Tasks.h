#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <iomanip>
//#include <limits>

#include "Utils.h"
#include "Spinners.h"


// Bad practice but fine for university tasks
using namespace std;

//========== Actual code ==========

streamsize defaultPrecision = cout.precision();

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
	cout << a * b;
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

	cout << "Press any key to delete file" << endl;

	_getch();
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

	switch (input) {
		case 1:
			cout << "Enter a: ";
			cin >> a;

			cout << "Enter b: ";
			cin >> b;

			cout << "Res: " << recSq(a, b);
			
			break;
		case 2:
			cout << "Enter a: ";
			cin >> a;

			cout << "Enter h: ";
			cin >> h;

			cout << "Res: " << triSq(a, h);
			break;
		case 3:
			cout << "Enter r: ";
			cin >> r;

			cout << "Res: " << cirSq(r);
			break;
		default:
			cout << "Function not found!";
	}
}

void task4_4() {
	for (int i = 0; i < 13; ++i)
	{
		if (i < 7) {
			if (0 == i % 2) {
				for (int j = 0; j < 4; ++j)
				{
					std::cout << "  *";
				}
				std::cout.width(60);
				std::cout << std::setw(60) << std::setfill('/');
			}
			else {
				std::cout << " ";
				for (int j = 0; j < 4; ++j)
					std::cout << "*  ";
			}
			std::cout << '\n';
		}

	}

	for (int i = 0; i < 18; ++i)
		if (0 == i % 2)
			std::cout << std::setw(72) << std::setfill(' ') << '\n';
		else
			std::cout << std::setw(72) << std::setfill('/') << '\n';
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
	
	cout << "Enter i: ";
	cin >> i;

	cout << "Enter c: ";
	cin >> c;

	cout << "Enter amount: ";
	cin >> amount;

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
	int A[3][4] = { {5, 2, 0, 10} ,{3, 5 , 2, 5} ,{20, 0 ,0, 0} };
	int B[4][2] = { {1.2, 0.5}, {2.8, 0.4}, {5, 1}, {2, 1.5} };
	int c[4][2] = {};

	cout << "Result of multiplication:" << endl;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 2; col++) {
			// Multiply the row of A by the column of B to get the row, column of product.
			for (int inner = 0; inner < 4; inner++) {
				c[row][col] += A[row][inner] * B[inner][col];
			}
			cout << c[row][col] << "  ";
		}
		cout << "\n";
	}
	int i;
	int max = 0;
	int v1 = 0;
	int v2 = 0;
	int min = 100;
	for (i = 0; i < 3; i++) {
		if (c[i][0] > max) {
			max = c[i][0];
			v1 = i + 1;
		}
		if (c[i][0] < min) {
			min = c[i][0];
			v2 = i + 1;
		}

	}
	cout << endl;
	cout << "1) Max income: " << v1 << endl;
	cout << "   Min income: " << v2 << endl;

	max = 0;
	v1 = 0;
	v2 = 0;
	min = 100;

	for (i = 0; i < 4; i++) {
		if (c[i][1] > max) {
			max = c[i][1];
			v1 = i + 1;
		}
		if (c[i][1] < min) {
			min = c[i][1];
			v2 = i + 1;
		}
	}
	cout << "2) Max comission: " << v1 << endl;
	cout << "   Min comission: " << v2 << endl;

	int sum1 = 0;
	for (i = 0; i < 3; i++) {
		sum1 += c[i][0];
	}
	cout << "3) Summary income: " << sum1 << endl;
	int sum2 = 0;
	for (i = 0; i < 3; i++) {
		sum2 += c[i][1];
	}
	cout << "4) Summary comissions: " << sum2 << endl;
	cout << "5) Total cash flow: " << sum1 + sum2;
}

int fromNS(string numRaw, int sourceNS) {
	//cout << "fromNS(num: " << numRaw << " NS: " << sourceNS << ")" << endl;
	int num = 0;

	for (int i = 0; i < numRaw.length(); i++) {
		int c = (int)numRaw[i];
		int cur = 0;

		if (c > 47 && c < 58) { // Numbers
			cur = c - 48;
			//cout << "[N]> toAdd = " << (c - 48) << " | cur = " << cur << endl;
		}
		else if (c > 64 && c < 91) { // Letters
			cur = c - 55;
			//cout << "[L]> toAdd = " << (c - 55) << " | cur = " << cur << endl;
		}
		else {
			cout << "Found unsupported symbol: '" << static_cast<char>(c) << "'";
			return -1;
		}

		num += cur * pow(sourceNS, numRaw.length() - 1 - i);
	}

	//cout << "fromNS(...) = " << num << endl;

	return num;
}

string toNS(int num, int targetNS) {
	//cout << "toNS(num: " << num << " NS: " << targetNS << ")" << endl;

	if (num < 0)
		return "";

	string res = "";
	
	while (num > 0) {
		int rest = num % targetNS;

		if (rest >= 0 && rest <= 10) {
			res = static_cast<char>(rest + 48) + res;
			//cout << "[N]> toAdd = " << (rest + 48) << " | res = " << res << endl;
		}
		else if (rest >= 10 && rest <= 36) {
			res = static_cast<char>(rest + 55) + res;
			//cout << "[L]> toAdd = " << (rest + 55) << " | res = " << res << endl;
		}
		else {
			cout << "Rest was too big while tried to convert to target NS: " << rest;
			return "";
		}

		num = num / targetNS;
	}

	//cout << "toNS(...) = " << res << endl;

	return res;
}

void task4_9() {
	int sourceNS, targetNS;
	string numRaw, res;

	cout << "Enter source NS: ";
	cin >> sourceNS;

	cout << "Enter target NS: ";
	cin >> targetNS;

	cout << "Enter number: ";
	cin >> numRaw;

	if (sourceNS == targetNS) {
		res = numRaw;
	}
	else if (numRaw == "0") {
		res = "0";
	}
	else {
		res = toNS(fromNS(numRaw, sourceNS), targetNS);
	}
	if(!res.empty())
		cout << "Res: " << res;
}

// Euclid

void taskEuclid() {
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

// Eratosthene

void taskEratosthenes() {
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

// Text files (12 and 13)

void taskTextFiles() {
	ofstream out("5_3.txt");
	ifstream in("5_3.txt");

	out << "Cookies" << endl;
	out << "Yay" << endl;

	out.close();
	
	string line;

	while (getline(in, line)) {
		cout << line << endl;
	}

	in.close();
}

int sumDigits(int num) {
	int res = 0, remainder;
	while (num > 0) {
		remainder = num % 10;
		res = res + remainder;
		num = num / 10;
	}
	return res;
}

// Rows 13
void taskRows1() {
	int m;

	while (true) {
		cout << "Enter m: ";
		cin >> m;

		if (m >= 27) {
			cout << "Number should be lower than 27!" << endl;
		}
		else {
			break;
		}
	}

	cout << "Processing..." << endl;

	for (int i = 100; i < 1000; i++) {
		if (sumDigits(i) == m) {
			cout << i << endl;
		}
	}

	cout << "Done";
}

// Rows 19
void taskRows2() {
	cout << "*** Student height analysis ***" << endl;
	cout << "Enter height (cm) and press <Enter>." << endl;
	cout << "Enter '0' to finish input and start analysis" << endl;

	vector<int> arr;
	int in;

	while (true) {
		cout << "-> ";
		cin >> in;
		if (in == 0) {
			break;
		}
		arr.push_back(in);
	}

	int sum = 0;

	for (auto const& el : arr) {
		sum += el;
	}

	float avHeight = sum / arr.size();

	cout << "Average height: " << avHeight << " cm" << endl;

	int higherCount = 0;

	for (auto const& el : arr) {
		if (el > avHeight) {
			higherCount++;
		}
	}

	cout << higherCount << " people are higher than average";
}

// Files 25

int randInt(int min, int max) {
	return min + (rand() % (max - min + 1));
}

void generateFile() {
	int seed;

	cout << "Enter seed for file generation (any integer number): ";
	cin >> seed;

	srand(seed);

	ofstream out("files.txt");

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 15; j++) {
			out << static_cast<char>(randInt(33, 126)); // https://en.m.wikipedia.org/wiki/File:ASCII-Table-wide.svg
		}
		out << endl;
	}

	out.close();
}

void taskFiles() {
	generateFile();

	bool loop = true;

	cout << "File generated. Press 'e' to open it or press 'a' to start analysis" << endl;

	while (loop) {
		switch (_getch()) {
		case 'e':
			system("notepad \"files.txt\"");
			break;
		case 'a':
			loop = false;
			break;
		}
	}

	cout << "Analysing..." << endl;

	ifstream in("files.txt");

	int amount = 0;

	string line;
	while (getline(in, line)) {
		bool fail = false;
		int prevCh = 0;

		for (char& ch : line) {
			int chCode = (int)ch;
			if (prevCh != 0) {
				if (prevCh != chCode - 1) {
					fail = true;
					break;
				}
			}
			prevCh = chCode;
		}

		if (!fail && !line.empty()) {
			cout << "Found: " << line << endl;
			amount++;
		}
	}

	in.close();

	cout << "Found " << amount << " strings with sorted characters";
}

// Balls

void perestanovka(int ballsAmount, int *amount, int step) { // step = 0, 1, 2, 3 | max = 10, 9, 8
	int max = ballsAmount - step;
	for (int i = 0; i < max; i++) {
		if (i == step + 1) {
			*amount += 1;
		}
		else if(step != ballsAmount - 1) {
			perestanovka(ballsAmount, amount, step + 1);
		}
	}
}

void taskBalls() {
	int ballsAmount = 10, amount = 0;

	perestanovka(ballsAmount, &amount, 0);

	cout << "Res: " << amount;
}

// Fibonnachi

int pressFToPayRespect(int n) {
	if (n == 1 || n == 2)
		return 1;
	return pressFToPayRespect(n - 1) + pressFToPayRespect(n - 2);
}

void miraculousNumbers() {
	int num;
	
	cout << "Which number do you want?" << endl;
	cout << "> ";
	
	cin >> num;

	cout << "Res: " << pressFToPayRespect(num);
}