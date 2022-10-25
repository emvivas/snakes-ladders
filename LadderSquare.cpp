/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#include "LadderSquare.h"

size_t LadderSquare::get_reward(void) {
	return reward;
}

void LadderSquare::set_reward(const size_t reward) {
	LadderSquare::reward = reward;
}

LadderSquare::LadderSquare(const size_t identificator) : GameSquare{ identificator }{}

char LadderSquare::get_symbol(void) const {
	return 'L';
}