/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#pragma once
#include "GameSquare.h"
#include "BoardInfo.h"

class SnakeSquare final : public GameSquare {
private:
	static inline size_t penalty{ default_snakesquare_penalty };
public:
	static size_t get_penalty(void);
	static void set_penalty(const size_t penalty);
	SnakeSquare(const size_t identificator);
	char get_symbol(void) const override;
};