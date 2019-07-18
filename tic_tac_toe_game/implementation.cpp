#include "pch.h"
#include "implementation.h"
#include <time.h>
#include <stdlib.h>
#include <utility>


tic_tac_toe::tic_tac_toe() :
	row_(0),
	column_(0),
	player_(true),
	game_({ { 32,32,32 }, { 32,32,32 }, { 32,32,32 } }),
	location_vector_()

{}

tic_tac_toe::~tic_tac_toe()
{
}

void tic_tac_toe:: make_pair()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{	
		location_vector_.push_back(std::make_pair(i, j));
		}
	}
}

void tic_tac_toe:: delete_pair(int row,int column)
{
	int i = 0;
	

	while(1)
	{
		if (location_vector_[i].first == row && location_vector_[i].second == column)
		{
			location_vector_.erase(location_vector_.begin() + i);
			
			break;
		}
		i++;
	}
	
}

 void tic_tac_toe::display_game()

{
	std::cout << "     |" << "     |     \n";
	std::cout << "  " << game_[0][0] << "  |" << "  " << game_[0][1] << "  |  " << game_[0][2] << "  \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |" << "     |     \n";
	std::cout << "  " << game_[1][0] << "  |" << "  " << game_[1][1] << "  |  " << game_[1][2] << "  \n";
	std::cout << "_____|_____|_____\n";
	std::cout << "     |" << "     |     \n";
	std::cout << "  " << game_[2][0] << "  |" << "  " << game_[2][1] << "  |  " << game_[2][2] << "  \n";
	std::cout << "     |" << "     |     \n";
}

 int tic_tac_toe::gameplay(int row, int column)
 {
	 char player_name;
	 if (player_)
	 {
		 row--;
		 column--;
	 }
	 
	 if (game_[row][column] == 32)
	 {
		 if (player_)
		 {
			 game_[row][column] = 'X';
			 delete_pair(row, column);
			 player_name = '1';
			 player_ = false;
		 }
		 else
		 {
			 game_[row][column] ='O';
			 delete_pair(row, column);
			 player_name = '2';
			 player_ = true;
		 }

		 
			 if ((game_[row][0] == game_[row][1]) && (game_[row][1] == game_[row][2]))
			 {
				 std::cout << "Player " << player_name << " won.\n";
				 return 0;
			 }
			 else if ((game_[0][column] == game_[1][column]) && (game_[1][column] == game_[2][column]))
			 {
				 std::cout << "Player " << player_name << " won.\n";
				 return 0;
			 }
			 else if (((game_[0][0]!=32)&&(game_[1][1]!=32)&& (game_[2][2] != 32))|| ((game_[2][0] != 32)&& (game_[0][2] != 32)&&(game_[1][1]!=32)))
			 {
				 if ((game_[0][0] == game_[1][1]) && (game_[1][1] == game_[2][2]))
				 {
					 std::cout << "Player " << player_name << " won.\n";
					 return 0;
				 }
				 if ((game_[2][0] == game_[1][1]) && (game_[1][1] == game_[0][2]))
				 {
					 std::cout << "Player " << player_name << " won.\n";
					 return 0;
				 }
			 }
			 
			
			 
	 }

	 else
	 {
		 if (player_)
		 {
			 std::cout << "location is full.Try again.\n";
		 }
		 
		 
	 }
	 return 1;
 }

void tic_tac_toe::play()
{
	display_game();

	for (int i = 0; i < 10; i++)
	{
		std::cout << (player_ ? "Player X\n" : "Player O\n");

		std::cin >> row_ >> column_;

		if (row_ < 1 || row_ > 3 || column_ < 1 || column_ > 3)
		{
			std::cout << "Please enter a valid number\n";
			continue;
		}

		system("cls");
		if (!gameplay(row_, column_))
		{
			return;
		}
		display_game();
	}
}

void tic_tac_toe::computer_play()
{
	display_game();
	make_pair();
	
	while(1)
	{
		std::cout << (player_ ? "Player X\n" : "Player O\n");
		
		if (player_)
		{
			std::cin >> row_ >> column_;
		}
		else
		{
			srand(static_cast<unsigned int>(time(nullptr)));
			if (location_vector_.size()!=0)
			{
				int size = location_vector_.size();
				int i = rand() % size;
				row_ = location_vector_[i].first;
				column_ = location_vector_[i].second;
			}
			else
			{
				std::cout << "Draw.\n";
				return;
			}
			
		
		}


		if (row_ < 1 || row_ > 3 || column_ < 1 || column_ > 3)
		{
			if (player_)
			{
				std::cout << "Please enter a valid number\n";
				continue;
			}
			
		}

		system("cls");
		if (!gameplay(row_, column_))
		{
			return;
		}
		
		display_game();

	}
}

void tic_tac_toe::smart_computer_play()
{
	display_game();
	make_pair();
	
	while (1)
	{
		
		std::cout << (player_ ? "Player X\n" : "Player O\n");

		if (player_)
		{
			std::cin >> row_ >> column_;
		}
		else
		{
			auto p = winnable_cases();
			int a = p.first;
			int b = p.second;
			
			if ((a!=-1) && (b!= -1))
			{
				row_ = a;
				column_ = b;
			}
			else
			{
				srand(static_cast<unsigned int>(time(nullptr)));
				if (location_vector_.size() != 0)
				{
					int size = location_vector_.size();
					int i = rand() % size;
					row_ = location_vector_[i].first;
					column_ = location_vector_[i].second;
				}

				else
				{
					std::cout << "Draw.\n";
					return;
				}
			}

		}

		if (row_ < 1 || row_ > 3 || column_ < 1 || column_ > 3)
		{
			if (player_)
			{
				std::cout << "Please enter a valid number\n";
				continue;
			}

		}

		system("cls");
		if (!gameplay(row_, column_))
		{
			return;
		}

		display_game();

	}
}

close_t tic_tac_toe::winnable_cases()

{
	

	int i = 0;
	auto best_pos = std::make_pair(-1, -1);

	while (i < 3)
	{
	//row

		if ((game_[i][0] == game_[i][1]) && game_[i][2] == 32)
		{
			if (game_[i][0] == 'X')
			{
				best_pos.first = i;
				best_pos.second = 2;
			}

			else if (game_[i][0] == 'O')
			{
				best_pos.first = i;
				best_pos.second = 2;
				return best_pos;

			}
		}

		else if ((game_[i][1] == game_[i][2]) && game_[i][0] == 32)
		{
			if (game_[i][1] == 'O')
			{
				best_pos.first = i;
				best_pos.second = 0;
			}

			else if (game_[i][1] == 'O')
			{
				best_pos.first = i;
				best_pos.second = 0;
				return best_pos;
				
			}

		}

		else if ((game_[i][0] == game_[i][2]) && game_[i][1] == 32)
		{
			if (game_[i][0] == 'X')
			{
				best_pos.first = i;
				best_pos.second = 1;
			}

			else if (game_[i][0] == 'O')
			{
				best_pos.first = i;
				best_pos.second = 1;
				return best_pos;

			}

		}

		

	//column

		else if ((game_[0][i] == game_[1][i]) && game_[2][i] == 32)
		{
			if (game_[0][i] == 'X')
			{
				best_pos.first = 2;
				best_pos.second = i;
					
			}

			else if (game_[0][i] == 'O')
			{
				best_pos.first = 2;
				best_pos.second = i;
				return best_pos;
			}

		}

		else if ((game_[1][i] == game_[2][i]) && game_[0][i] == 32)
		{
			if (game_[1][i] == 'X')
			{
				best_pos.first = 0;
				best_pos.second = i;
			}

			else if (game_[1][i] == 'O')
			{
				best_pos.first = 0;
				best_pos.second = i;
				return best_pos;
			}

		}

		else if ((game_[0][i] == game_[2][i]) && game_[1][i] == 32)
		{
			if (game_[0][i] == 'X')
			{
				best_pos.first = 1;
				best_pos.second = i;
				
			}

			else if (game_[0][i] == 'O')
			{
				best_pos.first = 1;
				best_pos.second = i;
				return best_pos;
		
			}

		}

	//diagonal 1

		else if ((game_[0][0] == game_[1][1]) && game_[2][2] == 32)
		{
			if (game_[0][0] == 'X')
			{
				best_pos.first = 2;
				best_pos.second = 2;
			}

			else if (game_[0][0] == 'O')
			{
				best_pos.first = 2;
				best_pos.second = 2;
				return best_pos;
			}
		}

		else if ((game_[1][1] == game_[2][2]) && game_[0][0] == 32)
		{
			if (game_[1][1] == 'X')
			{
				best_pos.first = 0;
				best_pos.second = 0;
					
			}

			else if(game_[1][1] == 'O')
			{
				best_pos.first = 0;
				best_pos.second = 0;
				return best_pos;
			}


		}

		else if ((game_[0][0] == game_[2][2]) && game_[1][1] == 32)
		{
			if (game_[0][0] == 'X')
			{
				best_pos.first = 1;
				best_pos.second = 1;
					
			}

			else if (game_[0][0] == 'O')
			{
				best_pos.first = 1;
				best_pos.second = 1;
				return best_pos;
			}

		}


	//diagonal 2

		else if ((game_[2][0] == game_[1][1]) && game_[0][2] == 32)
		{
			if (game_[2][0] == 'X')
			{
				best_pos.first = 0;
				best_pos.second = 2;
				
			}

			else if(game_[2][0] == 'O')
			{
				best_pos.first = 0;
				best_pos.second = 2;
				return best_pos;
			}

		}

		else if ((game_[1][1] == game_[0][2]) && game_[2][0] == 32)
		{
			if (game_[1][1] == 'X')
			{
				best_pos.first = 2;
				best_pos.second = 0;
					
			}

			else if(game_[1][1] == 'O')
			{
				best_pos.first = 2;
				best_pos.second = 0;
				return best_pos;
			}

		}

		else if ((game_[2][0] == game_[0][2]) && game_[1][1] == 32)
		{
			if (game_[2][0] == 'X')
			{
				best_pos.first = 1;
				best_pos.second = 1;
				return best_pos;
			}

			else if (game_[2][0] == 'O')
			{
				best_pos.first = 1;
				best_pos.second = 1;
				return best_pos;
			}

		}

		i++;
	}

	return best_pos;
	}






	
