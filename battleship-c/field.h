#pragma once

#include "cell.h"

#define FIELD_LENGTH 10
#define FIELD_HALF_LENGTH 5
#define CELLS_COUNT 100
#define SHIPS_COUNT 10

typedef unsigned char f_counter;

typedef struct Field Field;
typedef struct Ship Ship;
typedef struct Cell Cell;

Field* f__new__();
Cell* f_get_cell(Field*, c_coord, c_coord);
