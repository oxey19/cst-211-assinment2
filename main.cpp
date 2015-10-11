
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/7/2015
* Last Modification Date:	10/7/2015
* Lab Number:			CST 211 Assignment 2
* Filename:				Row.h
*/
#include "Array2D.h"

#include <iostream>

using namespace std;

/*
Questions:
1) To create a column class the classes would be restructured. The column class would hold the array of rows.

2)Forward Delcerations is telling the compialer that something exists, but it is defined later on. This works because the 
compiler reads files in order from top to bottem. So when the the file reads a forward declearion and knows that the
implimentation is later and it dosn't need to wory about things not being defined. You use forward decleartion before 
something that is trying to use a fucntion or a variable, or a class that is defined else where that is further down 
in the file, or sequence of files.

3)The code would look like this: if you were to use my 2dArray class

for (int idx = 0; idx < x.getRow(); idx++)
{
	for (int i = 0; i < x.getColumn(); i++)
	{
		y[i][idx] = x[idx][x.getColumn() - i - 1];
	}
}

The big-O notation would be: O(n^2)
*/




//Expected Output of programd
/*
44
44
The 2d Array
55
55
Collumn: 2
Row: 2
55
New Collumn: 2
New Row: 1
The 2d Array
55
55
Collumn: 2
Row: 2
5
5
New Collumn: 1
New Row: 2
An exception occrued. Exception column below 0
An exception occrued. Exception row specified is below 0
An exception occrued. Exception column above max column
An exception occrued. Exception row specified is above maximum row
An exception occrued. Exception column below 0
An exception occrued. Exception row specified is below 0
An exception occrued. Exception row specified is above maximum row
An exception occrued. Exception column specified is above maximum column

The Const object-842150451

The x array:
100100
100100
The Y array
100100
100100

The x array:
Original array:
01
23
13
02
Press any key to continue . . .
*/






void displayArray(Array2D<int> theArray)
{
	for (int i = 0; i < theArray.getRow(); i++)
	{
		for (int idx = 0; idx < theArray.getColumn(); idx++)
		{
			cout << theArray[i][idx];
		}
		cout << endl;
	}

}

void fillAnArray(int value)
{
	Array2D<int> x(2, 2);

	for (int i = 0; i < 2; i++)
	{
		for (int idx = 0; idx < 2; idx++)
		{
			x[i][idx] = value;
		}
	}

	displayArray(x);
}

void changeRowLength()
{
	//creates the array
	Array2D<int> x(2, 2);

	for (int i = 0; i < 2; i++)
	{
		for (int idx = 0; idx < 2; idx++)
		{
			x[i][idx] = 5;
		}
	}

	cout << "The 2d Array " << endl;
	displayArray(x);

	cout << "Collumn: " << x.getColumn() << endl;
	cout << "Row: " << x.getRow() << endl;

	//changes the row;
	x.setRow(1);
	displayArray(x);

	//Display 
	cout << "New Collumn: " << x.getColumn() << endl;
	cout << "New Row: " << x.getRow() << endl;
	//changes the length
}

void changeColLength()
{
	Array2D<int> x(2, 2);

	for (int i = 0; i < 2; i++)
	{
		for (int idx = 0; idx < 2; idx++)
		{
			x[i][idx] = 5;
		}
	}
	cout << "The 2d Array " << endl;
	displayArray(x);

	cout << "Collumn: " << x.getColumn() << endl;
	cout << "Row: " << x.getRow() << endl;

	//changes the row;
	x.setColumn(1);
	displayArray(x);

	//Display 
	cout << "New Collumn: " << x.getColumn() << endl;
	cout << "New Row: " << x.getRow() << endl;
}

void exceptionTester()
{
	Array2D<int> x(2, 2);

	for (int i = 0; i < 2; i++)
	{
		for (int idx = 0; idx < 2; idx++)
		{
			x[i][idx] = 5;
		}
	}

	try
	{
		x[-1][5] = 7;
	}
	catch (Exception boundException)
	{
		cout << "An exception occrued. Exception " << boundException << endl;

	}

	try
	{
		x[0][-1] = 7;
	}
	catch (Exception boundException)
	{
		cout << "An exception occrued. Exception " << boundException << endl;
	}

	try
	{
		x[5][0] = 7;
	}
	catch (Exception boundException)
	{
		cout << "An exception occrued. Exception " << boundException << endl;
	}

	try
	{
		x[0][5] = 7;
	}
	catch (Exception boundException)
	{
		cout << "An exception occrued. Exception " << boundException << endl;

	}

	try
	{
		x[-1][5] = 7;
	}
	catch (Exception boundException)
	{
		cout << "An exception occrued. Exception " << boundException << endl;
	}

	try
	{
		x[0][-1] = 7;
	}
	catch (Exception boundException)
	{
		cout << "An exception occrued. Exception " << boundException << endl;
	}

	try
	{
		x.Select(5, 0);
	}
	catch (Exception boundException)
	{
		cout << "An exception occrued. Exception " << boundException << endl;
	}

	try
	{
		x.Select(0,5);
	}
	catch (Exception boundException)
	{
		cout << "An exception occrued. Exception " << boundException << endl;
	}
}

void constObjectTester()
{
	Array2D<int> x(2, 2);
	const  Array2D<int> y(x);

	cout << endl << "The Const object" << y[0][0] << endl;
}

void copyContructoTester()
{
	Array2D<int> x(2, 2);

	for (int i = 0; i < 2; i++)
	{
		for (int idx = 0; idx < 2; idx++)
		{
			x[i][idx] = 100;
		}
	}
	Array2D<int> y(x);

	cout << endl << "The x array: " << endl;
	displayArray(x);

	cout << "The Y array" << endl;
	displayArray(y);
}

void emptyArrayTester()
{
	Array2D<int> y();

	cout << endl << "The x array: " << endl;
}


void rotateA2dArray()
{
	Array2D<int> x(2, 2);
	Array2D<int> y(2, 2);

	int num = 0;

	for (int i = 0; i < 2; i++)
	{

		
		for (int idx = 0; idx < 2; idx++)
		{
			x[i][idx] = num;
			num++;
		}
	}

	cout << "Original array: " << endl;
	displayArray(x);

	for (int idx = 0; idx < x.getRow(); idx++)
	{
		for (int i = 0; i < x.getColumn(); i++)
		{
			y[i][idx] = x[idx][x.getColumn() - i - 1];
		}
	}

	displayArray(y);



}
//the main program that calls all the test functions
int main(void)
{
	//int temp = x[1][1];
	fillAnArray(4);
	changeRowLength();
	changeColLength();

	exceptionTester();

	constObjectTester();

	copyContructoTester();

	emptyArrayTester();

	rotateA2dArray();
	return 0;
}