#include <iostream>
#include <string>
#include <conio.h>

#include "Tasks.h"
#include "Spinners.h"
#include "Utils.h"

using namespace std;


// Okay, this shit is boring. Let's add choice to make it FaNcY at least
int main() {
	system("chcp 65001");
	system("title University Tasks");

	system("cls");

	setupTasks(); // Because C++ doesn't have reflection, bruh

	string input;

	while (true) {
		cout << "Hello! Welcome to UniversityTasks! I've created this program for my university course" << endl;
		cout << "Use task id format '<task group>.<task id>' (example: '1.1' or '2.3')" << endl;
		cout << "to test task with certain id or use 'exit' to exit program" << endl;
		//cout << "(btw, you can rerun same task using 'r' key after task execution)" << endl;
		cout << "> ";
		
		cin >> input;

		if (input == "exit") {
			break;
		}
		else {
			if (tasks.find(input) != tasks.end()) { // if(map.contains(input)) but C++ style because C++ is garbage
				do {
					system("cls");
					tasks[input]();
					cout << endl << endl;
					cout << "Task execution finished." << endl << "Press 'r' if you want to rerun this task or 'enter' if you want to come back to main menu" << endl;
				} while (_getch() == 'r');
				system("cls");
				continue;
			}
			else {
				cout << "Task with this id not found! Use valid task id next time!";
				_getch();
			}
		}

		cout << endl;
		system("cls");
	}
}