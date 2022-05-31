#ifndef GRAPH_VIZUALIZATION_HPP
#define GRAPH_VIZUALIZATION_HPP

#include <iostream>
#include <vector>
#include <fstream>
using std::endl;
using std::vector;

struct edge
{
	unsigned leftVertex;
	unsigned rightVertex;
	edge() : leftVertex(0), rightVertex(0)
	{}
};

#endif  /* GRAPH_VIZUALIZATION_HPP */
