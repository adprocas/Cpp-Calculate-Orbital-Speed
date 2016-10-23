#pragma once
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include <math.h>

struct SecondsToTime {
private:
	boost::multiprecision::cpp_dec_float_100 y;
	boost::multiprecision::cpp_dec_float_100 m;
	boost::multiprecision::cpp_dec_float_100 d;
	boost::multiprecision::cpp_dec_float_100 hr;
	boost::multiprecision::cpp_dec_float_100 mn;
	boost::multiprecision::cpp_dec_float_100 s;

public:
	SecondsToTime(boost::multiprecision::cpp_dec_float_100 input) {
		std::cout << (input / 31557600) << std::endl;
		std::cout << (input / 31557600) << std::endl;
		y = boost::multiprecision::cpp_dec_float_100(int(input / 31557600));
		d = boost::multiprecision::cpp_dec_float_100(int(fmod(input, 31557600) / 86400));
		hr = boost::multiprecision::cpp_dec_float_100(int(fmod(fmod(input , 31557600), 86400) / 3600));
		mn = boost::multiprecision::cpp_dec_float_100(int(fmod(fmod(fmod(input , 31557600) , 86400), 3600) / 60));
		s = boost::multiprecision::cpp_dec_float_100(fmod(fmod(fmod(fmod(input , 31557600) , 86400) , 3600), 60));
	}

	void printTimes() {
		std::cout << "It will take the following amount of time to orbit:" << std::endl;
		std::cout << y << " Years" << std::endl;
		std::cout << d << " Days" << std::endl;
		std::cout << hr << " Hours" << std::endl;
		std::cout << mn << " Minutes" << std::endl;
		std::cout << s << " Seconds" << std::endl;
	}
};

struct OrbitSpeed {
private:
	boost::multiprecision::cpp_dec_float_100 _G;
	boost::multiprecision::cpp_dec_float_100 _M;
	boost::multiprecision::cpp_dec_float_100 _R;
	boost::multiprecision::cpp_dec_float_100 _v;
	boost::multiprecision::cpp_dec_float_100 _cir; // Circumference
	boost::multiprecision::cpp_dec_float_100 _t;
	SecondsToTime _times;

public:
	OrbitSpeed(boost::multiprecision::cpp_dec_float_100 G,
		boost::multiprecision::cpp_dec_float_100 M,
		boost::multiprecision::cpp_dec_float_100 R) :
		_G(G),
		_M(M),
		_R(R),
		_v(sqrt((_G * _M) / _R)),
		_cir(2 * boost::math::constants::pi<boost::multiprecision::cpp_dec_float_100>()  * _R),
		_t(boost::multiprecision::cpp_dec_float_100(_cir / _v)),
		_times(_t)
	{};

	boost::multiprecision::cpp_dec_float_100 getVelocity() {
		return _v;
	}

	void printEquationWithValues() {
		std::cout << "v = sqrt((" << _G << " * " << _M << ") / " << _R << "))" << std::endl;
	}

	void printInterestingInformation() {
		printDistanceTravelled();
		std::cout << std::endl;
		printTimeToOrbit();
		std::cout << std::endl;
		_times.printTimes();
	}

	void printVelocity() {
		std::cout << _v << "m/s";
	}

	void printDistanceTravelled(int orbits = 1) {
		std::cout << "Distance travelled in " << orbits << " orbits " << _cir * orbits << "m" << std::endl;
		std::cout << "This is equal to travelling from NYC to LA " << (_cir * orbits) / 440000 << " times";
	}

	void printTimeToOrbit() {
		std::cout << "Time to orbit - " << _t << " seconds.";
	}
};