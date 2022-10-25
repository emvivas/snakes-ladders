/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#pragma once
#include <ostream>
#include "BoardInfo.h"

class GameSquare {
private:
	static inline size_t counter{};
public:
	const size_t identificator{};
	GameSquare(void);
	GameSquare(const size_t identificator);
	virtual ~GameSquare(void) = default;
	virtual char get_symbol(void) const = 0;
};

std::ostream& operator<<(std::ostream& out, const GameSquare* square);