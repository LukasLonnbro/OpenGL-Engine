#include "matrics.h"

#include <iostream>

matrix::matrix() : matrix_values({ {} })
{
}
matrix::matrix(m_vals init_values)
{
	matrix_values = init_values;
}
matrix::matrix(int n, int m)
{
	m_vals vals(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			vals[i].push_back(0);

	matrix_values = vals;
}
matrix::~matrix()
{
}



void matrix::printFirst()
{
	std::cout << matrix_values[0][0];
}
void matrix::print()
{
	int rows = matrix_values.size();
	int columns = matrix_values[0].size();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << matrix_values[i][j] << " ";
		std::cout << "\n";
	}
}



void matrix::operator=(matrix otherMatrix)
{
	const m_vals &m = *otherMatrix.valuePointer();
	matrix_values = m;
}



std::vector<int>getColumn(m_vals mat, int column)
{
	std::vector<int> x;
	for (int i = 0; i < mat.size(); i++)
		x.push_back(mat[i][column]);
	return x;
}
int decideElement(std::vector<int> row, std::vector<int> column, int commonsize)
{
	int x;
	for (int i = 0; i < commonsize; i++)
	{
		x = row[i] * column[i];
	}
	return x;
}
matrix matrix::operator*(matrix otherMatrix)
{
	const m_vals &m1 = *otherMatrix.valuePointer();

	if (matrix_values[0].size() != m1.size())
	{
		std::cout << "Incorrect matrix dimensions." << std::endl;
		int a;
		std::cin >> a;

		return matrix_values;
	}

	int commonsize = m1.size();
	m_vals mul_values(matrix_values.size());

	int x = 0;

	for (int row = 0; row < matrix_values.size(); row++)
	{
		std::cout << "-- New row --\n";
		for (int column = 0; column < m1.size(); column++)
		{
			int val = decideElement(matrix_values[row], *otherMatrix.getColumn(0), commonsize);
			std::cout << "val #" << column << " : " << val << std::endl;
			mul_values[row].push_back(val);
		}
	}

	matrix mul_matrix(mul_values);
	return mul_matrix;
}
matrix matrix::operator*(int scalar)
{
	m_vals values = matrix_values;

	int sizeR = matrix_values.size();
	int sizeC = matrix_values[0].size();
	for (int i = 0; i < sizeR; i++)
	{
		for (int j = 0; j < sizeC; j++)
			values[i][j] *= scalar;
	}

	return values;
}

void matrix::operator*=(matrix m)
{
	matrix_values = (*this * m).valueVec();
}
void matrix::operator*=(int scalar)
{
	matrix_values = (*this * scalar).valueVec();
}