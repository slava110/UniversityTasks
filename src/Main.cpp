#include <iostream>
#include <string>
#include <conio.h>
#include <map>

#include "Tasks.h"
#include "Spinners.h"

// Bad practice but fine for university tasks
using namespace std;

// Create map with tasks
typedef void (*TaskFunc)();
map<string, TaskFunc> tasks;

// This is garbage language
// Why there's no reflection
// Pls let me code in Java/Kotlin
void setupTasks() {
	// Homework
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
	tasks["4.9"] = task4_9;

	tasks["euclid"] = taskEuclid;
	tasks["eratosthene"] = taskEratosthenes;
	tasks["textFiles"] = taskTextFiles;
	tasks["rows.1"] = taskRows1;
	tasks["rows.2"] = taskRows2;
	tasks["files"] = taskFiles;

	// Additional

	tasks["miraculousNums"] = miraculousNumbers;

	tasks["spinners.1"] = spinners1;
	tasks["spinners.2"] = spinners2;
	tasks["spinners.3"] = spinners3;
	tasks["spinners.4"] = spinners4;
	tasks["spinners.5"] = spinners5;

	tasks["balls"] = taskBalls;
}


// Okay, this shit is boring. Let's add choice to make it FaNcY at least
int main() {
	system("chcp 65001");
	system("title University Tasks");

	system("cls");

	setupTasks(); // Because C++ doesn't have reflection, bruh

	string input;

	while (true) {
		cout << "Hello! Welcome to UniversityTasks! I've created this program for my university course" << endl;
		cout << " Use 'help' command to open help window (will just open README.txt file)" << endl;
		cout << " Use task id to test task with certain id" << endl;
		cout << " Use 'exit' to exit program" << endl;
		cout << "> ";
		
		cin >> input;

		if (input == "exit") {
			break;
		}
		else if (input == "help") {
			system("notepad \"..\\README.txt\"");
		}
		else {
			if (tasks.find(input) != tasks.end()) { // if(map.contains(input)) but C++ style because C++ is garbage
				do {
					system("cls");
					tasks[input]();
					cout << endl << endl;
					cout << "Task execution finished." << endl;
					cout << "Press 'r' if you want to rerun this task or any other key if you want to come back to the main menu" << endl;
				} while (_getch() == 'r');
				system("cls");
				continue;
			}
			else {
				cout << "Task with this id not found! Use valid task id next time!" << endl;
				_getch();
			}
		}

		cout << endl;
		system("cls");
	}
}