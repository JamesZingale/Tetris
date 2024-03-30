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
                chosen.doImput(iter);
                Sleep(30);
                chosen.doImput(iter);
                Sleep(30);
                chosen.doImput(iter);
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
        chosen.addBlock(chosen.getnextBlockType());
    }
    chosen.gameoverscreen();
 }


