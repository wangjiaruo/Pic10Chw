#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using std::cout;
using std::endl;
using std::string;
using std::sqrt;
using std::sqrt;
using std::boolalpha;

namespace Pic10c{
	class vector{
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
	
	}
}

