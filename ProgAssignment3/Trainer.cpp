#include <iostream>
#include "Trainer.h"

using namespace std;

//------------Constructors
Trainer :: Trainer() : GameObject('T') 
{
    speed = 5;
    cout << "Trainer defualt constructed" << endl;
    state = STOPPED;
    is_at_center = false;
    is_IN_GYM = false;
    latch = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy =  0;
    experince_to_calc = 0;//made this
    health_to_calc = 0;//made this 
    current_center = NULL;
    current_gym = NULL;
}

Trainer :: Trainer(char in_code) 
    : GameObject(in_code)
{
    speed  = 5;
    cout << "Trainer constructed" << endl;
    state = STOPPED;
    //display_code = in_code;
    is_at_center = false;
    is_IN_GYM = false;
    latch = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy =  0;
    experince_to_calc = 0;
    health_to_calc = 0;
    current_center = NULL;
    current_gym = NULL;
    //destination already initialized to 0.0,0.0
 }

Trainer :: Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) 
    : GameObject(in_loc, in_id, in_code)
{
    speed = in_speed;
    name = in_name;
    cout << "Trainer constructed" << endl;
    is_at_center = false;
    is_IN_GYM = false;
    latch = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy =  0;
    experince_to_calc = 0;
    health_to_calc = 0;
    current_center = NULL;
    current_gym = NULL;
    state = STOPPED;
    //id_num = in_id; //not asked for but i think its implied
    //location = in_loc; //not asked for but i think its implied
    //display_code = in_code; //not asked for but i think its implied
}

//--------Public Member functions

void Trainer :: StartMoving(Point2D dest) //starts moving
{
    SetupDestination(dest);
    if (location.x == destination.x && location.y == destination.y)
    {
        cout << "(" << display_code << ")(" << id_num << ": Im already there. See?" << endl;
    }
    else if (HasFainted())
    {
        cout << "(" << display_code << ")(" << id_num << ": My pokemon have fainted. I may move but you cannot see me." << endl;
        state = FAINTED;
    }
    else 
    {
        cout << "(" << display_code << ")(" << id_num << "): On my way." << endl;
		state = MOVING;
    }
}

void Trainer :: StartMovingToGym(PokemonGym* gym) //starts moving to gym
{
    current_gym = gym;
    SetupDestination(current_gym -> GetLocation());
    if (HasFainted())
    {
        state = FAINTED;
        cout << "(" << display_code << ")(" << id_num << "): My pokemon have fainted so I can't move to gym..." << endl;
    }
    else if(destination.x == location.x && destination.y == location.y)
    {
        cout << "(" << display_code << ")(" << id_num << "): I am already at the PokemonGym!" << endl;
        is_IN_GYM = true;
    }
    else 
    {
        cout << "(" << display_code << ")(" << id_num << "): on my way to Gym (" << current_gym -> GetId() << ")." << endl;
        state = MOVING_TO_GYM;
    }

}

void Trainer :: StartMovingToCenter(PokemonCenter* center) //starts moving to pokemon center 
{
    current_center = center;
    SetupDestination(current_center -> GetLocation());
    if (HasFainted())
    {
        cout << "(" << display_code << ")(" << id_num << "): My pokemon have fainted so I should have gone to the center..." << endl;
    }
    else if(destination.x == location.x && destination.y == location.y)
    {
        
        cout << "(" << display_code << ")(" << id_num << "): I am already at the Center!" << endl;
        is_at_center = true;
    }
    else 
    {
        cout << "(" << display_code << ")(" << id_num << "): on my way to Center (" << current_center -> GetId() << ")." << endl;
        state = MOVING_TO_CENTER;
    }
}

void Trainer :: StartBattling(unsigned int num_battles) //tells trainer to start n battles in gym ///MAYBE DONE
{
    if (state = BATTLING_IN_GYM) // if the state is called again
    {
        cout << "(" << display_code <<  "): Started to battle PokemonGym (" << current_gym -> GetId() << ") with (";
        if (num_battles > current_gym -> GetNumBattlesRemaining())
        {
            num_battles = current_gym -> GetNumBattlesRemaining();
        }
        battles_to_buy = num_battles;
        cout << num_battles << ") left";
        if (num_battles == 1)
        {
            cout << " " << endl;
        }
        else
        {
            cout << "s" << endl;
        }
    }
    else if (HasFainted())
    {
        cout << "(" << display_code << ")(" << id_num << "): My Pokemon have fainted so no more battles for me... " << endl;
    }
    else if(state != IN_GYM)
    {
        cout << "(" << display_code << ")(" << id_num << "): I can only battle in a PokemonGym!" << endl;
    }
    else if(current_gym -> IsAbleToBattle(num_battles, PokeDollars, health) == false)
    {
        cout << "(" << display_code << ")(" << id_num << "): Not emough money for battles!" << endl;
    }
    else if (current_gym -> passed())
    {
        cout << "(" << display_code << ")(" << id_num << "): Cannot battle! This PokemonGym has no more trainers to battle!" << endl;
    }
    else 
    {
        state = BATTLING_IN_GYM;
        cout << "(" << display_code <<  "): Started to battle PokemonGym (" << current_gym -> GetId() << ") with (";
        if (num_battles > current_gym -> GetNumBattlesRemaining())
        {
            num_battles = current_gym -> GetNumBattlesRemaining();
        }
        battles_to_buy = num_battles;
        cout << num_battles << ") left";
        if (num_battles == 1)
        {
            cout << " " << endl;
        }
        else
        {
            cout << "s" << endl;
        }
    }
    //update will do something
}

void Trainer :: StartRecoveringHealth(unsigned int num_potions) //tells trainer to start healing pokemon
{
    if (state == RECOVERING_HEALTH) //incase of repeated request
    {
        cout << "(" << display_code << ")(" << id_num << "): Start recovering (" << num_potions << ") potion";
        if (num_potions > current_center -> GetNumPotionRemaining())
        {
            num_potions = current_center -> GetNumPotionRemaining();
        }
        potions_to_buy = num_potions;
        if (num_potions != 1)
        {
            cout << "s";
        }
        cout << " at Pokemon Center (" << current_center -> GetId() << ")" << endl;
    }
    else if (current_center -> CanAffordPotion(num_potions, PokeDollars) == false)
    {
        cout << "(" << display_code << ")(" << id_num << "): Not enough money to recover health." << endl;
    }
    else if (current_center -> HasPotions() == false)
    {
        cout << "(" << display_code << ")(" << id_num << "): Cannot Recover " << endl;
    }
    else if (state != AT_CENTER)
    {
        cout << "(" << display_code << ")(" << id_num << "): I can only recover at a Pokemon Center!" << endl;
    }
    else //if first time requesting
    {
        state = RECOVERING_HEALTH;
        cout << "(" << display_code << ")(" << id_num << "): Start recovering (" << num_potions << ") potion";
        if (num_potions > current_center -> GetNumPotionRemaining())
        {
            num_potions = current_center -> GetNumPotionRemaining();
        }
        potions_to_buy =  num_potions;
        if (num_potions != 1)
        {
            cout << "s";
        }
        cout << " at Pokemon Center (" << current_center -> GetId() << ")" << endl;
    }
}

void Trainer :: Stop() //to stop anything
{
    state = STOPPED;
    cout << "(" << display_code << ")(" << id_num << ") : Stopping..." << endl;
}

bool Trainer :: HasFainted() //return true if fainted
{
    if (health == 0)
    {
        return true;
    }
    else 
        return false;
}

bool Trainer :: ShouldBeVisible() // return true if not fainted 
{
    if (HasFainted())
    {
        return false;
    }
    else
        return true;
}

string Trainer :: GetName()
{
    return name;
}

void Trainer :: ShowStatus() //shows status 
{
    cout << "(" << name << ") status: "<< endl;
    GameObject :: ShowStatus();
    switch(state){
        case STOPPED:
            cout << "stopped" << endl;
            break;
        case MOVING:
            cout << "moving at a speed of (" << speed << ") to destination <X,Y> at each step of " << delta << endl; 
            break;
        case MOVING_TO_GYM:
            cout << "heading to Pokemon Gym (" << current_gym -> GetId() << ") at a speed of (" << speed << ") at each step of (" << delta << ")" << endl;
            break;
        case MOVING_TO_CENTER:
            cout << "heading to Pokemon Center (" << current_center -> GetId() << ") at a speed of (" << speed << ") at each step of (" << delta << endl;
            break;
        case IN_GYM:
            cout << " inside PokemonGYM (" << current_gym -> GetId() << ") " << endl;
            break;
        case AT_CENTER:
            cout << "inside Pokemon Center (" << current_center -> GetId() << ") " << endl;
            break;
        case BATTLING_IN_GYM:
            cout << "battling in Pokemon Gym (" << current_gym -> GetId() << ") " << endl;
            break;
        case RECOVERING_HEALTH:
            cout << "recovering health in Pokemon Center (" << current_center -> GetId() << ") " << endl;
            break;
    }
    cout << "Health: " << health << endl;
    cout << "PokeDollars: " << PokeDollars << endl;
    cout << "Experience: " << experience << endl;
}

bool Trainer :: Update() //change depending on state
{
    if (HasFainted())
    {
        state = FAINTED;
    }
    switch (state){
        case STOPPED:
            return false;
            break;
        case MOVING:
            if(UpdateLocation())
            {
                state = STOPPED;
                return true;
            }
            health--;
            PokeDollars += GetRandomAmountOfPokeDollars();
            return false;
            break;
        case FAINTED:
            if (latch == false)
            {
                cout << "(" << name << ") is out of health and cant move" << endl;
                display_code = 'f'; //fainted trainer
                latch = true;
                return true;
            }
            return false;
            break;
        case MOVING_TO_GYM:
            if (UpdateLocation())
            {
                state = IN_GYM;
                return true;
            }
            health--;
            PokeDollars += GetRandomAmountOfPokeDollars();
            return false;
            break;
        case MOVING_TO_CENTER:
            if (UpdateLocation())
            {
                state = AT_CENTER;
                return true;
            }
            health--;
            PokeDollars += GetRandomAmountOfPokeDollars();
            return false;
            break;
        case IN_GYM:
            return false;
            break;
        case AT_CENTER:
            return false;
            break;
        case BATTLING_IN_GYM:
            health = health - current_gym -> GetPokeDollarCost(battles_to_buy);
            PokeDollars = PokeDollars - current_gym -> GetPokeDollarCost(battles_to_buy);
            experince_to_calc = current_gym -> TrainPokemon(battles_to_buy);
            experience = experience + experince_to_calc;
            cout << "**("<< name << ") completed (" << experince_to_calc/(current_gym -> GetExperiencePerBattle()) << ") battles";
            if (experince_to_calc/(current_gym -> GetExperiencePerBattle()) == 1)
            {
                cout << "!**" << endl;
            }
            else
            {
                cout << "s! **" << endl;
            }
            cout << "**(" << name << ") gained (" << experince_to_calc << ") experince! **"<< endl;
            state = IN_GYM;
            return true;
            break;
        case RECOVERING_HEALTH:
            health_to_calc = current_center -> DistributePotion(potions_to_buy)  * 5; 
            health = health + health_to_calc;  
            PokeDollars = PokeDollars - current_center ->GetPokeDollarCost(potions_to_buy);
            cout << "**(" << name << ") recovered " << health_to_calc << " health! **";
            cout << "**(" << name << ") bought " <<  health_to_calc /5 << " potion";
            if ((health_to_calc /5) == 1)
            {
                cout << "!**" << endl;
            }
            else
            {
                cout <<  "s! **" << endl;
            }
            state = AT_CENTER;
            return true;
            break;
    }
    cout << "No cases true in Update" << endl;
    return false;
}

// //-------Protected Member Functions

bool Trainer :: UpdateLocation() 
{
    if(fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y))
    {
        location = destination;
		cout << "(" << display_code << ")(" << id_num <<"): I'm there!" << endl;
		return true;
    }
    else 
    {
        location = location + delta;
		cout << "(" << display_code << ")(" << id_num << "): step..." << endl;
		return false;      
    }//updates object's location
}

void Trainer :: SetupDestination(Point2D dest)
{
    destination = dest;
    Vector2D diffv = destination - location;
    double denom = speed / GetDistanceBetween(destination, location);
    delta = diffv * denom;
}
//------Non Member Function 
double GetRandomAmountOfPokeDollars() // random num from 0.0 to 2.0
{
    // srand(time(0));
    // int num = rand() % 200;
    // double fin = num / 100.0;
    // return fin;
    srand(time(0));
	return (double)rand()/(RAND_MAX) + (rand()%2);
} 

Trainer :: ~Trainer()
{
    cout << "Trainer destructed" << endl;
}