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
			 blockarr[i][j] = BACKCHAR;
		 }
	}

	switch (type){
	case 0: // line block (|)
		blockarr[1][0] = BLOCKCHAR;
		blockarr[1][1] = BLOCKCHAR;
		blockarr[1][2] = BLOCKCHAR;
		blockarr[1][3] = BLOCKCHAR;
		break;
	case 1: // Backwards L block
		blockarr[1][1] = BLOCKCHAR;
		blockarr[2][1] = BLOCKCHAR;
		blockarr[2][2] = BLOCKCHAR;
		blockarr[2][3] = BLOCKCHAR;
		break;
	case 2: // L block
		blockarr[1][2] = BLOCKCHAR;
		blockarr[2][0] = BLOCKCHAR;
		blockarr[2][1] = BLOCKCHAR;
		blockarr[2][2] = BLOCKCHAR;
		break;
	case 3: // Square block
		blockarr[1][1] = BLOCKCHAR;
		blockarr[1][2] = BLOCKCHAR;
		blockarr[2][1] = BLOCKCHAR;
		blockarr[2][2] = BLOCKCHAR;
		break;
	case 4: //  S block
		blockarr[1][1] = BLOCKCHAR;
		blockarr[1][2] = BLOCKCHAR;
		blockarr[2][0] = BLOCKCHAR;
		blockarr[2][1] = BLOCKCHAR;
		break;
	case 5: // Z block
		blockarr[1][1] = BLOCKCHAR;
		blockarr[1][2] = BLOCKCHAR;
		blockarr[2][2] = BLOCKCHAR;
		blockarr[2][3] = BLOCKCHAR;
		break;
	case 6: // T block
		blockarr[1][1] = BLOCKCHAR;
		blockarr[2][0] = BLOCKCHAR;
		blockarr[2][1] = BLOCKCHAR;
		blockarr[2][2] = BLOCKCHAR;
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
	nextBlockType = -1;
	score = 0;
	totalrowscleared = 0;
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			gamearr[i][j] = BACKCHAR;
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
	addBlocktoarr(it);
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
			moveBlock(iter, 3, 0);
			break;
		case 's': // down
			moveBlock(iter, 2, 0);
			break;
		case 'd':
			moveBlock(iter, 1, 0);
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
bool TetrisGame::moveBlock(std::vector<block>::iterator it, int dir, bool mainMove)
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
		if (mainMove)
		{
		it->active = 0;
		}
		addBlocktoarr(it);
		return 0;
	}
	
}
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
			if (temp.blockarr[i][j] == BLOCKCHAR)
			{
				
				if(gamearr[temp.topleft_Y + i][temp.topleft_X + j] == BLOCKCHAR || temp.topleft_Y + i < 0 || temp.topleft_Y + i > 24 || temp.topleft_X + j > 9|| temp.topleft_X + j < 0)
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
			if (it->blockarr[i][j] == BLOCKCHAR)
			{
				if (gamearr[newY + i][newX + j] == BLOCKCHAR || newY + i > 24 || newY + i < 0 || newX + j > 9 || newX + j < 0)
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
			if (it->blockarr[i][j] == BLOCKCHAR)
			{
				gamearr[it->topleft_Y + i][it->topleft_X + j] = BACKCHAR;
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
			if (it->blockarr[i][j] == BLOCKCHAR)
			{
				gamearr[it->topleft_Y + i][it->topleft_X + j] = BLOCKCHAR;
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
			if (gamearr[0 + i][3 + j] == BLOCKCHAR)
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
	std::cout << "|  TETRIS  |\n";
	std::cout << "|----------|\n";
	for (int i = 4; i < 25; i++) 
	{
		std::cout << '|';
		for (int j = 0; j < 10; j++) 
		{
			std::cout << gamearr[i][j];
		}
		std::cout << "| \n";
	}
	std::cout << "|----------|\n";
	std::cout << "Score: " << score << "\n";
	std::cout << "Next Block: \n";
	outputblock(nextBlockType);

}
int TetrisGame::clearRows()
{
	int clearedcount = 0;
	for (int i = 0; i < 25; i++) {
		bool rowfull = true;
		for (int j = 0; j < 10; j++) {
			if (gamearr[i][j] == BACKCHAR) {
				rowfull = false;
				break; // No need to check further if any cell in the row is empty
			}
		}
		if (rowfull) {
			clearedcount++;
			// Clear the row in gamearr
			for (int j = 0; j < 10; j++) {
				gamearr[i][j] = BACKCHAR;
			}
			// Clear blockarr of blocks overlapping with this row
			for (auto it = blockvec.begin(); it != blockvec.end(); it++) {
				for (int k = 0; k < 4; k++) {
					int blockRow = it->topleft_Y + k;
					if (blockRow == i) { // Block row matches cleared row
						for (int l = 0; l < 4; l++) {
							if (it->blockarr[k][l] == BLOCKCHAR) {
								it->blockarr[k][l] = BACKCHAR;
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
		moveBlock(iter, 2, 0);

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
	int temp = 200 - totalrowscleared;
	if (temp > 100)
	{
		return temp;
	}
	else {
		return 100;
	}
}
void TetrisGame::startscreen()
{
std::cout <<    "|----------------------------------------------------------------------------------|\n"
				"|         TTTTTTTTT   EEEEEEE   TTTTTTTTT   RRRRRR     IIIIIII    SSSSSSS          |\n"
				"|             T       E             T       R      R      I      S                 |\n"
				"|             T       EEEEE         T       RRRRRR        I       SSSSSS           |\n"
				"|             T       E             T       R    R        I             S          |\n"
				"|             T       EEEEEEE       T       R      R   IIIIIII   SSSSSSS           |\n"
				"|----------------------------------------------------------------------------------|\n"
				"| Instructions:                                                                    |\n"
				"|----------------------------------------------------------------------------------|\n"
				"|1: Move the falling blocks into position with A/S/D keys for left/down/right.     |\n"
	            "|2: Rotate the blocks counter-clockwise/clockwise with J/K keys                    |\n"
	            "|3: When a row is filled it will be cleared and the score will increase            |\n"
	            "|4: Plan your next move using the information from 'next block' section            |\n"
				"|----------------------------------------------------------------------------------|\n"
	            "|                         Press 'Enter' to start the game:                         |\n"
                "|----------------------------------------------------------------------------------|";
	std::cin.get();
}
void TetrisGame::gameoverscreen()
{
std::cout <<"|----------------------------------------------------------------------------------|\n"
			"|  GGGGGG       A       M     M   EEEEEE       OOOOO   V       V  EEEEEE   RRRRRR  |\n"
			"| G            A A      MM   MM   E           O     O   V     V   E        R     R |\n"
			"| G   GGG     AAAAA     M M M M   EEEEE       O     O    V   V    EEEEE    RRRRRR  |\n"
			"| G     G    A     A    M  M  M   E           O     O     V V     E        R    R  |\n"
			"|  GGGGG    A       A   M     M   EEEEEE       OOOOO       V      EEEEEE   R     R |\n"
			"|----------------------------------------------------------------------------------|\n"
			"| final score:                                                                     |\n"
			"|----------------------------------------------------------------------------------|\n"
			"| Score:" << score << "\n"
			"|----------------------------------------------------------------------------------|\n";
}
int TetrisGame::randomnum()
{
	return rand() % 7;
}
int TetrisGame::getnextBlockType()
{
	return nextBlockType;
}
void TetrisGame::setnextBlockType(int num)
{
	nextBlockType = num;
}
void TetrisGame::outputblock(int type)
{
	block temp(type);
	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			std::cout << temp.blockarr[i][j];
		}
		if (i == 1)
		{
			std::cout << "\n";
		}
	}
}