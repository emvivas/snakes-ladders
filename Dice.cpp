/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#include "Dice.h"

Dice::Dice(const size_t number) : number{ static_cast<Face>(number) } {}

Dice::Face Dice::roll(void) {
	srand(static_cast<unsigned int>(time(NULL)));
	return static_cast<Face> (1 + rand() % (6));
}

std::ostream& operator<< (std::ostream& out, const Dice::Face& face) {
	return (out << static_cast<size_t>(face));
}