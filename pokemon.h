
#ifndef _H
#define _H


#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class pokemon {
    private: 
        string name;
        int hpValue;
        int atkValue;
    public:
        pokemon();
        pokemon(string, int);
        pokemon(const pokemon&);
        string getName() const;
        int getHpValue();
        int getAtkValue();
        inline void setHp(int hp) { hpValue = hp; }
};

class pokedex {
    private:
        pokemon pokedexArray[100];
        int value;
    public:
        pokedex();
        void updatePokedex(pokemon);
        void printPokedex() const;

};

class player {
    private:
        string name;
        int pokemonNumber;
        int pokeballNumber;
        int badgeNumber;
        pokemon playerPokemon;
    public:
        pokedex playerPokedex;
        player();
        player(string, pokemon);
        int showPokemonNumber() const;
        int showPokeballNumber() const;
        int showBadgeNumber() const;
        pokemon getPokemon() const;
        void battleWon();
        void catchPokemon(pokemon);

};

class enemy {
    private:
        string name;
        pokemon enemyPokemon;
    public:
        enemy();
        enemy(string, pokemon);
        pokemon getPokemon() const;
        string getName() const;
};

#endif