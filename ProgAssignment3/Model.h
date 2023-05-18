#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <cstdlib>
#include "GameObject.h"
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"

using namespace std;

class Model {
	private: //-----Private Members
		int time;
		GameObject* object_ptrs[10];
		int num_objects;
		Trainer* trainer_ptrs[10];
		int num_trainers;
		PokemonCenter* center_ptrs[10];
		int num_centers;
		PokemonGym* gym_ptrs[10];
		int num_gyms;
		int count; //count to be used for different functions
		
	public: //-----Public Members
		Model();
		~Model();
		
		//-----Member Functions
		Trainer* GetTrainerPtr(int);
		PokemonCenter* GetPokemonCenterPtr(int);
		PokemonGym* GetPokemonGymPtr(int);
		bool Update();
		void Display(View&);
		void ShowStatus();
};

#endif