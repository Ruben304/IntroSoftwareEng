#ifndef PokemonCenter_h
#define PokemonCenter_h
#include <iostream>
#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "Building.h"

//-----Enum
    enum PokemonCenterStates { POTIONS_AVAILABLE , NO_POTIONS_AVAILABLE};
    
class PokemonCenter: public Building
{
    private: //--------Private Members
        unsigned int potion_capacity;
        unsigned int num_potions_remaining;
        double pokedollar_cost_per_potion;
        bool latch; //used for update

    public: //---------Public Members
    //----------Constructors & Deconstructor
        PokemonCenter();
        PokemonCenter(int, double, unsigned int, Point2D);

    //---------Public Member Functions
        bool HasPotions();
        unsigned int GetNumPotionRemaining();
        bool CanAffordPotion(unsigned int, double);
        double GetPokeDollarCost(unsigned int);
        unsigned int DistributePotion(unsigned int);
        bool Update();
        void ShowStatus();

        virtual ~PokemonCenter();
    
};

#endif 