#include "../include/alloc_memory.hpp"

unsigned** allocMemory(const size_t size)
{
	unsigned** matrix = new(std::nothrow) unsigned*[size];
	if (!matrix)
	{
		std::cerr << "ERROR: Can not allocate memory for matrix." << std::endl;
		exit(3);
	}

	for (size_t i = 0; i < size; ++i)
	{
		matrix[i] = new(std::nothrow) unsigned[size];
		if (!matrix[i])
		{
			freeMemory(matrix, i);
			std::cerr << "ERROR: Can not allocate memory for matrix[" << i << "]." << std::endl;
			exit(4);
		}
	}

	fillZero(matrix, size);
	return matrix;
}

void freeMemory(unsigned** matrix, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
		delete [] matrix[i];

	delete [] matrix;
	matrix = nullptr;
}

void fillZero(unsigned** matrix, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			matrix[i][j] = 0;
		}
	}	
}
