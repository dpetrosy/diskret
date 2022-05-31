#include "../include/check_connect_and_cycle.hpp"

bool isGraphConnected(unsigned** matrix, const size_t size, vector<unsigned>* vertices)
{
	getVertices(vertices, matrix, size);
	if (isEmptyVertex(vertices, size))
		return false;
	
	bool visVertices[size];
	fillArray(visVertices, false, size);
	dfs(vertices, visVertices, 1);

	for (size_t i = 1; i < size; ++i)
	{
		if (visVertices[i] == false)
			return false;
	}
	return true;
}

void getVertices(vector<unsigned>* vertices, unsigned** matrix, const size_t size)
{
	for (size_t i = 1; i < size; ++i)
	{
		for (size_t j = 1; j < size; ++j)
		{
			if (matrix[i][j] >= 1)
				vertices[i].push_back(j);
		}
	}
}

bool isEmptyVertex(vector<unsigned>* vertices, const size_t size)
{
	for (size_t i = 1; i < size; ++i)
	{
		if (vertices[i].size() == 0)
			return true;
	}
	return false;
}

void fillArray(bool* arr, bool elem, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		arr[i] = elem;
	}
}

void dfs(vector<unsigned>* vertices, bool* visVertices, unsigned vertex)
{
	visVertices[vertex] = true;

	for (auto i : vertices[vertex])
	{
		if (visVertices[i] == false)
			dfs(vertices, visVertices, i);
	}
}

void dfsFindTree(vector<unsigned>* vertices, bool* visVertices, unsigned vertex, vector<edge>& treeEdges)
{
	visVertices[vertex] = true;

	for (auto i : vertices[vertex])
	{
		if (visVertices[i] == false)
        {
            treeEdges.push_back(edge());
            treeEdges[treeEdges.size() - 1].leftVertex = vertex;
			treeEdges[treeEdges.size() - 1].rightVertex = i;
            dfsFindTree(vertices, visVertices, i, treeEdges);
        }
	}
}
