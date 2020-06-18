please use

char choice instead of int choice

char car_choice;
std::cout << "Please enter the vehicle types for determing its fuel consumption\n";

do
{
		
	std::cout << "Please enter your choice in number:\n";
	std::cout << "1) Convertable Car\n";
	std::cout << "2) Van\n";
	std::cout << "3) Truck\n";
	std::cout << "4) Do not want to enter any number and to stop\n";
	std::cin >> car_choice;
} while (car_choice != '1' && car_choice != '2' &&
	car_choice != '3' && car_choice != '4');
    
    
if (car_choice=='1')
