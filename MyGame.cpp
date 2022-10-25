/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#include "MyGame.h"

MyGame::MyGame(const std::vector<Player*>& player, const size_t laddersquare_number, const size_t snakesquare_number, const size_t max_round_number, const size_t laddersquare_reward, const size_t snakesquare_penalty) : laddersquare_number{ laddersquare_number }, snakesquare_number{ snakesquare_number }, max_round_number{ max_round_number }{
	LadderSquare::set_reward(laddersquare_reward);
	SnakeSquare::set_penalty(snakesquare_penalty);
	srand(static_cast<unsigned int>(time(NULL)));
	auto get_wildcart_id{
		[](const size_t number) {
			std::vector<size_t> square_id(number);
			for (size_t index{ 0 }; index < square_id.size(); ++index)
				square_id.at(index) = static_cast<size_t>(1 + rand() % (limit-2));
			return square_id;
		}
	};
	std::vector<size_t> laddersquare_id{ get_wildcart_id(laddersquare_number) };
	std::vector<size_t> snakesquare_id{ get_wildcart_id(snakesquare_number) };
	while (
		[&laddersquare_id, &snakesquare_id] {
			for (auto element : snakesquare_id) {
				if (std::find(laddersquare_id.begin(), laddersquare_id.end(), element) != laddersquare_id.end()) return true;
			}
			return false;
		}()) {
		laddersquare_id = get_wildcart_id(laddersquare_number);
		snakesquare_id = get_wildcart_id(snakesquare_number);
	}
	for (size_t row{0}; row < static_cast<size_t>(Dimension::rows); ++row) {
		for (size_t col{0}; col < static_cast<size_t>(Dimension::cols); ++col)
			squares[row][col] = new NormalSquare{};
	}
	for (size_t element : laddersquare_id) {
		size_t row{ static_cast<size_t>(std::round(element / static_cast<size_t>(Dimension::cols))) };
		size_t col{ element % static_cast<size_t>(Dimension::cols) };
		delete squares[row][col];
		squares[row][col] = new LadderSquare{ element };
	}
	for (size_t element : snakesquare_id) {
		size_t row{ static_cast<size_t>(std::round(element / static_cast<size_t>(Dimension::cols))) };
		size_t col{ element % static_cast<size_t>(Dimension::cols) };
		delete squares[row][col];
		squares[row][col] = new SnakeSquare{ element };
	}
	for (const auto& player : player){
		this->player.push_back(player);
		player->set_location(squares[static_cast<size_t>(Dimension::rows) - 1][static_cast<size_t>(Dimension::cols) -1]);
	}
}

MyGame::~MyGame(void) {
	for (size_t row{0}; row < static_cast<size_t>(Dimension::rows); ++row) {
		for (size_t col{0}; col < static_cast<size_t>(Dimension::cols); ++col) {
			delete squares[row][col];
			squares[row][col] = nullptr;
		}
	}
	for (const auto& player : player) delete player;
	console_log.close();
}

void MyGame::print_board(void) const {
	for (size_t row{ 0 }; row < static_cast<size_t>(Dimension::rows); ++row) {
		std::cout << "\t\t";
		for (size_t col{ 0 }; col < static_cast<size_t>(Dimension::cols); ++col)
		{
			std::cout << squares[row][col] << ' ';
			for (const auto& player : player) {
				if (player->get_location() == squares[row][col]) {
					std::cout << 'P' << player->identificator << ' ';
				}
			}
			std::cout << "\t\t";
		}
		std::cout << "\n\n";
	}
}

void MyGame::start(void){
	char option{};
	size_t round{};
	Dice::Face getted_face{};
	for (size_t controller{ 1 }; controller <= max_round_number; ++controller, ++round) {
		for (auto player : player) {
			do {
				system("cls");
				std::cout << "\n\n\n\t\tSnakes and Ladders!\n\t\tRound number " << controller << ".\n\n\t\t" << player << ".\n\t\tCurrently location: " << player->get_location() << ".\n\n\n\n";
				print_board();
				std::cout << "\n\t\tType 'c' to continue or type 'e' to exit the game: ";
				std::cin >> option;
				std::cout << "\n\n";
				option = tolower(option);
				switch (option) {
				case 'c':
					break;
				case 'e':
					std::cout << "\t\tThanks for playing!\n";
					return;
				default:
					std::cout << "\t\tInvalid option. Please, press 'c' to continue next turn or 'e' to end the game.\n";
					Sleep(2000);
				}
			} while (option != 'c');
			getted_face = Dice::roll();
			std::cout << "\t\tNumber obtained: " << getted_face << ".\n\t\tAdvance " << getted_face << " squares.\n";
			move(controller, player, getted_face);
			std::cout << "\t\t";
			system("pause");
			if (player->get_location()->identificator >= 30) {
				winning_player = player;
				controller = max_round_number + 1;
				break;
			}
		}
	}
	system("cls");
	std::cout << "\n\n\n\t\tSnakes and Ladders!\n\n\t\tGame status.\n\t\tNumber of rounds: " << round << ".\n\n\n\n";
	print_board();
	if (winning_player)
		std::cout << "\n\t\tThe winner is " << winning_player << "!\n";
	else
		std::cout << "\n\t\tThe maximum number of turns has been reached.\n";
}

void MyGame::move(const size_t turn, Player*& player, const Dice::Face& face, const bool mode, size_t loop) {
	if (loop < 2) {
		size_t identificator{ limit - (mode ? ((identificator = player->get_location()->identificator + static_cast<size_t>(face)) >= 30 ? 30 : identificator) : ((identificator = static_cast<short int>(player->get_location()->identificator) - static_cast<short int>(face)) <= 1 ? 1 : identificator)) }, row{ identificator >= 30 ? static_cast<size_t>(Dimension::rows) - 1 : static_cast<size_t>(std::round(identificator / static_cast<size_t>(Dimension::cols))) }, col{ identificator >= 30 ? static_cast<size_t>(Dimension::cols) - 1 : identificator % static_cast<size_t>(Dimension::cols) };
		std::string log{ std::to_string(turn) + " " + std::to_string(player->identificator) + " " + std::to_string(player->get_location()->identificator) + " " + std::to_string(static_cast<size_t>(face)) + " "};
		player->set_location(squares[row][col]);
		log += "char(" + std::to_string(player->get_location()->get_symbol()) + ") " + std::to_string(player->get_location()->identificator) + "\n";
		std::cout << "\t\tGo to square " << squares[row][col] << "!\n";
		std::cout << "\t\tConsole log: " << log;
		console_log << log;
		switch (squares[row][col]->get_symbol()) {
		case 'L':
			if (++loop < 2)
				std::cout << "\n\t\tLadder square! Advance " << LadderSquare::get_reward() << " positions...\n";
			move(turn, player, Dice{ LadderSquare::get_reward() }.number, true, loop);
			break;
		case 'S':
			if (++loop < 2)
				std::cout << "\n\t\tSnake square! Go back " << SnakeSquare::get_penalty() << " positions...\n";
			move(turn, player, Dice{ SnakeSquare::get_penalty() }.number, false, loop);
		}
	}
}