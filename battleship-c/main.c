#include "field.h"
#include <stdio.h>

int main() {
	Field* field = f__new__();
	Cell* cell = f_get_cell(field, 1, 1);

	printf("%d %d\n", c_get_x(cell), c_get_y(cell));
	return 0;
}