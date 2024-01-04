#include <bits/stdc++.h>
using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int choice;
int row,col;
char turn = 'X';
bool draw = false;


vector<vector<char>> comboard(3, vector<char>(3, ' '));

void display() {
    cout << "   0  1  2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << comboard[i][j];
            if (j < 2) cout << " |";
        }
        cout << endl;
        if (i < 2) cout << "  --------  " << endl;
    }
}
void display_board(){


    cout<<"PLAYER - 1 [X] PLAYER - 2 [O]\n";
    cout<<"                      |     |     ";
    cout<<"  "<<board[0][0]<<"  | "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
    cout<<"_|_|_";
    cout<<"     |     |     ";
    cout<<"  "<<board[1][0]<<"  | "<<board[1][1]<<"  |  "<<board[1][2]<<"\n";
    cout<<"_|_|_";
    cout<<"     |     |     ";
    cout<<"  "<<board[2][0]<<"  | "<<board[2][1]<<"  |  "<<board[2][2]<<"\n";
    cout<<"     |     |     ";
}

void player_turn(){
    if(turn == 'X'){
        cout<<"\nPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\nPlayer - 2 [O] turn : ";
    }
    cin>> choice;

    switch(choice){
        case 1: row=0; col=0; break;
        case 2: row=0; col=1; break;
        case 3: row=0; col=2; break;
        case 4: row=1; col=0; break;
        case 5: row=1; col=1; break;
        case 6: row=1; col=2; break;
        case 7: row=2; col=0; break;
        case 8: row=2; col=1; break;
        case 9: row=2; col=2; break;
        default:
            cout<<"Invalid Move";
    }
    if(turn == 'X' &&board[row][col] != 'X' && board[row][col] != 'O'){

        board[row][col] = 'X';
        turn = 'O';


    }
    else if(turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O'){

        board[row][col] = 'O';
        turn = 'X';

    }
    else {

        cout<<"invalid turn!!please turn another";
        player_turn();
    }

    display_board();
}

  bool gameover(){
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


bool wins(char mark) {
    for (int i = 0; i < 3; ++i) {
        if ((comboard[i][0] == mark && comboard[i][1] == mark && comboard[i][2] == mark) ||
            (comboard[0][i] == mark && comboard[1][i] == mark && comboard[2][i] == mark)) {
            return true;
        }
    }
    if ((comboard[0][0] == mark && comboard[1][1] == mark && comboard[2][2] == mark) ||
        (comboard[0][2] == mark && comboard[1][1] == mark && comboard[2][0] == mark)) {
        return true;
    }
    return false;
}

bool fullboard() {
    for (const auto &row : comboard) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

pair<int, int> randommove() {
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
if(x==1){
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'O' && draw == false){
        cout<<"\nCongo! Player 'X' has won the game"<<"\n";
    }
    else if(turn == 'X' && draw == false){
        cout<<"\nCongo! Player 'O' has won the game"<<"\n";
    }
    else
    cout<<"\nOpps! No one wins! Game is draw!!!"<<"\n";
    }
    else{
        int row, col;
    char currentPlayer = 'X';

    while (true) {
        display ();

        if (currentPlayer == 'X') {
            cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
            cin >> row >> col;

            if (row < 0  row > 2  col < 0  col > 2  comboard[row][col] != ' ') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            comboard[row][col] = currentPlayer;
        } else {
            cout << "Computer's turn:" << endl;
            pair<int, int> computerMove = randommove();
            row = computerMove.first;
            col = computerMove.second;

            while (comboard[row][col] != ' ') {
                computerMove = randommove();
                row = computerMove.first;
                col = computerMove.second;
            }

            comboard[row][col] = currentPlayer;
        }

        if (wins(currentPlayer)) {
            display();
            if (currentPlayer == 'X') {
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else {
                cout << "Computer wins!" << endl;
            }
            break;
        }

        if (fullboard()) {
            display();
            cout << "It's a tie!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    }
}
