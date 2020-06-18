/**
 * Main function to run the program whether the Car drives or not
 */

#include "Car.h"

int main() {
	Car car;

	// try to drive 10 times
	for (int i = 0; i < 10; i++) {
		bool didDrive = car.drive();
		if (!didDrive) {
			// car is broken! must fix it
			car.fix();
		}
	}

	return 0;
}

