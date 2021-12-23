#include <cstdlib>
#include <iostream>
#include <cassert>

#include "utils.h"
#include "list.h"

template <class T>
List<T>::List() {
	std::cout << "new\n";
	array = NULL;
	len = 0;
	cap = 0;
}

template <class T>
List<T>::List(int n): List() {
	assert(n >= 0);

	if (n > 0) {
		array = new T[n];
		len = 0;
		cap = n;
	}
}

template <class T>
List<T>::List(T const* A, int n): List(n) {
	assert(A != NULL);

	utils::copy(A, array, n);
	len = n;
}

template <class T>
List<T>::List(List const& other): List(other.cap) {
	len = other.len;

	if (other.len != 0) {
		assert(other.len > 0 && other.array != NULL);
		utils::copy(other.array, this->array, other.len);
	}
}

template <class T>
List<T>::~List() {
	delete[] array;
}

template <class T>
int List<T>::find(T object) {
	return find(object, 0, len);
}
template <class T>
int List<T>::find(T object, int start) {
	return find(object, start, len);
}
template <class T>
int List<T>::find(T object, int start, int end) {
	assert(end <= len);
	for(int i = start; i < end; i++) {
		if (array[i] == object) return i;
	}
	return ERR_VAL;
}
template <class T>
int List<T>::find(List const& subList) {
	return find(subList, 0, len);
}
template <class T>
int List<T>::find(List const& subList, int start) {
	return find(subList, start, len);
}
template <class T>
int List<T>::find(List const& subList, int start, int end) {
	for(int i=0; i<len; i++) {
		for(int j=0; i+j<len; j++) {
			if(j == subList.len) return i;
			if(array[i+j] != subList[j]) break;
		}
	}
	return ERR_VAL;
}

template <class T>
List<List<T>> List<T>::split(T c) {
	List<List<T>> subLists;

	int curr=find(c), last=0;
	while(curr != ERR_VAL) {
		subLists.append(
			List(array+last, curr-last)
		);

		last = curr+1;
		curr = find(c, last);
	}
	subLists.append(
		List(array+last, len-last)
	);

	return subLists;
}

template <class T>
T & List<T>::operator[] (int index) {
	if(index < 0) {
		assert(0-index <= len);
		return array[len + index];
	}
	else {
		assert(index < len);
		return array[index];
	}
}
template <class T>
T* List<T>::begin() const {
	return array;
}
template <class T>
T* List<T>::end() const {
	return array + len;
}

template <class T>
List<T> operator+ (List<T> const& a, List<T> const& b) {
	List<T> list;
	list.len = list.cap = a.len + b.len;
	list.array = new T[list.len];

	utils::copy(a.array, list.array, a.len);
	utils::copy(b.array, list.array + a.len, b.len);

	return list;
}

template <class T>
List<T> operator* (List<T> const& src, int n) {
	assert(n > 0);

	List<T> list;
	list.len = list.cap = src.len * n;
	list.array = new T[list.len];

	for(int i=0; i<n; i++) {
		utils::copy(
			src.array,
			list.array + (i*src.len),
			src.len
		);
	}

	return list;
}

template <class T>
std::ostream & operator<< (std::ostream & stream, List<T> const& list) {
	for(auto element: list) {
		stream << element;
	}
	return stream;
}
