#include <iostream>
#include "Model.h"

using namespace std;


//--------Constrcutor
Model::Model() {
	time = 0;
	num_objects = 6;
	count = 0; 
	
	trainer_ptrs[0] = new Trainer("Ash", 1, 'T', 1, Point2D(5, 1)); //creating trainers
	object_ptrs[0] = trainer_ptrs[0];
	trainer_ptrs[1] = new Trainer("Misty", 2, 'T', 2, Point2D(10, 1));
	object_ptrs[1] = trainer_ptrs[1];
	num_trainers = 2;
	
	center_ptrs[0] = new PokemonCenter(1, 1.0, 100, Point2D(1, 20)); //creating center
	object_ptrs[2] = center_ptrs[0];
	center_ptrs[1] = new PokemonCenter(2, 2.0, 200, Point2D(10, 20));
	object_ptrs[3] = center_ptrs[1];
	num_centers = 2;
	
	gym_ptrs[0] = new PokemonGym(10, 1, 2.0, 3, 1, Point2D(0, 0)); //creating gym
	object_ptrs[4] = gym_ptrs[0];
	gym_ptrs[1] = new PokemonGym(20, 5, 7.5, 4, 2, Point2D(5, 5));
	object_ptrs[5] = gym_ptrs[1];
	num_gyms = 2;

	cout << "Model default constructed" << endl;
}

//------Member Functions
Trainer* Model::GetTrainerPtr(int id) { //index to get respective called trainer
	int index;
	for (int i = 0; i < num_trainers; i++) {
		if (trainer_ptrs[i]->GetId() == id) {
			index = i;
			break;
		}
	}	
	return trainer_ptrs[index];
}

PokemonCenter* Model::GetPokemonCenterPtr(int id) { //index to get respective called pokemon center
	int index;
	for (int i = 0; i < num_centers; i++) {
		if (center_ptrs[i]->GetId() == id) {
			index = i;
			break;
		}
	}	
	return center_ptrs[index];
}

PokemonGym* Model::GetPokemonGymPtr(int id) { //index to get respective called pokemon gym
	int index;
	for (int i = 0; i < num_trainers; i++) {
		if (gym_ptrs[i]->GetId() == id) {
			index = i;
			break;
		}
	}	
	return gym_ptrs[index];
}

bool Model::Update() {
	bool trigger = false; 
	time++;
	

	for (int i = 0; i < num_objects; i++) {
		if(object_ptrs[i]->Update()) { 
			trigger = true;
		}
	}
	
	//Goes through each gym/center and inside each trainer essentially resets to the right amount in bulidings
	for (int i = 0; i < num_gyms; i++) { 
		for (int j = 0; j < num_trainers; j++) {
			gym_ptrs[i]->RemoveOneTrainer();
		}
	}
	for (int i = 0; i < num_centers; i++) { 
		for (int j = 0; j < num_trainers; j++) {
			center_ptrs[i]->RemoveOneTrainer();
		}
	}
	for (int i = 0; i < num_trainers; i++) { //checks the trainers location
		for (int j = 0; j < num_centers; j++) { //checks to see if trainer is in center, if so it adds 1 person
			if (trainer_ptrs[i]->GetLocation().x == center_ptrs[j]->GetLocation().x && trainer_ptrs[i]->GetLocation().y == center_ptrs[j]->GetLocation().y) {
				center_ptrs[j]->AddOneTrainer();
			}
		}
		for (int j = 0; j < num_gyms; j++) { //checks to see if trainer is in gym, if so it adds 1 person
			if (trainer_ptrs[i]->GetLocation().x == gym_ptrs[j]->GetLocation().x && trainer_ptrs[i]->GetLocation().y == gym_ptrs[j]->GetLocation().y) {
				gym_ptrs[j]->AddOneTrainer();
			}
		}
	}
	
	
	for (int i = 0; i < num_trainers; i++) { //checks if every trainer beat the gym
		if(gym_ptrs[i]->passed()) {
			count++; 
		}
	}
	if (count == num_gyms) { // if the number of gyms passed equals the number of gyms made then the game is complete
		cout << "GAME OVER: You WIN! All battles done!" << endl;
		exit(0);
	}

	count = 0;//resets count
	
	for (int i = 0; i < num_trainers; i++) { //checks how many trainers are fainted 
		if(trainer_ptrs[i]->HasFainted()) {
			count++; 
		}
	}
	if (count == num_trainers) { //if the number of trainer fainted is all of them the game is over
		cout << "GAME OVER: You LOSE! All of your Trainer's pokemon have fainted!" << endl;
		exit(0);
	}
	count = 0;
	
	if (trigger) { 
		return true;
	}
	
	return false;
}

void Model::Display(View& view) {
	for (int i = 0; i < num_objects; i++) {
		view.Plot(object_ptrs[i]);
	}
	view.Draw();
} 

void Model::ShowStatus() {
	cout << "Time: " << time << endl;
	for (int i = 0; i < num_objects; i++) {
		object_ptrs[i]->ShowStatus();
	}
	
}

//------Decontrustor
Model::~Model() {
	for (int i = 0; i < num_objects; i++) {
		delete object_ptrs[i];
	}
	cout << "Model destructed" << endl;
}