#include <iostream>
using namespace std;

void DrawBoard(char board[3][3])
{
	for (int i = 0; i < 7; i++)
	{
		if (!(i % 2))//if(i % 2 == 0)
		{
			for (int j = 0; j < 12; j++)
			{
				cout << "-";
			}
		}
		else
		{
			for (int j = 0; j < 4; j++)
			{
				if (board[i / 2][j] && j < 3)
				{
					cout << "| " << board[i / 2][j] << " ";
				}
				else
				{
					cout << "|";
				}
			}
		}
		cout << endl;
	}
}

char CheckWinner(char board[3][3])
{
	//Check horizontally first
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1]
			&& board[i][1] == board[i][2] && board[i][0] != ' ')
		//if (board[i][0] == board[i][1] == board[i][2] && board[i][0]!= ' ')
		{
			return board[i][0];
		}
	}


	//Check vertically first
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i]
			&& board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
		&& board[0][0] != ' ')
	{
		return board[0][0];
	}

	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] &&
		board[2][0] != ' ')
	{
		return board[2][0];
	}

	return ' ';
}


void main()
{
	char gameOver = ' ';
	/*char board[3][3]{
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};*/
	char board[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}

	bool isX = true;
	DrawBoard(board);
	int placed = 0;
	do
	{
		cout << "Please choose which block: ";
		int x, y;
		cin >> x >> y;

		while (board[x][y] != ' ')
		{
			cout << "Already filled location! Please choose again! " << endl;
			cin >> x >> y;
		}

		if (isX)
		{
			board[x][y] = 'X';
		}
		else
		{
			board[x][y] = 'O';
		}

		placed++;
		DrawBoard(board);
		gameOver = CheckWinner(board);
		if (gameOver == ' ' && placed == 9)
		{
			cout << "Game over! No one won!" << endl;
			break;
		}

		isX = !isX;
	} while (gameOver == ' ');

	if (gameOver == 'X')
	{
		cout << "X won!" << endl;
	}
	else if (gameOver == 'Y')
	{
		cout << "Y won!" << endl;
	}
}