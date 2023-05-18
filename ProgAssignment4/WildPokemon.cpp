#include <iostream>
#include "WildPokemon.h"

using namespace std;

//------Constructor
WildPokemon :: WildPokemon()
    : GameObject('W')
{
    attack = 5.0;
    health = 2.0;
    variant = false;
    in_combat = false;
    current_trainer = NULL;
    state = IN_ENVIRONMENT;
    trigger = false;
    count = 0;
    cout << "Wild Pokemon defualt Constructed" << endl;
}

WildPokemon :: WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc)
    : GameObject(in_loc, id, 'W')
{
    this -> name = name;
    this -> attack = attack;
    this -> health = health;
    this -> variant = variant;
    in_combat = false;
    current_trainer = NULL;
    state = IN_ENVIRONMENT;
    trigger = false;
    count = 0;
    cout << "Wild Pokemon Constructed" << endl;
}

//--------Member Functions
void WildPokemon ::follow(Trainer* t)
{
    if (!(in_combat))// if not already in combat with trainer
    {
        current_trainer = t;
        state = IN_TRAINER; 
        in_combat = true; //they are fighting
        location = current_trainer -> GetLocation(); //setting the wild pokemon location to trainers
    }


}
bool WildPokemon ::get_variant()
{
    return variant;
}
double WildPokemon ::get_attack()
{
    return attack;
}
double WildPokemon ::get_health()
{
    return health;
}
bool WildPokemon ::get_in_combat()
{
    return in_combat;
}

bool WildPokemon :: ShouldBeVisible()
{
    return true;
}
bool WildPokemon ::Update()
{
    switch(state){
        case IN_ENVIRONMENT:
            srand(time(NULL));       
            location.x += (rand()%3 + (-1));  // a random movement of the x(left/right) and y(up/down) location by 1 
            location.y += (rand()%3 + (-1));
            return false;
            break;

        case IN_TRAINER:
            if (!(trigger)){ // the first time a wild pokemon attacks a trainer if trigger is false
                cout << current_trainer -> GetName() << " is fighting " << name << "." << endl;
                trigger = true; //so it wont happen again 
                current_trainer -> setAttack(attack);
                location = current_trainer -> GetLocation(); //verifies the wild pokemons location is on trainer
                return true;
            }
            if (IsAlive() && (current_trainer -> GetState() == 1 || current_trainer -> GetState() == 5 || current_trainer -> GetState() == 6)) {// check this whole function
                if (count == (health - 1)){
                    health--;
                    if (health == 0) //if health is 0 before the next update call
                    {
                        trigger = false; //set the trigger to false so the if statement used wont re set to dead again
                        state = DEAD;//set it to dead
                    }
                    count = 0; //setting count to 0
                    location = current_trainer -> GetLocation();
                }
                else
                {
                    count++; //increament count
                    location = current_trainer -> GetLocation();
                }
            }
            return false;
            break;
        case DEAD:
            if (!(trigger)){
                display_code = 'w'; // a dead wild pokemon
                trigger = true;
                cout << current_trainer -> GetName() << " is free from " << name << "." << endl;
                current_trainer -> setAttack(attack - 2*attack); // removes attack from trainer
            }
            return false;
            break;
    }
    cout << endl;
    cout << "ERROR: No wild pokemon Update() match!" << endl;
    return false;
}
void WildPokemon ::ShowStatus()
{
    cout << name << " status: ";
    GameObject ::ShowStatus();
    cout << endl;
    cout << "\tHealth: " << health << endl;
    cout << "\tAttack: " << attack << endl;
    cout << "\tVariant: " << variant << endl;
    if (get_in_combat() && IsAlive())
    {
        cout << "\tIn Combat with trainer: " << current_trainer -> GetName() << endl;
    }
}
bool WildPokemon ::IsAlive()
{
    if (health > 0)
    {
        return true;
    }
    return false;
}



