
#include <iostream>
using namespace std;

//void helperFunctionForTask1(int number) {
//
//}
//
//void solvesTask1(int number) {
//	int result = 0;
//	for (size_t i = 0; i < 5; i++) {
//		if (number % 2 == 0) {
//			helperFunctionForTask1(number);
//		}
//		else {
//			helperFunctionForTask1(number / 2);
//		}
//	}
//
//	cout << result;
//}

void printArray(int array[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		cout << "Element # " << i + 1 << " -> " << array[i] << endl;
	}
}

void readArray(int array[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		cout << "-> ";
		cin >> array[i];
	}
}

double getAverageSumFromArray(int array[], int arraySize) {
	double sumOfElements = 0;
	for (int i = 0; i < arraySize; i++) {
		sumOfElements += array[i];
	}
	double average = sumOfElements / arraySize;
	return average;
}

int main()
{
	/*solvesTask1(5);
	solvesTask1(2);
	solvesTask1(3);
	solvesTask1(3);
	solvesTask1(3);*/

	/*double gradeStudent1 = 6;
	double gradeStudent2 = 5;
	double gradeStudent3 = 5;
	double gradeStudent4 = 5;
	double gradeStudent5 = 3.56;
	double gradeStudent6 = 4.67;
	double gradeStudent7 = 5;
	double gradeStudent8 = 2;
	double gradeStudent9 = 3;
	double gradeStudent10 = 4;*/

	/*double studentGrades0[10] = {};

	double studentGrades2[10] = { 5, 4, 4 , 5, 3, 1, 5, 3, 4, 5 };
	int size = 10;*/

	// cout << "First grade in array: " << studentGrades2[6] << endl;
	//for (int i = 0; i < size; i++) {
	//	cout << "Student # " << i + 1 << " grade - " << studentGrades2[i] << endl;
	//}

	/*double studentGrades1[100] = {};
	int classSize = 8;

	for (int i = 0; i < classSize; i++) {
		cout << "Enter student # " << i + 1 << " grades: ";
		cin >> studentGrades1[i];
	}

	cout << endl;

	for (int i = 0; i < classSize; i++) {
		cout << "Student # " << i + 1 << " grade - " << studentGrades1[i] << endl;
	}*/
		
	/*const int MAX_ARRAY_CAPACITY = 100;


	int initializedArray[MAX_ARRAY_CAPACITY] = { 5,4,5,3,1 };
	int initializedArraySize = 5;

	int testArray[MAX_ARRAY_CAPACITY] = {};
	int testArraySize = 0;
	for (int i = 0; i < initializedArraySize; i++) {
		testArray[i] = initializedArray[i];
		testArraySize++;
	}

	printArray(testArray, testArraySize);*/

	int size = 0;
	cin >> size;

	int arrayOfNumbers[10000] = {};
	readArray(arrayOfNumbers, size);

	printArray(arrayOfNumbers, size);
	cout << endl;

	cout << "Average: " << getAverageSumFromArray(arrayOfNumbers, size);
}
