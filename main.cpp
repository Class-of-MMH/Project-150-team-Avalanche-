#include<bits/stdc++.h>

using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int main(){
  for(int i=0; i<9; i++){
    board draw();
    move();
    switching();
  }
  board draw();
  cout<<"Opps no one wins! It's a draw! "<<endl;
  return 0;  
}
