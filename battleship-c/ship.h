#ifndef SHIP_H_
#define SHIP_H_

#include "boolean.h"

typedef unsigned char s_size;
typedef unsigned char s_health;

typedef struct Cell Cell;
typedef struct Field Field;

typedef struct Ship {
	Cell** cells;
	Field* field;
	s_size size;
	s_health health;
	boolean horizontal;
	boolean alive;
	boolean on_field;
} Ship;

Ship* s__new__(s_size, Field*);
boolean s_board(Ship*, Cell**);
void s_unboard(Ship*);
void s_shoot(Ship*);
boolean s_damaged(Ship*);
boolean s_on_field(Ship*);
Cell** s_get_cells(Ship*);
Cell* s_get_cell(Ship*, s_size);
Field* s_get_field(Ship*);

#endif
