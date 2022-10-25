/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#include "SnakeSquare.h"

size_t SnakeSquare::get_penalty(void) {
	return penalty;
}

void SnakeSquare::set_penalty(const size_t penalty) {
	SnakeSquare::penalty = penalty;
}

SnakeSquare::SnakeSquare(const size_t identificator) : GameSquare{ identificator } {}

char SnakeSquare::get_symbol(void) const {
	return 'S';
}