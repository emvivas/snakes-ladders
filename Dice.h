/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#pragma once
#include <ctime>
#include <cstdlib>
#include <ostream>

class Dice final {
public:
	enum class Face : unsigned int { one = 1u, two = 2u, three = 3u, four = 4u, five = 5u, six = 6u };
	const Face number{};
	static Face roll(void);
	explicit Dice(const size_t number);
};

std::ostream& operator<< (std::ostream& out, const Dice::Face& face);