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

void getUserInput(vector<edge>& edges);

int main()
{
	vector<edge> edges;
	getUserInput(edges);

	for (size_t i = 0; i < edges.size(); ++i)
	{
		cout << "left vertex  =  " << edges[i].leftVertex << endl;	
		cout << "right vertex  =  " << edges[i].rightVertex << endl;
	}
}
