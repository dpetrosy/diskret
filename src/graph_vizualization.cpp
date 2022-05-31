#include "../include/graph_vizualization.hpp"

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

void graphViz(vector<edge>& edges, const std::string& fileName)
{
    std::fstream pngFile;
    pngFile.open("data/" + fileName, std::ios::out);

    if (!pngFile.is_open())
    {
        std::cerr << "Can not open file \"" << fileName << "\", try again!";
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
