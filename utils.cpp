#include <cstddef>
#include <iostream>
#include <cassert>

#include "utils.h"

void utils::copy(const char* src, char* dst, int len)
{
	assert(src && dst);
	assert(len > 0);

	for(int i=0; i<len; i++)
	{
		if(src[i] == '\0')
		{
			std::cerr << "WARNING: Copying null terminator character\n";
		}
		dst[i] = src[i];
	}
}
