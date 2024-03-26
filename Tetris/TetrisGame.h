#ifndef TETRISGAME_H
#define TETRISGAME_H

struct block
{
	int x1, y1, x2, y2, x3, y3, x4, y4;

};
class TetrisGame
{
public:
	TetrisGame();
	~TetrisGame();
	int displayArray;

private:
	char gamearr[15][10];
	block blockarr[15];
};


#endif // !TETRISGAME_H


