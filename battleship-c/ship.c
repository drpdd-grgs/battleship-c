#include <stdlib.h>
#include "ship.h"
#include "cell.h"

 struct Ship {
	Cell** cells;
	s_size size;
	s_health health;
	boolean horizontal;
	boolean alive;
	boolean on_field;
};

 Ship* s__new__(s_size size) {
	 Ship* ship = malloc(sizeof(Ship));
	 if (!ship) return NULL;

	 ship->size = size;
	 ship->health = size;
	 ship->horizontal = true;
	 ship->alive = true;
	 ship->on_field = false;
	 ship->cells = NULL;

	 return ship;
 }

 Cell* s_get_cells(Ship* ship) {
	 return ship->cells;
 }

 void s_board(Ship* ship, Cell** cells) {
	 ship->cells = cells;
	 ship->on_field = true;
 }

 void s_unboard(Ship* ship) {
	 ship->alive = true;
	 ship->horizontal = true;
	 ship->on_field = false;
	 ship->health = ship->size;
 }

 boolean s_is_alive(Ship* ship) {
	 return ship->alive;
 }

 boolean s_is_on_field(Ship* ship) {
	 return ship->on_field;
 }

 s_size s_get_size(Ship* ship) {
	 return ship->size;
 }

 boolean s_is_horizontal(Ship* ship) {
	 return ship->horizontal;
 }

 void s_set_dimension(Ship* ship, boolean horizontal) {
	 ship->horizontal = horizontal;
 }

 void s_shoot(Ship* ship) {
	 ship->health--;
	 if (!ship->health)
		 ship->alive = false;
 }

 boolean s_damaged(Ship* ship) {
	 return ship->health != ship->size;
 }
