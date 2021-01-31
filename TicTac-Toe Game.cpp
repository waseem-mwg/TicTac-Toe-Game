#include<bits/stdc++.h>
using namespace std;
char interface_number[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
bool d=false;
int row,col;
void show_interface()
{
	system("cls");
	cout<<"\n\n\t-----T i c - T a c   T o e   G a m e-----\n\n\tPlayer1 [X]\n\tPlayer2 [O]\n\n\n";
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t\t  "<<interface_number[0][0]<<"  |  "<<interface_number[0][1]<<"  |  "<<interface_number[0][2]<<"  \n";
	cout<<"\t\t\t_____|_____|_____\n";
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t\t  "<<interface_number[1][0]<<"  |  "<<interface_number[1][1]<<"  |  "<<interface_number[1][2]<<"  \n";
	cout<<"\t\t\t_____|_____|_____\n";
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t\t  "<<interface_number[2][0]<<"  |  "<<interface_number[2][1]<<"  |  "<<interface_number[2][2]<<"  \n";
	cout<<"\t\t\t     |     |     \n\n";
}
void define_turn()
{
	int choice;
	if(turn=='X')
		cout<<"\tPlayer1 [X] turn: ";
	else
		cout<<"\tPlayer2 [O] turn: ";
	cin>>choice;
	switch(choice)
	{
		case 1: row=0;
				col=0;
				break;
		case 2: row=0;
				col=1;
				break;
		case 3: row=0;
				col=2;
				break;
		case 4: row=1;
				col=0;
				break;
		case 5: row=1;
				col=1;
				break;
		case 6: row=1;
				col=2;
				break;
		case 7: row=2;
				col=0;
				break;
		case 8: row=2;
				col=1;
				break;
		case 9: row=2;
				col=2;
				break;
		default: cout<<"\t----------Invalid Choice----------\n\n";
				 break;
	}
	if(turn=='X'&&interface_number[row][col]!='X'&&interface_number[row][col]!='O')
	{
		interface_number[row][col]='X';
		turn='O';
	}
	else if(turn=='O'&&interface_number[row][col]!='X'&&interface_number[row][col]!='O')
	{
		interface_number[row][col]='O';
		turn='X';
	}
	else
	{
		cout<<"\n\tEnter Valid Choice!\n\tTry Again!!\n\n";
		define_turn();
	}
	show_interface();
}
bool result()
{
	for(int i=0;i<3;i++)
	{
		if(interface_number[i][0]==interface_number[i][1]&&interface_number[i][0]==interface_number[i][2]||interface_number[0][i]==interface_number[1][i]&&interface_number[0][i]==interface_number[2][i])
			return true;
	}
	if(interface_number[0][0]==interface_number[1][1]&&interface_number[0][0]==interface_number[2][2]||interface_number[0][2]==interface_number[1][1]&&interface_number[2][0]==interface_number[0][2])
		return true;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(interface_number[i][j]!='X'&&interface_number[i][j]!='O')
				return false;
		}
	}
	d=true;
	return true;
}
int main()
{
	while(!result())
	{
		show_interface();
		define_turn();
		result();
	}
	if(turn=='X'&&d==false)
		cout<<"\t-----Congratulations! Player2 [O] Won-----\n";
	else if(turn=='O'&&d==false)
		cout<<"\t-----Congratulations! Player1 [X] Won-----\n";
	else
		cout<<"\t-----Game is DRAW-----\n";
		
}
