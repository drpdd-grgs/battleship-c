#pragma once

#include "boolean.h"

typedef unsigned char c_coord;

typedef struct Cell Cell;
typedef struct Ship Ship;

Cell* c__new__(c_coord, c_coord);
c_coord c_get_x(Cell*);
c_coord c_get_y(Cell*);
boolean c_has_ship(Cell*);
void c_reset_ship(Cell*);
void c_set_ship(Cell*, Ship*);
void c_shoot(Cell*);
boolean c_is_damaged(Cell*);