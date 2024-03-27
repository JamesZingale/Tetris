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
	bool inplay, active;
	int blocktype;
	block();
	char blockarr[4][4];
};


class TetrisGame
{
public:
	TetrisGame();
	void displayGameArray();
	void addblock(int type);

	//some function to generate random string of new blocks
	//

private:
	char gamearr[25][10];
	std::vector<block> blockvec{ 50 };
};


#endif // !TETRISGAME_H


