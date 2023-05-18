#include <iostream>
#include "Model.h"

using namespace std;


//--------Constrcutor
Model::Model() {
	time = 0;
	num_objects = 8;
	count = 0; 
	
	trainer_ptrs.push_back(new Trainer("Ash", 1, 'T', 1, Point2D(5, 1))); //creating trainers
	trainer_ptrs.push_back(new Trainer("Misty", 2, 'T', 2, Point2D(10, 1)));
	object_ptrs.push_back(trainer_ptrs[0]);
	object_ptrs.push_back(trainer_ptrs[1]);
	num_trainers = 2;
	
	center_ptrs.push_back(new PokemonCenter(1, 1.0, 100, Point2D(1, 20))); //creating center
	center_ptrs.push_back(new PokemonCenter(2, 2.0, 200, Point2D(10, 20)));
	object_ptrs.push_back(center_ptrs[0]);
	object_ptrs.push_back(center_ptrs[1]);
	num_centers = 2;
	
	gym_ptrs.push_back(new PokemonGym(10, 1, 2.0, 3, 1, Point2D(0, 0))); //creating gym
	gym_ptrs.push_back(new PokemonGym(20, 5, 7.5, 4, 2, Point2D(5, 5)));
	object_ptrs.push_back(gym_ptrs[0]);
	object_ptrs.push_back(gym_ptrs[1]);
	num_gyms = 2;
	
	wildpokemon_ptrs.push_back(new WildPokemon("W1", 5.0, 2.0, false, 1, Point2D(10,12)));
	wildpokemon_ptrs.push_back(new WildPokemon("W2", 5.0, 2.0, false, 2, Point2D(15,5)));
	object_ptrs.push_back(wildpokemon_ptrs[0]);
	object_ptrs.push_back(wildpokemon_ptrs[1]);
	num_wildpokemon = 2;

	active_ptrs = object_ptrs;

	cout << "Model default constructed" << endl;
}

//------Member Functions
Trainer* Model::GetTrainerPtr(int id) { //index to get respective called trainer
	int index;
	bool latch = false;

	try{
		for (int i = 0; i < num_trainers; i++) {
			if (trainer_ptrs[i]->GetId() == id) {
				index = i;
				latch = true;
				break;
			}
		}
		if (!(latch)){
			Invalid_Input inva("No matching Trainer ID");
			throw inva;
		}
		else {
			return trainer_ptrs[index];
		}
	} catch (Invalid_Input inva){
		cout << "ERROR: " << inva.msg_ptr <<endl;
		return NULL;
	}	

}

PokemonCenter* Model::GetPokemonCenterPtr(int id) { //index to get respective called pokemon center
	int index;
	bool latch = false;
	try{
		for (int i = 0; i < num_centers; i++) {
			if (center_ptrs[i]->GetId() == id) {
				index = i;
				latch = true;
				break;
			}
		}
		if (!(latch)){
			Invalid_Input inva("No matching Pokemon Center ID");
			throw inva;
		}
		else {
			return center_ptrs[index];
		}
	} catch (Invalid_Input inva){
		cout << "ERROR: " << inva.msg_ptr <<endl;
		return NULL;
	}	
}

PokemonGym* Model::GetPokemonGymPtr(int id) { //index to get respective called pokemon gym
	int index;
	bool latch = false;
	try{
		for (int i = 0; i < num_gyms; i++) {
			if (gym_ptrs[i]->GetId() == id) {
				index = i;
				latch = true;
				break;
			}
		}
		if(!(latch)) {
			Invalid_Input inva("No matching Pokemon Gym ID");
			throw inva;
		} 
		else {
			return gym_ptrs[index];
		}
	} catch (Invalid_Input inva) {
		cout << "ERROR: " << inva.msg_ptr << endl;
		return NULL;
	}
}

WildPokemon* Model :: GetWildPokemonPtr(int id){
	int index;
	bool latch = false;
	try{
		for (int i = 0; i < num_wildpokemon; i++) {
			if (wildpokemon_ptrs[i]->GetId() == id) {
				index = i;
				latch = true;
				break;
			}
		}
		if(!(latch)) {
			Invalid_Input inva("No matching Wild Pokemon ID");
			throw inva;
		} 
		else {
			return wildpokemon_ptrs[index];
		}
	} catch (Invalid_Input inva) {
		cout << "ERROR: " << inva.msg_ptr << endl;
		return NULL;
	}
}


bool Model::Update() {
	bool trigger = false; 
	time++;
	

	for (int i = 0; i < active_ptrs.size(); i++) {
		if(active_ptrs[i]->Update()) {  //if the update is called we set the trigger to true
			trigger = true;
			if (active_ptrs[i] -> GetDisplayCode() == 'c' || active_ptrs[i] -> GetDisplayCode() == 't' || active_ptrs[i] -> GetDisplayCode() == 'g' || active_ptrs[i] -> GetDisplayCode() == 'w'){
				active_ptrs.erase(active_ptrs.begin() + i); //we show that its dead when it is converted to lowercase
			}
		}
	}
	
	//Goes through each gym/center and inside each trainer essential   ly resets to the right amount in bulidings
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
	
	for (int i = 0; i < num_trainers; i++){ //following the trainer if encountered
		for (int j = 0; j < num_wildpokemon; j++){
			if ((fabs(trainer_ptrs[i] -> GetLocation().x - wildpokemon_ptrs[j]->GetLocation().x) <= 2) && (fabs(trainer_ptrs[i]->GetLocation().y - wildpokemon_ptrs[j]->GetLocation().y) <= 2)){
				wildpokemon_ptrs[j] -> follow(trainer_ptrs[i]);
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

void Model :: NewCommand(char type, int in_id, Point2D in_loc){
	switch(type){
		case 'c' : case 'C':
		try{
			for (int i = 0; i < num_centers; i++){ //checks to see if ID is currently use
				if(center_ptrs[i] -> GetId() == in_id){
					Invalid_Input inva("ID already in use");
					throw inva;
				}
			}
			if (in_id < 0 || in_id > 9){
				Invalid_Input inva("ID must be 0 through 9");
				throw inva;
			}
			for (int i = 0; i < num_objects; i++){
				if (object_ptrs[i]->GetLocation().x == in_loc.x && object_ptrs[i]->GetLocation().y == in_loc.y) {
					Invalid_Input inva("Location is already in use");
					throw inva;
				}
			}
			center_ptrs.push_back(new PokemonCenter(in_id, 5, 100, in_loc)); //creating of that new center if it meats the requirements
			PokemonGym* gPtr = NULL;
			for (int i = 0; i < num_objects; i++){ //inserting objects in the right are to follow format
				gPtr = dynamic_cast<PokemonGym*>(object_ptrs[i]);
				if(gPtr != NULL){
					object_ptrs.insert(object_ptrs.begin() + i, center_ptrs[num_centers]);
					break;
				}
			}
			active_ptrs.push_back(center_ptrs[num_centers]);
			num_centers++;
			num_objects++;
		}catch(Invalid_Input inva){
				cout << "Error: " << inva.msg_ptr << endl;
		}
		break;
	    case 'g' : case 'G': 
		try{
			for (int i = 0; i < num_gyms; i++){ //checks to see if ID is currently use
				if(gym_ptrs[i] -> GetId() == in_id){
					Invalid_Input inva("ID already in use");
					throw inva;
				}
			}
			if (in_id < 0 || in_id > 9){
				Invalid_Input inva("ID must be 0 through 9");
				throw inva;
			}
			for (int i = 0; i < num_objects; i++){
				if (object_ptrs[i]->GetLocation().x == in_loc.x && object_ptrs[i]->GetLocation().y == in_loc.y) {
					Invalid_Input inva("Location is already in use");
					throw inva;
				}
			}
			gym_ptrs.push_back(new PokemonGym(10, 1, 1.0, 2, in_id, in_loc));
			WildPokemon* wpPtr = NULL;
			for (int i = 0; i < num_objects; i++){
				wpPtr = dynamic_cast<WildPokemon*>(object_ptrs[i]);
				if(wpPtr != NULL){
					object_ptrs.insert(object_ptrs.begin() + i, gym_ptrs[num_gyms]);
					break;
				}
			}
			active_ptrs.push_back(gym_ptrs[num_gyms]);
			num_gyms++;
			num_objects++;
		}catch(Invalid_Input inva){
				cout << "Error: " << inva.msg_ptr << endl;
		}
		break;
		case 't' : case 'T': 
		try{
			for (int i = 0; i < num_trainers; i++){ //checks to see if ID is currently use
				if(trainer_ptrs[i] -> GetId() == in_id){
					Invalid_Input inva("ID already in use");
					throw inva;
				}
			}
			if (in_id < 0 || in_id > 9){
				Invalid_Input inva("ID must be 0 through 9");
				throw inva;
			}
			for (int i = 0; i < num_objects; i++){
				if (object_ptrs[i]->GetLocation().x == in_loc.x && object_ptrs[i]->GetLocation().y == in_loc.y) {
					Invalid_Input inva("Location is already in use");
					throw inva;
				}
			}
			stringstream strs; //since the contructor requires a name we created one that can be used
			strs << "Trainer" << in_id; //Creates a defualy name with id so we can differenciate
			trainer_ptrs.push_back(new Trainer(strs.str(), in_id, 'T', 5, in_loc));
			PokemonCenter* cPtr = NULL;
			for (int i = 0; i < num_objects; i++) {
				cPtr = dynamic_cast<PokemonCenter*>(object_ptrs[i]);
				if (cPtr != NULL) {
					object_ptrs.insert(object_ptrs.begin() + i, trainer_ptrs[num_trainers]);
					break;
				}
			}
			active_ptrs.push_back(trainer_ptrs[num_trainers]);
			num_trainers++;
			num_objects++;
		} catch (Invalid_Input inva){
			cout << "Error: " << inva.msg_ptr << endl;
		}
		break;
		case 'w' : case 'W' : 
		try{
			for (int i = 0; i < num_wildpokemon; i++){ //checks to see if ID is currently use
				if(wildpokemon_ptrs[i] -> GetId() == in_id){
					Invalid_Input inva("ID already in use");
					throw inva;
				}
			}
			if (in_id < 0 || in_id > 9){
				Invalid_Input inva("ID must be 0 through 9");
				throw inva;
			}
			for (int i = 0; i < num_objects; i++){
				if (object_ptrs[i]->GetLocation().x == in_loc.x && object_ptrs[i]->GetLocation().y == in_loc.y) {
					Invalid_Input inva("Location is already in use");
					throw inva;
				}
			}
			stringstream strs; //since the contructor requires a name we created one that can be used
			strs << "WildPokemon" << in_id; //Creates a defualy name with id so we can differenciate
			wildpokemon_ptrs.push_back(new WildPokemon(strs.str(), 5.0, 2.0, false, in_id, in_loc));
			object_ptrs.push_back(wildpokemon_ptrs[num_wildpokemon]);
			active_ptrs.push_back(wildpokemon_ptrs[num_wildpokemon]);
			num_wildpokemon++;
			num_objects++;
		} catch (Invalid_Input inva){
			cout << "Error: " << inva.msg_ptr << endl;
		}
		break;
	}
}

//------Decontrustor
Model::~Model() {
	for (int i = 0; i < num_objects; i++) {
		delete object_ptrs[i];
	}
	cout << "Model destructed" << endl;
}