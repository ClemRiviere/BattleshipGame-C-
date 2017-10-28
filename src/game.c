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
 * @author Clément LUCAS <jambo@baboune>
 * @version 0.0.1 / 28-10-2017
 */

/**
 * @file game.c
 * Provides the functions used during the game.
 */

#include "../include/game.h"

#define NBOATCELLS 5

int askInt( char * message ) {

   int res;

   printf("%s",message);
   scanf("%d",&res);

   return res;
}

void setUpPlayerFleet( Board *board, int n ) {

   int i = 0;
   int x ;
   int y ;

   while ( i < n ) {

      system("clear");
      printf("Player fleet : set your boats ! \n");
      printBoard(*board);
      
      x = askInt("x value ? : ");
      y = askInt("y value ? : ");

      if ( checkInTab( *board, y, x) && !board->tab[y][x] ) {
	 putValue( board, y, x, 1 );
	 i++ ;
      }
   }

}


void setUpComputerFleet( Board *board, int n ) {

   int i = 0;
   int x ;
   int y ;

   while ( i < n ) {
      
      x = rand()%board->col;
      y = rand()%board->row;

      if ( checkInTab( *board, y, x) && !board->tab[y][x] ) {
	 putValue( board, y, x, 1 );
	 i++ ;
      }
   }
   
}

void initGame(Board *player, Board *computer) {

   setUpPlayerFleet(player, NBOATCELLS);
   setUpComputerFleet(computer, NBOATCELLS);
   
}

void printGame(Board *player, Board * computer) {

   system("clear");

   printf("Player fleet : \n");
   printBoard(*player);

   printf("Computer fleet : \n");
   printBoard(*computer);
   
}
      
