

//Array Class
//Raymond Berry
//9/30/2015



/************************************************************************
* Class: Exception.
*

Description: This is a template array class, that alows a user to specify
a starting position and a length. The user can specify a -starting position.
This array class has overloaded [] operators, and overloaded = operator.
this array can be of any type specified.



* Constructors:
*	Array()
*		length initialized to 0
*		msg initizlized to an array of 1



Array(int length, int start_index = 0)
length the number of ellements in the array specified by the user
start_index the starting possing of the array (can be negitive)


Array(const Array& originalArray)
originalArray the array that is going to be coppied
*
* Mutators:
*	setMessage(char* msg)
*		This mutator initializes the member varable m_msg to the parameter that was passed in
*
*
*operator=(const Exception& rhs)
*	this mutator sets all the member varables of the class, to the rhs's member variables
*

setLength(int length);
Changes the length of the array to the specified perameter

setStartIndex(int start_index);
Changes the starting position of the array to what is passed in

&operator[](int index) const;
Returns by reference the ellement at the position specified in the []. throws an exceptiong if the position is out of bounds of the array

&operator[](int index);
Returns by reference the ellement at the position specified in the []. throws an exceptiong if the position is out of bounds of the array

&operator=(const Array &rhs);
Allows one array to be set to the parameter passed in

Inspectors:
int getLength()
Returns the length of the array

int getStartIndex() const;
returns the starting index of the array

*************************************************************************/

#include "Exception.h"
#include "Row.h"


template <class  Type> class Array2D
{
public:
	//constructor
	Array2D();

	//constructor
	Array2D(int row, int col = 0);

	//copy contructor
	Array2D(const Array2D& originalArray);

	//destructor
	~Array2D();

	//operator overloading
	Array2D &operator=(const Array2D &rhs);

	//overloaded subscript operator
	Row<Type> operator[](int index);

	//const subscript operator
	Row<Type> operator[](int index) const;

	//Getting rows and collomns
	int getRow();
	int getColumn();

	//sets the row and column
	void setRow(int rows);
	void setColumn(int columns);

	//selects a row and column
	Type& Select(int row, int column);

private:
	Type **m_array;
	int m_row;
	int m_col;
};

//Array implimination
/**************************************************************
*   Entry:  nothing
*
*    Exit:  nothing
*
*
* Purpose: Allows the user to create an array class
**************************************************************/

template<class Type> Array2D<Type>::Array2D()
{
	m_col = 0;
	m_row = 0;

	for (int i = 0; i < m_row; i++)
	{
		m_array[i] = new Type[m_col];
	}

}

/**************************************************************
*   Entry:  length, the length of the array, start_index the starting position of the array
*
*    Exit:  nothing
*
*
* Purpose: Allows the user to create an array class
**************************************************************/
template<class Type> Array2D<Type>::Array2D(int row, int col)
{
	m_row = row;
	m_col = col;

	m_array = new Type*[row];

	for (int i = 0; i < row; i++)
	{
		m_array[i] = new Type[col];
	}
}
	

/**************************************************************
*   Entry:  A class object
*
*    Exit:  nothing
*
*
* Purpose: Allows the user to copy an array
**************************************************************/
template<class Type> Array2D<Type>::Array2D(const Array2D& originalArray) :
//m_length(originalArray.getLength()),
//m_start_index(originalArray.getStartIndex())
m_row(originalArray.m_row),
m_col(originalArray.m_col)
{
	//realocate the array

	//Type **tempArray;
	m_array = new Type*[m_row];
	//Type* arrayofTypes = new Type[row];
	//m_array = new Row<Type>(arrayofTypes, col)[row];


	//creates the 2 dimentional array
	for (int i = 0; i < m_row; i++)
	{
		m_array[i] = new Type[m_col];
	}


	//coppys the originalArray into this array
	for (int rowIdx = 0; rowIdx < m_row; rowIdx++)
	{
		for (int Colidx = 0; Colidx < m_col; Colidx++)
		{
			m_array[rowIdx][Colidx] = originalArray.m_array[rowIdx][Colidx];
		}
	}
}

/**************************************************************
*   Entry:  nothing
*
*    Exit:  nothing
*
*
* Purpose: cleans up allowcating memory
**************************************************************/
template<class Type> Array2D<Type>::~Array2D()
{
	//cleanup allowcated memor

	
	//***STEP THROUGH m_array AND DELETE ALL THE MEMORY IN ROW FIRST BEFORE DELEATING m_array***
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	delete[] m_array;
}

//operator overloading

/**************************************************************
*   Entry:  the array object that the user wants to copy
*
*    Exit:  the modified array
*
*
* Purpose: allows the user to assing one array to another array
**************************************************************/
template<class Type> Array2D<Type> &Array2D<Type>::operator=(const Array2D &rhs)
{
	//Array<Type> returnArray(rhs);
	//m_length = rhs.getLength();
	//m_start_index = rhs.getStartIndex();

	m_row = rhs.m_row;
	m_col = rhs.m_col;


	m_array = new Type*[m_row];
	//Type* arrayofTypes = new Type[row];
	//m_array = new Row<Type>(arrayofTypes, col)[row];


	//creates the 2 dimentional array
	for (int i = 0; i < rhs.m_row; i++)
	{
		m_array[i] = new Type[rhs.m_col];
	}


	//coppys the originalArray into this array
	for (int rowIdx = 0; rowIdx < m_row; rowIdx++)
	{
		for (int Colidx = 0; Colidx < m_col; Colidx++)
		{
			m_array[rowIdx][Colidx] = rhs.m_array[rowIdx][Colidx];
		}
	}

	
	

	/*m_array = new Type[m_length];

	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = rhs[i];
	}
	return *this;
	*/
	return *this;
}


/**************************************************************
*   Entry:  The index
*
*    Exit:  the element at that index
*
*
* Purpose: allows the user to use the [] to get accses and change elements at
the specified index
**************************************************************/
template<class Type>   Row<Type> Array2D<Type>::operator[](int index)
{
	//check for index being <  the lower bound
	//int m_length;
	//int m_start_index;
	if (index < 0)
	{
		throw Exception("column below 0");
	}

	if (index > m_row)
	{
		throw Exception("column above max column");
	}

	Row<Type> row(*this, index);
	return row;
	//return row[index];
}

template<class Type> Type& Array2D<Type>::Select(int row, int column)
{
	//Checking for user trying to go out of bounds
	if (row < 0)
	{
		throw Exception("row specified is below 0");
	}

	if (row > m_row)
	{
		throw Exception("row specified is above maximum row");
	}

	if (column < 0)
	{
		throw Exception("column specified is below 0");
	}

	if (column > m_col)
	{
		throw Exception("column specified is above maximum column");
	}

	return m_array[row][column];
}

template<class Type> int Array2D<Type>::getRow()
{
	return m_row;
}

template<class Type> int Array2D<Type>::getColumn()
{
	return m_col;
}

template<class Type> void Array2D<Type>::setColumn(int newCol)
{
	//Type **tempArray;
	Array2D temp;
	temp = *this;

	//deletes m_array
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	delete[] m_array;

	//allocates the new memory for the array
	m_row = temp.m_row;
	m_col = newCol;

	m_array = new Type*[m_row];

	for (int i = 0; i < m_row; i++)
	{
		m_array[i] = new Type[newCol];
	}

	//transfers the temp to the new memory
	for (int rowIdx = 0; rowIdx < m_row; rowIdx++)
	{
		for (int Colidx = 0; Colidx < m_col; Colidx++)
		{
			m_array[rowIdx][Colidx] = temp[rowIdx][Colidx];
		}
	}
}

template<class Type> void Array2D<Type>::setRow(int newRow)
{
	Array2D<Type> temp;
	temp = *this;

	//deletes m_array
	for (int i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}

	delete[] m_array;

	//allocates the new memory for the array
	m_row = newRow;
	m_col = temp.m_col;

	m_array = new Type*[newRow];

	for (int i = 0; i < newRow; i++)
	{
		m_array[i] = new Type[m_col];
	}

	//transfers the temp to the new memory
	for (int rowIdx = 0; rowIdx < m_row; rowIdx++)
	{
		for (int Colidx = 0; Colidx < m_col; Colidx++)
		{
			m_array[rowIdx][Colidx] = temp[rowIdx][Colidx];
		}
	}
}



template<class Type>   Row<Type> Array2D<Type>::operator[](int index) const
{
	//check for index being <  the lower bound
	//int m_length;
	//int m_start_index;
	if (index < 0)
	{
		throw Exception("column below 0");
	}

	if (index > m_row)
	{
		throw Exception("column above max column");
	}

	Row<Type> row(*this, index);
	return row;
	//return row[index];
}


















































/**************************************************************
*   Entry:  The index
*
*    Exit:  the element at that index
*
*
* Purpose: allows the user to use the [] to get accses and change elements at
the specified index
**************************************************************/


/*
template<class Type> Row<Type> &Array2D<Type>::operator[](int index) const
{
	if (index < m_start_index)
	{
		throw Exception("index below start index");
	}

	if (index > m_start_index + m_length - 1)
	{
		throw Exception("index above max index");
	}

	//check for index being > uper bound
	return m_array[index - m_start_index];
}

*/

/**************************************************************
*   Entry:  nothing
*
*    Exit:  the starting index
*
*
* Purpose: alows the user to get the current start Index
**************************************************************/

/*
template<class Type> int Array2D<Type>::getStartIndex() const
{
	return m_start_index;
}
*/

/**************************************************************
*   Entry:  New start index
*
*    Exit:  nothing
*
* Purpose: alows the user to set the  start Index
**************************************************************/

/*
template<class Type> void Array2D<Type>::setStartIndex(int start_index)
{
	if (start_index < m_start_index)
	{
		throw Exception("index below start index");
	}

	if (start_index > m_start_index + m_length - 1)
	{
		throw Exception("index above max index");
	}

	m_start_index = start_index;
}
*/


//getting and setting the length

//getLength
/**************************************************************
*   Entry:  nothing
*
*    Exit:  the length of the array
*
* Purpose: alows the user to get the  length of the array
**************************************************************/


/*
template<class Type> int Array2D<Type>::getLength() const
{
	return m_length;
}
*/

//set Length
/**************************************************************
*   Entry:  the length
*
*    Exit:  nothing
*
* Purpose: alows the user to set the  length of the array
**************************************************************/



/*
template<class Type> void Array2D<Type>::setLength(int length)
{
	m_length = length;
	m_array = new Type[m_length];
}


*/