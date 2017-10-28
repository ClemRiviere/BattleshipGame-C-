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
 * @author Clément Lucas <clement.lucas@ecole.ensicaen.fr>
 * @author Clément Rivière <criviere@ecole.ensicaen.fr>
 * @version 0.0.1 / 28-10-2017
 */

/**
 * @file game.h
 * Provides the prototypes of the functions used during the game.
 */

#ifndef __GAME_H
#define __GAME_H

#include <stdio.h>
#include <stdlib.h>
#include "../lib/include/board.h"
#include "../include/boat.h"

/**
 * Asks the user for an int. Prints a message first.
 *
 * @param message the message we want to display to the user
 * @return the asked int
 */
int askInt(char * message) ;

/**
 * Processes the settlement of the player's fleet. Asks the user to give the positions of
 * his n boat cells.
 *
 * @param board the board to set the fleet into.
 * @param n the number of boat cells to put.
 * @return void
 */
void setUpPlayerFleet(Board *board, int n) ;

/**
 * Sets up  the computer's fleet. Asks the user to give the positions of
 * his n boat cells.
 *
 * @param board the board to set the fleet into.
 * @param n the number of boat cells to put.
 * @return void
 */
void setUpComputerFleet(Board *board, int n) ;

/**
 * Initializes the the game : asks the player for the position of his boats, generate the board of the computer and prints 
 * the result.
 * 
 * @param player the board of the player
 * @param computer the board of the computer
 * @return void
 */
void initGame(Board *player, Board *computer) ;

/**
 * Prints two boards. This function can be used also as a debugging tool : you can choose either to print the data (secret) boards
 * or the public boards.
 *
 * @param player the board of the player
 * @param computer the board of the computer
 * @return void
 */
void printGame(Board *player, Board *computer);

#endif
