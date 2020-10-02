#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;
int row,column;
char turn='X';
bool draw;
bool game_over();
int Display_board();
int player_chance();
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int main()
{
	while(game_over()){
 Display_board();  
 player_chance();
 Display_board();
 game_over();
}
if(turn=='0'&&draw==false)
cout<<"player 1 win\n";
else if(turn=='X'&&draw==false)  
cout<<"player 2 win\n";
else
   cout<<"game is draw \n";  
	return 0;
}
bool game_over()
{
	int i,j;
	//game winner.....
	for(i=0;i<3;i++)
	if(board[i][0]==board[i][1]&&board[i][0]==board[i][2] ||board[0][i]==board[1][i]&&board[0][i]==board[2][i])
	return(false);
	
	//diagonal wise.........
	if(board[0][0]==board[1][1]&&board[0][0]==board[2][2] ||board[0][2]==board[1][1]&&board[0][2]==board[2][0])
	return(false);
	
	// game continue.....
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	if(board[i][j]!='X'&&board[i][j]!='0')
	return(true);
	//draw condition
	draw=true;
	return(false);
}
int player_chance()
{ 
	int choice;
	if(turn=='X')
	 cout<<"\n player 1 chance";
	else
	cout<<"\n player 2 chance\n"; 
	cout<<"\n\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			   row=0;column=0;break;
			   case 2:
			   row=0;column=1;break;
			   case 3:
			   row=0;column=2;break;
			   case 4:
			   row=1;column=0;break;
			   case 5:
			   row=1;column=1;break;
			   case 6:
			   row=1;column=2;break;
			   case 7:
			   row=2;column=0;break;
			   case 8:
			   row=2;column=1;break;
			   case 9:
			   row=2;column=2;break;	  
			   default:
			           cout<<"wrong choice \n";
					   break; 	    
	}
	if(turn=='X'){
		board[row][column]='X';
		turn='0';
	}
	else if(turn=='0'){
		board[row][column]='0';
		turn='X';
	}
	
}

int Display_board()
{
	system("cls");
	cout<<"\n Tic Tac Toe \n\n";
	cout<<"player 1[X]  -  player 2[0] \n";
	cout<<endl;
	cout<<"    |     |    "<<endl;
	cout<<"  "<<board[0][0]<<" |  "<<board[0][1]<<"  |  "<<board[0][2]<<" "<<endl;
	cout<<"____|_____|____"<<endl;
	cout<<"  "<<board[1][0]<<" |  "<<board[1][1]<<"  |  "<<board[1][2]<<" "<<endl;
	cout<<"____|_____|____"<<endl;
	cout<<"  "<<board[2][0]<<" |  "<<board[2][1]<<"  |  "<<board[2][2]<<" "<<endl;
	cout<<"    |     |    "<<endl;
}
