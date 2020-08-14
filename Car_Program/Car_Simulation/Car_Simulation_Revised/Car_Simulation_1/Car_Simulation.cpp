// Car_Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
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
	
	Vehicle * vehicleptr;
	if (car_choice==1)
	{
		Convertable_Car convert_Car_sim(car_distance);
		vehicleptr = &convert_Car_sim;
		double fuel_result1 = vehicleptr->fuel_consumption();
		std::cout << "From Car function\n";
		std::cout << fuel_result1 << "\n";
	}
	else if (car_choice == 2)
	{
		Van van_sim(car_distance);
		vehicleptr = &van_sim;
		double fuel_result2 = vehicleptr->fuel_consumption();
		std::cout << "From Van function\n";
		std::cout << fuel_result2 << "\n";
	}
	else if (car_choice == 3)
	{
		Truck truck_sim(car_distance);
		double fuel_result4 = truck_sim.fuel_consumption_with_trailer();
		if (fuel_result4==0) std::cout << "\nNo value Provided/No Trailer attached, Terminating\n";
		else
		std::cout << "From Truck with trailer function:\n" << fuel_result4 << "\n";
		
	}

	else	std::cout << "Press anykey to terminate the program";
	delete vehicleptr;

	return 0;
}

