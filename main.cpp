
#include "Array2D.h"

#include <iostream>

using namespace std;





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

	const Array2D<int> x(2, 2);

	cout << endl << "The Const object" << x[0][0] << endl;


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

	return 0;
}