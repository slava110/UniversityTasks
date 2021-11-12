#pragma once

void spinners1() {
	int baseCost, pCost, maxCost;
	cout << "Enter A: ";
	cin >> baseCost;

	if (baseCost < 0 || baseCost > 2000000000) {
		cout << "Illegal input. Expected integer number 0 <= A <= 2x10^9";
		return;
	}

	cout << "Enter B: ";
	cin >> pCost;

	if (pCost < 0 || pCost > 2000000000) {
		cout << "Illegal input. Expected integer number 0 <= B <= 2x10^9";
		return;
	}

	cout << "Enter C: ";
	cin >> maxCost;

	if (maxCost < baseCost || maxCost > 2000000000) {
		cout << "Illegal input. Expected integer number A <= C <= 2x10^9";
		return;
	}

	int cost = maxCost - baseCost;
	for (; cost % pCost == 0; cost--) {

	}
	cout << "L: " << cost / pCost; //  << " | Cost: " << (cost + 1)
}

void spinners2() {
	int count;
	cout << "Enter M: ";
	cin >> count;

	if (count < 0 || count > 2000000000) {
		cout << "Illegal input. Expected integer number 0 <= M <= 2x10^9";
		return;
	}

	int countT = 0, countF = 0, rest = 0;

	if (count > 6 || count == 4 || count == 3) {
		countF = count % 3;
		rest = countF * 4;
		countT = (count - rest) / 3;
	}

	cout << countT << " " << countF;
}

void spinners3() {
	int N, M;
	cout << "Enter N: ";
	cin >> N;

	if (N < 0 || N > 75000) {
		cout << "Illegal input. Expected integer number 0 <= N <= 75000";
		return;
	}

	cout << "Enter M: ";
	cin >> M;

	if (M < 0 || M > 75000) {
		cout << "Illegal input. Expected integer number 0 <= M <= 75000";
		return;
	}

	cout << "Res: " << (N + 1) * (M + 1) * N * M / 4;
}

void spinners4() {
	int N;
	cout << "Enter N: ";
	cin >> N;

	if (N < 0 || N > 54) {
		cout << "Illegal input. Expected integer number 0 <= N <= 54";
		return;
	}

	int freePlaces[9] = {};

	int m;

	cout << "Enter numbers of free places:" << endl;

	for (int i = 0; i < N; i++) {
		cin >> m;
		if (m < 0 || m > 54) {
			cout << "Illegal input. Expected integer number 0 <= free place number <= 54";
			return;
		}
		if (m > 0 && m <= 36) {
			freePlaces[(m - 1) / 4]++;
		}
		else if (m > 36 && m <= 54) {
			freePlaces[8 - (m - 37) / 2]++;
		}
		/*else {
			cout << "Cannot add!" << endl;
		}*/
	}

	cout << endl;

	int c = 0, max = 0;

	for (int i = 0; i < 9; i++) {
		if (freePlaces[i] == 6) {
			c++;
		}
		if (c > max) {
			max = c;
		}
		else {
			c = 0;
		}
	}

	cout << "Res: " << max;
}

void spinners5() {
	unsigned long long int N, K, left, right, i1 = 0, i2 = 0, sum = 0, max = 0;
	cout << "Enter N: ";
	cin >> N;

	if (N <= 0 || N > 10000000000000000000) {
		cout << "Illegal input. Expected integer number 0 < K < 10^18";
		return;
	}

	cout << "Enter K: ";
	cin >> K;

	if (K < N || K > 10000000000000000000) {
		cout << "Illegal input. Expected integer number K <= N <= 10^18";
		return;
	}

	unsigned long long int* a = new unsigned long long int[N + 2];
	a[0] = 8; a[N + 1] = 8;
	for (unsigned long long int i = 1; i <= N; i++)
		a[i] = 0;

	while (K > 0) {
		for (unsigned long long int i = 0; i <= N + 1; i++) {
			if (a[i] == 0)
				sum = sum + 1;
			else {
				if (sum > max) {
					i1 = i - 1 - sum;
					i2 = i;
					max = sum;
				}
				sum = 0;
			}
		}
		a[(i1 + i2) / 2] = 2;
		sum = 0;
		max = 0;
		K = K - 1;
	}

	a[(i1 + i2) / 2] = 3;
	left = (i1 + i2) / 2 - (i1 + 1);
	right = (i2 - 1) - (i1 + i2) / 2;

	//cout << "Row: ";
	//for (unsigned long long int i = 0; i <= N + 1; i++)
	//	cout << a[i] << " ";

	cout << "Left: " << left << endl << "Right: " << right;
}