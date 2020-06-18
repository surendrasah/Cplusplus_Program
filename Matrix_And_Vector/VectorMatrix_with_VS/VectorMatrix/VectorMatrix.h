#pragma once
//Contains the body declaration for Matrix and Vector class
#include<vector>
class Matrix
{

public:
	
	void initializeMatrix(std::vector<std::vector<double> >&, int, int);
	void printMatrix(const std::vector<std::vector<double> >&);
};



class Vector
{

public:	
	void initializeVector(std::vector<double>&, int);
	void printVector(const std::vector<double>&);
};



class Operation:public Matrix, public Vector
{
public:
	void matMulVect(const std::vector<std::vector<double> >&, const std::vector<double>&);
	void scalarmulmat(std::vector<std::vector<double> >& , int);
	void scalaraddmat(std::vector<std::vector<double> >& , int);
	void scalarmulvec(std::vector<double>& , int );
	void scalaraddvec(std::vector<double>& , int );
	void mataddmat(std::vector<std::vector<double> >& matr, std::vector<std::vector<double> >& matr2);
	void vectaddvect(std::vector<double>&, std::vector<double>&);
};