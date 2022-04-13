#ifndef GET_INPUT_HPP
#define GET_INPUT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#define VERTEX_DIGITS_MAX_COUNT 5
using std::endl;
using std::string;
using std::vector;

struct edge
{
	unsigned leftVertex;
	unsigned rightVertex;
	edge() : leftVertex(0), rightVertex(0)
	{}
};

void		getUserInput(vector<edge>& edges);
bool		isEmpty(string& str);
unsigned	getNumber(string& str, size_t& i);

#endif  /* GET_INPUT_HPP */
