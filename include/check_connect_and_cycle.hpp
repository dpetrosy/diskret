#ifndef CONNECT_AND_CYCLE_HPP
#define CONNECT_AND_CYCLE_HPP

#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::vector;

struct edge
{
	unsigned leftVertex;
	unsigned rightVertex;
	edge() : leftVertex(0), rightVertex(0)
	{}
};

bool isGraphConnected(unsigned** matrix, const size_t size, vector<unsigned>* vertices);
void getVertices(vector<unsigned>* vertices, unsigned** matrix, const size_t size);
bool isEmptyVertex(vector<unsigned>* vertices, const size_t size);
void fillArray(bool* arr, bool elem, const size_t size);
void dfs(vector<unsigned>* vertices, bool* visVertices, unsigned vertex);
void dfsFindTree(vector<unsigned>* vertices, bool* visVertices, unsigned vertex, vector<edge>& treeEdges);

#endif  /* CONNECT_AND_CYCLE_HPP */



