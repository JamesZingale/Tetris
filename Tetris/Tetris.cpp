// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TetrisGame.h"

int main()
{
    TetrisGame chosen;
    chosen.displayGameArray();

    for (int typee = 0; typee < 7; typee++)
    {
        std::cout << '\n';
        std::cout << '\n';
        block test(typee);
        for (int i = 0; i < 4; i++)
        {
            std::cout << '\n';
            for (int j = 0; j < 4; j++)
            {
                std::cout << test.blockarr[i][j];
            }
        }
    }
  }


