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
            if(board_sent[j][i] == -1)
            {
                cout << ".";
            }
            else
            {
                if(board_sent[j][i] % 2)
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

void clear_board(int board_sent[][6])
{
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            board_sent[i][j] = -1;
        }
    }
}

int main()
{
    int board[7][6];

    bool play = true;
    bool first_turn = true;
    bool game_started = true;
    bool game_ended;

    short int player = 0;

    do
    {
        if(first_turn)
        {
            if(game_started)
            {
                cout << endl << "Welcome to Connect Four game!" << endl;

                //choose 2 players or AI

                game_started = false;
            }

            clear_board(board);

            game_ended = false;

            first_turn = false;
        }

        bool stalemate = true;

        for(int i = 0; i < 7; i++)
        {
            if(board[i][0] == -1)
            {
                stalemate = false;
                break;
            }
        }

        //check whether someone won

        if(stalemate) game_ended = true;// or if won

        if(game_ended)
        {
            cout << endl << "Here's the final look of the board:" << endl << endl;

            draw_board(board);

            cout << endl;

            if(stalemate)
            {
                cout << endl << "Noone won!" << endl;
            }
            //else if won

            cout << endl << "Decide:"
                 << endl << "1 - rematch"
                 << endl << "2 - back to menu"
                 << endl << "3 - exit"
                 << endl << "Your choice: ";
            short int what_now;
            cin >> what_now;

            //also check if it's an int

            if(what_now > 3 || what_now < 1)
            {
                while(what_now > 3 || what_now < 1)
                {
                    cout << "Invalid input! Choose again:";
                    cin >> what_now;
                }
            }

            switch(what_now)
            {
                case 2:
                    game_started = true;
                case 1:
                    first_turn = true;
                    break;
                case 3:
                    play = false;
                    break;
            }

        }
        else
        {
            cout << endl;

            draw_board(board);

            player = (player + 1) % 2;

            cout << endl << "Your turn \"";

            if(player)
            {
                cout << "O";
            }
            else
            {
                cout << "X";
            }

            cout << "\". Choose a column: ";

            bool wrong_number = true;
            short int choice;
            bool another_try = false;

            do
            {
                if(another_try)
                {
                    cout << "Invalid input! Choose a correct column: ";
                }
                cin >> choice;

                //check whether it is an int at first

                if( (choice > 7 && choice < 1) || (board[choice - 1][0] != -1) )
                {
                    another_try = true;
                }
                else
                {
                    wrong_number = false;
                }

            }while(wrong_number);

            for(int i = 5; i >= 0; i--)
            {
                if(board[choice - 1][i] == -1)
                {
                    board[choice - 1][i] = player;
                    break;
                }
            }
        }

    } while(play);

    cout << endl;

    system("pause");

    return 0;
}
