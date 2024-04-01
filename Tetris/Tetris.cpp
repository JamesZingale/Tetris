#include "TetrisGame.h"

int main()
{
    srand(time(0));
    TetrisGame chosen;
    chosen.startscreen();
    chosen.addBlock(chosen.randomnum());
    chosen.displayGameArray();
    while (!chosen.gameover) 
    {
        chosen.setnextBlockType(chosen.randomnum());
        for (auto iter = chosen.blockvec.begin(); iter != chosen.blockvec.end(); iter++)
        {
            if (iter->active)
            {
                while (chosen.moveBlock(iter, 2, 1))
                {
                chosen.moveAllDown();
                chosen.doImput(iter);
                Sleep(30);
                chosen.doImput(iter);
                Sleep(30);
                chosen.doImput(iter);
                system("cls");
                chosen.displayGameArray();
                Sleep(chosen.waitTime());
                }
            }
        }
        int val1 = chosen.clearRows();
        if (val1 != 0)
        {
            for (auto iter = chosen.blockvec.begin(); iter != chosen.blockvec.end(); iter++)
            {
                chosen.splitblock(iter);
            }
        }
        chosen.updatescoreYtotalrowcleared(val1);
       
        chosen.addBlock(chosen.getnextBlockType());
    }
    chosen.gameoverscreen();
 }


