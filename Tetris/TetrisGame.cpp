#include "TetrisGame.h"

block::block()
{
	topleft_X = -1;
	topleft_Y = -1;
	blocktype = -1;
	inplay = 0;
	active = 0;
	for(int i = 0; i < 4; i++)
	{
		 for (int j = 0; j < 4; j++)
		{
			 blockarr[i][j] = '#';
		}
	}
}

TetrisGame::TetrisGame()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gamearr[i][j] = '#';
		}
	}

}

void TetrisGame::displayGameArray()
{
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << gamearr[i][j];
		}
		std::cout << "\n";
	}
}
