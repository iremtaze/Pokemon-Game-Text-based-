
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "pokemon.h"

using namespace std;


int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it

string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);

int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);
    

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};

string* readEnemyNames(const char* argv){
    string* enemyNames = new string[5];
    ifstream file(argv); // open file for reading
    if(!file.is_open()) {
        cout << "File could not be opened\n" << endl;
        return nullptr;
    }
    
    string line;
    int i = 0;
    getline(file, line); 
    while(getline(file, line)) {
        enemyNames[i] = line;
        i++; //NAME_COUNTER++
    }
    file.close();
    return enemyNames;
};

    

string* readPokemonNames(const char* argv){

    string* pokemonNames = new string[6];
    ifstream file(argv); // open file for reading
    if(!file.is_open()) {
        cout << "File could not be opened\n" << endl;
        return nullptr;
    }
    string line;
    int i = 0;
    getline(file, line);
    while(getline(file, line)) {
        pokemonNames[i] = line;
        i++; //POK_COUNTER++
    }
    file.close(); //close the file
    return pokemonNames; // return the array
};
//-----------------------------------------------------//

player characterCreate(string playerName, int pokemonChoice){
    int attackValue = 20;

    //name of the chosen pokemon according to player's choice
    string pokemonName;

    switch(pokemonChoice) {
        case 1:
            pokemonName = "Bulbasaur";
            break;
        case 2:
            pokemonName = "Charmender";
            break;
        case 3:
            pokemonName = "Squirtle";
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    //create a new pokemon object with the chosen name and the attack value
    pokemon newPokemon(pokemonName, attackValue);

    //create a new player object with given name and  the pokemon object
    player newPlayer(playerName, newPokemon);
    return newPlayer;
};

void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};

void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){
//Remember!! enemyNames contains the name of enemy players, pokemonNames contains pokemons 
    //create a player pokemon
    pokemon playerPokemon = newPlayer->getPokemon();
    //create a enemy pokemon
    pokemon enemyPokemon(pokemonNames[POK_COUNTER++ % 6], 10);
    //create a enemy player
    enemy currentEnemy(enemyNames[NAME_COUNTER++ % 5], enemyPokemon);

    cout << "You encounter with " << currentEnemy.getName() << " and his/hers pokemon " << enemyPokemon.getName() << endl;
    cout << enemyPokemon.getName() <<  " Health: "<< enemyPokemon.getHpValue() << " Attack: " << enemyPokemon.getAtkValue() << endl;


    int choice;
    
    //battle loop 
    while(playerPokemon.getHpValue() > 0 && enemyPokemon.getHpValue() > 0 ) {
        cout << "1- Fight" << endl;
        cout << "2- Runaway" << endl;
        cout << "Choice: ";
        cin >> choice;

         if(choice == 2 ) 
        {
            cout << "You ran away from the battle!" << endl;
            return; 
        }
        else if(choice == 1) {
        enemyPokemon.setHp(enemyPokemon.getHpValue() - PLAYER_POKEMON_ATTACK);
        playerPokemon.setHp(playerPokemon.getHpValue() - ENEMY_POKEMON_ATTACK);

        //display current health status
        cout << "Your Pokemons Health: " << playerPokemon.getHpValue() << endl;
        cout << currentEnemy.getName() << " Pokemons Health: " << enemyPokemon.getHpValue() << endl; 
        
        //check battle result

      if(playerPokemon.getHpValue() <= 0){
        cout << "You lost the battle!" << endl;
        break; // Exit the function
      } 
      else if( enemyPokemon.getHpValue() <= 0){
        cout << "You Won!" << endl;
        newPlayer->battleWon(); //player won the battle, update player's badge and pokeball number
        newPlayer->playerPokedex.updatePokedex(currentEnemy.getPokemon()); //update player's pokedex array
        return; // exit the function
      }

        }

    
      
}
};

void catchPokemon(player* newPlayer, string* pokemonNames){
        
        if(newPlayer->showPokeballNumber() == 0) {
            cout << "You don't have any pokeballs!" << endl;
            return;
        }

        //create a new pokemon instance
        pokemon wildPokemon(pokemonNames[POK_COUNTER % 5], ENEMY_POKEMON_ATTACK);

        cout << "You encounter with " << wildPokemon.getName() << " Health: " << wildPokemon.getHpValue() << " Attack: " << wildPokemon.getAtkValue() << endl;


        cout << "1- Catch" << endl;
        cout << "2- Runaway" << endl;
        cout << "Choice: ";
        int choice;
        cin >> choice;

    if(choice == 1) {
        newPlayer->catchPokemon(wildPokemon); //player caught the pokemon, update player's pokemon number and pokeball number
        newPlayer->playerPokedex.updatePokedex(wildPokemon); //update player's pokedex array
        cout << "You catch " << wildPokemon.getName() << endl;
        POK_COUNTER++; //increment the pokemon counter
    }
    else if(choice == 2) {
        cout << "You ran away from the battle!" << endl;
        newPlayer->playerPokedex.updatePokedex(wildPokemon); //update player's pokedex array
        return;
    }

}
    

