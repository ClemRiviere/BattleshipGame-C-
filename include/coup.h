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
 * @author Clément LUCAS
 * @version 0.0.1 / 25-10-2017
 */

/**
 * @file coup.h
 */

#ifndef __INCLUDE_H
#define __INCLUDE_H

#include "position.h"

/**
 *  @brief Coup
 *
 * Defines an attemp of strike by the position
 */
typedef struct{
   Position p; /**< Position where to shoot */
   int val; /**< Value of the shoot : 1 if touché, 0 otherwise */
} Coup;

#endif