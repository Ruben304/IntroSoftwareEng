#include <iostream>
#include "PokemonGym.h"

using namespace std;


//----------Constructors
PokemonGym :: PokemonGym() : Building ()
{
     display_code = 'G';
     state = NOT_DEFEATED;
     max_number_of_battles = 10;
     num_battle_remaining = max_number_of_battles;
     health_cost_per_battle = 1;
     PokeDollar_cost_per_battle = 1.0;
     experience_per_battle = 2;
     cout << "PokemonGym defualt constructed";
} 

PokemonGym :: PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc)
     : Building('G', id_num, in_loc)
{
     id_num = in_id;
     max_number_of_battles = max_battle;
     health_cost_per_battle = health_loss;
     experience_per_battle = exp_per_battle;
     PokeDollar_cost_per_battle = PokeDollar_cost;
     num_battle_remaining = max_number_of_battles; 
     //location = in_loc;
     cout << "PokemonGym contructed" << endl;
}

//-----------Public Member Functions
double PokemonGym :: GetPokeDollarCost(unsigned int battle_qty)//returns the cost of a certain number of battles
{
     return battle_qty * PokeDollar_cost_per_battle;
}

unsigned int PokemonGym :: GetHealthCost(unsigned int battle_qty)//returns the health cost of a certain number of battles
{
     return battle_qty * health_cost_per_battle;
}

unsigned int PokemonGym :: GetNumBattlesRemaining()//returns number of battles remaining in the gym
{
     return num_battle_remaining;
}

bool PokemonGym :: IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health)//check if trainer meets the money and health requirements
{
     if(budget >= (battle_qty * PokeDollar_cost_per_battle) && health >= (battle_qty * health_cost_per_battle))
     {
          return true;
     }
     else 
     {
          return false;
     }
}

unsigned int PokemonGym :: TrainPokemon(unsigned int battle_units) //determins how much experince gained from the number of battles requested
{
     if (num_battle_remaining >= battle_units)
     {
          num_battle_remaining = num_battle_remaining - battle_units;
          return battle_units * experience_per_battle;
     }
     else
     {
          int temp = num_battle_remaining;
          num_battle_remaining = 0;
          return temp * experience_per_battle; //temperary store the num reamaining beefore setting it to 0
     }
}

unsigned int PokemonGym :: GetExperiencePerBattle()//returns experince per battle
{
     return experience_per_battle;
} 

bool PokemonGym :: Update()
{
     if(num_battle_remaining == 0 && latch == false)
     {
          latch == true; //so this happens once and not undone
          state = DEFEATED;
          display_code = 'g';
          cout << "(" << display_code << ")(" << id_num << ") has been beaten" << endl;
          return true;
     }
     else {
          return false;
     }
}

bool PokemonGym :: passed() //checks to see if there is any remaining battles
{
     if (num_battle_remaining == 0)
     {
          return true;
     }
     else {
          return false;
     }
}

void PokemonGym :: ShowStatus() //shows the status of the current gym
{
     cout << "PokemonGymStatus: ";
     Building :: ShowStatus();
     cout << "Max number of battles : " << max_number_of_battles << endl;
     cout << "Health cost per battle: " << health_cost_per_battle << endl;
     cout << "PokeDollar per battle: " << PokeDollar_cost_per_battle << endl;
     cout << "Experience per battle: " << experience_per_battle << endl;
     cout << num_battle_remaining << " battle"; 
     if (num_battle_remaining == 1)
     {
          cout <<" remaining for this PokemonGym" << endl;
     }
     else
     {
          cout << "s remaining for this PokemonGym" << endl;
     }
}

//-------Deconstructor
PokemonGym :: ~PokemonGym()
{
     cout << "Pokemon Gym destructed" << endl;
}