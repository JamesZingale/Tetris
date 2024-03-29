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
	bool  gameover = 0;
	std::vector<block> blockvec;
	TetrisGame();
	int waitTime();
	void updatescoreYtotalrowcleared( int rowscleared);
	void doImput(std::vector<block>::iterator iter);
	int clearRows();
	void moveAllDown();
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
	int score;
	int totalrowscleared;
};

#endif // !TETRISGAME_H


