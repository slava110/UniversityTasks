#pragma once

void spinners1() {
	int baseCost, pCost, maxCost;
	cout << "Enter A: ";
	cin >> baseCost;
	cout << "Enter B: ";
	cin >> pCost;
	cout << "Enter C: ";
	cin >> maxCost;

	int cost = maxCost - baseCost;
	for (; cost % pCost == 0; cost--) {

	}
	cout << "L: " << cost / pCost; //  << " | Cost: " << (cost + 1)
}

void spinners2() {
	int count;
	cout << "Enter rotors: ";
	cin >> count;

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
	cout << "Enter M: ";
	cin >> M;
	cout << "Res: " << (N + 1) * (M + 1) * N * M / 4;
}

void spinners4() {
	int N;
	cout << "Enter N: ";
	cin >> N;

	int freePlaces[9] = {};

	int m;

	cout << "Enter numbers of free places:" << endl;

	for (int i = 0; i < N; i++) {
		cin >> m;
		if (m > 0 && m <= 36) {
			freePlaces[(m - 1) / 4]++;
			//cout << "Added +1 to " << (m - 1) / 4 << endl;
		}
		else if (m > 36 && m <= 54) { // 37, 38 => 8 | 39, 40 => 7
			freePlaces[8 - (m - 37) / 2]++;
			//cout << "Added +1 to " << (8 - (m - 37) / 2) << endl;
		}
		/*else {
			cout << "Cannot add!" << endl;
		}*/
	}

	/*for (int i = 0; i < 9; i++) {
		cout << freePlaces[i] << ", ";
	}*/

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
	cout << "Enter K: ";
	cin >> K;

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