// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TetrisGame.h"

int main()
{
    TetrisGame chosen;
    chosen.addBlock(0);
    chosen.displayGameArray();
    while (!chosen.gameover) 
    {
        for (auto iter = chosen.blockvec.begin(); iter != chosen.blockvec.end(); iter++)
        {
            if (iter->active)
            {
                while (chosen.moveBlock(iter, 2))
                {
                chosen.doImput(iter);
                chosen.doImput(iter);
                chosen.doImput(iter);
                chosen.displayGameArray();
                Sleep(250);
                }
            }
        }
        chosen.addBlock(1);
        std::cout << chosen.gameover << '\n';
    }
 }


