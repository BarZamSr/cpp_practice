#pragma once

class String
{
public:
	String();
	String(int);
	String(const char*);
	String(const char*, int);
	String(String*);

	friend std::ostream& operator<< (std::ostream&, const String&);
protected:
	char* data;
	int len, cap;
};

std::ostream& operator<< (std::ostream&, String const&);

