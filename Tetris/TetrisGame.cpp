#include "TetrisGame.h"

block::block(int type)
{
	topleft_X = -1;
	topleft_Y = -1;
	blocktype = type;
	active = 1;

	for(int i = 0; i < 4; i++)
	{
		 for (int j = 0; j < 4; j++)
		 {
			 blockarr[i][j] = '-';
		 }
	}

	switch (type){
	case 0: // line block (|)
		blockarr[1][0] = '#';
		blockarr[1][1] = '#';
		blockarr[1][2] = '#';
		blockarr[1][3] = '#';
		break;
	case 1: // Backwards L block
		blockarr[1][1] = '#';
		blockarr[2][1] = '#';
		blockarr[2][2] = '#';
		blockarr[2][3] = '#';
		break;
	case 2: // L block
		blockarr[1][2] = '#';
		blockarr[2][0] = '#';
		blockarr[2][1] = '#';
		blockarr[2][2] = '#';
		break;
	case 3: // Square block
		blockarr[1][1] = '#';
		blockarr[1][2] = '#';
		blockarr[2][1] = '#';
		blockarr[2][2] = '#';
		break;
	case 4: //  S block
		blockarr[1][1] = '#';
		blockarr[1][2] = '#';
		blockarr[2][0] = '#';
		blockarr[2][1] = '#';
		break;
	case 5: // Z block
		blockarr[1][1] = '#';
		blockarr[1][2] = '#';
		blockarr[2][2] = '#';
		blockarr[2][3] = '#';
		break;
	case 6: // T block
		blockarr[1][1] = '#';
		blockarr[2][0] = '#';
		blockarr[2][1] = '#';
		blockarr[2][2] = '#';
		break;
	default:
		break;
	}
}

TetrisGame::TetrisGame()
{
	for (int i = 5; i < 25; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gamearr[i][j] = ' ';
		}
	}
}

void TetrisGame::addBlock(int type)
{

}
void TetrisGame::moveBlockDown(block curBlock)
{

}

void TetrisGame::displayGameArray()
{
	for (int i = 0; i < 25; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			std::cout << gamearr[i][j];
		}
		std::cout << "\n";
	}
}
