
# BATTLESHIP

In this Battleship game, 2 players are facing in each other in a 10*10 grid. Player 2 is a computer (AI).
Each player has :
1 aircraft carrier (5 squares)
1 cruiser (4 squares)
1 destroyer (3 spaces)
1 submarine (3 squares)
1 torpedo boat (2 squares).

The players will shoot round by round a square of the other's grid. The point is to sink the maximum ships of the oponent.
The game last 100 shots. The winner is the one having the most ships at the end.

## Install Battleship

Place yourself in the root of the project.
Then execute the following command :
```
make
```

## Know the 'make' commands

In order to create the documentation of the project you'll have to use the following command :
'''
make doc
'''

If you want to delete the documentation execute the following command :
'''
make docclean
'''

To create the test of our functions, please do the command :
'''
make test
'''
This command will create an executable in the bin directory. 

You can choose to create the game with a static pr dynamic library for the board management. (lib board)
The default library (generated with a simple 'make') is dynamic.

If you want the program to use the static version of this library, please use the following command :
'''
make static
'''

## Play Battleship

Being in the root of the project, execute the following command :
```
bin/Battleship
```

## Uninstall Battleship

Execute the command :
```
make distclean
```

## Message from the developers

We apologize for not finishing the game, even though that structures and algorithms were ready to be used.
We tried to test most of our functions as if we were using them.
To keep developing our game, we'd have to link our c files. For example we should use the structure of a fleet
to constraint the intialising phase of the battleship : the user should not be allowed to put the boat cells everywhere.
Then, the whole processus of playing hasn't been implemented. Though, we would just have to ask for a position (x,y) to shoot at
and then put a -1 value in this cell.
We'll need a function that checks if a board is empty (or if a fleet is destroyed) to end the game.
Anyway, there's a lot of work left