#ifndef PokemonGym_h
#define PokemonGym_h
#include <iostream>
#include "GameObject.h"
#include "Point2D.h"
#include "Building.h"

using namespace std;

//-----Enum
    enum PokemonGymStates {NOT_DEFEATED, DEFEATED};
    
class PokemonGym: public Building
{

    private: //--------Private Members
        unsigned int num_battle_remaining;
        unsigned int max_number_of_battles;
        unsigned int health_cost_per_battle;
        double PokeDollar_cost_per_battle;
        unsigned int experience_per_battle;
        bool latch;

    public: //---------Public Members
    //-------Constructors
        PokemonGym();
        PokemonGym(unsigned int, unsigned int, double, unsigned int, int, Point2D);

    //------Public Member Functions
        double GetPokeDollarCost(unsigned int);
        unsigned int GetHealthCost(unsigned int);
        unsigned int GetNumBattlesRemaining();
        bool IsAbleToBattle(unsigned int, double, unsigned int);
        unsigned int TrainPokemon(unsigned int);
        bool Update();
        bool passed();
        void ShowStatus();
        unsigned int GetExperiencePerBattle();

        virtual ~PokemonGym();

};

#endif 