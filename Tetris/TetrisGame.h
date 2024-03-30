#ifndef TETRISGAME_H
#define TETRISGAME_H

#include <ctime>
#include <vector>
#include <iostream>
#include <windows.h>
#include <conio.h>


const char BLOCKCHAR = '#';
const char BACKCHAR = ' ';


class block{
public:
	block(int type);
	void transpose();
	void reverseRows();
	void rotateCounterCW();
	void rotateCW();
	bool active;
	int topleft_Y, topleft_X;
	int blocktype;
	char blockarr[4][4];
};

class TetrisGame{
public:
	TetrisGame();
	int waitTime();
	int clearRows();
	bool moveBlock(std::vector<block>::iterator it, int dir, bool mainMove);
	bool rotBlock(std::vector<block>::iterator it, int rot);
	bool validRot(std::vector<block>::iterator it, int rot);
	bool validMove(std::vector<block>::iterator it, int dir);
	void updatescoreYtotalrowcleared( int rowscleared);
	void doImput(std::vector<block>::iterator iter);
	void moveAllDown();
	void displayGameArray();
	void clearBlock(std::vector<block>::iterator it);
	void addBlocktoarr(std::vector<block>::iterator it);
	void addBlock(int type);
	void startscreen();
	void gameoverscreen();
	int randomnum();
	int getnextBlockType();
	void setnextBlockType( int num);
	void outputblock(int type);
	bool  gameover = 0;
	std::vector<block> blockvec;

private:
	char nextBlockType;
	char gamearr[25][10];
	int score;
	int totalrowscleared;
};

#endif // !TETRISGAME_H


