
/*


@author Kyle Benjamin Wucik
Project for SNHU: Chada Display Clock
03/27/2022



*/

#include <iomanip>
#include <iostream>
using namespace std;

class Time { //class ties everything together and can be used to call specific functions in main

public: //sets class to public so can be used elsewhere
	int hour1, min1, sec1; //sets variables for the 12 hour clock as integers

	int hour2, min2, sec2; //sets variables for the 24 hour clock as integers

	string AmorPm = "AM"; //sets string variable to display if AM or PM with 12 hour clock format

	Time() { //constructor for the two clocks variables

		this->hour1 = 12;
		this->hour2 = 00;
		this->min1 = 00;
		this->min2 = 00;
		this->sec1 = 00;
		this->sec2 = 00;

	}

	void manageTime(int timeType = 1) { //void return type for the manage time function

		if (timeType == 1) { //if time type is set to one, manage 12 hour format

			if (sec1 / 60 > 0) { //this will add a minute if seconds is 60 or greater

				sec1 %= 60; //sets seconds to remainder
				min1++; //and adds a minute

			}

			if (min1 / 60 > 0) { //if minute goes above 60

				min1 %= 60; //set minute to remainder
				hour1++; //and add an hour

			}

			if (hour1 / 12 > 0) { //if hour goes past 12 will set to 1 instead of 13

				hour1 %= 12;// sets to remainder to hour 1

				if (hour1 == 0) { // if the remainder is 0
					hour1 = 12; // set to 12

				}
			}

		}
		if (timeType == 2) { //manages time for 24 hour format

			if (hour2 >= 12) { //sets to pm if hour 2 goes to 12 or greater

				AmorPm = "PM";

			}

			if (hour2 >= 24) { //resets to am if hour 2 goes to 24 or greater

				AmorPm = "AM";

			}

			if (sec2 / 60 > 0) { //this will add a minute if seconds is 60 or greater


				sec2 %= 60; //sets seconds to remainder
				min2++; //and adds a minute

			}

			if (min2 / 60 > 0) { //if minute goes above 60

				min2 %= 60; //set minute to remainder
				hour2++; //and add an hour

			}

			if (hour2 / 24 > 0) { //if the 24 hour format goes about 24

				hour2 %= 24; //set hour2 to remainder

			}

		}
	}

	void incSec() {

		sec1++;
		sec2++;
		manageTime(1);
		manageTime(2);

	}

	void waitSec() {

		sec1++;
		sec2++;
		manageTime(1);
		manageTime(2);

	}

	void incMinute() {

		min1++;
		min2++;
		manageTime(1);
		manageTime(2);


	}

	void incHour() {

		hour1++;
		hour2++;
		manageTime(1);
		manageTime(2);


	}

	void displayTime() {

		cout.fill('0');
		cout << "Time in 12 Hour Format: " << setw(2) << hour1 << ":" << setw(2) << min1 << ":" << setw(2) << sec1 << AmorPm << endl;
		cout << "Time in 24 Hour Format: " << setw(2) << hour2 << ":" << setw(2) << min2 << ":" << setw(2) << sec2 << endl;

	}
};

int main() {

	Time t;
	int firstChoice;
	int timeChoice;
	int menuChoice;
	int loopChoice = 1;

	while (loopChoice > 0) {


		t.displayTime();// displays time
		//below outputs options so user knows what numbers to use
		cout << "What do you want to do?: " << endl;
		cout << "1. Change time" << endl;
		cout << "2. Wait 2 seconds" << endl;
		cout << "3. Exit" << endl;
		cin >> firstChoice;
		system("CLS"); // used to clear screen


		if (firstChoice == 1) {

			t.incSec(); // adds a second used to simulate real time passing
			t.displayTime();// displays time
			//below outputs options so user knows what numbers to use
			cout << "Choose option: " << endl;
			cout << "1. Add Time" << endl;
			cout << "2. Exit" << endl;
			cin >> timeChoice; //gets user input
			system("CLS"); // used to clear screen
			t.incSec(); // adds a second used to simulate real time passing

			if (timeChoice == 1) {

				t.displayTime();// displays time
				//below outputs options so user knows what numbers to use
				cout << "Choose option" << endl;
				cout << "1. Add 1 hour" << endl;
				cout << "2. Add 1 minute" << endl;
				cout << "3. Add 1 second" << endl;
				cout << "4. Exit" << endl;

				cin >> menuChoice; //user input for menu option
				system("CLS"); // used to clear screen
				t.incSec(); // adds a second used to simulate real time passing

				switch (menuChoice) {  //starts cases

				case 1:
					t.incHour(); //adds an hour

					system("CLS"); // used to clear screen
					//t.displayTime();// displays time might not need
					break;//breaks function and resets 
				case 2:
					t.incMinute(); //adds a minute

					system("CLS"); // used to clear screen
					//t.displayTime();// displays time might not need
					break;//breaks function and resets 
				case 3: //third option increments the second
					t.incSec(); // adds a second
					system("CLS"); // used to clear screen
					//t.displayTime(); // displays time
					break;//breaks function and resets 
				case 4: //this is the fourth option will let user exit
					cout << "Thanks for using this clock!";
					exit(1);
					break; //breaks function and resets 
				default: //deafult case. Will show this if user inputs option other than 1 2 3 or 4
					cout << "Invalid option!" << endl;
					t.incSec(); // adds a second used to simulate real time passing
					system("CLS"); // used to clear screen
					//t.displayTime(); // displays time might not need
					break; //breaks function and resets 

				}

			}

			if (timeChoice == 2) {

				loopChoice = -1; // stops loop if exit is picked


			}

		}

		else if (firstChoice == 2) {

			t.incSec(); //increments second
			t.waitSec(); //waits a second
			system("CLS"); // used to clear screen

		}

		else if (firstChoice == 3) {

			cout << "Thanks for using this clock!"; // thanks user
			exit(1); //exits clock

		}
	}
}