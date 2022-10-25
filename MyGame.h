/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstddef>
#include <algorithm>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <functional>
#include <string>
#include <fstream>
#include "Dice.h"
#include "LadderSquare.h"
#include "SnakeSquare.h"
#include "NormalSquare.h"
#include "Player.h"
#include "BoardInfo.h"

class MyGame final {
public:
	const size_t laddersquare_number{ default_laddersquare_number }, snakesquare_number{ default_snakesquare_number }, max_round_number{ default_max_round_number };
	MyGame(const std::vector<Player*>& players, const size_t laddersquare_number = default_laddersquare_number, const size_t snakesquare_number = default_snakesquare_number, const size_t max_round_number = default_max_round_number, const size_t laddersquare_reward = default_laddersquare_reward, const size_t snakesquare_penalty =  default_snakesquare_penalty);
	~MyGame(void);
	void start(void);
private:
	std::vector<Player*> player{};
	const Player* winning_player{};
	std::ofstream console_log{ "console_log.txt" };
	GameSquare* squares[static_cast<unsigned short int>(Dimension::rows)][static_cast<unsigned short int>(Dimension::cols)]{};
	void print_board(void) const;
	void move(const size_t turn, Player*& player, const Dice::Face& face, const bool mode = true, size_t repetition = 0ui64);
};