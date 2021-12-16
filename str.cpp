#include <cstdlib>
#include <cassert>

#include "utils.h"
#include "str.h"

String::String()
{
	data = NULL;
	len = 0;
	cap = 0;
}

String::String(char* A)
{
	assert(A);

	char c;
	int i = 0;

	do
	{
		c = A[i];
		i++;
	} while (c != '\0');

	i--;

	data = new char[i];
	len = i;
	cap = i;

	utils::copy(A, data, i);
}

String::String(char* A, int n)
{
	assert(A);
	assert(n > 0);

	for(int i=0; i<n; i++)
	{
		
