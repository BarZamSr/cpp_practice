#include <cstdlib>
#include <iostream>
#include <cassert>

#include "utils.h"
#include "str.h"


String::String()
{
	data = NULL;
	len = 0;
	cap = 0;
}

String::String(int n)
{	assert(n>0);

	data = new char[n];
	len = 0;
	cap = n;
}

String::String(const char* A)
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

String::String(const char* A, int n): String(n)
{
	assert(A);

	utils::copy(A, data, n);

	len = n;
}

String::String(String& that): String(that.cap)
{
	// one shouldn't be true without the other
	assert((that.data == NULL) == (that.len == 0));

	this.len = that.len;

	if (that.data == NULL && that.len == 0)
	{
		this.data = NULL;
	}
	else
	{
		utils::copy(that.data, this.data, that.len);
	}
}

std::ostream& operator<< (std::ostream& stream, const String& str)
{
	for(int i=0; i < str.len; i++)
	{
		stream << str.data[i];
	}

	return stream;
}
