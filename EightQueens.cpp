// Author:       Harshal Khandare
// Description:  This program solves the Eight Queen puzzle
//		 by placing eight queens on a chessboard such that no queen attacks any other queen.              
//
// Revisions:   v1.0
// $Log:        EightQueens.cpp,v1.0 $

#include<iostream>

using namespace std;
bool check_if_valid(int(*chessboard)[8], int row, int col);

/* Name: Main
*
* Description:	This method will check for a valid position to place a queen
*				in a row by row manner. If no possible positions exists
*				backtracing takes place and the previous rows valid position
*				is modified by resuming from the current valid position.
*
* Arguments:	No arguments
* Modifies:		null
* Returns:		0
* Pre:			null
*
* Post:		    Executes till all queens are placed on the chessboard in valid positions.
*
*/

int main()
{
	int chessboard[8][8];	//define a 8x8 chessboard matrix
	int row = 0;	//keeps track of row positions on the chessboards
	int col = 0;	//keeps track of column positions on the chessboards
	int flag = 0;	//states if resume value is properly set
	int no_of_queens = 8;	//number of queens to be placed
	int resume = 0;		//gives proper resuming of positions

	//initialize chessboard to 0
	for (int l = 0; l < no_of_queens; l++)
	for (int m = 0; m < no_of_queens; m++)
		*(*(chessboard + l) + m) = 0;
	//
	//continue till all queens are placed
	//
	while (row < no_of_queens)
	{
		//
		//initilize flag to 0 for every new row calculation
		//
		flag = 0;
		//
		//continue till proper resume position is set
		//
		while (flag == 0)
		{
			//
			//initialize resume to 0
			//and search current row for queen occurrence
			//
			resume = 0;
			for (int i = 0; i < no_of_queens; i++)
			{
				//
				//if backtracking occurs, a queen is encountered
				//then set a new resume for futhur calculation
				//
				if (*(*(chessboard + row) + i) == 1)
				{
					resume = i + 1;
					*(*(chessboard + row) + i) = 0;
					flag = 1;
					break;
				}
				else
				{
					//
					//if entire row is checked for a valid position,
					//backtrack a row and set flag to 0 to compute a
					//new resume position
					//
					if (*(*(chessboard + row) + (no_of_queens - 1)) == 1)
					{
						*(*(chessboard + row) + (no_of_queens - 1)) = 0;
						row--;
						flag = 0;
						break;
					}
					else{
						//
						//when a fresh row is to be calculated,
						//no queens are occured hence flag is set to 1
						//and resume would be 0
						//
						flag = 1;
					}
				}
			}
		}
		//
		//for the current row, check all the column positions
		//for a valid position to place the queen.
		//checking will start from the resume value which was
		//computed before
		//
		for (col = resume; col < no_of_queens; col++)
		{
			//
			//check if the current positions is valid
			//if yes then place a queen(indicated by 1)
			//and move to the next row else backtrack
			//
			if (check_if_valid(chessboard, row, col))
			{

				*(*(chessboard + row) + col) = 1;
				row++;
				break;
			}
			else
			{
				if (col == no_of_queens - 1){
					row--;
				}
			}
		}
	}
	//
	//display the chessboard with queens placed
	//
	for (int l = 0; l < no_of_queens; l++){
		for (int m = 0; m < no_of_queens; m++)
		if (*(*(chessboard + l) + m) == 1)
			cout << ("Q ");
		else
			cout << "_ ";
		cout << endl;
	}
	return 0;
}

/* Name: check_if_valid
*
* Description:	Checks if the current position is a valid position
*				to place the queen
* Arguments:	*chessboard,row,col
* Modifies:		null
* Returns:		boolean (true or false)
* Pre:			null
*
* Post:			null
*/

bool check_if_valid(int(*chessboard)[8], int row, int col)
{
	//
	//check if another queen is placed in the same row
	//
	for (int i = row; i >= 0; i--){
		if (*(*(chessboard + i) + col) == 1){
			return false;
		}
	}
	//
	//check if another queen is placed in the same column
	//
	for (int i = col; i >= 0; i--){
		if (*(*(chessboard + row) + i) == 1){
			return false;
		}
	}
	//
	//checks if another queen is placed along the right diagonal
	//
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
		if (*(*(chessboard + i) + j) == 1){
			return false;
		}
	}
	//
	//check if another queen is placed along the left diagonal
	//
	for (int i = row, j = col; i >= 0 && j < 8; i--, j++){
		if (*(*(chessboard + i) + j) == 1){
			return false;
		}
	}
	//
	//if no queen found then the postion is valid
	//
	return true;
}
