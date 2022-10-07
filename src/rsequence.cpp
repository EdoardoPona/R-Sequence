
#include "rsequence.h"
#include <iostream>
#include <cmath>
#include <vector>

#include <iomanip>
#include <sstream>
#include <stdexcept>


double phi(double d) {
	double x = 2;
	for (int i=0; i<10; i++){
		x = pow((1+x), (1/(d+1)));
	}
	return x;
}

double RationalApproximation(double t)
{
    // Abramowitz and Stegun formula 26.2.23.
    // The absolute value of the error should be less than 4.5 e-4.
    double c[] = {2.515517, 0.802853, 0.010328};
    double d[] = {1.432788, 0.189269, 0.001308};
    return t - ((c[2]*t + c[1])*t + c[0]) /
        (((d[2]*t + d[1])*t + d[0])*t + 1.0);
}

double NormalCDFInverse(double p)
''' 
credits for this code to the article at https://www.johndcook.com/blog/normal_cdf_inverse/
'''
{
    if (p <= 0.0 || p >= 1.0)
    {
        std::stringstream os;
        os << "Invalid input argument (" << p
           << "); must be larger than 0 but less than 1.";
        throw std::invalid_argument( os.str() );
    }

    // See article above for explanation of this section.
    if (p < 0.5)
    {
        // F^-1(p) = - G^-1(p)
        return -RationalApproximation( sqrt(-2.0*log(p)) );
    }
    else
    {
        // F^-1(p) = G^-1(1-p)
        return RationalApproximation( sqrt(-2.0*log(1-p)) );
    }
}

RSequence::RSequence(int d, double seed) : 
		d(d), 
		seed(seed)
		{
			double g = phi((double) d);
			for (int i=1; i < d+1; i++){
				basis.push_back(1 / (double) pow(g, i)); 
				current.push_back(0);
			}
		}

std::vector<std::vector<double> > RSequence::sample_uniform(int N){
		std::vector<std::vector<double> > sample;

		for (int i=0; i<N; i++){
			current = vec_add(current, basis); 
			vec_mod(current, 1);    // this prevents 'current' from growing indefinitely with number of samples 

			std::vector<double> point = vec_scalar_add(current, seed);
			point = vec_mod(point, 1);
			sample.push_back(point);
		}

		return sample;
	}
	
std::vector<std::vector<double> > RSequence::sample_normal(int N){
		std::vector<std::vector<double> > sample = sample_uniform(N);
		for (auto& point : sample){
			for (double& c : point){
				c = NormalCDFInverse(c);
			}
		}
		return sample;
	}
