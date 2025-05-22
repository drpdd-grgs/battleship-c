#pragma once

#include "boolean.h"

typedef unsigned char s_size;
typedef unsigned char s_health;

typedef struct Ship Ship;
typedef struct Cell Cell;

Ship* s__new__(s_size);
Cell* s_get_cells(Ship*);
void s_board(Ship*, Cell*);
void s_unboard(Ship*);
boolean s_is_alive(Ship*);
boolean s_is_on_field(Ship*);
s_size s_get_size(Ship*);
boolean s_is_horizontal(Ship*);
void s_set_dimension(Ship*, boolean);
void s_shoot(Ship*);
boolean s_damaged(Ship*);