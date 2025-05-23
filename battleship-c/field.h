#ifndef FIELD_H_
#define FIELD_H_

#include "boolean.h"
#include "cell.h"

#define FIELD_LENGTH 10
#define FIELD_HALF_LENGTH 5
#define CELLS_COUNT 100
#define SHIPS_COUNT 10

typedef unsigned char f_counter;

typedef struct Cell Cell;
typedef struct Ship Ship;

typedef struct Field {
	Cell*** cells;
	Ship** ships;
	f_counter ships_on_board;
	f_counter alive_ships;
} Field;

Field* f__new__();
Cell** f_get_cells(Field*);
Cell* f_get_cell(Field*, c_coord, c_coord);
void f_unboard(Ship*);
boolean f_board(Ship*, Cell*);
boolean f_has_alive_ships(Field*);
boolean f_has_unboarded_ships(Field*);

#endif
