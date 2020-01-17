#pragma once
#include <iostream>

using namespace std;
class Knights
{
public:
	void createBoard() {
		cout << "Amount of rows" << endl;
		cin >> rowSize;
		cout << "Amount of Columns" << endl;
		cin >> colSize;

		board = new int*[rowSize];

		for (int i = 0; i < rowSize; i++) {
			board[i] = new int[colSize];
		}

		for (int i = 0; i < rowSize; i++)
		{
			for (int j = 0; j < colSize; j++)
			{
				board[i][j] = -1;
			}
		}

	}

	void deleteBoard() {

		for (int i = 0; i < rowSize; i++) {
			delete[] board[i];
		}

		delete[] board;
	}

	void printOut() {

		

		for (int i = 0; i < rowSize; i++)    
		{
			for (int j = 0; j < colSize; j++) 
			{
				cout << board[i][j] << "  ";
			}
			cout << endl;
		}

	}

	void markStart(int r, int c) {
		board[r][c] = 0;
	}

	int maxMoves() {
		return colSize * rowSize;
	}

	bool validLocation(int r, int c) {
		
		if ((r < 0) || (r >= rowSize))
    {
        return false;
    }
 
    if ((c < 0) || (c >= colSize))
    {
        return false;
    }
 
    if (board[r][c] != -1)
    {
        return false;
    }
 
    return true;
	
	}
	
	
	
	void run(int r, int c /*int moveCounter*/) {
	
		board[r][c] = moveCounter;

		if (moveCounter == maxMoves()-1 && !solutionPrinted) {
			printOut();
			solutionPrinted = true;
			return;
		}
		

		if (validLocation(r + 2, c - 1)|| validLocation(r + 1, c - 2)|| validLocation(r - 1, c - 2) || validLocation(r - 2, c - 1) ||validLocation(r+2,c+1) ||validLocation(r+1,c+2)||validLocation(r-1,c+2) ||validLocation(r-2,c+1)) {
			//left1
			int tempc = c - 1;
			int tempr = r + 2;
			if (validLocation(tempr, tempc)) {
				moveCounter++;
				run(tempr, tempc);
			}
			
			//left 2
			tempc = c - 2;
			tempr = r + 1;
			if (validLocation(tempr, tempc)) {
				moveCounter++;
				run(tempr, tempc);
			}
			
			//left 3
			tempc = c - 2;
			tempr = r - 1;
			if (validLocation(tempr, tempc)) {
				moveCounter++;
				run(tempr, tempc);
				
			}
			
			//left 4
			tempc = c - 1;
			tempr = r - 2;
			if (validLocation(tempr, tempc)) {
				moveCounter++;
				run(tempr, tempc);
			}
			
			//right 1
			tempc = c + 1;
			tempr = r + 2;
			if (validLocation(tempr, tempc)) {
				moveCounter++;
				run(tempr, tempc);
			}
			
			//right 2
			tempc = c + 2;
			tempr = r + 1;
			if (validLocation(tempr, tempc)) {
				moveCounter++;
				run(tempr, tempc);
			}
			
			//right 3
			tempc = c + 2;
			tempr = r - 1;
			if (validLocation(tempr, tempc)) {
				moveCounter++;
				run(tempr, tempc);
			}
			
			//right 4
			tempc = c + 1;
			tempr = r - 2;
			if (validLocation(tempr, tempc)) {
				moveCounter++;
				run(tempr, tempc);
			}
			
			
		}
		
			board[r][c] = -1;
			moveCounter--;

			if (moveCounter <= 0 && !solutionPrinted) {
				cout << " No solutions found" << endl;
				solutionPrinted = true;
			}

	}
	
private:
	int **board;
	int rowSize, colSize;
	int moveCounter = 0;
	bool solutionPrinted = false;

};

