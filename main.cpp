#include <iostream>
#include <cstdlib>

using namespace std;

void draw_board(int board_sent[][6])
{
    for(int i = 0; i < 7; i ++)
    {
        cout << "| " << i + 1 << " ";
    }

    cout << "|" << endl;

    for(int o = 0; o < 29; o++)
    {
        cout << "-";
    }
    cout << endl;
    for(int i = 0; i < 6; i++)
    {
        cout << "| ";
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
            cout << " |";
            if(j != 6)
            {
                cout << " ";
            }
        }
        cout << endl;
        for(int o = 0; o < 29; o++)
        {
            cout << "-";
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
    bool first_turn = true;
    short int player = 0;

    do
    {
        if(first_turn)
        {
            cout << "Welcome to Connect Four game!" << endl << endl;
            first_turn = false;
        }

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

        cout << " choose a row: ";

        bool wrong_number = true;
        int choice;
        bool another_try = false;

        do
        {
            if(another_try)
            {
                cout << "Invalid input! Choose a row: ";
            }
            cin >> choice;
            if(choice < 7 && choice > 0)
            {
                wrong_number = false;
            }//here also if for the rows that are full
            else
            {
                another_try = true;
            }

        }while(wrong_number);

        //here we have choice and we should add it to the board

        //then check whether someone won, it's still in progress or that it's a stalemate

        if(true)//game done and they dont want to play anymore
        {
            play = false;
        }

    } while(play);

    cout << endl;
    system("pause");

    return 0;
}
