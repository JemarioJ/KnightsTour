// KnightsTour.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "knight.h"

using namespace std;

int main()
{
	int rowStart, colStart;
	Knights k;
	k.createBoard();
	cout << "What row would you like to start your knight in?" << endl;
	cin >> rowStart;
	cout << "What col would you like to start your knight in?" << endl;
	cin >> colStart;

	//k.markStart(rowStart, colStart);
	k.run(rowStart,colStart);
	//k.printOut();

	system("pause");
	k.deleteBoard();
	
}

