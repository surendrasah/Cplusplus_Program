// Car_Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include "Car_Sim_Eval.h"

int main()
{  
	std::cout << "Enter the distance value for calculation of fuel\n";
	double car_distance;
	std::cin >> car_distance;

	int car_choice;//change to double to take care of decimal point
	std::cout << "Please enter the vehicle types for determing its fuel consumption\n";

	do
	{
		std::cout << "Please enter your choice in number:\n";
		std::cout << "1) Convertable Car\n";
		std::cout << "2) Van\n";
		std::cout << "3) Truck\n";
		std::cout << "4) Do not want to enter any number and to stop\n";
		std::cin >> car_choice;
	} while (car_choice != 1 && car_choice != 2 &&
		car_choice != 3 && car_choice != 4);

	if (car_choice==1)
	{
		Convertable_Car convert_Car_sim(car_distance);
		double fuel_result1 = convert_Car_sim.fuel_consumption();
		std::cout << "From Car function\n";
		std::cout << fuel_result1 << "\n";
	}
	else if (car_choice == 2)
	{
		Van van_sim(car_distance);
		double fuel_result2 = van_sim.fuel_consumption();
		std::cout << "From Van function\n";
		std::cout << fuel_result2 << "\n";
	}
	else if (car_choice == 3)
	{
		int trail_attachment;
		std::cout << "please provide the value for trailer attachment\n";
		std::cout << "0. Not attaching trailer\n1 or any other number except 0 for attaching trailer \n";
		std::cin >> trail_attachment;

		if (trail_attachment)
		{
			Truck truck_sim(car_distance, trail_attachment);
			double fuel_result4 = truck_sim.fuel_consumption_with_trailer();
			if (fuel_result4 == 0) std::cout << "\nNo value Provided/No Trailer attached, Terminating\n";
			else
				std::cout << "From Truck with trailer function:\n" << fuel_result4 << "\n";
		}
		else
		{
			Truck truck_sim(car_distance, trail_attachment);
			double fuel_result4 = truck_sim.fuel_consumption_with_trailer();
			if (fuel_result4 == 0) std::cout << "\nNo value Provided/No Trailer attached, Terminating\n";
			else
				std::cout << "From Truck with trailer function:\n" << fuel_result4 << "\n";
		}
	}

	else	std::cout << "Press anykey to terminate the program";

	/*
	Vehicle vehicles(42.195, 10, 5); //different signature with distance, weight and height
	double fuel_result0 = vehicles.fuel_consumption();
	std::cout << "Base class vehicle function\n";
	std::cout << fuel_result0 << "\n";


	Vehicle * vehicleptr;
	Convertable_Car con_car(42.195);

	vehicleptr = &con_car;
	double fuel_resultc = vehicleptr->fuel_consumption();
	std::cout << "From Car function\n";
	std::cout << fuel_resultc << "\n";

	Van van(42.195);
	vehicleptr = &van;
	double fuel_resultv = vehicleptr->fuel_consumption();
	std::cout << "From van function\n";
	std::cout << fuel_resultv << "\n";

	Truck truck(4);
	vehicleptr = &truck;
	double fuel_resultt = vehicleptr->fuel_consumption();
	//double fuel_resultt = vehicleptr->fuel_consumption_with_trailer();//will throw compile time error
	std::cout << "From truck function\n";
	std::cout << fuel_resultt << "\n";


	Truck truck_sim(42.195);
	double fuel_result3 = truck_sim.fuel_consumption();
	std::cout << "From Truck wiithout trailer function\n";
	std::cout << fuel_result3 << "\n";

	Truck truck_sim_with_trailer(car_distance);
	double fuel_result4 = truck_sim.fuel_consumption_with_trailer();
	std::cout << "From Truck with trailer function\n";
	std::cout << fuel_result4 << "\n";*/

	return 0;
}

