# pa4-template

## You must pass your code from pa3 to this repository

Step 1: 
    -Wild Pokemon:
        +movement: 
            = Wild Pokemon move 1 step in the x or y direction or stay in the same position at random              
            = Wild Pokemon will attach/ be in combat with trainer if within two steps of wild pokemons location

        +attack:
            = Multiplied with health
                - if health cost per battle is 2 and attack is 3, then the total cost per battle is 6
            = Trainers can be in combat iwth more than one wild pokemon which causes their attack to add
                - if wild pokemon 1 attack is 4 and wild pokemon 2 attack is 1, then total Trainer attack is 5
            = When all the wild pokemon faint, the attack of the trainer is returned to normal

        +health:
            = if health is 0 then the wild pokemon get out of combat/unattaches from the trainer and is set to 'w'
            = each step that is taken decerses this health by 1
Step 2:
    -Vector Array were used as Professor Densmore said any type of STL can be used. 
    -Active Ptrs are used for the Update function and check which objects are dead, so they can be removed from the active ptrs.

Step 3: 
    -Input_Handling was created with the same members as the PDF. It is used to check the user's input falls within the given parameters.
    -It is used in:
        + GameCommand.pp:
            = DoCommands() : 
                -Checks if the input is the meets the correct type and parameter order for each switch command
                -cin.clear() and cin.ignore(numeric_limits<streamsize>::max(), '\n') is used to clear everything "numerical long long" inputs long once enter is hit

        + Model.cpp:
            = GetTrainerPtr() : 
                -Checks that there is no matching id in use and returns NULL

            = GetPokemonCenterPtr() : 
                -Checks that there is no matching id in use and returns NULL

            = GetPokemonGymPtr() : 
                -Checks that there is no matching id in use and returns NULL

            = GetWildPokemonPtr() : 
                -Checks that there is no matching id in use and returns NULL

            = NewCommand() : 
                -Checks that there is no matching id in use
                -Checks that the id is single digit
                -Checks that the location is not already in use of another object


Step 4:
    -A NewCommand() function is created with the purpose of creating new objects by a switch statement
        +Objects are created using the same parameters as in PA3
        +Objects inserted in object_ptrs are done in the same order as the ShowStatus() of PA3:
            = Trainer
            = PokemonCenter
            = PokemonGym
            = WildPokemon
        +The objects that require a name, one is created with its classname and id number jointed
        +Each respective object their is a counter for each one 
        +Active ptrs is also kept up to date 
