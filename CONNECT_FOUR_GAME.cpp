#include <iostream>                            // Inamullah khan and Muhammad Amir. Game name is Connect four.
using namespace std;

class playerInfo{
	public:
	string playerName;
	char playerID;
};

class ConnectFour: public playerInfo{
	public:
//								Protype of Functions

	int PlayerDrop(char board[][10], playerInfo activePlayer);
	
	void CheckBellow (char board[][10], playerInfo activePlayer, int dropChoice);
	
	void DisplayBoard (char board[][10]);
	
	int CheckFour (char board[][10], playerInfo activePlayer);
	
	int FullBoard(char board[][10]);
	
	void PlayerWin (playerInfo activePlayer);
	
	int restart (char board[][10]);
	
	void start_the_game();
};

//-------------------------------------------------------------------------------------
int ConnectFour::PlayerDrop( char board[][10], playerInfo activePlayer )
{
	int dropChoice;
	do
	{
		cout<<endl;
		cout<<endl;
		cout << activePlayer.playerName << "'s Turn " <<endl;
		cout << "Please Enter a number between 1  7: ";
		cin  >> dropChoice;

		while ( board[1][dropChoice] == 'X' || board[1][dropChoice] == 'O' )
		{
			cout << "That row is full, please enter a new row: ";
			cin  >> dropChoice;
		}

	}while ( dropChoice < 1 || dropChoice > 7 );

return dropChoice;
}




//----------------------------------------------------------------------------------------------------
void ConnectFour::CheckBellow ( char board[][10], playerInfo activePlayer, int dropChoice )
{
	int length, turn;
	length = 6;
	turn = 0;

	do 
	{
		if ( board[length][dropChoice] != 'X' && board[length][dropChoice] != 'O' )
	
		{
			board[length][dropChoice] = activePlayer.playerID;
			turn = 1;
		}
		else
		length--;
	}while (  turn != 1 );
//
//
}



//-----------------------------------------------------------------------------------------------
void ConnectFour::DisplayBoard ( char board[][10] )
{

	int rows = 6, columns = 7;

	for(int i = 1; i <= rows; i++)
	{
		cout << "||  ";
		for(int j = 1; j <= columns; j++)
		{
			if(board[i][j] != 'X' && board[i][j] != 'O')
				board[i][j] = '0';
				
			cout << board[i][j]<<"  ";

		}

		cout << "  ||" << endl;
	}

}


//----------------------------------------------------------------------------------------------------
int ConnectFour::CheckFour( char board[][10], playerInfo activePlayer )
{

	char player_id;
	int win;

	player_id = activePlayer.playerID;
	win = 0;

	for( int i = 8; i >= 1; i-- )
	{

		for( int j = 9; j >= 1; j-- )
		{

			if( board[i][j] == player_id     &&
				board[i-1][j-1] == player_id &&
				board[i-2][j-2] == player_id &&
				board[i-3][j-3] == player_id )
			{
				win = 1;
			}


			if( board[i][j] == player_id   &&
				board[i][j-1] == player_id &&
				board[i][j-2] == player_id &&
				board[i][j-3] == player_id )
			{
				win = 1;
			}

			if( board[i][j] == player_id   &&
				board[i-1][j] == player_id &&
				board[i-2][j] == player_id &&
				board[i-3][j] == player_id )
			{	
				win = 1;
			}

			if( board[i][j] == player_id     &&
				board[i-1][j+1] == player_id &&
				board[i-2][j+2] == player_id &&
				board[i-3][j+3] == player_id )
			{
				win = 1;
			}

			if ( board[i][j] == player_id   &&
				 board[i][j+1] == player_id &&
				 board[i][j+2] == player_id &&
				 board[i][j+3] == player_id )
			{
				win = 1;
			}
		}

	}

return win;
}

//-------------------------------------------------------------------------------------------------------------
int ConnectFour::FullBoard( char board[][10] )
{
	int full;
	full = 0;
	for ( int i = 0; i <= 6; ++i )  
	{
		if ( board[1][i] != '*' )
			full++;
	}

return full;
}

void ConnectFour::PlayerWin ( playerInfo activePlayer )
{
	cout << "Congratulations " << activePlayer.playerName << " You Win!" << endl; 
}

//-------------------------------------------------------------------------------------------------------------
int ConnectFour::restart( char board[][10] ){
	

	int restart;

	cout << "Would you like to restart? Yes(1) No(2): ";
	cin  >> restart;
	if ( restart == 1 )
	{
		for(int i = 0; i <= 5; i++)
		{
			for(int j = 0; j <= 6; j++)
			{
				board[i][j] = '*';
			}
		}
	}
	else
		cout << "Goodbye!" << endl;
		return restart;
}

void ConnectFour::start_the_game(){
	ConnectFour game;
	playerInfo playerOne, playerTwo;
	char board[9][10]; 
//	int trueWidth = 7; 
//	int trueLength = 6; 
	int dropChoice, win, full, again;

	cout << "Let's Play Connect 4" << endl << endl;
	cout << "Player One please enter your name: ";
	
	cin  >> playerOne.playerName;
	playerOne.playerID = 'X';
	cout << "Player Two please enter your name: ";
	cin  >> playerTwo.playerName;
	cout<<endl;
	cout<<endl;
	playerTwo.playerID = 'O';

	full = 0;
	win = 0;
	again = 0;
	game.DisplayBoard( board );
	do
	{
		dropChoice = game.PlayerDrop( board, playerOne );
		game.CheckBellow( board, playerOne, dropChoice );
		game.DisplayBoard( board );
		win = game.CheckFour( board, playerOne );
		if ( win == 1 )
		{
			game.PlayerWin(playerOne);
			again = game.restart(board);
			if (again == 2)
			{
				break;
			}
		}

		dropChoice = game.PlayerDrop( board, playerTwo );
		game.CheckBellow( board, playerTwo, dropChoice );
		game.DisplayBoard( board );
		win = game.CheckFour( board, playerTwo );
		if ( win == 1 )
		{
			game.PlayerWin(playerTwo);
			again = game.restart(board);
			if (again == 2)
			{
				break;
			}
		}
		full = game.FullBoard( board );
		if ( full == 7 )
		{
			cout << "The board is full, it is a draw!" << endl;
			again = game.restart(board);
		}

	}while ( again != 2 );
	
}

int main(){
	ConnectFour game;
	game.start_the_game();
	return 0;
}

