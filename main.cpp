#include<iostream>

//FUNCTION DECLARATION
void printBoard();
void playerInput();
bool gameCheck();

//GLOBAL VARIABLES
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int rows{0};
int columns{0};
char token='x';
std::string p1=" ";
std::string p2=" ";
bool draw=false;

int main(){

    std::cout<<"Welcome! Let Play Tic-Tac-Toe : "<<std::endl;
    std::cout<<"************ > TIC TAC TOE < ************"<<std::endl;
    printBoard();
    std::cout<<"Enter the Name of the 1st Player -> ";
    getline(std::cin,p1);
    std::cout<<"\nEnter the Name of the 2nd Player -> ";
    getline(std::cin,p2);
    std::cout<<std::endl;

    std::cout<<"Player 1 is "<<p1<<", so he will start the game "<<std::endl;
    std::cout<<"Player 2 is "<<p2<<", so he will be next "<<std::endl;

    while(!gameCheck()){
        printBoard();
        playerInput();
        gameCheck();
    }

    if(token=='x' && !draw){
        std::cout<<p2<<" wins the GAME of TIC TAC TEO ! :)"<<std::endl;
    }
    else if(token=='o' && !draw){
        std::cout<<p1<<" wins the GAME of TIC TAC TEO ! :)"<<std::endl;
    }

    return 0;
}

//Prints The Board
void printBoard(){

    std::cout<<"     "<<board[0][0]<<" \t |   "<<board[0][1]<<" \t |   "<<board[0][2]<<" \t  "<<std::endl;
    std::cout<<" "<<" -------|"<<"-------|--------"<<std::endl;
    std::cout<<"     "<<board[1][0]<<" \t |   "<<board[1][1]<<" \t |   "<<board[1][2]<<" \t  "<<std::endl;
    std::cout<<" "<<" -------|"<<"-------|--------"<<std::endl;
    std::cout<<"     "<<board[2][0]<<" \t |   "<<board[2][1]<<" \t |   "<<board[2][2]<<" \t   "<<std::endl;
    std::cout<<std::endl;
}

//Take Input from players
void playerInput(){

    int digit;

    if(token=='x'){
        std::cout<<p1<<" Its Your Turn Please Enter : -> ";
        std::cin>>digit;
    }
    if(token=='o'){
        std::cout<<p2<<" Its Your Turn Please Enter : -> ";
        std::cin>>digit;
    }

    switch (digit) {
        case 1:rows=0;columns=0;break;
        case 2:rows=0;columns=1;break;
        case 3:rows=0;columns=2;break;
        case 4:rows=1;columns=0;break;
        case 5:rows=1;columns=1;break;
        case 6:rows=1;columns=2;break;
        case 7:rows=2;columns=0;break;
        case 8:rows=2;columns=1;break;
        case 9:rows=2;columns=2;break;
        default:std::cout<<"Please Enter a Valid Choice(0-9)"<<std::endl;
    }
    if(token=='x' && board[rows][columns]!='x' && board[rows][columns]!='o'){
        board[rows][columns]='x';
        token='o';
    }
    else if(token=='o' && board[rows][columns]!='x' && board[rows][columns]!='o'){
        board[rows][columns]='o';
        token='x';
    }

    printBoard();
}

//Checks if all boxes are filled or any pattern is found
bool gameCheck(){

    for(int i{0};i<3;i++){
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2]
        || board[0][i]==board[1][i] && board[0][i]==board[2][i]){
            return true;
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] || board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        return true;
    }

    //Checking if Game is still going on or not
    for(int i{0};i<3;i++){
        for(int j{0};j<3;j++){
            if(board[i][j]!='x' && board[i][j]!='o'){
                return false;
            }
        }
    }
    draw=true;
    std::cout<<"The Game IS DRAW!"<<std::endl;
    return true;
}
