/*
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
 * @author Clément Rivière <criviere@ecole.ensicaen.fr>
 * @version     0.0.1 - 25-10-2017
 *
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */

#ifndef __BOAT_H
#define __BOAT_H


/**
 * @file boat.h
 *
 * Description of the program objectives.
 * All necessary references.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/position.h"
#include "../include/const.h"

/**
  * @brief A cell of a boat.
  *
  * The position of the boat cell and it's value.
  */
typedef struct {
	Position pos;	/**< The position of the cell */
	int val;		/**< The value of the cell (destroyed or not destroyed) */
}Boat_cell;

/**
  * @brief A boat.
  *
  * Cells of a boat and it's name.
  */
typedef struct {
	Boat_cell *cells;	/**< The boat cells */
	char *name;			/**< The boat name */
}Boat;

/**
 * Initialize a boat.
 *
 * @param boat the boat.
 * @param n_cells the number of boat cells.
 * @param name the boat name.
 */
void initBoat(Boat *boat, int n_cells, char *name);

/**
 * Initialize a fleet.
 *
 * @param fleet a boat tab representing a fleet.
 */
void initFleet(Boat *fleet);

/**
 * Set the position of a boat
 *
 * @param boat the boat that needs to be modified.
 * @param pos the new position of the boat.
 * @param r the orientation of the boat.
 */
void placeBoat(Boat boat, Position pos, int r);

/**
 * Opponent missile process
 *
 * @param pos the position of the missile.
 * @return 1 if the game is finish.
 */
int missile(Position pos);

/**
 * Checks if a boat is destroyed.
 *
 * @param boat the boat that needs to be tested.
 * @return 1 if the boat is destroyed.
*/
int isBoatDestroyed(Boat boat);

/**
 * Checks if all boats are destroyed.
 *
 * @param fleet a boat tab that representes a player fleet.
 * @return 1 if the fleet is destroyed.
 */
int isFleetDefeated(Boat *fleet);

/**
 * Free a fleet memory.
 *
 * @param fleet a boat tab that representes a player fleet.
 */
void freeMemory(Boat *fleet);

#endif
