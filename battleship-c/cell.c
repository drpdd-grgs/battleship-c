#include <stdlib.h>
#include "cell.h"
#include "ship.h"

struct Cell {
	Ship* ship;
	c_coord x;
	c_coord y;
	boolean damaged;
};

Cell* c__new__(c_coord x, c_coord y) {
	Cell* cell = malloc(sizeof(Cell));
	if (!cell) return NULL;

	cell->x = x;
	cell->y = y;
	cell->damaged = false;
	cell->ship = NULL;
}

c_coord c_get_x(Cell* cell) {
	return cell->x;
}

c_coord c_get_y(Cell* cell) {
	return cell->y;
}

boolean c_has_ship(Cell* cell) {
	return cell->ship;
}

void c_reset_ship(Cell* cell) {
	cell->ship = NULL;
}

void c_set_ship(Cell* cell, Ship* ship) {
	cell->ship = ship;
}

void c_shoot(Cell* cell) {
	cell->damaged = true;
}

boolean c_damaged(Cell* cell) {
	return cell->damaged;
}