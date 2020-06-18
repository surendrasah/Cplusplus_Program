//This file contains the definition of Matix and Vector class
#include "VectorMatrix.h"
#include <iostream>
#include<vector>

//============Matrix  Class Starts===============
void Matrix::initializeMatrix(std::vector<std::vector<double> > &mat1, int row, int col)
{

	std::cout << "From Initialize method of Matrix\n";
	std::cout << "Enter the "<< row * col <<" elements for matrix\n";
	int number;

	// Inserting elements into vector 
	for (unsigned int i = 0; i < row; i++) {
		// Vector to store column elements 
		std::vector<double> v1;
		for (unsigned int j = 0; j < col; j++) {
			std::cin >> number;
			v1.push_back(number);			
		}
		// Pushing back above 1D vector to create the 2D vector 
		mat1.push_back(v1);
	}
	


}

void Matrix::printMatrix(const std::vector<std::vector<double> >& mat1)
{

	std::cout << "From print method of Matrix\n";
	std::cout << "Matrix elements are:\n";
	// Displaying the 2D vector 
	for (unsigned  int i = 0; i < mat1.size(); i++) {
		for (unsigned int j = 0; j < mat1[i].size(); j++)
			std::cout << mat1[i][j] << " ";
		std::cout << std::endl;
	}

}
//============Matrix  Class Ends===============


//============Vector  Class Starts===============
 void Vector::initializeVector(std::vector<double> &vec1, int num)
 {

	 std::cout << "From Intialize method of Vector\n";
	 std::cout << "Enter the "<<num<<" elements in the vector:\n";
	 int vect;
	 for (unsigned int i = 0; i < num; i++)
	 {
		 std::cin >> vect;
		 vec1.push_back(vect);

	 }

 }

 void Vector::printVector(const std::vector<double>& vec1)
 {

	 std::cout << "From print method of Vector\n";
	 std::cout << "Vector elemets are:\n";

	 
	 for (unsigned int i = 0; i < vec1.size(); i++)
		 std::cout << vec1[i] << "\n";

 }
  //============Vector  Class Ends===============


 //============Operation Class Starts===============
 void Operation::matMulVect(const std::vector<std::vector<double> >& matr, const std::vector<double>& vect)
 {
	 std::cout << "From the matMulVect method\n";

	 // matr[0].size() = column size of matrix;
	 //vect.size() = row/no. of vector elements;
	 std::cout << "Matrix columns  size : " << matr[0].size() << "\n";
	 std::cout << "Vector size: "<<vect.size()<< "\n";

	 //checking multiplication condition if column of matrix == row of vector/total elements
	 if (matr[0].size() == vect.size())
	 {
		 std::cout << "Matrix Vector multiplication is possible:\n";
		 std::vector<double> mul_mat_vect(matr.size());

		 for (unsigned int i = 0; i < matr.size(); i++)
		 {
			 mul_mat_vect[i] = 0;
			 for (unsigned int j = 0; j < vect.size(); j++)
				 mul_mat_vect[i] += matr[i][j] * vect[j];
		 }

		 // Displaying the vector after multiplication
		 std::cout << "the elements Matrix*Vector:\n";
		 printVector(mul_mat_vect);
	 }

	 else
		 std::cout << "Matrix Vector multiplication is not possible:\n";

 
 }


 void Operation::scalarmulmat(std::vector<std::vector<double> >& matr, int scalar)
 {
	 std::cout << "From the scalarmulmat method\n";
	 std::cout << "Scalar Matrix multiplication size\n ";

	 //Multiplication of Matrix with scalar
	 for (unsigned int i = 0; i < matr.size(); i++)
		 for (unsigned int j = 0; j < matr[i].size(); j++)
			 matr[i][j] *= scalar;
	 
	 // Displaying the 2D vector 
	 std::cout << "Matrix elements after scalar mat mul :\n";
	 printMatrix(matr);
 }

 void Operation::scalaraddmat(std::vector<std::vector<double> >& matr, int scalar)
 {
	 std::cout << "From the scalaraddmat method\n";
	 std::cout << "Scalar Matrix addition size\n ";

	 //Addition of Matrix with scalar
	 for (unsigned int i = 0; i < matr.size(); i++)
		 for (unsigned int j = 0; j < matr[i].size(); j++)
			 matr[i][j] += scalar;

	 // Displaying the 2D vector 
	 std::cout << "Matrix elements after scalar add :\n";
	 printMatrix(matr);
 }


 void Operation::scalarmulvec(std::vector<double>& vect, int scalar)
 {
	 std::cout << "From the scalarmulvec method\n";
	 std::cout << "Scalar Vector multiplication size\n ";

	 //Addition of Matrix with scalar
	 for (unsigned int i = 0; i < vect.size(); i++)
			 vect[i]*= scalar;

	 // Displaying the vector 
	 std::cout << "Vector elements after scalar mul :\n";
	 printVector(vect);
 }


 void Operation::scalaraddvec(std::vector<double>& vect, int scalar)
 {
	 std::cout << "From the scalaraddmat method\n";
	 std::cout << "Scalar Matrix addition size\n ";

	 //Addition of Matrix with scalar
	 for (unsigned int i = 0; i < vect.size(); i++)
		 vect[i] += scalar;

	 // Displaying the  vector 
	 std::cout << "Vector elements after scalar add:\n";
	 printVector(vect);
 }

 void Operation::mataddmat(std::vector<std::vector<double> >& matr,  std::vector<std::vector<double> >& matr2)
 {
	 std::cout << "From the mataddmat method\n";

	 if (matr.size() == matr2.size() && matr[0].size() == matr2[0].size())
	 {
		 std::cout << "Matrices Addition is possible:\n";
		 //std::vector<std::vector<int> > add_mat_mat(matr2.size());

		 for (unsigned int i = 0; i < matr.size(); i++)
		 {
			 //mul_mat_vect[i] = 0;
			 for (unsigned int j = 0; j < matr[0].size(); j++)
				 matr[i][j] += matr2[i][j];
		 }

		 // Displaying the Matrix after multiplication
		 std::cout << "the elements Matrix+Matrix:\n";
		 printMatrix(matr);
	 }

	 else
		 std::cout << "Matrices addition is not possible:\n";


 }

 void Operation::vectaddvect(std::vector<double>& vect, std::vector<double>& vect2)
 {
	 std::cout << "From the vectaddvect method\n";

	 //checking addition condition if both vector are equal
	 if (vect.size() == vect2.size())
	 {
		 std::cout << "Vectors addition is possible:\n";
			 for (unsigned int i = 0; i < vect.size(); i++)
				 vect[i] += vect2[i];

		 // Displaying the vector after multiplication
		 std::cout << "the elements Vector+Vector:\n";
		 printVector(vect);
	 }

	 else
		 std::cout << "Vectors addition is not possible:\n";


 }

 //============Operation Class Ends===============