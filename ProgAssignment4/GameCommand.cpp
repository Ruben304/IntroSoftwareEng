#include <iostream>
#include "GameCommand.h"

//-------------Function definitions
void DoCommands(Model& model, View& view) {
	char command, type;
	int id1, id2, x, y;
	unsigned int battles, potions_needs;
	
	model.ShowStatus();
	view.Clear();
	model.Display(view);
	
	cout << "Enter command: ";
	 
	while(true) { //this is used to error check the inputs instead of doing each one individually
		cin >> command;
		switch(command) {
			case 'm': case 'M': 
			try{
				if(cin >> id1 >> x >> y){ //echos the user order input of m 1 10 15
					DoMoveCommand(model, id1, Point2D(x, y));
					view.Clear();
					model.Display(view);
				}
				else 
				{
					Invalid_Input inva("Invalid parameters (id, X, Y)");
					throw inva;
				}
			}catch (Invalid_Input inva){
				cout << "ERROR: " << inva.msg_ptr << endl;
			}
			break;
			case 'c': case 'C':
			try{
				if (cin >> id1 >> id2){
					DoMoveToCenterCommand(model, id1, id2);
					view.Clear();
					model.Display(view);
				}
				else 
				{
					Invalid_Input inva("Invalid parameters (id1, id2)");
					throw inva;
				}
			} catch (Invalid_Input inva){
				cout << "ERROR: " << inva.msg_ptr << endl;
			}
			break;
			case 'g': case 'G':
			try{
				if (cin >> id1 >> id2){
					DoMoveToGymCommand(model, id1, id2);
					view.Clear();
					model.Display(view);
				}
				else 
				{
					Invalid_Input inva("Invalid parameters (id1, id2)");
					throw inva;
				}
			} catch (Invalid_Input inva){
				cout << "ERROR: " << inva.msg_ptr << endl;
			}
			break;
			case 's': case 'S':
			try{
				if(cin >> id1){
					DoStopCommand(model, id1);
					view.Clear();
					model.Display(view);
				}
				else
				{
					Invalid_Input inva("Invalid parameters (id)");
					throw inva;
				}
			}catch (Invalid_Input inva) {
				cout << "Error: " << inva.msg_ptr << endl;
			}
			break;
			case 'p': case 'P':
			try{
				if((cin >> id1 >> potions_needs) && potions_needs > 0){
					DoRecoverInCenterCommand(model, id1, potions_needs);
				}
				else
				{
					Invalid_Input inva("Invalid parameters (id, potions_needed) & potions_needed > 0");
					throw inva;
				}
			}catch (Invalid_Input inva) {
				cout << "Error: " << inva.msg_ptr << endl;
			}
			break;
			case 'b': case 'B':
			try{
				if((cin >> id1 >> battles) && battles > 0)
				{
					DoBattleCommand(model, id1, battles);
				}
				else 
				{
					Invalid_Input inva("Invalid parameters (id, battles) & battles > 0");
					throw inva;
				}
			}catch (Invalid_Input inva) {
				cout << "Error: " << inva.msg_ptr << endl;
			}
			break;
			case 'a': case 'A':
			DoAdvanceCommand(model, view);
			break;
			case 'r': case 'R':
			DoRunCommand(model, view);
			break;
			case 'n' : case 'N':
			try{
				if(cin >> type >> id1 >> x >> y)
				{
					model.NewCommand(type, id1, Point2D(x, y));
					view.Clear();
					model.Display(view);
				}
				else
				{
					Invalid_Input inva("Invalid parameters (type, id1, X, Y)");
					throw inva;
				}
			}catch (Invalid_Input inva) {
				cout << "Error: " << inva.msg_ptr << endl;
			}
			case 'q': case 'Q':
			exit(0);
			break;
			default:
			cout << "Error: Please enter a valid command!" << endl;
		}
		cin.clear(); //clears extra inputs that arent needed
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores everything else of the same line then skips to the next
		cout << "Enter command: ";
	}	
}

void DoMoveCommand(Model& model, int trainer_id, Point2D p1) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	if (trainerPtr != NULL)
	{
		trainerPtr->StartMoving(p1);
		cout << "Moving (" << trainerPtr->GetName() << ") to (" << p1 << ")" <<endl;
	}
}

void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	PokemonCenter* centerPtr = model.GetPokemonCenterPtr(center_id);
	if (trainerPtr != NULL && centerPtr != NULL)
	{
		trainerPtr->StartMovingToCenter(centerPtr);
		cout << "Moving (" << trainerPtr->GetName() << ") to pokemon center (" << center_id << ")" << endl;
	}
}

void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	PokemonGym* gymPtr = model.GetPokemonGymPtr(gym_id);
	if(trainerPtr != NULL && gymPtr != NULL)
	{
		trainerPtr->StartMovingToGym(gymPtr);
		cout << "Moving (" << trainerPtr->GetName() << ") to pokemon gym (" << gym_id << ")" << endl;
	}
}

void DoStopCommand(Model& model, int trainer_id) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	if (trainerPtr !=NULL)
	{
		trainerPtr->Stop();
		cout << "Stopping (" << trainerPtr->GetName() << ")" << endl;
	}
}

void DoBattleCommand(Model& model, int trainer_id, unsigned int battles) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	if (trainerPtr !=NULL)
	{
		trainerPtr->StartBattling(battles);
		if (trainerPtr->GetState() == 7) {
			cout << "(" << trainerPtr->GetName() << ") is battling" << endl;
		}
	}
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needs) {
	Trainer* trainerPtr = model.GetTrainerPtr(trainer_id);
	if (trainerPtr !=NULL)
	{
		trainerPtr-> StartRecoveringHealth(potions_needs);
		if (trainerPtr->GetState() == 8) {
			cout << "Recovering (" << trainerPtr->GetName() << ")'s Pokemon's health" << endl;
		}
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