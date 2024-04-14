# Pokemon-Game-Text-based-
Pokemon Game Project
Introduction
This project implements a text-based Pokémon game in C++, where players can create characters, battle enemies, catch wild Pokémon, and manage their collections. The game features four main classes: Pokemon, Pokedex, Player, and Enemy, each with specific attributes and methods.

Implementation Details
1. Pokemon
Attributes: Name, Health Points (HP), Attack Value (Atk)
Constructors: Default, Parameterized (name, attack value), Copy
Getters: getName(), getHpValue(), getAtkValue()
Note: Additional methods should be implemented as inline functions.
2. Pokedex
Attributes: Pokedex Array, Value (Position Tracker)
Constructor: Initializes value to 0
Methods: updatePokedex() to add new Pokémon, printPokedex() to display names.
3. Player
Attributes: Name, Pokémon Number, Pokeball Number, Badge Number, Player's Pokémon, Player's Pokedex
Constructors: Default, Parameterized (name, Pokémon object)
Methods: showPokemonNumber(), showPokeballNumber(), showBadgeNumber(), getPokemon(), battleWon(), catchPokemon()
4. Enemy
Attributes: Name, Enemy's Pokémon
Constructors: Default, Parameterized (name, Pokémon object)
Methods: getPokemon(), getName()
Necessary Methods in main.cpp
readEnemyNames(): Reads enemyNames.txt, creates a dynamic string array.
readPokemonNames(): Reads pokemonNames.txt, creates a dynamic string array.
characterCreate(): Creates a character with a chosen name and Pokémon.
fightEnemy(): Simulates battles between player and enemy Pokémon.
catchPokemon(): Simulates catching wild Pokémon.
Gameplay
Players can engage in battles to earn badges and pokeballs or catch Pokémon to expand their collection. Available actions include fighting enemies, catching Pokémon, checking inventory, viewing the Pokédex, and exiting the game.

How to Run
To run the game, compile the main.cpp file along with the other necessary files. Ensure that the enemy_names.txt and pokemon_names.txt files are present in the same directory. Then execute the compiled program.
