#pragma once

class String
{
public:
	String();
	String(char*);
	String(char*, int);
	String(String);
protected:
	char* data;
	int len, cap;
};
