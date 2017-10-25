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
 * @version 0.0.1 - 25-10-2017
 *
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */
/**
 * @file boat.c
 *
 * Description of the program objectives.
 * All necessary references.
 */

#include "../include/boat.h"

void initBoat(Boat *boat, int n_cells, char *name) {
  int i;
  boat->cells = (Boat_cell *)malloc(sizeof(Boat_cell)*n_cells);
  for (i=0;i<n_cells;i++) {
    boat->cells[i].val = 1;
  }
  boat->name = (char *)malloc(sizeof(char)*strlen(name));
  strcpy(boat->name,name);
}
