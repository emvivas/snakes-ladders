/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#pragma once
#include <string>
#include <ostream>
#include "GameSquare.h"

class Player final {
private:
	static inline size_t counter{};
	GameSquare* location{};
public:
	const size_t identificator{};
	const std::string nickname{};
	Player(const std::string& nickname = "New");
	void set_location(GameSquare*& location);
	const GameSquare* get_location(void) const;
};

std::ostream& operator<<(std::ostream& out, Player*& player);
std::ostream& operator<<(std::ostream& out, const Player*& player);