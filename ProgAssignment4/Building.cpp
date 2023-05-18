#include <iostream>
#include "Building.h"

using namespace std;
//----------Contructors
Building::Building() : GameObject('B') {
	
	trainer_count = 0; 
	cout << "Building default constructed" << endl;
}

Building::Building(char in_code, int in_id, Point2D in_loc) : GameObject(in_loc, in_id, in_code) {
	
	trainer_count = 0;
	
	cout << "Building constructed" << endl;
}

//--------Public Member Functions
void Building::AddOneTrainer() {
	trainer_count++;
}

void Building::RemoveOneTrainer() {
	if (trainer_count != 0) { 
		trainer_count--;
	} else { 
		trainer_count = 0;
	}
}

void Building::ShowStatus() {
	cout << "(" << display_code << ")(" << id_num << ") located at " << location << endl;
	if (trainer_count == 1) {
		cout << "(" << trainer_count << ") trainer is in this building." << endl;
	} else {
		cout << "(" << trainer_count << ") trainers are in this building." << endl;
	}
}

bool Building::ShouldBeVisible() {
	return true;
}