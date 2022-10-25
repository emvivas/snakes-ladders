/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#include "GameSquare.h"

GameSquare::GameSquare(void) : identificator{limit - counter++} {}

GameSquare::GameSquare(const size_t identificator) : identificator{ limit - identificator } {}

std::ostream& operator<<(std::ostream& out, const GameSquare* square) {
	return (out << square->get_symbol() << '-' << square->identificator);
}