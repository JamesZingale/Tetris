#ifndef TETRISGAME_H
#define TETRISGAME_H

#include <vector>
#include <iostream>


class block
{
public:
	//functions for transpose, reverse row, -> rotate counter-clw/clw
	// 
	//clear row (have it call on all blocks but only do it based on top left y)

	int topleft_Y, topleft_X;
	bool active;
	int blocktype;
	block();
	~block();
	char blockarr[5][5];
};


class TetrisGame
{
public:
	TetrisGame();
	~TetrisGame();
	void displayGameArray();
	void addblock(int type);
	char gamearr[25][10];
	//some function to generate random string of new blocks
	//

private:
	std::vector<block> blockvec;
};


#endif // !TETRISGAME_H


