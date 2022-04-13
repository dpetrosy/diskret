#include "../include/make_matrix.hpp"

size_t getMatrixSize(vector<edge>& edges)
{
	size_t max = 0;

	max = edges[0].leftVertex;
	for (size_t i = 0; i < edges.size(); ++i)
	{
		if (max < edges[i].leftVertex)
			max = edges[i].leftVertex;
		if (max < edges[i].rightVertex)
			max = edges[i].rightVertex;
	}
	return max + 1;
}

void makeMatrix(unsigned** matrix, vector<edge>& edges)
{
	unsigned left = 0;
	unsigned right = 0;
	for (size_t i = 0; i < edges.size(); ++i)
	{
		left = edges[i].leftVertex;
		right = edges[i].rightVertex;

		if (left != right)
			matrix[left][right] += 1;
		matrix[right][left] += 1;
	}
}

void makeSimpleGraph(unsigned** matrix, const size_t size)
{
	for (size_t i = 1; i < size; ++i)
	{
		for (size_t j = 1; j < size; ++j)
		{
			if (i == j)
				matrix[i][j] = 0;
			else if (matrix[i][j] > 1)
				matrix[i][j] = 1;
		}
	}
}
