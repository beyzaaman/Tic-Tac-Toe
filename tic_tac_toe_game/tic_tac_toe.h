#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include <random>

typedef std::pair<int, int> close_t;


class tic_tac_toe
{
public:
	tic_tac_toe();
	~tic_tac_toe();
	void play();
	void  computer_play();
	void smart_computer_play();

private:
	void delete_pair(int row_,int column_);
	void make_pair();
	void display_game();
	int gameplay(int row,int column);
	close_t winnable_cases();

private:
	std::vector<std::vector<char>> game_;
	std::vector<std::pair<int, int>> location_vector_;
	int							   row_;
	int							   column_;
	bool						   player_;

	
};
