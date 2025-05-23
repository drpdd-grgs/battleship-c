#include <stdlib.h>
#include "cell.h"

Cell* c__new__(Field* field, c_coord x, c_coord y) {
	Cell* cell = malloc(sizeof(Cell));
	if (!cell) return NULL;

	cell->x = x;
	cell->y = y;
	cell->damaged = false;
	cell->ship = NULL;
	cell->field = field;

	return cell;
}

boolean c_has_ship(Cell* cell) {
	return cell->ship;
}

boolean c_has_no_ship(Cell* cell) {
	return !cell->ship;
}

boolean c_board(Cell* cell, Ship* ship) {
	if (c_has_ship(cell)) return false;
	cell->ship = ship;
	return true;
}

void c_unboard(Cell* cell) {
	cell->ship = NULL;
}

boolean c_shoot(Cell* cell) {
	if (cell->damaged) return false;
	cell->damaged = true;
	return true;
}