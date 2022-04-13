#include "../include/main.hpp"

int main()
{
	vector<edge> edges;
	getUserInput(edges);

	size_t matrixSize = getMatrixSize(edges);
	unsigned** matrix = allocMemory(matrixSize);

	makeMatrix(matrix, edges);
	makeSimpleGraph(matrix, matrixSize);
	
	vector<unsigned> vertices[matrixSize];
	if (!isGraphConnected(matrix, matrixSize, vertices))
	{
		cout << "Inputed graph is not connected!" << endl;	
		cout << "Correct your input and try again." << endl;
		freeMemory(matrix, matrixSize);
		return 0;
	}

	//////////////////////////////////////////////////////////////
	// ------------------------------COUT-------------------------
	cout << endl << "Inputed graph is connected!" << endl << endl;
	for (size_t i = 0; i < edges.size(); ++i)
	{
		cout << "left vertex  =  " << edges[i].leftVertex << "   " << "right vertex  =  " << edges[i].rightVertex << endl;
	}
	cout << endl << "----------------Matrix-----------------" << endl;
	for (size_t i = 1; i < matrixSize; ++i)
	{
		cout << endl;
		for (size_t j = 1; j < matrixSize; ++j)
		{
			cout << matrix[i][j] << "  ";
		}
	}
	cout << endl << endl;
	// ------------------------------COUT-------------------------
	//////////////////////////////////////////////////////////////


	bool visVertices[matrixSize];
	fillArray(visVertices, false, matrixSize);
	cout << "Found spannig tree nodes:  ";
	dfs(vertices, visVertices, 1, true, matrixSize);
	cout << endl << endl;

	freeMemory(matrix, matrixSize);
	return 0;
}
