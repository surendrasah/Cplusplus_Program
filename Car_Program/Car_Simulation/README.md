Before, I had used this one

//lets ask user to enter choice for operations
	char operation_choice;
	std::cout << "Please enter the choice for different operation for Matrix and Vector\n";

	do
	{

		std::cout << "Please enter your choice in Integer number:\n";
		std::cout << "1) Matrix Multiplication with Vector\n";
		std::cout << "2) Scalar Multiply with Matrix\n";
		std::cout << "3) Scalar Addition with Matrix\n";
		std::cout << "4) Scalar Multiply with Vector\n";
		std::cout << "5) Scalar Addition with Vector\n";
		std::cout << "6) Two Matrix Addition\n";
		std::cout << "7) Two vector Addition\n";
		std::cout << "8) Do not want to perform any operations and please terminate the program\n";
		std::cin >> operation_choice;
	} while (operation_choice != '1' && operation_choice != '2' &&
		operation_choice != '3' && operation_choice != '4' && operation_choice != '5' && operation_choice != '6' 
		&& operation_choice != '7' && operation_choice != '8');
    	std::cin.ignore(32767, '\n');

	// matrix multipication with vector
	if (operation_choice == '1')
	{	

		operationobj.matMulVect(mat, vec);

	}
    
    //This above char operation_choice is not correct way to ask user to enter value. 
    //As a character, it accept only one value, so when we enter 12, it will accept 1 and perform the action accordingly but its not 	what we give.
    //so, just change to 
    int operation_choice;
    //now even this has a problem, when we give 1.3, it takes 1 as input and select the option 1 for action which is not what we want
    //so its better to use 
    double operation_choice
    
    
    //int will work if user doesnot enter double value
    
    //char should never be put here.
    
    //There is a program called Input_from_user.cpp(https://github.com/surendrasah/Cplusplus_Program/edit/master/)  which shows different ways to accept user input.
