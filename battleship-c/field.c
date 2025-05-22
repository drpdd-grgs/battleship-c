#include <stdlib.h>
#include "field.h"
#include "ship.h"

struct Field {
	Cell*** cells;
	Ship** ships;
	f_counter ships_on_board;
	f_counter alive_ships;
};

Field* f__new__() {
	Field* field = malloc(sizeof(Field));
	if (!field) return NULL;

	Cell*** cells = malloc(sizeof(Cell**) * FIELD_LENGTH);
	if (!cells) return NULL;
	for (char i = 0; i < FIELD_LENGTH; i++) {
		cells[i] = malloc(sizeof(Cell*) * FIELD_LENGTH);
	}
	field->cells = cells;

	Ship** ships = malloc(sizeof(Ship*) * SHIPS_COUNT);
	if (!ships) return NULL;
	field->ships = ships;

	field->ships_on_board = 0;
	field->alive_ships = SHIPS_COUNT;

	c_coord i;
	c_coord j;
	for (i = 0; i < FIELD_LENGTH; i++) {
		for (j = 0; j < FIELD_LENGTH; j++) {
			cells[i][j] = c__new__(i, j);
		}
	}

	s_size size;
	s_size count;
	s_size start;
	for (s_size size = 1; i < FIELD_HALF_LENGTH; i++) {
		count = FIELD_HALF_LENGTH - i;
		start = ((count - 1) * count) / 2;
		for (j = start; j < start + count; j++) {
			ships[j] = s__new__(size);
		}
	}
}

Cell* f_get_cell(Field* field, c_coord x, c_coord y) {
	return field->cells[x][y];
}