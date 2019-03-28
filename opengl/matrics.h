#pragma once

#include <vector>

#define m_vals std::vector< std::vector<int> > 

class matrix
{
public:
	matrix();
	matrix(m_vals init_values);
	matrix(int, int);
	~matrix();

	const inline m_vals *const valuePointer() const { return &matrix_values; };
	const inline m_vals valueVec() const { return matrix_values; };

	matrix operator*(matrix);
	matrix operator*(int);
	void operator*=(matrix);
	void operator*=(int);
	void operator=(matrix);
	int operator()(int x, int y) const { return matrix_values[x][y]; };

	void printFirst();
	void print();

	const std::vector<int> const getColumn(int column) const
	{
		std::vector<int> x;
		for (int i = 0; i < matrix_values.size(); i++)
			x.push_back(matrix_values[i][column]);
		return x;
	}
private:
	m_vals matrix_values;
};

