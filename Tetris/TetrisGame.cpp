#include "TetrisGame.h"

TetrisGame::TetrisGame()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gamearr[i][j] = ' ';
		}
	}

}

void TetrisGame::displayGameArray()
{
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << gamearr[i][j];
		}
	}
}
