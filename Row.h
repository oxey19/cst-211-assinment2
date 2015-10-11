
/***********************************************************
* Author:				Raymond Berry
* Date Created:			10/7/2015
* Last Modification Date:	10/7/2015
* Lab Number:			CST 211 Assignment 2
* Filename:				Row.h
*/

//Declaring Array2D class exsistes so Array2D.h dosn't need to be included
template <class  Type> class Array2D;


template <class Type> class Row
{
public:

	//Row &operator=(const Row &rhs);

	Row(Array2D<Type>& theArray, int row);

	Row(const Array2D<Type>& theArray, int row);
	
	Type &operator[](int column);

	Type &operator[](int column) const;


private:

	//Array2D<Type>& m_array2D;
	int m_row;
	Array2D<Type>& m_data;





};




template<class Type> Row<Type>::Row(Array2D<Type>& theArray, int row):
m_row(row),
m_data(theArray)
{
}


template<class Type> Row<Type>::Row(const Array2D<Type>& theArray, int row):
m_row(row)

{
	m_data& theArray;

}

template<class Type> Type& Row<Type>::operator[](int column)
{
	//m_data.select(row, column);
	if (column < 0)
	{
		throw Exception("row specified is below 0");
	}

	if (column >= m_data.getColumn())
	{
		throw Exception("row specified is above maximum row");
	}
	return m_data.Select(m_row, column);
}


template<class Type> Type& Row<Type>::operator[](int column) const
{
	//m_data.select(row, column);
	if (column < 0)
	{
		throw Exception("row specified is below 0");
	}

	if (column >= m_data.getColumn())
	{
		throw Exception("row specified is above maximum row");
	}
	return m_data.Select(m_row, column);
}