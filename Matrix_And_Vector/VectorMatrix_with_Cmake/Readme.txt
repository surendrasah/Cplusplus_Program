/*There are three files.
Car_Simulation.cpp as the main file for running the program
Car_Sim_Eval.cpp contains all the attributes and methods implementation
Car_Sim_Eval.h is a header files which contains the body/decalration of classes

All most , all the variable name gives the meaning by themself, so i have not explained on anything.

I didnot find anything to comment as its straight forward implementation program

Vehicle as base class

double fuel_consume - total fuel consumed
double distance - total distance covered by vehicle
double roll_resistance - roll resistance on vehcile
double wind_resistance -wind resistance on vehicle
double vehicle_weight  - vehicle weight
double vehicle_height  - vehicle height

Convertable_Car, Van  and Truck are child class of Vehicle class



fuel_consumption_with_trailer() //for calculating the total fuel consumed for the given distance and vehicle type including trailer. Here an input needs to be given if there is empty or full weight  trailer.


double empty_trailer_weight;  //later on try to use double vehicle_weight;
double full_trailer_weight;	//later on try to use double car_height;
bool isTrailer;

fuel_consumption() // for calculating the total fuel consumed for the given distance and vehicle type