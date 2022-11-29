#include "Recursion.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ChessBoard chessBoard;

	bool status = chessBoard.Solve(chessBoard,0);
	if(status)
	{
		string output = chessBoard.ToString();
		cout << output << endl;
	}
	else
	{
		cout << " 2 Hello No solution found"  << endl;
	}
	

	return 0;
}