#include <vector>
using std::vector;

bool isGraphConnected(unsigned** matrix, size_t size);
void getVertices(vector<unsigned>* vertices, unsigned** matrix, size_t size);
bool isEmptyVertex(vector<unsigned>* vertices, size_t size);
void fillArray(bool* arr, bool elem, size_t size);
void dfs(vector<unsigned>* vertices, bool* visVertices, unsigned vertex);

bool isGraphConnected(unsigned** matrix, size_t size)
{
	vector<unsigned> vertices[size]; 

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

void getVertices(vector<unsigned>* vertices, unsigned** matrix, size_t size)
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

bool isEmptyVertex(vector<unsigned>* vertices, size_t size)
{
	for (size_t i = 1; i < size; ++i)
	{
		if (vertices[i].size() == 0)
			return true;
	}
	return false;
}

void fillArray(bool* arr, bool elem, size_t size)
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
