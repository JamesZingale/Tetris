#ifndef TETRISGAME_H
#define TETRISGAME_H

#include <vector>
#include <iostream>


class block{
public:
	//function for clear row (have it call on all blocks but only do it based on top left y)
	void transpose();
	void reverseRows();
	void rotateCounterCW();
	void rotateCW();
	//int leftmostCol();      // returns leftmost col of block on main arr using topleft y/x
	//int rightmostCol();     // returns leftmost col of block on main arr using topleft y/x
	//int bottommostRow();    // returns leftmost col of block on main arr using topleft y/x

	int topleft_Y, topleft_X;
	bool active;
	int blocktype;
	block(int type);
	char blockarr[4][4];
};

class TetrisGame{
public:
	TetrisGame();
	void addBlockstoGameArr();
	void displayGameArray();
	void addBlock(int);
	void updateBlockPos(std::vector<block>::iterator, int rot, int dir);

	//some function to generate random string of new blocks
private:
	char gamearr[25][10];
	std::vector<block> blockvec;
};

#endif // !TETRISGAME_H


