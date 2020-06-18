#include "pch.h"
#include "Car_Sim_Eval.h"
#include <iostream>


//=========Vehicle Base Class implementaion starts=========
//Vehicle default constructor
Vehicle::Vehicle() = default;

//vehicle paramterized constructor
Vehicle::Vehicle(double dist) : distance { dist }{}





//destructor call for vehicle
Vehicle::~Vehicle() = default;
//========Vehicle Class implementation ends===========


//=========Convertable_Car Class implementation  starts=========
Convertable_Car::Convertable_Car(double dist)
{
	distance = dist;
	vehicle_height = 1.5; //REQ_CAR_4
	vehicle_weight = 500; //REQ_CAR_5
}

//REQ_ID_1: Fuel consumption for Car
double Convertable_Car::fuel_consumption()
{
	roll_resistance = c_rollresistance * vehicle_weight; //REQ_ID_2:  0.75 *vehicle weight
	wind_resistance = c_windresistance * vehicle_height;//REQ_ID_3: 0.2 *vehicle height
	fuel_consume = distance * roll_resistance + distance * wind_resistance;
	return fuel_consume;
}

Convertable_Car::~Convertable_Car() = default;
//========Convertable_Car Class implementation ends=======

//========Van Class implementation start=======
Van::Van(double dist)
{
	distance = dist;
	vehicle_height = 1.5; //REQ_VAN_6
	vehicle_weight = 4000; //REQ_VAN_7
}

//REQ_ID_1: Fuel consumption for Van
double Van::fuel_consumption()
{
	roll_resistance = c_rollresistance * vehicle_weight; //REQ_ID_2:  0.75 *vehicle weight
	wind_resistance = c_windresistance * vehicle_height; //REQ_ID_3: 0.2 *vehicle height
	fuel_consume = distance * roll_resistance + distance * wind_resistance;
	return fuel_consume;
}

Van::~Van() = default;
//======Van Class implementation  ends========


//======Truck Class implementation starts=====

Truck::Truck(double dist)
{
	distance = dist;
	vehicle_height = 4; //REQ_TRUCK_8
	vehicle_weight = 5000; // REQ_TRUCK_9
	//isTrailer = 0; //REQ_TRUCK_10 : checking for trailer attachment
	empty_trailer_weight = 500; //REQ_TRUCK_11
	full_trailer_weight = 30000;  //REQ_TRUCK_12
}


//fuel consumption of truck without without trailer
double Truck::fuel_consumption() 
{
	roll_resistance = c_rollresistance * vehicle_weight;
	wind_resistance = c_windresistance * vehicle_height;
	fuel_consume = distance * roll_resistance + distance * wind_resistance;
	return fuel_consume;

}

//REQ_TRUCK_14- Calculation for fuel consumption of truck with empty or full weight of trailer 
double Truck::fuel_consumption_with_trailer()
{
	//Ask the user for selection of trailer types
	std::cin.ignore(32767, '\n');
	std::cout << "Please enter if you need trailer to be attached with truck for calculation\n";
	std::cout << "0. ->No - trailer not required\n";
	std::cout << "1 or other number except 0-> Yes - attach trailer\n";
	std::cin >> isTrailer; //REQ_TRUCK_10 : user input for trailer attachment
	
	if (isTrailer)
	{
		
		std::cin.ignore(32767,'\n');
		std::cout << "You are looking for fuel consumption of truck with trailer\n";
		int trailer_choice_num;
		do
		{
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
//=====Truck Class implementation  ends=====