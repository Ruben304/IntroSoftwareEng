#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h" 
#include "PokemonGym.h"
#include "PokemonCenter.h" 
#include "Trainer.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"

using namespace std;

int main (){
    //Since we put everything in a combined while loop inside do commands thats all we call and declare its inputs
    View vw;
    Model mod;
    DoCommands(mod, vw);
    return 0;
}

