#include "rsequence.h"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]){

	int d = atoi(argv[1]);
	int N = atoi(argv[2]);
	float seed = 0.5;

	RSequence rand(d, seed);

	std::vector<std::vector<float> > data = rand.sample(N);
	for (auto vec: data){
		print_vec(vec);
	}
	// std::cout<<"new sample"<<std::endl;

	std::vector<std::vector<float> > data_ = rand.sample(N);
	for (auto vec: data_){
		print_vec(vec);
	}

    return 0;
}


