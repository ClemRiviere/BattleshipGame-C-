/* -*- c-basic-offset: 3 -*- 
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

/**
 * @author Clément LUCAS
 * @author Clément RIVIERE
 * @version 0.0.1 / 25-10-2017
 */

/**
 * @file main.c
 * Main function of the game BattleShip
 */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <board.h>


int main(void) {
   
   /* Initialize the game*/
   Board player_fleet;
   Board player_shoot;
   Board computer_fleet;
   Board computer_shoot;

   int width;
   int height;

   int nbBoatCells = 3;
   
   width = askInt("Width of the board ? : ");
   height = askInt("Height of the maze ? : ");

   initBoard(&player_fleet, width, height);
   initBoard(&player_shoot, width, height);
   initBoard(&computer_fleet, width, height);
   initBoard(&computer_shoot, width, height);

   /* Game */
   printf("Player fleet : \n");
   
   setUpPlayerFleet(&player_fleet,nbBoatCells);
   printBoard(player_fleet);
   
   printf("Computer fleet : \n");
   setUpComputerFleet(&computer_fleet,nbBoatCells);
   printBoard(computer_fleet);
   
   /* Print the result */

   /* Play again ?*/
   
   return EXIT_SUCCESS;
}

