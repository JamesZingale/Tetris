#ifndef TETRISGAME_H
#define TETRISGAME_H

#include <vector>
#include <iostream>
#include <windows.h>
#include <conio.h>


class block{
public:
	void transpose();
	void reverseRows();
	void rotateCounterCW();
	void rotateCW();
	bool active;
	int topleft_Y, topleft_X;
	int blocktype;
	block(int type);
	char blockarr[4][4];
};

class TetrisGame{
public:
	bool activeblock, gameover = 0;
	std::vector<block> blockvec;
	TetrisGame();
	void doImput(std::vector<block>::iterator iter);
	void displayGameArray();
	bool moveBlock(std::vector<block>::iterator it, int dir);
	bool rotBlock(std::vector<block>::iterator it, int rot);
	void clearBlock(std::vector<block>::iterator it);
	void addBlocktoarr(std::vector<block>::iterator it);
	void addBlock(int type);
	bool validRot(std::vector<block>::iterator it, int rot);
	bool validMove(std::vector<block>::iterator it, int dir);
private:
	char gamearr[25][10];
};

#endif // !TETRISGAME_H


