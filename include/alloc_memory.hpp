#ifndef ALLOC_MEMORY_HPP
#define ALLOC_MEMORY_HPP

#include <iostream>

unsigned**	allocMemory(const size_t size);
void		freeMemory(unsigned** matrix, const size_t size);
void		fillZero(unsigned** matrix, const size_t size);

#endif  /* ALLOC_MEMORY_HPP */
