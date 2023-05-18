#include <iostream>
#include "GameCommand.h"


//-------------Function definitions
void DoCommands(Model& model, View& view) {
	char command;
	int id1, id2, x, y;
	unsigned int battles, potions_needs;
	
	model.ShowStatus();
	view.Clear();
	model.Display(view);
	
	cout << "Enter command: ";
	 
	while(cin >> command) { //this is used to error check the inputs instead of doing each one individually
		switch(command) {
			case 'm': case 'M': 
			cin >> id1 >> x >> y; //echos the user order input of m 1 10 15
			DoMoveCommand(model, id1, Point2D(x, y));
			view.Clear();
			model.Display(view);
			break;
			case 'c': case 'C':
			cin >> id1 >> id2;
			DoMoveToCenterCommand(model, id1, id2);
			view.Clear();
			model.Display(view);
			break;
			case 'g': case 'G':
			cin >> id1 >> id2;
			DoMoveToGymCommand(model, id1, id2);
			view.Clear();
			model.Display(view);
			break;
			case 's': case 'S':
			cin >> id1;
			DoStopCommand(model, id1);
			view.Clear();
			model.Display(view);
			break;
			case 'p': case 'P':
			cin >> id1 >> potions_needs;
			DoRecoverInCenterCommand(model, id1, potions_needs);
			break;
			case 'b': case 'B':
			cin >> id1 >> battles;
			DoBattleCommand(model, id1, battles);
			break;
			case 'a': case 'A':
			DoAdvanceCommand(model, view);
			break;
			case 'r': case 'R':
			DoRunCommand(model, view);
			break;
			case 'q': case 'Q':
			exit(0);
			break;
			default:
			cout << "Error: Please enter a valid command!" << endl;
		}
		cout << "Enter command: ";
	}	
}

void DoMoveCommand(Model& model, int trainer_id, Point2D p1) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	trainerPtr->StartMoving(p1);
	cout << "Moving (" << trainerPtr->GetName() << ") to (" << p1 << ")" <<endl;
}

void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	PokemonCenter* centerPtr = model.GetPokemonCenterPtr(center_id);
	trainerPtr->StartMovingToCenter(centerPtr);
	cout << "Moving (" << trainerPtr->GetName() << ") to pokemon center (" << center_id << ")" << endl;
}

void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	PokemonGym* gymPtr = model.GetPokemonGymPtr(gym_id);
	trainerPtr->StartMovingToGym(gymPtr);
	cout << "Moving (" << trainerPtr->GetName() << ") to pokemon gym (" << gym_id << ")" << endl;
}

void DoStopCommand(Model& model, int trainer_id) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	trainerPtr->Stop();
	cout << "Stopping (" << trainerPtr->GetName() << ")" << endl;
}

void DoBattleCommand(Model& model, int trainer_id, unsigned int battles) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	trainerPtr->StartBattling(battles);
	if (trainerPtr->GetState() == 7) {
		cout << "(" << trainerPtr->GetName() << ") is battling" << endl;
	}
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needs) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	trainerPtr-> StartRecoveringHealth(potions_needs);
	if (trainerPtr->GetState() == 8) {
		cout << "Recovering (" << trainerPtr->GetName() << ")'s Pokemon's health" << endl;
	}
}

void DoAdvanceCommand(Model& model, View& view) {
	model.Update();
	model.ShowStatus();
	view.Clear();
	model.Display(view);
}

void DoRunCommand(Model& model, View& view) {
	bool trigger = false;
	int count = 0;
	while (count < 5) {
		trigger = model.Update();
		if(trigger) {
			model.ShowStatus();
			view.Clear();
			model.Display(view);
			return;
		}
		count++;
	}
	model.ShowStatus();
	view.Clear();
	model.Display(view);
}