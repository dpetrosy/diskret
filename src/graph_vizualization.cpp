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

bool fileExists(const std::string& name) 
{
    std::fstream userFile;
    userFile.open(name, std::ios::in);

    if (!userFile.is_open())
        return false;
    else
    {
        userFile.close();
        return true;
    }
}

void inputedGraphViz(vector<edge>& edges)
{
    std::fstream pngFile;
    pngFile.open("data/input.dot", std::ios::out);

    if (!pngFile.is_open())
    {
        std::cerr << "Can not open file \"input.dot\", try again!";
        exit(5);
    }

    pngFile << "graph {\n";
    for (auto& it : edges)
    {
        pngFile << "\t" << it.leftVertex << " -- " << it.rightVertex << std::endl;
    }
    pngFile << "}";
    
    pngFile.close();
}
