#pragma once

class String {
public:
	String();
	String(int);
	String(const char*);
	String(const char*, int);
	String(String const&);
	~String();

	friend std::ostream& operator<< (std::ostream&, const String&);
	friend String operator+ (String const&, String const&);
	friend String operator* (String const&, int);
protected:
	char* data;
	int len, cap;
};

std::ostream& operator<< (std::ostream&, String const&);
String operator+ (String const&, String const&);
String operator* (String const&, int);
