
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

	Row(Type* theArray, int row);
	
	Type &operator[](int column);


private:

	//Array2D<Type>& m_array2D;
	int m_row;
	Type* &m_data;

};




template<class Type> Row<Type>::Row(Type* theArray, int row):
m_row(row),
m_data(theArray)
{
	//m_data(theArray);

	

	//m_data = theArray;
	//for (int i = 0; i < row; i++)
	//{
		//m_data[i] = theArray[i];

	//}


}

template<class Type> Type &Row<Type>::operator[](int column)
{




	return m_data[column];
}


/*template<class Type> Row<Type> &Row<Type>::operator=(const Row &rhs)
{
	//m_data
	m_row = rhs.m_row;

	//m_data = new Type[row];

	//m_row = 0;


	for (int i = 0; i < m_row; i++)
	{
		m_data[i] = rhs.m_data[i];
	}
	return *this;

}
*/