#pragma once
#include<iostream>
#include <iomanip>           
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::sqrt;
using std::sqrt;
using std::boolalpha;

namespace Pic10b {
	class vector {
	private:
		int* the_data;
		size_t the_size;
		size_t the_capacity;
		static const int INIT_CAP = 10;

		void reserve(size_t new_capacity);

	public:
		//Big 4
		vector();
		vector(const vector&);
		vector& operator=(const vector&);
		~vector();
		
		//Other member functions
		size_t size() const;
		size_t capacity() const;
		int& operator[](size_t index);
		int operator[](size_t index) const;
		void push_back(int new_value);

		//Operator overloading
		vector& operator+=(const vector& rhs);

	};
}

//non-member Operator overloading
template<typename T>
Pic10c::vector<T> operator*(const Pic10b::vector<T>& v, int x) {
	Pic10b::vector<T> w;
	for (size_t i = 0; i < v.capacity(); ++i) {
		w[i] = x*v[i];
	}
	return w;
}

template<typename T>
Pic10c::vector<T> operator+(const Pic10b::vector<T>& lhs,const Pic10b::vector<T>& rhs) {
	vector<T> w;
	if (lhs.size() == rhs.size()) {
		for (size_t i = 0; i < rhs.size(); ++i)
			w[i] = lhs[i] + rhs[i];
	}
	return w;
}
