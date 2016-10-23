#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <math.h>

struct OrbitSpeed {
private:
	boost::multiprecision::cpp_dec_float_100 _G;
	boost::multiprecision::cpp_dec_float_100 _M;
	boost::multiprecision::cpp_dec_float_100 _R;
	boost::multiprecision::cpp_dec_float_100 _v;

public:
	OrbitSpeed(boost::multiprecision::cpp_dec_float_100 G,
		boost::multiprecision::cpp_dec_float_100 M, 
		boost::multiprecision::cpp_dec_float_100 R) : 
		_G(G),
		_M(M),
		_R(R),
		_v(sqrt((_G * _M) / _R))
	{};

	boost::multiprecision::cpp_dec_float_100 getVelocity() {
		return _v;
	}

	void printEquationWithValues() {
		std::cout << "v = sqrt((" << _G << " * " << _M << ") / " << _R << "))" << std::endl;
	}

	void printVelocity() {
		std::cout << _v << "m/s" << std::endl;
	}
};