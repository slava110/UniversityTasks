#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <map>

// Bad practice but fine for university tasks
using namespace std;

// Create map with tasks
typedef void (*TaskFunc)();
map<string, TaskFunc> tasks;


//========== Actual code ==========

double PI = 3.14159265358979323846;

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
float calcZaemFormula(float S, float n, float p) {
	float r = p / 100;
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
	float S, n, p, m, temp;

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

	cout << "Enter m: ";
	cin >> m;

	if (m <= 0) {
		cout << "Please don't use 0 as m. Idk why but it will return NAN or INF. So... Yeah";
		return;
	}


}

void task3_3() {
	std::cout << std::ifstream("text.txt").rdbuf();
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
}