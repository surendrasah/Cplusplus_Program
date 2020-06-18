//#include "pch.h"
#include "Car_Sim_Eval.h"
#include <iostream>



//=========Vehicle Base Class implementation starts
Vehicle::Vehicle() = default;

Vehicle::Vehicle(double dist, double veh_weight, double veh_height) : distance { dist }, 
vehicle_weight { veh_weight }, vehicle_height { veh_height }{}


//REQ_ID_1: Fuel consumption
double Vehicle::fuel_consumption()
{
	roll_resistance = c_rollresistance * vehicle_weight;  //REQ_ID_2:  0.75 *vehicle weight
	wind_resistance = c_windresistance * vehicle_height;  //REQ_ID_3: 0.2 *vehicle height
	fuel_consume = distance * roll_resistance + distance * wind_resistance; //REQ_ID_1
	return fuel_consume;
}

/*double Vehicle::fuel_consumption_with_trailer() //need to add trailer value
{
	//ask the user for selection of trailer types
	std::cout << "You are looking for fuel consumption truck with trailer\n";
	std::cout << "Please enter your choice in number:\n 1. Empty Trailer\n 2. Full Weight of Trailer\n";
	std::cin.ignore();
	int choice_num;
	std::cin >> choice_num;
	double consume= fuel_consumption();

	//REQ_TRUCK_14- Calculation for fuel consumption with empty or full weight of trailer
	if (choice_num)
		fuel_consume = consume+ distance * c_trailerresistance*empty_trailer_weight;//REQ_TRUCK_13 -only muliplication part belongs(trailresistance *empty trailer)
	else
		fuel_consume = consume+ distance * c_trailerresistance*full_trailer_weight;//REQ_TRUCK_13 -only muliplication part belongs(trailresistance *full weight trailer)
	return fuel_consume;
}*/

Vehicle::~Vehicle() = default;
//========Vehicle implementation ends=========


//=========Convertable_Car  implementation starts ==========
Convertable_Car::Convertable_Car(double dist)
{
	distance = dist;
	vehicle_height = 1.5; //REQ_CAR_4
	vehicle_weight = 500; //REQ_CAR_5
}

//REQ_ID_1: Fuel consumption
double Convertable_Car::fuel_consumption()
{
	roll_resistance = c_rollresistance * vehicle_weight;
	wind_resistance = c_windresistance * vehicle_height;
	fuel_consume = distance * roll_resistance + distance * wind_resistance;
	return fuel_consume;
}

Convertable_Car::~Convertable_Car() = default;
//========Convertable_Car implementation  ends============

//========Van Class implementation starts ==============
Van::Van(double dist)
{
	distance = dist;
	vehicle_height = 1.5; //REQ_VAN_6
	vehicle_weight = 4000; //REQ_VAN_7
}

/*double Van::fuel_consumption()
{
	roll_resistance = c_rollresistance * vehicle_weight;
	wind_resistance = c_windresistance * vehicle_height;
	fuel_consume = distance * roll_resistance + distance * wind_resistance;
	return fuel_consume;
}*/

Van::~Van() = default;
//======Van Class implementation ends=============


//======Truck Class implementation starts===========

Truck::Truck(double dist, bool istrailer_attached)
{
	distance = dist;
	vehicle_height = 4; //REQ_TRUCK_8
	vehicle_weight = 5000; // REQ_TRUCK_9
	isTrailer = istrailer_attached; //REQ_TRUCK_10 : checking for trailer attachment
	empty_trailer_weight = 500; //REQ_TRUCK_11
	full_trailer_weight = 30000;  //REQ_TRUCK_12
}


//for truck without trailer
/*double Truck::fuel_consumption() 
{
	roll_resistance = c_rollresistance * vehicle_weight;
	wind_resistance = c_windresistance * vehicle_height;
	fuel_consume = distance * roll_resistance + distance * wind_resistance;
	return fuel_consume;

}*/

//REQ_TRUCK_14- Calculation for fuel consumption with empty or full weight of trailer 
double Truck::fuel_consumption_with_trailer()
{
	//ask the user for selection of trailer type	

	if (isTrailer)  
	{
		std::cin.ignore(32767, '\n');
		
		int trailer_choice_num;
		do
		{
			std::cout << "You are looking for fuel consumption of truck with trailer\n";
			std::cout << "Please enter your choice in number:\n";
			std::cout << "1. Empty Trailer\n";
			std::cout << "2. Full Weight of Trailer\n";
			std::cout << "3. Do not want to enter any number and to stop\n";
			std::cin >> trailer_choice_num;
		} while (trailer_choice_num != 1 && trailer_choice_num != 2 &&
			trailer_choice_num != 3);

		//fuel consumption of truck with trailer
		if (trailer_choice_num == 1)
		{
			std::cout << "fuel consumption of truck with Empty trailer\n";
			double consume = fuel_consumption(); //truck fuel calculation without trailer
			fuel_consume = consume + distance * c_trailerresistance*empty_trailer_weight;//REQ_TRUCK_13 -trailer resisatnce[(trailresistance(0.05) *empty trailer]
			return fuel_consume;
		}
		else if (trailer_choice_num == 2)
		{
			std::cout << "fuel consumption of truck with full weight trailer\n";
			double consume = fuel_consumption(); //truck fuel calculation without trailer
			fuel_consume = consume + distance * c_trailerresistance*full_trailer_weight;//REQ_TRUCK_13 -trailer resisatnce[(trailresistance(0.05) *full weight trailer]
			return fuel_consume;
		}
		else std::cout << "Terminating the calculation\n";
	}
	else
	{
		std::cout << "Fuel consumption for truck without attaching trailer:\n";
		std::cout << fuel_consumption();
	}
	return 0;
}
Truck::~Truck() = default;

//========Truck Class implementation ends============