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
 * @file coup.h
 */

#ifndef __INCLUDE_H
#define __INCLUDE_H

#include "position.h"

typedef struct{
   Position p;
   int val;
} Coup;

#endif
