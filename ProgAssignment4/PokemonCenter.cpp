#include <iostream>
#include "PokemonCenter.h"

using namespace std;


//-------Constructors -- CHECK THE VARIALBES
PokemonCenter :: PokemonCenter() 
    : Building()
{
    display_code = 'C';
    potion_capacity = 100;
    pokedollar_cost_per_potion = 5;
    num_potions_remaining = potion_capacity; //private member initialize
    latch = false;
    state = POTIONS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;

}

PokemonCenter :: PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc) 
    : Building('C', in_id, in_loc)
{
    pokedollar_cost_per_potion = potion_cost;
    potion_capacity = potion_cap;
    latch = false;
    num_potions_remaining = potion_capacity; //private number initialize
    state = POTIONS_AVAILABLE;
    cout << "PokemonCenter constructed" << endl;
    //the rest of the variables are assigned to defualt values
}

//--------Public Member Functions
bool PokemonCenter :: HasPotions()
{
    if (num_potions_remaining > 0) //return true if atleast one potion remaining
    {
        return true;
    }
    else 
    {
        return false;
    }
}  

unsigned int PokemonCenter :: GetNumPotionRemaining() //returns the number of potions remaining
{
    return num_potions_remaining;
}

bool PokemonCenter :: CanAffordPotion(unsigned int potion, double budget) //checks if trainer can afford a number of potions
{
    if (potion * pokedollar_cost_per_potion <= budget)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double PokemonCenter :: GetPokeDollarCost(unsigned int potion) //calculates total cost of given number of potions
{
    return potion * pokedollar_cost_per_potion;
}

unsigned int PokemonCenter :: DistributePotion(unsigned int potion_needed) //checks if there is potions in the pokemoncenter
{
    if (num_potions_remaining >= potion_needed)
    {
        num_potions_remaining = num_potions_remaining - potion_needed;
        return potion_needed;
    }
    else
    {
        unsigned int temp_potions = num_potions_remaining;
        num_potions_remaining = 0;
        return temp_potions; 
    }

}

bool PokemonCenter :: Update() //return true when there is no potions remaining
{
    if (num_potions_remaining == 0 && latch == false)
    {
        latch = true;
        state = NO_POTIONS_AVAILABLE;
        display_code = 'c';
        cout << "PokemonCenter (" << id_num << ") has ran out of potions." << endl;
        return true;
    }
    else
        return false;
}

void PokemonCenter :: ShowStatus() //Calls the building operator and shows the stats and potion numbers
{
    cout << "PokemonCenter Status: ";
    Building :: ShowStatus();
    cout << endl;
    cout << "\tPokeDollars per potion: " << pokedollar_cost_per_potion << endl;
    cout << "\t";
    if (num_potions_remaining ==1)
    {
        cout << num_potions_remaining << " potion remaining" << endl;
    }
    else 
    {
        cout << num_potions_remaining << " potions remaining" << endl;
    }
}
 
//------Deconstructor
PokemonCenter :: ~PokemonCenter()
{
    cout << "Pokemon Center destructed" << endl;
}


