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
 * @file board.h
 * Prototypes of the library board.
 */

/**
 *	Initializes a board with zeros (allocates memory)
 *	
 * 	@param tab the table of int we want to create
 * 	@param row the number of raws of the table
 *  @param col the number of columns of the table
 * 	@return void
 */
void initBoard(int ** tab, int row, int col);

/**
 *	Prints a board
 *	
 * 	@param tab the table of int we want to print
 * 	@param row the number of raws of the table
 *  @param col the number of columns of the table
 * 	@return void
 */
void printBoard(int ** tab, int row, int col);

/**
 *	Puts a value in the tab at the given position
 *	
 * 	@param tab the table of int 
 * 	@param row the index of the raw in the table
 *  @param col the index of the column in the table
 *  @param value the value to put in the table
 * 	@return void
 */
void putValue(int ** tab, int l, int c, int value);

/**
 *	Checks if a position is in the tab
 *	
 * 	@param tab the table of int
 * 	@param row the index of the raw in the table
 *  @param col the index of the column in the table
 * 	@return 1 if true, else 0
 */
int checkInTab(int ** tab, int l, int c);

/**
 *	Frees the memory allocated for the board
 *	
 * 	@param tab the table of int we want to free
 * 	@return void
 */
void freeBoard(int ** tab);