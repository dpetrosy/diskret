#include "../include/main.hpp"

int main()
{
	vector<edge> edges;
	getUserInput(edges);

    graphViz(edges, "input.dot");
    if (!fileExists("data/input.dot"))
    {
        std::cerr << "File \"input.dot\" was not created, try again!\n";
        exit(4);
    }
    system("dot -Tpng -O data/input.dot && xdg-open data/input.dot.png");

	size_t matrixSize = getMatrixSize(edges);
	unsigned** matrix = allocMemory(matrixSize);

	makeMatrix(matrix, edges);

    /////////////////////////////////////////////////////
	// -------------------------OUTPUT-------------------
	cout << endl;
    for (size_t i = 0; i < edges.size(); ++i)
	{
		cout << "left vertex  =  " << edges[i].leftVertex << "   " << "right vertex  =  " << edges[i].rightVertex << endl;
	}
	cout << endl << "-------Inputed Graph Adjacency Matrix-------" << endl;
    displayMatrix(matrix, matrixSize);
	// -------------------------OUTPUT--------------------
	//////////////////////////////////////////////////////

	makeSimpleGraph(matrix, matrixSize);
	
	vector<unsigned> vertices[matrixSize];
	if (!isGraphConnected(matrix, matrixSize, vertices))
	{
		cout << "Inputed graph is not connected!" << endl;	
		cout << "Correct your input and try again." << endl << endl;
		freeMemory(matrix, matrixSize);
		exit(1);
	}

    cout << "Inputed graph is connected!" << endl;
	cout << endl << "-------Simple Graph Adjacency Matrix-------" << endl;
    displayMatrix(matrix, matrixSize);

	bool visVertices[matrixSize];
	fillArray(visVertices, false, matrixSize);
    vector<edge> treeEdges;
	dfsFindTree(vertices, visVertices, 1, treeEdges);
    
    graphViz(treeEdges, "tree.dot");
    if (!fileExists("data/tree.dot"))
    {
        std::cerr << "File \"tree.dot\" was not created, try again!\n";
        exit(4);
    }
    system("dot -Tpng -O data/tree.dot && xdg-open data/tree.dot.png");

	freeMemory(matrix, matrixSize);
	return 0;
}
