#include <iostream>
#include <vector>
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
unsigned**	allocMemory(size_t size);
void		freeMemory(unsigned** matrix, size_t size);
void		makeMatrix(unsigned** matrix, vector<edge>& edges);
void		makeSimpleGraph(unsigned** matrix, size_t size);
bool		isGraphConnected(unsigned** matrix, size_t size);

int main()
{
	vector<edge> edges;
	getUserInput(edges);

	size_t matrixSize = getMatrixSize(edges);
	unsigned** matrix = allocMemory(matrixSize);
	makeMatrix(matrix, edges);
	makeSimpleGraph(matrix, matrixSize);
	
	if (!isGraphConnected(matrix, matrixSize))
	{
		cout << "Inputted graph is not connected!" << endl;	
		cout << "Correct your input and try again." << endl;
		freeMemory(matrix, matrixSize);
		return 0;
	}
	cout << endl << "Inputted graph is connected!" << endl;




	// ------------------------------COUT-------------------------
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



	freeMemory(matrix, matrixSize);
	return 0;
}
