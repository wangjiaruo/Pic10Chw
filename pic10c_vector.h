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

	//other member functions implemetation
	size_t vector::size() const{
		return the_size;
	}

	size_t vector::capacity() const{
		return the_capacity;
	}

	int vector::operator[](size_t index) const{
		return the_data[index];
	}

	void vector::push_back(int new_value) {
		if(the_size == the_capacity)
			reserve(the capacity + 1);
		the_data[the_size++] = new_value;
	}
	
	void vector::reserve(size_t new_capacity) {
		if (new_capacity > the_capacity) {
			if (new_capacity <= 2 * the_capacity)
				new_capacity = 2 * the_capacity;
			
			int* old_location = the_data;

			the_data = new int[new_capacity];
			the_capacity = new_capacity;

			for(size_t i = 0; i < the_size; ++i)
				the_data[i] = old_location[i];

			delete old_location;
		}
	}

	//Implementation Big 4
	vector::vector(): the_size(0), the_capacity(INIT_CAP) {
		the_data = new int[the_capacity];
	}

	vector::vector(const vector& source): the_size(source.the_size), the_capacity(source.the_capacity) {
		the_data = new int[the_capacity];
		// Deep copy of internal array
		for (int i = 0; i < the_size; ++i) {
			the_data[i] = source.the_data[i];
		}
		cout << "xxx: " << "Copy Constructor..." << endl;
		cout << "xxxxxxxx: " << "This is the copy constructor :xxxxxxxx" << endl;
	}

	vector& vector::operator=(const vector& rhs) {
		if (this != &rhs) {     // Self-assignment?
			// Release old memory and request more
			delete[] the_data;
			the_data = new int[rhs.the_capacity];

			// Shallow copy non-pointers
			the_size = rhs.the_size;
			the_capacity = rhs.the_capacity;

			// Deep copy internal array
			for (int i = 0; i < the_size; ++i)
				the_data[i] = rhs.the_data[i];
		}
		return *this;
		cout << "xxx: " << "Assignment Operartor..." << endl;
		cout << "xxxxxxxx: " << "This is the assignment operator :xxxxxxxx" << endl;
	}

	vector::~vector() {
		delete[] the_data;
		cout << "xxx: " << "Destructor..." << endl;
		cout << "xxxxxxxx: " << "This is the destructor :xxxxxxxx" << endl;
	}

	//Other member Operator overloading
	//template<typename T>
	vector& vector::operator+=(const vector&rhs) {
		if ((*this).the_size == rhs.the_size) {
			for (int i = 0; i < rhs.size(); ++i)
				the_data[i] += rhs.the_data[i];
		}
		return *this;
	}
}
	
