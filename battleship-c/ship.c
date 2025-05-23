#include <stdlib.h>
#include "cell.h"
#include "ship.h"

 Ship* s__new__(s_size size, Field* field) {
	 Ship* ship = malloc(sizeof(Ship));
	 if (!ship) return NULL;

	 ship->size = size;
	 ship->health = size;
	 ship->horizontal = true;
	 ship->alive = true;
	 ship->on_field = false;
	 ship->cells = NULL;
	 ship->field = field;

	 return ship;
 }

 boolean s_board(Ship* ship, Cell** cells) {
	 Cell* cell = cells[0];
	 for (s_size i = 0; i < ship->size; i++) {
		 if (!cell || cell->field != ship->field) return false;
	 }

	 ship->cells = cells;
	 ship->on_field = true;

	 return true;
 }

 void s_unboard(Ship* ship) {
	 ship->alive = true;
	 ship->horizontal = true;
	 ship->on_field = false;
	 ship->health = ship->size;
 }

 void s_shoot(Ship* ship) {
	 ship->health--;
	 if (!ship->health)
		 ship->alive = false;
 }

 boolean s_damaged(Ship* ship) {
	 return ship->health != ship->size;
 }

 boolean s_on_field(Ship* ship) {
	 return ship->on_field;
 }

 Cell** s_get_cells(Ship* ship) {
	 return ship->cells;
 }

 Cell* s_get_cell(Ship* ship, s_size index) {
	 return ship->cells[index];
 }

 Field* s_get_field(Ship* ship) {
	 return ship->field;
 }