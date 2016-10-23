#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <math.h>
#include "orbitalSpeed.h"

using boost::multiprecision::cpp_dec_float_100;
using namespace std;

int main(int argv, char* argc[]) {
	// To do - give the option to find the force for the planet based on gravity here
	// www.physicsclassroom.com/class/circles/Lesson-4/Mathematics-of-Satellite-Motion

	cout << "This program calculated orbital speed of an object. For example, a Satellite orbiting the Earth." << endl;
	cout << "The equation used here is v = sqrt((G*M / R))" << endl << endl;

	string sG;
	cout << "Please enter the value for G, in N*m^2/kg^2 (gravitational force of the object the satellite is orbiting)" << endl;
	cout << "For example, 0.00000000006673 (this is for Earth)" << endl;
	cin >> sG;
	//sG = "0.00000000006673";

	string sM;
	cout << "Please enter the value for M in kg (mass of object the satellite is orbiting)";
	cout << "For example, 5,980,000,000,000,000,000,000,000 (this is for Earth)" << endl;
	cin >> sM;
	//sM = "5980000000000000000000000";

	string sR;
	cout << "Please enter the value for R, in meters (radius of the orbiting object)";
	cout << "For example, 6470000" << endl;
	cin >> sR;
	//sR = "6470000";

	OrbitSpeed orbitSpeed = OrbitSpeed(cpp_dec_float_100(sG), cpp_dec_float_100(sM), cpp_dec_float_100(sR));
	cpp_dec_float_100 v = orbitSpeed.getVelocity();

	orbitSpeed.printEquationWithValues();

	cout << "  = ";
	orbitSpeed.printVelocity();
	cout << endl;

	cout << "Therefore, the satellite is moving at a speed of " << v << "m/s about the Earth" << endl << endl;
}