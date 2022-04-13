#include "../include/get_input.hpp"

void getUserInput(vector<edge>& edges)
{
	string str;
	size_t i = 0;
	size_t j = 0;
	unsigned left = 0;
	unsigned right = 0;

	std::fstream inputFile;
	string inputFilePath = "data/input.txt";
	inputFile.open(inputFilePath, std::ios::in);
	if (!inputFile.is_open())
	{
		std::cerr << "ERROR: Can not open file \"input.txt\"" << endl;
		exit(1);
	}

	while (getline(inputFile, str))
	{
		i = 0;
		if (isEmpty(str))
			continue;
		left = getNumber(str, i);
		right = getNumber(str, i);

		if (left > 0 && right > 0)
		{
			edges.push_back(edge());
			edges[j].leftVertex = left;		
			edges[j].rightVertex = right;
			++j;
		}
	}

	if (edges.size() == 0)
	{
		std::cerr << "ERROR: input is incorrect." << endl;
		inputFile.close();
		exit (2);
	}
	inputFile.close();
}

bool isEmpty(string& str)
{
	size_t i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return false;
		++i;
	}
	
	return true;
}

unsigned getNumber(string& str, size_t& i)
{
	unsigned vertex = 0;

	while (str[i] && !(str[i] >= '1' && str[i] <= '9'))
		++i;

	size_t j = 0;
	while (isdigit(str[i]) && str[i] && j < VERTEX_DIGITS_MAX_COUNT)
	{
		vertex = vertex * 10 + (str[i] - '0');
		++i;
		++j;
	}

	while (str[i] && str[i] != ' ')
		++i;

	return vertex;
}
