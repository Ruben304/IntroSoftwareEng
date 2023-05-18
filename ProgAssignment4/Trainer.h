#ifndef Trainer_h
#define Trainer_h
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"

using namespace std;

enum TrainerStates {
        STOPPED = 0,
        MOVING,
        FAINTED,
        AT_CENTER,
        IN_GYM,
        MOVING_TO_CENTER,
        MOVING_TO_GYM,
        BATTLING_IN_GYM ,
        RECOVERING_HEALTH 
    };
    
class Trainer: public GameObject //inherits from game object
{

    public: //-----Public Members 
    //---------Constructorsand Destructor
        Trainer();
        Trainer(char);
        Trainer(std::string, int, char, unsigned int, Point2D);

    //---------Member Functions
        void StartMoving(Point2D);
        void StartMovingToGym(PokemonGym*);
        void StartMovingToCenter(PokemonCenter*);
        void StartBattling(unsigned int);
        void StartRecoveringHealth(unsigned int);
        void Stop();
        bool HasFainted();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
        string GetName(); //made to get trainer ename in game command
        void setAttack(int);

    protected: //---Protected Members
        bool UpdateLocation();
        void SetupDestination(Point2D);

    private: //-----Private Members
        double speed;
        bool is_at_center;
        bool is_IN_GYM;
        bool latch;//checks for update
        unsigned int health;
        unsigned int experience;
        double PokeDollars;
        unsigned int battles_to_buy;
        unsigned int potions_to_buy;
        unsigned int experince_to_calc; //added to store experince
        unsigned int health_to_calc; //added to store health
        unsigned int attack;
        string name;
        PokemonCenter* current_center;
        PokemonGym* current_gym;
        Point2D destination;
        Vector2D delta;

    public: 
        virtual ~Trainer();

};
// Non Member Static Function  How do i get static??

double GetRandomAmountOfPokeDollars();


#endif 