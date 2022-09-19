#ifndef RSEQUENCE
#define RSEQUENCE

#include <vector>
#include <cmath>


void print_vec(std::vector<float> &vec);
float phi(float d);

// definition of templates is sometimes problematic if in .cpp 
// https://stackoverflow.com/questions/3008541/template-class-symbols-not-found
template <typename T>
std::vector<T> vec_add(std::vector<T> &a, std::vector<T> &b){
	std::vector<T> out;
	for (int i=0; i<a.size(); i++){
		out.push_back(a.at(i) + b.at(i));
	}
	return out;
}

template <typename T>
std::vector<T> vec_mod(std::vector<T> &a, int m){
	for (T& e: a) {
	    e = fmod(e, m);
	}
	return a;
}

template <typename T>
std::vector<T> vec_scalar_add(std::vector<T> a, T b){
	for (T & e: a) {
	    e = e + b;
	}
	return a;
}


class RSequence {

	private:
		int d;
		float seed; 
		std::vector<float> basis;
		std::vector<float> current;   // current sample, excluding the seed 
	
	public:
		RSequence(int d, float seed); 
		std::vector<std::vector<float> > sample(int N);

};

#endif
