#pragma once

template <class T>
class List {
public:
	List();
	List(int);
	List(const T*, int);
	List(List<T> const&);
	~List();

	int find(T);
	int find(T, int);
	int find(T, int, int);
	int find(List<T> const&);
	int find(List<T> const&, int);
	int find(List<T> const&, int, int);

	List<List<T>> split(T);

	T& operator[] (int);
	T* begin() const;
	T* end() const;

	friend List<T> operator+ (List<T> const&, List<T> const&);
	friend List<T> operator* (List<T> const&, int);
	friend List<T> operator* (List<T> const&, List<T> const&);
protected:
	T* array;
	int len, cap;
};

template <class T>
List<T> operator+ (List<T> const&, List<T> const&);

template <class T>
List<T> operator* (List<T> const&, int);

#include "list.cpp"
