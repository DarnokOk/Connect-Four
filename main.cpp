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
                    cout << "O";
                }
                else
                {
                    cout << "X";
                }
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

    short int player = 0;

    do
    {
        draw_board(board);

        player = (player + 1) % 2;

        cout << endl << "Your turn ";

        if(player)
        {
            cout << "O";
        }
        else
        {
            cout << "X";
        }

        if(true)//game done and they dont want to play anymore
        {
            play = false;
        }

    } while(play);

    cout << endl;
    system("pause");

    return 0;
}
