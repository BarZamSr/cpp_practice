#ifndef LIST
#define LIST

#include <cstdlib>
#include <iostream>
#include <cassert>

#include "utils.cpp"

template <class T>
class List {
public:
	List() {
		std::cout << '+' << std::endl;
		array = NULL;
		len = 0;
		cap = 0;
	}
	List(int n): List() {
		assert(n >= 0);

		if (n > 0) {
			array = new T[n];
			len = 0;
			cap = n;
		}
	}
	List(std::initializer_list<T> A): List(A.size()) {
		len = A.size();
		utils::copy(A.begin(), array, A.size());
	}
	List(T const* A, int n): List(n) {
		assert(A != NULL);

		utils::copy(A, array, n);
		len = n;
	}
	List(List const& other): List(other.cap) {
		len = other.len;

		if (other.len != 0) {
			assert(other.len > 0 && other.array != NULL);
			utils::copy(other.array, this->array, other.len);
		}
	}
	~List() {
		delete[] array;
	}

	int getLen() const {
		return len;
	}

	int find(T object) {
		return find(object, 0, len);
	}
	int find(T object, int start) {
		return find(object, start, len);
	}
	int find(T object, int start, int end) {
		assert(end <= len);
		for(int i = start; i < end; i++) {
			if (array[i] == object) return i;
		}
		return ERR_VAL;
	}
	int find(List const& subList) {
		return find(subList, 0, len);
	}
	int find(List const& subList, int start) {
		return find(subList, start, len);
	}
	int find(List const& subList, int start, int end) {
		for(int i=0; i<len; i++) {
			for(int j=0; i+j<len; j++) {
				if(j == subList.len) return i;
				if(array[i+j] != subList[j]) break;
			}
		}
		return ERR_VAL;
	}

	List<List<T>> split(T c) {
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

	// element access
	T & operator[] (int index) {
		if(index < 0) {
			assert(0-index <= len);
			return array[len + index];
		}
		else {
			assert(index < len);
			return array[index];
		}
	}
	const T & operator[] (int index) const {
		if(index < 0) {
			assert(0-index <= len);
			return array[len + index];
		}
		else {
			assert(index < len);
			return array[index];
		}
	}
	T const* begin() const {
		return array;
	}
	T const* end() const {
		return array + len;
	}

	List<T> operator+ (T element) {
		List<T> sum(len + 1);
		return sum;
	}

	List<T> operator+ (List<T> const& other) {
		List<T> sum(len + other.len);
		sum.array = new T[sum.len];

		utils::copy(array, sum.array, len);
		utils::copy(other.array, sum.array + len, other.len);

		return sum;
	}

	List<T> operator* (int n) {
		assert(n > 0);

		List<T> product(len * n);

		for(int i=0; i<n; i++) {
			utils::copy(
				array,
				product.array + (len * i),
				len
			);
		}

		product.len = len * n;

		return product;
	}
private:
	T* array;
	int len, cap;
};

template <class T>
std::ostream & operator<< (std::ostream & stream, List<T> const& list) {
	int i;

	stream << '[';
	for(i=0; i<list.getLen()-1; i++) {
		stream << list[i] << ", ";
	}
	stream << list[i] << ']';
	return stream;
}

#endif
