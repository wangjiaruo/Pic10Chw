#pragma once
#include<iostream>
#include <iomanip>           
#include <string>            
#include <cmath>            

using std::cout;
using std::endl;
using std::string;
using std::sqrt;
using std::boolalpha;

namespace Pic10b {
	template <typename T>
	class vector {

	private:
		T* the_data;
		size_t the_size;
		size_t the_capacity;
		static const int INIT_CAP = 10;

		void reserve(size_t new_capacity);

	public:
		//Big 4
		vector();
		vector(const vector<T>&);
		vector& operator=(const vector<T>&);
		~vector();


		//Other member functions
		size_t size() const;
		size_t capacity() const;
		T& operator[](size_t index);
		T operator[](size_t index) const;
		void push_back(T new_value);


		//Operator overloading
		vector operator*(T x);
		vector& operator+=(const vector<T>& rhs);

	};



	//********************Implementation Big 4********************
	template<typename T>
	vector<T>::vector<T>() : the_size(0), the_capacity(INIT_CAP) {
		the_data = new T[the_capacity];
		cout << "xxx: " << "Default Constructor called" << endl;
	}

	template<typename T>
	vector<T>::vector<T>(const vector& source) : the_size(source.the_size), the_capacity(source.the_capacity) {
		the_data = new T[the_capacity];
		// Deep copy of internal array
		for (int i = 0; i < the_size; ++i) {
			the_data[i] = source.the_data[i];
		}
		cout << "xxx: " << "Copy Constructor called" << endl;

	}

	template<typename T>
	vector<T>& vector<T>::operator=(const vector& rhs) {
		if (this != &rhs) {     // Self-assignment?
								// Release old memory and request more 
			delete[] the_data;
			the_data = new T[rhs.the_capacity];

			// Shallow copy non-pointers
			the_size = rhs.the_size;
			the_capacity = rhs.the_capacity;

			// Deep copy internal array
			for (int i = 0; i < the_size; ++i)
				the_data[i] = rhs.the_data[i];
		}
		cout << "xxx: " << "Assignment Operartor called" << endl;
		return *this;

	}

	template<typename T>
	vector<T>::~vector<T>() {
		delete[] the_data;
		cout << "xxx: " << "Destructor called" << endl;

	}



	//********************Other member functions********************
	template<typename T>
	size_t vector<T>::size() const {
		return the_size;
	}

	template<typename T>
	size_t vector<T>::capacity() const {
		return the_capacity;
	}

	template<typename T>
	T& vector<T>::operator[](size_t index) {
		return the_data[index];
	}

	template<typename T>
	T vector<T>::operator[](size_t index) const {
		return the_data[index];
	}

	template<typename T>
	void vector<T>::push_back(T new_value) {
		if (the_size == the_capacity)
			reserve(the_capacity + 1);     // `the_data` is reassigned

		the_data[the_size++] = new_value;
	}

	template<typename T>
	void vector<T>::reserve(size_t new_capacity) {
		if (new_capacity > the_capacity) {
			if (new_capacity <= 2 * the_capacity)
				new_capacity = 2 * the_capacity;

			T* old_location = the_data;

			the_data = new T[new_capacity];
			the_capacity = new_capacity;

			for (size_t i = 0; i < the_size; ++i)
				the_data[i] = old_location[i];

			delete old_location;
		}
	}




	//********************Other member Operator overloading********************
	template<typename T>
	vector<T>& vector<T>::operator+=(const vector<T>&rhs) {
		if ((*this).the_size == rhs.the_size) {
			for (int i = 0; i < rhs.size(); ++i)
				the_data[i] += rhs.the_data[i];
		}
		return *this;
	}

	template<typename T>
	vector<T> vector<T>:: operator*(T x) {
		for (size_t i = 0; i < the_size; ++i)
			the_data[i]*= x;
		return *this;
	}

	vector<string> vector<string>:: operator*(string x) {
		for (size_t i = 0; i < the_size; ++i)
			the_data[i] += " "+x;
		return *this;
	}
}


//********************non-member Operator overloading********************
//<<for int and double
template<typename T>
std::ostream& operator<<(std::ostream& out, const Pic10b::vector<T>& v) {
	out << "{";
	for (size_t i = 0; i < v.size()-1; ++i)
		out << v[i] <<", ";
	out << v[v.size() - 1];
	out << "}";
	return out;
}

//<<for string
std::ostream& operator<<(std::ostream& out, const Pic10b::vector<string>& v) {
	out << "[ ";
	for (size_t i = 0; i < v.size() - 1; ++i)
		out << v[i] << ", ";
	out << v[v.size() - 1];
	out << " ]";
	return out;
}

//int||double multiply vector
template<typename T>
Pic10b::vector<T> operator*(int x, Pic10b::vector<T>& v) {
	return v*x;
}

//string "multiplies" vector<string>:this function add to front of  each element in the vector<string>
Pic10b::vector<string> operator*(string s, Pic10b::vector<string>v) {
	for (size_t i = 0; i < s.size(); ++i)
		v[i] = s + " " + v[i];
	return v;
}

//addtion for vector<int>||vector<double>
template<typename T>
Pic10b::vector<T> operator+(const Pic10b::vector<T>& lhs, const Pic10b::vector<T>& rhs) {
	vector<T> clone(lhs);
	if (lhs.size() == rhs.size()) {
		for (size_t i = 0; i < rhs.size(); ++i)
			clone[i] = lhs[i] + rhs[i];
	}
	return clone;
}

//*overloaded for dot product
template<typename T>
T operator*(const Pic10b::vector<T>& v1, const Pic10b::vector<T>& v2) {
	T sum=0;
	if (v1.size() == v2.size()) {
		for (size_t i = 0; i < v1.size(); ++i)
			sum += v1[i] * v2[i];
		return sum;
	}
}

//comparison operators for vector<int> vector <double> 
template<typename T>
bool operator<(const Pic10b::vector<T>& v1, const Pic10b::vector<T>& v2) {
	if (sqrt(v1*v1) < sqrt(v2*v2))
		return true;
	return false;
}

template<typename T>
bool operator>(const Pic10b::vector<T>& v1, const Pic10b::vector<T>& v2) {
	if (v2<v1)
		return true;
	return false;
}

template<typename T>
bool operator>=(const Pic10b::vector<T>& v1, const Pic10b::vector<T>& v2) {
	if (!(v1<v2))
		return true;
	return false;
}

template<typename T>
bool operator<=(const Pic10b::vector<T>& v1, const Pic10b::vector<T>& v2) {
	if (!(v1>v2))
		return true;
	return false;
}

//comparison operators for vector<int> vector <double> vector<string>
template<typename T>
bool operator==(const Pic10b::vector<T>& v1, const Pic10b::vector<T>& v2) {
	if (v1.size() == v2.size()) {
		for (size_t i = 0; i < v1.size(); ++i)
			if (v1[i] != v2[i])
				return false;
		return true;
	}
	return false;
}

template<typename T>
bool operator!=(const Pic10b::vector<T>& v1, const Pic10b::vector<T>& v2) {
	return(!(v1 == v2));
}
