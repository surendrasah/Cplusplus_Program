// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "VectorMatrix.h"
#include<vector>


int main()
{
	
	Matrix matrixobj;
	std::vector<std::vector<double> > mat;
	int row_mat, col_mat;
	std::cout << "Enter the number of rows for matrix\n";
	std::cin >> row_mat;
	std::cout << "Enter the number of columns for matrix\n";
	std::cin >> col_mat;
	// Initializing the vector of vectors i.e. Matrix 
	// Elements to insert in column 
	matrixobj.initializeMatrix(mat, row_mat, col_mat);
	matrixobj.printMatrix(mat);


	Vector vectorobj;
	std::vector<double> vec;
	int col_vect;
	std::cout << "Enter the number of elements for vector\n";
	std::cin >> col_vect;
	// Initializing the vector
	vectorobj.initializeVector(vec, col_vect);
	vectorobj.printVector(vec);

	
	Operation operationobj;
	double scalar;

	//lets ask user to enter choice for operations
	double operation_choice;//to take care of decimal value
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
	} while (operation_choice != 1 && operation_choice != 2 &&
		operation_choice != 3 && operation_choice != 4 && operation_choice != 5 && operation_choice != 6 
		&& operation_choice != 7 && operation_choice != 8);

	std::cin.ignore(32767, '\n');

	// matrix multipication with vector
	if (operation_choice == 1)
	{	

		operationobj.matMulVect(mat, vec);

	}

	//scalar multiplication with matrix
	else if (operation_choice == 2)
	{
		

		std::cout << "You choose the Scalar elements for multiplying with Matrix\n";
		std::cin >> scalar;
		operationobj.scalarmulmat(mat, scalar);

	}


	//scalar addition with matrix
	else if (operation_choice == 3)
	{
		
		std::cout << "You choose the Scalar elements for addition with Matrix\n";
		std::cin >> scalar;
		operationobj.scalaraddmat(mat, scalar);

	}

	//scalar multiplication with Vector
	else if (operation_choice == 4)
	{

		std::cout << "You choose the Scalar elements for multiplying with Vector\n";
		std::cin >> scalar;
		operationobj.scalarmulvec(vec, scalar);

	}

	//scalar addition with Vector
	else if (operation_choice == 5)
	{

		std::cout << "You choose the Scalar elements for addition with Vector\n";
		std::cin >> scalar;
		operationobj.scalaraddvec(vec, scalar);

	}

	//addition with matrices
	else if (operation_choice == 6)
	{
		std::cout << "You choose the addition with matrices\n";
		std::vector<std::vector<double> > mat2;
		int row_mat2, col_mat2;
		std::cout << "Enter the number of rows for matrix\n";
		std::cin >> row_mat2;
		std::cout << "Enter the number of columns for matrix\n";
		std::cin >> col_mat2;
		// Initializing the vector of vectors i.e. Matrix 
		matrixobj.initializeMatrix(mat2, row_mat2, col_mat2);
		matrixobj.printMatrix(mat2);

		operationobj.mataddmat(mat, mat2);

	}

	//addition with two Vectors
	else if (operation_choice == 7)
	{

		std::vector<double> vec2;
		int col_vect2;
		std::cout << "Enter the number of elements for vector\n";
		std::cin >> col_vect2;
		// Initializing the vector
		vectorobj.initializeVector(vec2, col_vect2);
		vectorobj.printVector(vec2);

		operationobj.vectaddvect(vec, vec2);

	}

	else	std::cout << "Press anykey to terminate the program";



	return 0;
}
