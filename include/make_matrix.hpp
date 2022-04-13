#ifndef MAKE_MATRIX_HPP
#define MAKE_MATRIX_HPP

#include <vector>
using std::vector;

struct edge
{
	unsigned leftVertex;
	unsigned rightVertex;
	edge() : leftVertex(0), rightVertex(0)
	{}
};

size_t getMatrixSize(vector<edge>& edges);
void makeMatrix(unsigned** matrix, vector<edge>& edges);
void makeSimpleMatrix(unsigned** matrix, const size_t size);

#endif  /* MAKE_MATRIX_HPP */