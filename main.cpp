#include <bits/stdc++.h>
using namespace std;

int choice;
int row,col;
char turn = 'X';
bool draw = false;


vector<vector<char>> board(3, vector<char>(3, ' '));

void display()
{
    cout << "   0   1   2" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << i << " ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j];
            if (j < 2) cout << "  |";
        }
        cout << endl;
        if (i < 2) cout << "  ***|***|*** " << endl;
    }
}
void display_board()
{
    cout << "   0   1   2" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << i << " ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j];
            if (j < 2) cout << "  |";
        }
        cout << endl;
        if (i < 2) cout << "  ***|***|*** " << endl;
    }
}

bool win(char mark) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
            return true;
        }
    }
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
        return true;
    }
    return false;
}

  bool gameover()
{
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;


    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;


    draw = true;
    return false;
}


bool wins(char mark)
{
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark))
        {
            return true;
        }
    }
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
    {
        return true;
    }
    return false;
}

bool fullboard()
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ') return false;
        }
    }
    return true;
}

pair<int, int> randommove()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int row = rand() % 3;
    int col = rand() % 3;
    return {row, col};
}

int main()
{
    cout<<"T I C  -- T A C -- T O E -- G A M E\n";
    cout<<"\nHello! Hope you are doing well. For some refreshment, let's play a game.\n";
    cout<<"You can play with your friend or computer. Which one will you prefer? "<<endl;
    cout<<"For playing with your friend press 1, Or for playing with computer press 2. Good Luck."<<endl;
    int x;
    cin>>x;
if(x==1)
    {
    int row, col;
    char currentPlayer = 'X';

    while (true) {
        display_board();

        cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Please choose another move." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (win(currentPlayer)) {
            display_board();
            cout << "Congo! Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (fullboard()) {
            display_board();
            cout << "Opps! No one wins! It's a draw" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    }
    else
    {
        int row, col;
    char currentPlayer = 'X';

    while (true)
   {
        display ();

        if (currentPlayer == 'X')
        {
            cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
            cin >> row >> col;

            if (row < 0 && row > 2 || col < 0 && col > 2 || board[row][col] != ' ')
            {
                cout << "Invalid move. Please choose another move." << endl;
                continue;
            }

            board[row][col] = currentPlayer;
        }
      else
        {
            cout << "Computer's turn:" << endl;
            pair<int, int> computerMove = randommove();
            row = computerMove.first;
            col = computerMove.second;

            while (board[row][col] != ' ')
            {
                computerMove = randommove();
                row = computerMove.first;
                col = computerMove.second;
            }

            board[row][col] = currentPlayer;
        }

        if (wins(currentPlayer))
        {
            display();
            if (currentPlayer == 'X')
            {
                cout << "Congo! Player " << currentPlayer << " wins!" << endl;
            } else
            {
                cout << "OMG! Computer wins!" << endl;
            }
            break;
        }

        if (fullboard())
        {
            display();
            cout << "Opps! No one wins! It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    }
}
