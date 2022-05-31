#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
using std::cout;
using std::endl;
using std::vector;

struct edge
{
	unsigned leftVertex;
	unsigned rightVertex;
	edge() : leftVertex(0), rightVertex(0)
	{}
};

void		getUserInput(vector<edge>& edges);
size_t		getMatrixSize(vector<edge>& edges);
unsigned**	allocMemory(const size_t size);
void		freeMemory(unsigned** matrix, const size_t size);
void		makeMatrix(unsigned** matrix, vector<edge>& edges);
void		makeSimpleGraph(unsigned** matrix, const size_t size);
bool		isGraphConnected(unsigned** matrix, const size_t size, vector<unsigned>* vertices);
void		fillArray(bool* arr, bool elem, const size_t size);
void		dfs(vector<unsigned>* vertices, bool* visVertices, unsigned vertex, bool isFindingTree, size_t size);
bool        fileExists(const std::string& name);
void        graphViz(vector<edge>& edges, const std::string& fileName);
void        dfsFindTree(vector<unsigned>* vertices, bool* visVertices, unsigned vertex, vector<edge>& treeEdges);
void        displayMatrix(unsigned** matrix, size_t matrixSize);

#endif  /* MAIN_HPP */
