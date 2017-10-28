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
 * @file board.h
 * Prototypes of the library board.
 */

#ifndef __BOARD_H
#define __BOARD_H


/**
 * @brief A simple board
 *
 * The tab board with it's rows and cols.
 */
typedef struct{
  int ** tab; /**< The tab board */
  int row;    /**< The number of rows of the tab */
  int col;    /**< The number of columns of the tab */
}Board;

/**
 * Initializes a board with zeros (allocates memory)
 *
 * @param board the board that needs to be initialized.
 * @param row the number of row of the new board.
 * @param col the number of columns of the new board.
 * @return void
 */
void initBoard(Board *board, int row, int col);

/**
 * Prints a board
 *
 * @param board the board that needs to be displayed
 * @return void
 */
void printBoard(Board board);

/**
 *  Puts a value in the board at the given position
 *
 *  @param board the board that needs to be modified.
 *  @param l the index of the raw in the table
 *  @param c the index of the column in the table
 *  @param value the value to put in the table
 *  @return void
 */
void putValue(Board *board,  int l, int c, int value);

/**
 * Checks if a position is in the tab
 *
 * @param board the board that needs to be checked.
 * @param l the index of the raw in the table
 * @param c the index of the column in the table
 * @return 1 if true, else 0
 */
int checkInTab(Board board, int l, int c);

/**
 * Frees the memory allocated for the board
 *
 * @param board the board that needs to be free.
 * @return void
 */
void freeBoard(Board board);

#endif
