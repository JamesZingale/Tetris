#include "TetrisGame.h"

block::block(int type)
{
	topleft_X = 3;
	topleft_Y = 0;
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
void block::transpose()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			std::swap(blockarr[i][j], blockarr[j][i]);
		}
	}
}
void block::reverseRows()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			std::swap(blockarr[i][j], blockarr[i][3-j]);
		}
	}
}
void block::rotateCounterCW()
{
	reverseRows();
	transpose();
}
void block::rotateCW()
{
	transpose();
	reverseRows();
}

TetrisGame::TetrisGame()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gamearr[i][j] = 'O';
		}
	}
}
bool TetrisGame::rotBlock(std::vector<block>::iterator it, int rot)
{
	clearBlock(it);
	if (validRot(it, rot))
	{
		if (rot == -1)
		{
			it->rotateCounterCW();
		}
		if (rot == 1)
		{
			it->rotateCW();
		}
		return 1;
	}
	return 0;

}

void TetrisGame::doImput(std::vector<block>::iterator iter)
{
	if (_kbhit())
	{
		char key = _getch();
		switch (key)
		{
		case 'a': //left
			moveBlock(iter, 3);
			break;
		case 's': // down
			moveBlock(iter, 2);
			break;
		case 'd':
			moveBlock(iter, 1);
			break;
		case 'j': // CCW
			rotBlock(iter, -1);
			break;
		case 'k':
			rotBlock(iter, 1);
			break;
		default:
			break;

		}
	}
}
bool TetrisGame::moveBlock(std::vector<block>::iterator it, int dir)
{
	clearBlock(it);
	int newY, newX;
	switch (dir)
	{
	case 0: // up
		newY = it->topleft_Y - 1;
		newX = it->topleft_X;
		break;
	case 1: // right
		newY = it->topleft_Y;
		newX = it->topleft_X + 1;
		break;
	case 2: // down
		newY = it->topleft_Y + 1;
		newX = it->topleft_X;
		break;
	case 3: // left
		newY = it->topleft_Y;
		newX = it->topleft_X - 1;
		break;
	default:
		newY = it->topleft_Y;
		newX = it->topleft_X;
		break;
	}
	if (validMove(it, dir))
	{
		it->topleft_X = newX;
		it->topleft_Y = newY;
		addBlocktoarr(it);
		return 1;
	}else{
		it->active = 0;
		addBlocktoarr(it);
		return 0;
	}
	
}

// Valid rot need to check bounds
bool TetrisGame::validRot(std::vector<block>::iterator it, int rot)
{
	block temp = block(*it);
	switch (rot)
	{
	case -1: // CCW
		temp.rotateCounterCW();
		break;
	case 1: // CW
		temp.rotateCW();
		break;
	case 0:
		break;
	default:
		break;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (it->blockarr[i][j] == '#')
			{
				if (gamearr[it->topleft_Y + i][it->topleft_X + j] == '#')
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
bool TetrisGame::validMove(std::vector<block>::iterator it, int dir)
{
	block temp = block(*it);
	int newY, newX;
	switch (dir)
	{
	case 0: // up
		newY = temp.topleft_Y - 1;
		newX = temp.topleft_X;
		break;
	case 1: // right
		newY = temp.topleft_Y;
		newX = temp.topleft_X + 1;
		break;
	case 2: // down
		newY = temp.topleft_Y + 1;
		newX = temp.topleft_X;
		break;
	case 3: // left
		newY = temp.topleft_Y;
		newX = temp.topleft_X - 1;
		break;
	default:
		newY = it->topleft_Y;
		newX = it->topleft_X;
		break;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (it->blockarr[i][j] == '#')
			{
				if (gamearr[newY + i][newX + j] == '#' || newY + i > 24 || newY + i < 0 || newX + j > 9 || newX + j < 0)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
void TetrisGame::clearBlock(std::vector<block>::iterator it)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (it->blockarr[i][j] == '#')
			{
				gamearr[it->topleft_Y + i][it->topleft_X + j] = 'O';
			}
		}
	}
}
void TetrisGame::addBlocktoarr(std::vector<block>::iterator it)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (it->blockarr[i][j] == '#')
			{
				gamearr[it->topleft_Y + i][it->topleft_X + j] = '#';
			}
		}
	}
}
void TetrisGame::addBlock(int type)
{
	bool canadd = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (gamearr[0 + i][3 + j] == '#')
			{
				canadd = 0;
			}
		}
	}
	if (canadd)
	{
		blockvec.push_back(block(type));
		addBlocktoarr(blockvec.end() - 1);
	}
	else {
		gameover = 1;
	}
}
void TetrisGame::displayGameArray()
{
	std::cout << '\n';
	std::cout << "|----------|\n";
	for (int i = 0; i < 25; i++) 
	{
		std::cout << '|';
		for (int j = 0; j < 10; j++) 
		{
			std::cout << gamearr[i][j];
		}
		std::cout << "| \n";
	}
	std::cout << "|----------|\n";
	std::cout << "| Score: " << score << "\n";
	std::cout << "| Next Blocks: " << "\n";
	std::cout << "|__________|\n";

}
int TetrisGame::clearRows() 
{
	std::cout << "\n clear rows called \n";
	int clearedcount = 0;
	for (int i = 0; i < 25; i++) {
		bool rowfull = true;
		for (int j = 0; j < 10; j++) {
			if (gamearr[i][j] == 'O') {
				rowfull = false;
				break; // No need to check further if any cell in the row is empty
			}
		}
		if (rowfull) {
			clearedcount++;
			// Clear the row in gamearr
			for (int j = 0; j < 10; j++) {
				gamearr[i][j] = 'O';
			}
			// Clear blockarr of blocks overlapping with this row
			for (auto it = blockvec.begin(); it != blockvec.end(); it++) { //for every block
				if (it->topleft_Y <= i && it->topleft_Y + 3 >= i) {     // if i could be in range of block area
					for (int k = 0; k < 4; k++) {           // then check every block
						for (int l = 0; l < 4; l++) {
							if (it->blockarr[i - it->topleft_Y][l] == '#') {
								it->blockarr[i - it->topleft_Y][l] = '-';
							}
						}
					}
				}
			}
		}
	}
	return clearedcount;
}
void TetrisGame::moveAllDown()
{

	for (auto iter = blockvec.begin(); iter != blockvec.end(); iter++)
	{
		moveBlock(iter, 2);

	}
}
void TetrisGame::updatescoreYtotalrowcleared(int rowscleared)
{
	int add = 0;
	switch (rowscleared)
	{
	case 0:
		add = 0;
		break;
	case 1:
		add = 250;
		break;
	case 2:
		add = 500;
		break;
	case 3:
		add = 900;
		break;
	case 4:
		add = 1500;
	}
	if (rowscleared > 4)
	{
		add = 2500;
	}
	score += add;
	totalrowscleared += rowscleared;
}
int TetrisGame::waitTime()
{
	int temp = 275 - totalrowscleared;
	if (temp > 100)
	{
		return temp;
	}
	else {
		return 100;
	}
}