#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <math.h>

using boost::multiprecision::cpp_dec_float_100;
using namespace std;

int main(int argv, char* argc[]) {
	// To do - give the option to find the force for the planet based on gravity here
	// www.physicsclassroom.com/class/circles/Lesson-4/Mathematics-of-Satellite-Motion

	cpp_dec_float_100 G("0.00000000006673");
	cpp_dec_float_100 M("5980000000000000000000000");
	cpp_dec_float_100 R("6470000");

	cpp_dec_float_100 v(sqrt((G * M) / R));

	cout << "This is an example problem with a satellite orbiting at a height of " << R << "m, from the centre of the Earth." << endl;
	cout << "The mass and gravitational force are values for the Earth." << endl;
	cout << "The equation used here is v = sqrt((G*M / R))" << endl << endl;

	cout << "v = sqrt((" << G << " * " << M << ") / " << R << "))" << endl << endl;

	cout << "  = " << v << "m/s" << endl << endl;

	cout << "Therefore, the satellite is moving at a speed of " << v << "m/s about the Earth" << endl << endl;
}