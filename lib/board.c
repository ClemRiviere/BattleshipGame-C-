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
 * @version 0.0.1 / 25-10-2017
 */

/**
 * @file board.c
 * Library that handles the basics of a board game
 */

#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void initBoard(int *** tab, int row, int col) {

   int i;
   int j;

   /* Allocating memory */
   *tab = (int **)malloc(sizeof(int *) * row);

   for ( i=0; i<row ; i++ ) {
       (*tab)[i] = (int *)malloc(sizeof(int) * col);
       for ( j=0; j<col; j++ ) {
	       (*tab)[i][j] = 0;
       }
   }

}

void printBoard(int ** tab, int row, int col) {

   int i;
   int j;

   for ( i=0; i<row; i++ ) {
      for ( j=0; j<col; j++ ) {
        printf("----");
      }
      printf("-\n");
      for ( j=0; j<col; j++ ) {
	       printf("| %d ",tab[i][j]);
      }
      printf("|\n");
   }
   for ( j=0; j<col; j++ ) {
        printf("----");
    }
      printf("-\n");
}

void putValue(int *** tab,int row, int col, int l, int c, int value) {
  int b = checkInTab(*tab, l, c, row, col);
  if ( b ) {
    (*tab)[l][c] = value;
  }
}

int checkInTab(int ** tab, int l, int c, int row, int col) {

  int res = 1;

  if ( l<0 || c<0 ) {
    res = 0;
  }

  if ( l>= row || c>=col ) {
    res = 0;
  }

  return res;
}

void freeBoard(int ** tab, int row) {

  int i;

  for ( i=0; i< row; i++ ) {

    free(tab[i]);

  }

  free(tab);
}

