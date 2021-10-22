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

