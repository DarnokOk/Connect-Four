#include <iostream>
#include <cstdlib>

using namespace std;

void draw_board(int board_sent[][6])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(board_sent[i][j] == -1)
            {
                cout << ".";
            }
            else
            {
                if(board_sent[i][j] % 2)
                {
                    system("Color 3");
                }
                else
                {
                    system("Color 2");
                }
                cout << "O";
            }
        }
        cout << endl;
    }
}

int main()
{
    int board[7][6];

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            board[i][j] = -1;
        }
    }

    bool play = true;

    system("Color 2");

    do
    {
        draw_board(board);
        play = false;
    }while(play);

    system("pause");

    return 0;
}
