
// Take a look at Car.cpp to see how to define the Car class.
/*

Header file for the class and its methods and data members

*/

#ifndef CAR_H
#define CAR_H
class Car {

	bool in_working_condition_;
public:
	Car();
	void wearAndTear();
	bool drive();
	void fix();
};

#endif