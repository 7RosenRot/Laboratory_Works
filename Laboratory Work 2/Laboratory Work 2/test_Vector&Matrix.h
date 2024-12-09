#pragma once
#include "TDynamicMatrix.h"
#include "TDynamicMatrix.cpp"
#include "TDynamicVector.h"
#include "TDynamicVector.cpp"

inline void testVector(void) {
	int length = 5;

	TDynamicVector<int> exampleVector_first(length);
	for (int i = 0; i < length; i += 1) { exampleVector_first[i] = i + 1; }

	TDynamicVector<int> exampleVector_second(length);
	for (int i = 0; i < length; i += 1) { exampleVector_second[i] = i + 1; }

	cout << "1. Vector Test\n";

	cout << "\nFirst Vector: " << exampleVector_first;
	cout << "\nSecond Vector: " << exampleVector_second;

	cout << endl;

	auto amountVector = exampleVector_first + exampleVector_second;
	cout << "\nVectros Amount: " << amountVector << endl;
	
	auto differenceVector = exampleVector_first - exampleVector_second;
	cout << "Vectors Differece: " << differenceVector << endl;
	
	auto productVector = exampleVector_first * exampleVector_second;
	cout << "Vectors Product: " << productVector << endl;
	
	auto multiplyVector = exampleVector_first * 2;
	cout << "Vectors Multiply: " << multiplyVector << endl;
}

inline void testMatrix(void) {
	int length = 3;
	
	TDynamicMatrix<int> exampleMatrix_first(length);
	for (int i = 0; i < length; i += 1) {
		for (int j = 0; j < length; j += 1) {
			exampleMatrix_first[i][j] = i + j;
		}
	}

	TDynamicMatrix<int> exampleMatrix_second(length);
	for (int i = 0; i < length; i += 1) {
		for (int j = 0; j < length; j += 1) {
			exampleMatrix_second[i][j] = i + j;
		}
	}

	cout << "\n2. Matrix Test\n";

	cout << "\nFirst Matrix:\n" << exampleMatrix_first << endl;
	cout << "Second Matrix:\n" << exampleMatrix_second << endl;

	auto amountMatrix = exampleMatrix_first + exampleMatrix_second;
	cout << "\nMatrix Amount:\n" << amountMatrix << endl;
	
	auto differenceMatrix = exampleMatrix_first - exampleMatrix_second;
	cout << "Matrix Differece:\n" << differenceMatrix << endl;
	
	auto multiplyMatrix = exampleMatrix_first * 2;
	cout << "Matrix Multiply:\n" << multiplyMatrix << endl;
}