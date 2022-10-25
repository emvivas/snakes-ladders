/*
* Program: Snakes and Ladders!
* Version: 1.0 alpha
* Date: 08/14/2022
* Authors: Emiliano Vivas Rodríguez; Aldo Olascoaga Olmedo.
* Contact: a01424732@tec.mx; a01424731@tec.mx
*/

#pragma once

enum class Dimension : size_t { rows = 5ui64, cols = 6ui64 };
constexpr inline size_t limit{ static_cast<size_t>(Dimension::rows) * static_cast<size_t>(Dimension::cols) };
constexpr inline size_t default_laddersquare_number{ 3ui64 }, default_snakesquare_number{ 3ui64 }, default_max_round_number{ 5ui64 }, default_laddersquare_reward{ 3ui64 }, default_snakesquare_penalty{ 3ui64  };