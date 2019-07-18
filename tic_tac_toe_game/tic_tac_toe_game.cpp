#include "pch.h"
#include <iostream>
#include <string>
#include "implementation.h"

int main()
{
	tic_tac_toe* ttt = new tic_tac_toe();
	ttt->smart_computer_play();
	delete ttt;
	return 0;
}
