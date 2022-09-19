
#include "rsequence.h"
#include <iostream>
#include <cmath>
#include <vector>


float phi(float d) {
	float x = 2;
	for (int i=0; i<10; i++){
		x = pow((1+x), (1/(d+1)));
	}
	return x;
}


RSequence::RSequence(int d, float seed) : 
		d(d), 
		seed(seed)
		{
			float g = phi((float) d);
			for (int i=1; i < d+1; i++){
				basis.push_back(1 / (float) pow(g, i)); 
				current.push_back(0);
			}
		}

std::vector<std::vector<float> > RSequence::sample(int N){
		std::vector<std::vector<float> > sample;

		for (int i=0; i<N; i++){
			current = vec_add(current, basis); 
			vec_mod(current, 1);    // this prevents 'current' from growing indefinitely with number of samples 

			std::vector<float> point = vec_scalar_add(current, seed);
			point = vec_mod(point, 1);
			sample.push_back(point);
		}

		return sample;
	}
	