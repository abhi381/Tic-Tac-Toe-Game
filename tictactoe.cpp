#include<iostream>
#include <cstdlib>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
string p1,p2;
char turn = 'X';
int row,col;
bool draw=false;


int display()
{
    //DISPLAYING BOARD

    system("cls");
    cout<<"           \t\t    _____  __ __   ____    _____  _____   _____    _____   _____   _____ "<<endl;
    cout<<"           \t\t      |      |    |          |   |     | |           |    |     | |      \n";
    cout<<"           \t\t      |      |    |          |   |_____| |           |    |     | |____  \n";
    cout<<"           \t\t      |      |    |          |   |     | |           |    |     | |      \n";
    cout<<"           \t\t      |    __|__  |____      |   |     | |_____      |    |_____| |_____ \n"<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<p1<<" YOUR SYMBOL IS [X]\n"<<endl;
    cout<<p2<<" YOUR SYMBOL IS [O]"<<endl;
    cout<<"\t\t\t\t\t\t     |     |     "<<endl;
    cout<<"\t\t\t\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"\t\t\t\t\t\t_____|_____|_____"<<endl;
    cout<<"\t\t\t\t\t\t     |     |     "<<endl;
    cout<<"\t\t\t\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"\t\t\t\t\t\t_____|_____|_____"<<endl;
    cout<<"\t\t\t\t\t\t     |     |     "<<endl;
    cout<<"\t\t\t\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
    cout<<"\t\t\t\t\t\t     |     |     "<<endl;
}

void player_turn()
{
    //turn given to the players.
    if(turn == 'X')
        cout<<p1<<" YOUR TURN:\n";

    if(turn == 'O')
        cout<<p2<<" YOUR TURN:\n";
    cin>>choice;
    switch(choice)
    {
case 1:row=0;col=0;break;
case 2:row=0;col=1;break;
case 3:row=0;col=2;break;
case 4:row=1;col=0;break;
case 5:row=1;col=1;break;
case 6:row=1;col=2;break;
case 7:row=2;col=0;break;
case 8:row=2;col=1;break;
case 9:row=2;col=2;break;
default:
    cout<<"\nINVALID INPUT\n";
    }
    if(turn == 'X' && board[row][col]!='X' && board[row][col]!='O')
    {
        board[row][col]='X';
        turn='O';
    }
    else if(turn == 'O' && board[row][col]!='X' && board[row][col]!='O')
    {
    board[row][col]='O';
    turn='X';
    }
    else
    {
        cout<<"\n\nPLEASE TRY AGAIN!!\n";
        player_turn();
    }
    display();
}

bool gameover()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i])
            return false;
    }

    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2] ||board[0][2]==board[1][1]&&board[0][2]==board[2][0])
    {
        return false;
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='X' && board[i][j]!='O')
                return true;
        }
    }
    draw=true;
    return false;
}
int main()
{

    cout<<"           \t\t    _____  __ __   ____    _____  _____   _____    _____   _____   _____ "<<endl;
    cout<<"           \t\t      |      |    |          |   |     | |           |    |     | |      \n";
    cout<<"           \t\t      |      |    |          |   |_____| |           |    |     | |____  \n";
    cout<<"           \t\t      |      |    |          |   |     | |           |    |     | |      \n";
    cout<<"           \t\t      |    __|__  |____      |   |     | |_____      |    |_____| |_____ \n"<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"Player1 ENTER YOUR NAME:\n";
    cin>>p1;

    cout<<endl<<"Player2 ENTER YOUR NAME:\n";
    cin>>p2;

    cout<<endl<<endl<<endl;

    while(gameover())
    {


    display();

    player_turn();

    gameover();

    }

    if(turn == 'X' && draw==false)
    {
        cout<<"\n\n\n\n\n\t\t\t\t\t\t"<<p2<<" WINS!! CONGRATULATIONS!!\n";
    }
    else if(turn == 'O' && draw==false)
    {
        cout<<"\n\n\n\n\n\t\t\t\t\t\t"<<p1<<" WINS!! CONGRATULATIONS!!\n";
    }
    else
    {
        cout<<"\n\n\n\n\n\t\t\t\t\t\t   GAME DRAW!!\n";
    }

}
