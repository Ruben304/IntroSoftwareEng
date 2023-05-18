#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H
#include <iostream>
#include"GameObject.h"
#include "Point2D.h"
#include "Trainer.h"
#include <string>

using namespace std;

//enum made for the update function
enum WildPokemonStates {IN_ENVIRONMENT, DEAD, IN_TRAINER};

class WildPokemon: public GameObject{
    //-------Protected Members 
    private:    
        double attack;
        double health;
        bool variant;
        bool in_combat;
        bool trigger;//added
        int count; //added
        string name;
        Trainer* current_trainer;

    //-------Public Member Constructor & Functions
    public:
        WildPokemon();
        WildPokemon(std::string, double, double, bool, int, Point2D);

        void follow(Trainer*);
        bool get_variant();
        double get_attack();
        double get_health();
        bool get_in_combat();
        bool ShouldBeVisible();
        bool Update();
        void ShowStatus();
        bool IsAlive();
};

#endif