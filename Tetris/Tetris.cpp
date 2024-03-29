#include <iostream>
#include "TetrisGame.h"

//issues / ToDo
// Valid rot need to check bounds
// add constants for the constants and test diffrent chars
// add function to generate block type maybe to a queue(for the next blocks display) to gen rand block
// add title screen and gameover screen
// maybe change it so the top 4 rows arnt output( like real game and room for header.
// (maybe) make blockvec in TetrisGame class private
//maybe put a doImput(and sleep) in the else condition of the move (to add last chance move)

int main()
{
    std::cout << "press Enter to start";
    std::cin.get();
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
                Sleep(20);
                chosen.doImput(iter);
                Sleep(20);
                chosen.doImput(iter);
                Sleep(20);
                chosen.displayGameArray();
                Sleep(chosen.waitTime());
                }
            }
        }
        int val = chosen.clearRows();
        chosen.updatescoreYtotalrowcleared(val);
        if (val != 0)
        {
            for (int i = 0; i < 25; i++)
            {
                chosen.moveAllDown();
            }
        }
        chosen.addBlock(0);
        std::cout << "Gameover: " << chosen.gameover << '\n';

        //for (auto iter = chosen.blockvec.begin(); iter != chosen.blockvec.end(); iter++)
        //{
        //    std::cout << "\n \n";
        //   for (int i = 0; i < 4; i++)
        //    {
        //        for (int j = 0; j < 4; j++)
        //        {
        //           std::cout << iter->blockarr[i][j];
        //        }
        //        std::cout << "\n";
        //     }
        //}
    }
 }


