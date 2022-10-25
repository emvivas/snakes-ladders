/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#include "MyGame.h"

int main(int argc, char** argv)
{
	size_t players_number{}, laddersquare_number{}, snakesquare_number{}, round_number{}, laddersquare_reward{}, snakesquare_penalty{};
	system("cls");
	SetConsoleTitleA("Snakes and Ladders! Version 1.0a");
	std::cout << "\n\n\n\t\tSnakes and Ladders!\n\t\tVersion 1.0 alpha.\n\n\t\tAldo Olascoaga Olmedo, a01424731@tec.mx\n\t\tEmiliano Vivas Rodriguez, a01424732@tec.mx\n\n\n\n\t\t- Number of ladders: ";
	std::cin >> laddersquare_number;
	std::cout << "\n\t\t- Ladder square reward: ";
	std::cin >> laddersquare_reward;
	std::cout << "\n\t\t- Number of snakes: ";
	std::cin >> snakesquare_number;
	std::cout << "\n\t\t- Snake square penalty: ";
	std::cin >> snakesquare_penalty;
	std::cout << "\n\t\t- Number of turns: ";
	std::cin >> round_number;
	std::cout << "\n\t\t- Number of players: ";
	std::cin >> players_number;
	std::string player_nickname{};
	std::vector<Player*> player{};
	player.reserve(players_number);
	for (size_t index{ 0 }; index < players_number; ++index) {
		std::cout << "\n\t\t\t+ Player " << index+1 << "'s nickname: ";
		std::getline(std::cin >> std::ws, player_nickname);
		player.push_back(new Player{ player_nickname });
	}
	MyGame game{player, laddersquare_number, snakesquare_number, round_number, laddersquare_reward, snakesquare_penalty};
	game.start();
	std::cout << "\t\tGame over.\n\n\n";
	return EXIT_SUCCESS;
}