#pragma once
#include<iostream>
#include <iomanip>           // std::boolalpha
#include <string>            // std::string
#include <cmath>             // sqrt(...)

using std::cout;
using std::endl;
using std::string;
using std::sqrt;
using std::boolalpha;

namespace Pic10b {
	//template <typename T>
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
