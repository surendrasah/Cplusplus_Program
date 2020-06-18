// program_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<ctype.h>
#include <charconv>


int main()
{
	std::cout << "Using enum to choose the choice\n";

	enum cars { Convertable_car = 1, Van, Truck, No_Car_Selected };
	std::cout << "enter user choice for these cars:\n";
	int choice; //change it double and it will accept double value and wonot create proble for enum as well

	cars Car;
	std::cout << "value for 1 is " << Convertable_car << "\n";
	std::cout << "value for 4 is " << No_Car_Selected << "\n";

	do
	{
		std::cout << "By using enum:\n";
		std::cout << "enter user choice for these cars in Integer:\n";
		std::cout << "1- Convertable car:\n";
		std::cout << "2- Van:\n";
		std::cout << "3- Truck:\n";
		std::cout << "4- No_Car_Selected:\n";
		std::cin >> choice;
	} while (choice != cars::Convertable_car && choice != cars::Van && choice != cars::Truck && choice != cars::No_Car_Selected);//you can use cars:: to access the enum
	//Before I was trying with int as choice but it doesnot work. if i entered 1.2, it takes 1 , but i donot want it to so
	//now i tried using enum, but it does not acccept double value all. when we give double value, it runs infinite times/occurs problem. so it accept only integer

	if (choice == 1) std::cout << "1 is selected\n";
	else if (choice == 2) std::cout << "2 is selected\n";
	else if (choice == 3) std::cout << "3 is selected\n";
	else std::cout << "No Car Selected is selected\n";

//===============Another Method======string::front()::works for single digit==========
	int car_choice = -1;
	do
	{
		std::cout << "By decalring as string::front():\n";
		std::cout << "enter user choice for these cars in Integer:\n";
		std::cout << "1- Convertable car:\n";
		std::cout << "2- Van:\n";
		std::cout << "3- Truck:\n";
		std::cout << "4- No_Car_Selected:\n";
		std::string car_choice_string;
		std::cin >> car_choice_string;	

		//front-used to reference a first character of the string.
		//the below is only single digit
		if (car_choice_string.size() == 1 && isdigit(car_choice_string.front()))
			car_choice = car_choice_string.front() - '0';//converts to decimal value
		
		else
			std::cout << "no proper input";
		std::cout << "the value entered is "<<car_choice << "\n";

	} while (car_choice != cars::Convertable_car && car_choice != cars::Van && car_choice != cars::Truck
		&& car_choice != cars::No_Car_Selected);

	if (car_choice == 1) std::cout << "1 is selected\n";
	else if (car_choice == 2) std::cout << "2 is selected\n";
	else if (car_choice == 3) std::cout << "3 is selected\n";
	else std::cout << "No Car Selected is selected\n";

	//=======Another Method======string=====
	//int car_choice1 = -1;
	std::string car_choice1;
	do
	{
		std::cout << "by declaring as string:\n";
		std::cout << "enter user choice for these cars:\n";
		std::cout << "1- Convertable car:\n";
		std::cout << "2- Van:\n";
		std::cout << "3- Truck:\n";
		std::cout << "4- No_Car_Selected:\n";
		
		std::cin >> car_choice1;

	} while (car_choice1 != "1" && car_choice1 != "2" && car_choice1 !="3"
		&& car_choice1 != "4");

	if (car_choice1 == "1") std::cout << "1 is selected\n";
	else if (car_choice1 == "2") std::cout << "2 is selected\n";
	else if (car_choice1 == "3") std::cout << "3 is selected\n";
	else std::cout << "No Car Selected is selected\n";

	//=======Another Method===double========

	double car_choice2 = -1;
	do
	{
		std::cout << "By decalring as double:\n";
		std::cout << "enter user choice for these cars in Integer:\n";
		std::cout << "1- Convertable car:\n";
		std::cout << "2- Van:\n";
		std::cout << "3- Truck:\n";
		std::cout << "4- No_Car_Selected:\n";
		
		std::cin >> car_choice2;


	} while (car_choice2 != 1 && car_choice2 != 2 && car_choice2 != 3
		&& car_choice2 != 4);

	if (car_choice2 == 1) std::cout << "1 is selected\n";
	else if (car_choice2 == 2) std::cout << "2 is selected\n";
	else if (car_choice2 == 3) std::cout << "3 is selected\n";
	else std::cout << "No Car Selected is selected\n";


	return 0;



}

