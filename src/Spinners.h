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
	cout << "L: " << cost / pCost << " | Cost: " << (cost + 1);
}