#include <iostream>
using namespace std;

char board[3][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard()
{
    cout << "\n";
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "--|---|--" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "--|---|--" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

int checkWin()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return 1;

        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return 1;
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return 1;

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return 1;

    return 0;
}

int main()
{
    int player = 1;
    int choice;
    char mark;
    int moves = 0;

    while(moves < 9)
    {
        displayBoard();

        if(player == 1)
            mark = 'X';
        else
            mark = 'O';

        cout << "Player " << player << " Enter Position (1-9): ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                if(board[0][0]=='1') board[0][0]=mark;
                else continue;
                break;

            case 2:
                if(board[0][1]=='2') board[0][1]=mark;
                else continue;
                break;

            case 3:
                if(board[0][2]=='3') board[0][2]=mark;
                else continue;
                break;

            case 4:
                if(board[1][0]=='4') board[1][0]=mark;
                else continue;
                break;

            case 5:
                if(board[1][1]=='5') board[1][1]=mark;
                else continue;
                break;

            case 6:
                if(board[1][2]=='6') board[1][2]=mark;
                else continue;
                break;

            case 7:
                if(board[2][0]=='7') board[2][0]=mark;
                else continue;
                break;

            case 8:
                if(board[2][1]=='8') board[2][1]=mark;
                else continue;
                break;

            case 9:
                if(board[2][2]=='9') board[2][2]=mark;
                else continue;
                break;

            default:
                cout << "Invalid Choice!\n";
                continue;
        }

        moves++;

        if(checkWin())
        {
            displayBoard();
            cout << "Player " << player << " Wins!\n";
            return 0;
        }

        if(player == 1)
            player = 2;
        else
            player = 1;
    }

    displayBoard();
    cout << "Match Draw!\n";

    return 0;
}