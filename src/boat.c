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
 * @author Clément Lucas <clement.lucas@ecole.ensicaen.fr>
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
  boat->n_cells = n_cells;
  for (i = 0; i < n_cells; i++) {
    boat->cells[i].val = 1;
  }
  boat->name = (char *)malloc(sizeof(char)*strlen(name));
  strcpy(boat->name,name);
}

void initFleet(Boat **fleet){
  int i;

  *fleet = (Boat *)malloc(sizeof(Boat)*N_BOAT);

  int tab_n_cases[N_BOAT] = {N_PORTE_AVION,N_CROISEUR,N_CONTRE_TORPILLEUR,N_SOUS_MARIN,N_TORPILLEUR};
  char *tab_name[N_BOAT] = {"porte_avion","croiseur","contre_torpilleur","sous_marin","torpilleur"};

  for (i = 0; i < N_BOAT; i++) {
    initBoat(&(*fleet)[i], tab_n_cases[i], tab_name[i]);
  }
}

int placeBoat(Boat *boat, Board board, Position pos, int r) {
  int i;

  if ( r == R_HOR ){
    if ( pos.x + boat->n_cells > board.row-1 ) {
      return 0;
    }
    else {
      for ( i = 0; i < boat->n_cells; i++ ) {
        boat->cells[i].pos.x = pos.x + i;
        boat->cells[i].pos.y = pos.y;
      }
      return 1;
    }
  }
  else {
    if ( pos.y + boat->n_cells > board.col-1 ) {
      return 0;
    }
    else {
      for ( i = 0; i < boat->n_cells; i++ ) {
        boat->cells[i].pos.x = pos.x;
        boat->cells[i].pos.y = pos.y + i;
      }
      return 1;
    }
  }
  return 0;
}
