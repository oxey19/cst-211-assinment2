
#include "Array2D.h"


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
	//m_length = 0;
	//m_start_index = 0;
	m_col = 0;
	m_row = 0;
	m_array = new Type[m_length];
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
	//m_length = length;
	//m_start_index = start_index;
	m_row = row;
	m_col = col;
	m_array = new Type[m_length];
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

	//****NEED TO CHANGE***
	m_array = new Type[m_length];

	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = originalArray[i];
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
	
	m_array = new Type[m_length];

	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = rhs[i];
	}
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
template<class Type> Type &Array2D<Type>::operator[](int index)
{
	//check for index being <  the lower bound
	//int m_length;
	//int m_start_index;
	if (index < m_start_index)
	{
		throw Exception("index below start index");
	}
	
	if (index > m_start_index + m_length - 1)
	{
		throw Exception("index above max index");
	}

	return m_array[index - m_start_index];
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
template<class Type> Type &Array2D<Type>::operator[](int index) const
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

/**************************************************************
*   Entry:  nothing
*
*    Exit:  the starting index
*
*
* Purpose: alows the user to get the current start Index
**************************************************************/
template<class Type> int Array2D<Type>::getStartIndex() const
{
	return m_start_index;
}

/**************************************************************
*   Entry:  New start index
*
*    Exit:  nothing
*
* Purpose: alows the user to set the  start Index
**************************************************************/
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

//getting and setting the length

//getLength
/**************************************************************
*   Entry:  nothing
*
*    Exit:  the length of the array
*
* Purpose: alows the user to get the  length of the array
**************************************************************/
template<class Type> int Array2D<Type>::getLength() const
{
	return m_length;
}

//set Length
/**************************************************************
*   Entry:  the length
*
*    Exit:  nothing
*
* Purpose: alows the user to set the  length of the array
**************************************************************/
template<class Type> void Array2D<Type>::setLength(int length)
{
	m_length = length;
	m_array = new Type[m_length];
}