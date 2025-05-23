#include <stdlib.h>
#include "field.h"
#include "ship.h"

Field* f__new__() {
	Field* field = malloc(sizeof(Field));
	if (!field) return NULL;

	Cell*** cells = malloc(sizeof(Cell**) * FIELD_LENGTH);
	if (!cells) return NULL;
	for (char i = 0; i < FIELD_LENGTH; i++) {
		cells[i] = malloc(sizeof(Cell*) * FIELD_LENGTH);
		if (!cells[i]) return NULL;
	}
	field->cells = cells;

	Ship** ships = malloc(sizeof(Ship*) * SHIPS_COUNT);
	if (!ships) return NULL;
	field->ships = ships;

	field->ships_on_board = 0;
	field->alive_ships = SHIPS_COUNT;

	for (c_coord i = 0; i < FIELD_LENGTH; i++) {
		for (c_coord j = 0; j < FIELD_LENGTH; j++) {
			cells[i][j] = c__new__(field, i, j);
		}
	}

	s_size count = 0;
	s_size start = 0;
	for (s_size size = 1; size < FIELD_HALF_LENGTH; size++) {
		count = FIELD_HALF_LENGTH - size;
		start = ((count - 1) * count) / 2;
		for (s_size i = start; i < start + count; i++) {
			ships[i] = s__new__(size, field);
		}
	}

	return field;
}

Cell** f_get_cells(Field* field) {
	return field->cells;
}

Cell* f_get_cell(Field* field, c_coord x, c_coord y) {
	return field->cells[x][y];
}

void f_unboard(Ship* ship) {
	if (s_on_field(ship)) {
		s_unboard(ship);
		Cell* cell = s_get_cell(ship, 0);
		for (s_size i = 0; i < ship->size; i++) {
			c_unboard(cell++);
		}
		s_get_field(ship)->ships_on_board--;
	}
}

static boolean do_with_nearby_cells(Field* field, c_coord x, c_coord y, boolean(*action)(Cell*)) {
	for (c_coord xi = (x == 0 ? 0 : -1); xi <= (x == FIELD_LENGTH - 1 ? 0 : 1); xi++) {
		for (c_coord yi = (y == 0 ? 0 : -1); yi <= (y == FIELD_LENGTH - 1 ? 0 : 1); yi++) {
			if (!((*action)(f_get_cell(field, x + xi, y + yi)))) return false;
		}
	}
	return true;
}

boolean f_board(Ship* ship, Cell* start_cell) {
	Field* field = s_get_field(ship);

	c_coord x = start_cell->x;
	c_coord y = start_cell->y;

	s_size ship_size = ship->size;
	boolean horizontal = ship->horizontal;
	s_size i;

	if (s_on_field(ship)) return false;
	if (ship_size + (horizontal ? x : y) > FIELD_LENGTH) return false;

	Cell** cells = malloc(sizeof(Cell*) * ship_size);
	if (!cells) return false;

	c_coord next_x = x;
	c_coord next_y = y;
	for (i = 0; i < ship_size; i++) {
		if (horizontal) {
			next_x = x + i;
		} else {
			next_y = y + i;
		}
		if (!(do_with_nearby_cells(field, next_x, next_y, &c_has_no_ship))) return false;
		cells[i] = f_get_cell(field, next_x, next_y);
	}

	for (i = 0; i < ship_size; i++) {
		if (!(c_board(cells[i], ship))) return false;
	}
	if (!s_board(ship, cells)) return false;
	field->ships_on_board++;

	return true;
}

boolean f_has_alive_ships(Field* field) {
	return field->alive_ships;
}

boolean f_has_unboarded_ships(Field* field) {
	return field->ships_on_board != SHIPS_COUNT;
}