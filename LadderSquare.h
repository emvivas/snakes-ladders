/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#pragma once
#include "GameSquare.h"

class LadderSquare final : public GameSquare {
private:
	static inline size_t reward{ default_laddersquare_reward };
public:
	static size_t get_reward(void);
	static void set_reward(const size_t reward);
	LadderSquare(const size_t identificator);
	char get_symbol(void) const override;
};