//Tic-Tac-Toe
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
//function prototype
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanpiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanmove(const vector<char>& board, char human);
int computermove(const vector<char> board, char computer);
void announcewinner(char winner, char human, char computer);

//main function
int main(int argc, char argv[])
{
	int move;
	const int NUM_SQUARES = 9;
	vector <char> board(NUM_SQUARES, EMPTY);
	instructions();
	char human = humanpiece();
	char computer = opponent(human);
	char turn = X;
	displayBoard(board);
	while (winner(board) == NO_ONE)
	{
		if (turn == human)
		{
			move = humanmove(board, human);
			board[move] = human;

		}
		else
		{
			move = computermove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);

	}
	announcewinner(winner(board), computer, human);
	return 0;
}

//instructions()
void instructions()
{
	cout << "Welcome to the ultimate man-machine showdown: Tic_Tac_Toe.\n";
	cout << "--where human brain is pit against silicon processor\n\n";
	cout << "Make your move dnown by enter a number ,0-8.The number\n";
	cout << " 0 | 1 | 2 \n";
	cout << "-----------\n";
	cout << " 3 | 4 | 5 \n";
	cout << "-----------\n";
	cout << " 6 | 7 | 8 \n\n";
	cout << "Prepare yourself ,human ,The battle is about to begin.\n";

}

//askYesNo()
char askYesNo(string question)
{
	char response;
	do
	{
		cout << question << "(Y/N):";
		cin >> response;
	} while (response != 'Y' && response != 'N');
	return response;
}

//askNumber()
int askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << "(" << low << " - " << high << "):";
		cin >> number;
	} while (number > high || number < low);
	return number;
}

//humanpiece()
char humanpiece()
{
	char go_first = askYesNo("Do you require the first move ?");
	if (go_first == 'Y')
	{
		cout << "\nThen take the first move . You will need it. \n";
		return X;
	}
	else
	{
		cout << "\nYour bravery will be your undoing ... I will go first .\n";
		return O;
	}
}

//opponent()
char opponent(char piece)
{
	if (piece == X)
		return O;
	else
		return X;
}

//displayBoard()
void displayBoard(const vector <char>& board)
{
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "-----------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "-----------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\n";
}

//winner()
char winner(const vector<char>& board)
{
	//all possible winning rows
	const int WINNING_ROWS[8][3] = { { 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 0, 4, 8 },
	{ 2, 4, 6 } };
	const int TOTLE_ROWS = 8;
	//if any winning row has three values that are the same (and not EMPTY ),
	//Then we have a winner 
	for (int row = 0; row < TOTLE_ROWS; ++row)
	{
		if ((board[WINNING_ROWS[row][0]]) != EMPTY && (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) && (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
		{
			return board[WINNING_ROWS[row][0]];
		}
	}
	//since nobody has won, check for a tie (no empty squares left)
	if (count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;
	//since nobody has won and it isn't a tie ,the game aren't over
	return NO_ONE;
}

//isLegal()
inline bool isLegal(const vector<char>& board, int move)
{
	return (board[move] == EMPTY);
}

//humanmove()
int humanmove(const vector<char>& board, char human)
{
	int move = askNumber("Where will you move ?", (board.size() - 1));
	while (!isLegal(board, move))
	{
		cout << "\nThat square is already occupied, foolish human.\n";
		move = askNumber("Where woll you move ?", (board.size() - 1));
	}
	cout << "Fine...\n";
	return move;
}

//computermove()
int computermove(vector<char> board,char computer)
{
	unsigned int move = 0;
	bool found = false;
	//if computer can win on next move,that's the move to make
	while(!found && move < board.size())
	{
		if(isLegal(board,move))
	{
		board[move] = computer;
		found = winner(board) == computer;
		board[move] = EMPTY;

	}
		if(!found)
		{
			++move;
		}
	}
	//otherwise,if human can win on next move ,that's the move to make
	if(!found)
	{
		move = 0;
		char human = opponent(computer);
		while(!found && move < board.size())
		{
			if(isLegal(board,move))
		{
			board[move] = human;
			found = winner(board) == human;
			board[move] = EMPTY;
		}
			if(!found)
			{
				++move;
			}
		}
	}
	//otherwise, mvoing the best open square is the move to make 
	if(!found)
	{
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		//pick the best open square
		while(!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if(isLegal(board,move))
			{
				found = true;
			}
			++i;
		}
	}
	cout << "I shall tqake square number " << move << endl;
	return move;
}

//announcewinner()
void announcewinner(char winner ,char computer,char human)
{
	if(winner == computer)
{
	cout << winner << "'s won! \n";
	cout << "As I predicted,human ,I am triumphant once more -- proof \n";
	cout << "that computers are superior to human in all regards.\n";

}
	else if(winner == human)
	{
		cout << winner << "'s won !\n";
		cout << "NO,no! It cannot be! Someday you tricked me ! human !\n";
		cout << "But never again! I , the computer ,so swear it !\n";
	}
	else 
	{
		cout << "It's tie!\n";
		cout << "You were most lucky, human,and somehow managed to tie me .\n";
		cout << "Celebrate ...for this is the best you will ever achieve.\n";
	}
}
