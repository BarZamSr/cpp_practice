#pragma once

class String {
public:
	String();
	String(int);
	String(const char*);
	String(const char*, int);
	String(String const&);
	~String();

	int find(char);
	int find(char, int);
	int find(char, int, int);
	int find(String const&);
	int find(String const&, int);
	int find(String const&, int, int);

	bool is_num();
	bool is_alpha();

	std::vector<String> split(char);

	char & operator[] (int) const;

	friend char* begin(String const&);
	friend char* begin(String const*);
	friend char* end(String const&);
	friend char* end(String const*);

	friend std::ostream& operator<< (std::ostream&, const String&);
	friend String operator+ (String const&, String const&);
	friend String operator* (String const&, int);
protected:
	char* data;
	int len, cap;
};

char* begin(String const&);
char* begin(String const*);
char* end(String const&);
char* end(String const*);

std::ostream& operator<< (std::ostream&, String const&);
String operator+ (String const&, String const&);
String operator* (String const&, int);
