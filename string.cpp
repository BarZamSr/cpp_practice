#ifndef STRING
#define STRING

#include "list.cpp"

class String: public List<char> {
public:
	String(const char * c_str): List<char>(c_str, utils::c_str_len(c_str)) {
		// hmmm
	}
	String(const char * A, int n): List<char>(A, n) {
		// hmmm
	}

	String operator+ (const String & other) const {
		String sum(*this);
		sum += other;
		return sum;
	}
/*
	int find(const String & sub_str) {
		return find(sub_str, 0, len);
	}
	int find(const String & sub_str, int start) {
		return find(sub_str, start, len);
	}
	int find(const String & sub_str, int start, int end) {
		LOG("find(String)");
		for(int i=0; i<len; i++) {
			for(int j=0; i+j<len; j++) {
				if(j == sub_str.len) return i;
				if(array[i+j] != sub_str[j]) break;
			}
		}
		return ERR_VAL;
	}
*/
	List<String> split(char c = ' ') {
		List<String> sub_strings;

		int curr = find(c), last=0;
		while(curr != ERR_VAL) {
			sub_strings.push(
				String(array+last, curr-last)
			);

			last = curr+1;
			curr = find(c, last);
		}
		sub_strings.push(
			String(array+last, len-last)
		);

		return sub_strings;
	}

	friend std::ostream & operator<< (std::ostream & stream,
						const String & string) {
		for(const char & c: string) {
			stream << c;
		}
		return stream;
	}

private:
	String(int n): List<char>(n) {
		// hmmm
	}
};

#endif
