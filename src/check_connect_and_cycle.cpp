#include "../include/check_connect_and_cycle.hpp"

bool isGraphConnected(unsigned** matrix, const size_t size, vector<unsigned>* vertices)
{
	getVertices(vertices, matrix, size);
	if (isEmptyVertex(vertices, size))
		return false;
	
	bool visVertices[size];
	fillArray(visVertices, false, size);
	dfs(vertices, visVertices, 1, false, size);

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

void dfs(vector<unsigned>* vertices, bool* visVertices, unsigned vertex, bool isFindingTree, size_t size)
{
	if (isFindingTree)
	{
		static size_t count = 2;
		cout << vertex;
		if (count < size)
		{
			cout << "  =>  ";
			++count; 
		}
	}

	visVertices[vertex] = true;

	for (auto i : vertices[vertex])
	{
		if (visVertices[i] == false)
			dfs(vertices, visVertices, i, isFindingTree, size);
	}
}
