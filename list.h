#pragma once

template <class T>
class List {
public:
	// constructors/destructor
	List();
	List(int);
	List(std::initializer_list<T>);
	List(const T*, int);
	List(List<T> const&);
	~List();

	// getters/setters
	int getLen() const;

	int find(T);
	int find(T, int);
	int find(T, int, int);
	int find(List<T> const&);
	int find(List<T> const&, int);
	int find(List<T> const&, int, int);

	List<List<T>> split(T);

	T& operator[] (int);
	T const& operator[] (int) const;
	T const* begin() const;
	T const* end() const;

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
