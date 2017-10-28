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
 * @author Clément Rivière <criviere@ecole.ensicaen.fr>
 * @author Clément Lucas <clement.lucas@ecole.ensicaen.fr>
 * @version 0.0.1 / 25-10-2017
 */

/**
 * @file position.h
 */

#ifndef __POSITION_H
#define __POSITION_H


/**
 * @brief Position
 *
 * A position defined by x and y
 */
typedef struct{
   int x; /**< x value of the position */
   int y; /**< y value of the position */
} Position;

#endif
