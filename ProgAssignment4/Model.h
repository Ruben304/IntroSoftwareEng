#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <cstdlib>
#include "Point2D.h"
#include "GameObject.h"
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include "WildPokemon.h"
#include "Input_Handling.h"
#include <cmath>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Model {
	private: //-----Private Members
		int time;
		int num_objects;
		int num_trainers;
		int num_centers;
		int num_gyms;
		int num_wildpokemon;
		int count; //count to be used for different functions
		//These are put in vector array as a method of using the STL
		vector<GameObject*> object_ptrs;
		vector<GameObject*> active_ptrs;
		vector<Trainer*> trainer_ptrs;
		vector<PokemonCenter*> center_ptrs;
		vector<PokemonGym*> gym_ptrs;
		vector<WildPokemon*> wildpokemon_ptrs;
		
	public: //-----Public Members
		Model();
		~Model();
		
		//-----Member Functions
		Trainer* GetTrainerPtr(int);
		PokemonCenter* GetPokemonCenterPtr(int);
		PokemonGym* GetPokemonGymPtr(int);
		WildPokemon* GetWildPokemonPtr(int);
		bool Update();
		void Display(View&);
		void ShowStatus();
		void NewCommand(char, int, Point2D);
};

#endif