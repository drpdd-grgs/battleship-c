#ifndef CELL_H_
#define CELL_H_

#include "boolean.h"

typedef signed char c_coord;

typedef struct Field Field;
typedef struct Ship Ship;

typedef struct Cell {
	Field* field;
	Ship* ship;
	c_coord x;
	c_coord y;
	boolean damaged;
} Cell;

Cell* c__new__(Field*, c_coord, c_coord);
boolean c_has_ship(Cell*);
boolean c_has_no_ship(Cell*);
boolean c_board(Cell*, Ship*);
void c_unboard(Cell*);
boolean c_shoot(Cell*);

#endif
