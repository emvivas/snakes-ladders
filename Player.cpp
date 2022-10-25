/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#include "Player.h"

Player::Player(const std::string& nickname) : identificator{ ++counter }, nickname { nickname } {}

void Player::set_location(GameSquare*& location){
	this->location = location;
}

const GameSquare* Player::get_location(void) const {
	return location;
}

std::ostream& operator<<(std::ostream& out, Player*& player) {
	return(out << "Player " << player->identificator << ", " << player->nickname);
}

std::ostream& operator<<(std::ostream& out, const Player*& player) {
	return(out << "Player " << player->identificator << ", " << player->nickname);
}