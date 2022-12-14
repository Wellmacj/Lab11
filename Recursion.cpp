#include "Recursion.h"
#include <stack>
#include <stdbool.h>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2 * 1


int FactorialByRecursion::CalculateFactorial(int num) 
{

    if(num == 0) return 1;
  	else return num*(CalculateFactorial(num-1));

}


int FactorialByStack::CalculateFactorial(int num) {

	// making the answer, or the stuff thats getting added, and other needed variables
	int answer = 1;
	int counter = 1;
	int nextVal = 0;

	// create the stack known as gilbert
	stack<int> gilbert;

	// im lazy and dont feel like implementing the factioral for 0
	if (num == 0) 
	{
		return 1;
	}


	// adding the factorials to a stack
	while (counter <= num) 
	{
		gilbert.push(counter);
		counter = counter + 1;
	}


	// checking to see if the stack "gilbert" is empty, if not add to answer
	while (!gilbert.empty()) 
	{

		answer = answer * gilbert.top();
		gilbert.pop();

	}

	return answer;
}

bool ChessBoard::Solve(ChessBoard chessBoard, int col) {

	if (col >= 8) {
		return true;
	}


	for (int i = 0; i < 8; ++i) {

		if (CheckSafeQueens(chessBoard, i, col)) 
		{
			m_board[i][col] = 1;

			if (Solve(chessBoard, col + 1) == true)
			{
				return true;
			}

			m_board[i][col] = 0;

		}
	}
	return false;
}


bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) 
{

    return false;

    // TODO
}


string ChessBoard::ToString() {

	string answer = "";
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int temp = m_board[i][j];
			stringstream ss;
			ss << temp;
			string str = ss.str();
			answer = answer + str;
		}
		answer = answer + "\n";
	}
	return answer;
}

extern std::string CallSimpleExceptionMethod(int i)
{    
    // TODO:
    // Note this is starter code that is not safe.  
    // As Simple exceptin method will throw an exception
    // which will not be handled, and we will also leak resources.
    // Make this method safer and handle all possible exceptions 
    // And also return a string of the exception recieved
    // The tests will tell you what to string to return.


	std::string retVal = "I did not get an Exception";

	MyFakeClass* resourceThatNeedsToBeCleanedup = nullptr;
	try
	{
		resourceThatNeedsToBeCleanedup = new MyFakeClass();
		SimpleExceptionMethod(i);
	}
	catch(MyException1 excep1 )
	{
		excep1.what();
		delete resourceThatNeedsToBeCleanedup;
		return("I got Exception 1");
	}
	catch(MyException2 excep2 ) 
	{
		excep2.what();
		delete resourceThatNeedsToBeCleanedup;
		return("I got Exception 2");
	}
	catch(MyException3 excep3 )
	{
		excep3.what();
		delete resourceThatNeedsToBeCleanedup;
		return("I got Exception 3");
	}

	return retVal;
}

// NOTE this function should not be editted.
extern void SimpleExceptionMethod(int i)
{
	int retVal = 0;

	if (i == 1)
	{
		throw MyException1();
	}
	else if (i == 2)
	{
		throw MyException2();

	}
	else if (i == 3)
	{
        // TODO uncomment line below, as you need to have all three exceptions working here
		throw MyException3();
	}
	else
	{
		retVal = 20;
	}

	return;

}



char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}
char const* MyException1::what() const throw() {
	return "MyException1";
}
char const* MyException2::what() const throw() {
	return "MyException2";
}
char const* MyException3::what() const throw() {
	return "MyException3";
}
// TODO make a MyException3::what