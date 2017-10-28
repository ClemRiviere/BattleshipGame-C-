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
 * @author Clément RIVIERE <criviere@ecole.ensicaen.fr>
 * @version 0.0.1 / 25-10-2017
 */

/**
 * @file board.c
 * Library that handles the basics of a board game
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/board.h"

void initBoard(Board *board, int row, int col) {

   int i;
   int j;

   board->row = row;
   board->col = col;

   /* Allocating memory */
   board->tab = (int **)malloc(sizeof(int *) * row);

   for ( i=0; i<row ; i++ ) {
       board->tab[i] = (int *)malloc(sizeof(int) * col);
       for ( j=0; j<col; j++ ) {
	       board->tab[i][j] = 0;
       }
   }

}

void printBoard(Board board) {

   int i;
   int j;



   for ( i=0; i<board.row; i++ ) {
      for ( j=0; j<board.col; j++ ) {
        printf("----");
      }
      printf("-\n");
      for ( j=0; j<board.col; j++ ) {
	       printf("| %d ",board.tab[i][j]);
      }
      printf("|\n");
   }
   for ( j=0; j<board.col; j++ ) {
        printf("----");
    }
      printf("-\n");
}

void putValue(Board *board, int l, int c, int value) {
  int b = checkInTab(*board, l, c);
  if ( b ) {
    board->tab[l][c] = value;
  }
}

int checkInTab(Board board, int l, int c) {

  int res = 1;

  if ( l<0 || c<0 ) {
    res = 0;
  }

  if ( l>= board.row || c>= board.col ) {
    res = 0;
  }

  return res;
}

void freeBoard(Board board) {

  int i;

  for ( i=0; i< board.row; i++ ) {

    free(board.tab[i]);

  }

  free(board.tab);
}