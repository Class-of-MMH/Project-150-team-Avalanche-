#include <bits/stdc++.h>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; 

int choice;
int row,col;
char turn = 'X';
bool draw = false;


void display_board(){


    cout<<"PLAYER - 1 [X] PLAYER - 2 [O]\n";
    cout<<"                      |     |     ";
    cout<<"  "<<board[0][0]<<"  | "<<board[0][1]<<"  |  "<<board[0][2]<<"\n";
    cout<<"_____|_____|_____";
    cout<<"     |     |     ";
    cout<<"  "<<board[1][0]<<"  | "<<board[1][1]<<"  |  "<<board[1][2]<<"\n";
    cout<<"_____|_____|_____";
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

int main()
{
    cout<<"T I C  -- T A C -- T O E -- G A M E\n";
   
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){
        cout<<"Congo! Player 'X' has won the game"<<"\n";
    }
    else if(turn == 'O' && draw == false){
        cout<<"Congo! Player 'O' has won the game"<<"\n";
    }
    else
    cout<<"\nOpps! No one wins! Game is draw!!!"<<"\n";
}
