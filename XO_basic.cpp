#include <iostream>
using namespace std;

void DrawBoard(char board[5][5], int width)
{
	for (int row = 0; row < (width * 2) + 1; row++)
	{
		if (!(row % 2))//if(i % 2 == 0)
		{
			for (int j = 0; j < (width * 4) + 1; j++)
			{
				cout << "-";
			}
		}
		else
		{
			for (int j = 0; j <= width; j++)
			{
				if (j < width)
				{
					cout << "| " << board[row / 2][j] << " ";
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

char CheckHorizontal(char board[5][5], int width) {
	for (int row = 0; row < width; row++) {
		char current = board[row][0];
		if (current == ' ') break;

		int matches = 1;
		for (int col = 1; col < width; col++) {
			if (board[row][col] != current) {
				break;
			}
			else {
				matches++;
			}
		}
		if (matches == width) return current;
	}
	return ' ';
}

char CheckVerical(char board[5][5], int width) {
	for (int col = 0; col < width; col++) {
		char current = board[0][col];
		if (current == ' ') break;

		int matches = 1;
		for (int row = 1; row < width; row++) {
			if (board[row][col] != current) {
				break;
			}
			else {
				matches++;
			}
		}
		if (matches == width) return current;
	}
	return ' ';
}

char CheckDaigonal(char board[5][5], int width) {
	int matches;
	char current;

	matches = 1;
	current = board[0][0];
	for (int colRow = 1; colRow < width; colRow++) {
		if (current == ' ') break;

		if (board[colRow][colRow] != current) {
			break;
		}
		else {
			matches++;
		}
	}
	if (matches == width) return current;

	matches = 1;
	current = board[0][width - 1];
	int row = 1;
	for (int col = width - 2; col >= 0; col--) {
		if (current == ' ') break;

		if (board[row][col] != current) {
			break;
		}
		else {
			matches++;
		}
		row++;
	}
	if (matches == width) return current;

	return ' ';
}

char CheckWinner(char board[5][5], int width)
{
	char winner = ' ';

	winner = CheckHorizontal(board, width);
	winner = CheckVerical(board, width);
	winner = CheckDaigonal(board, width);

	return winner;
}


void main()
{
	int width;

	cout << "Please enter board width: ";
	cin >> width;

	while (width < 3 || width > 5) {
		cout << "Please enter a board width between 3 and 5: ";
		cin >> width;
	}


	char gameOver = ' ';

	char board[5][5];
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			board[i][j] = ' ';
		}
	}

	bool isX = true;
	DrawBoard(board, width);
	int placed = 0;
	do
	{
		cout << "Please choose which block: ";
		int x, y;
		cin >> x >> y;

		while (board[x][y] != ' ' || x < 0 || x > width - 1 || y < 0 || y > width - 1)
		{
			cout << "Please enter a valid number: ";

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
		DrawBoard(board, width);
		gameOver = CheckWinner(board, width);
		if (gameOver == ' ' && placed == width * width)
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