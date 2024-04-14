
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "pokemon.h"


using namespace std;

    //default constructor
        pokemon::pokemon() : name("Pikachu"), hpValue(100), atkValue(20) {}

    
    //constructor that takes 2 parameters which are string for the name and an integer for attack value of pokemon and set hpValue to 100
        pokemon::pokemon(string name, int atkValue) : name(name), hpValue(100), atkValue(atkValue) {}

    //copy constructor
        pokemon::pokemon(const pokemon &p) : name(p.name), hpValue(p.hpValue), atkValue(p.atkValue) {}  

    //necessary setters and getters

    //the reason that we are using const keyword is to prevent the function from changing the object's member variables
    //if we use const keyword, we can only call the getter functions of the object

       string pokemon::getName()  const {
        return name;
       }   

       int pokemon::getHpValue()  {
        return hpValue;
       }

       int pokemon::getAtkValue()  {
        return atkValue;
       }
    
    //default constructor that initializes the value to 0
        pokedex::pokedex() : value(0) {}

    //method  to add new pokemons to pokedexArray
    void  pokedex::updatePokedex(pokemon newPokemon)  {
        //checking duplicates
        for(int i = 0; i < value; i++) {
            if(pokedexArray[i].getName() == newPokemon.getName()) {
                return;
            }
        }
        //add a new pokemon to pokedexArray if array is not full
            pokedexArray[value] = newPokemon;
            value++;
        
    }

    //method to print pokemon names from pokedexArray
    void pokedex::printPokedex() const {
        for(int i = 0; i < value; i++ ) {
            cout << pokedexArray[i].getName() << endl;
        }
    }

       



    
    //default constructor to initialize
    player::player() : name("Ash"), pokemonNumber(0), pokeballNumber(10), badgeNumber(0) {}

    //constructor to construct a new player with a given name (string),and Pokemon (object)
    player::player(string name, pokemon playerPokemon) : name(name), playerPokemon(playerPokemon), pokemonNumber(0), pokeballNumber(10), badgeNumber(0) {}

    //necessary seters and getters
    int player::showPokemonNumber() const {
        return pokemonNumber;
    }
    int player::showPokeballNumber() const {
        return pokeballNumber;
    }
    int player::showBadgeNumber() const {
        return badgeNumber;
    }
    //method to return playerPokemon object
    pokemon player::getPokemon() const {
        return playerPokemon;
    } 

    void player::battleWon() {
        badgeNumber += 1;
        pokeballNumber += 3;
    }

    void player::catchPokemon(pokemon p) {
        playerPokedex.updatePokedex(p);
        pokemonNumber += 1;
        pokeballNumber -= 1;
    }
    

   
    //default constructor to initialize all values
    enemy::enemy() : name("Misty"), enemyPokemon(pokemon("Alakazam",10)) {}

    //constructor to construct construct a new enemy with a given name (string), and Pokemon (object)
    enemy::enemy(string name, pokemon enemyPokemon) : name(name), enemyPokemon(enemyPokemon) {}

    //necessary seters and getters
    pokemon enemy::getPokemon() const {
        return enemyPokemon;
    }

    string enemy::getName() const {
        return name;
    }


        

