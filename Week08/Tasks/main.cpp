#include <iostream>

using namespace std;

void changeFirstElementOfArray(int * arr) {
    arr[0] = 5;
    *arr = 5;
}

void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int getSmallestElementInMatrix(int matrix[][100], int rows, int cols) {
    int smallest = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(matrix[i][j] < smallest) {
                smallest = matrix[i][j];
            }
        }
    }
    return smallest;   
}

int getBiggestElementInMatrix(int matrix[][100], int rows, int cols) {
    int biggest = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(matrix[i][j] > biggest) {
                biggest = matrix[i][j];
            }
        }
    }
    return biggest;
}

void printMaxAndMinOfMatrix(int matrix[][100], int rows, int cols) {
    int smallestElement = getSmallestElementInMatrix(matrix, rows, cols);
    int largestElement = getBiggestElementInMatrix(matrix, rows, cols);

    cout << "Min: " << smallestElement << endl;
    cout << "Max: " << largestElement << endl;
}  

int getSumAboveDiagonal(int matrix[][100], int size) {
    int sum = 0;
    for (int i = 1; i < size; i++) {
        sum += matrix[i - 1][i];
    }
    return sum;
}

int getSumBelowDiagonal(int matrix[][100], int size) {
    int sum = 0;
    for (int i = 1; i < size; i++) {
        sum += matrix[i][i - 1];
    }
    return sum;
}

void printSumAboveDiagonalAndBelow(int matrix[][100], int size) {
    int sumAboveDiagonal = getSumAboveDiagonal(matrix, size);
    int sumBelowDiagonal = getSumBelowDiagonal(matrix, size);
    cout << "Sum above diagonal - " << sumAboveDiagonal << endl;
    cout << "Sum below diagonal - " << sumBelowDiagonal << endl;
}

int getSumMainDiagonal(int matrix[][100], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int getSumSecondDiagonal(int matrix[][100], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][size - 1 - i];
    }
    return sum;
}

bool isPowerOfTwo(int number) {
    while(number != 1) {
        if(number % 2 != 0) {
            return false;
        }
        number /= 2;
    } 
    return true;
}

int main() {
    // int a = 5;
    // int* pointer = &a;
    // a = 7;
    // a++;
    // ++a;


    // cout << pointer << endl;

    // *pointer = 10;
    // cout << a << endl;

    // int** ptr_to_ptr = &(pointer);

    // cout << &a << endl;
    // cout << pointer << endl;
    // cout << **ptr_to_ptr << endl;

    // int a = 5;
    // int* ptr_one = nullptr;
    // ptr_one = &a;
    // cout << *ptr_one << endl; 

    // int array[10] = {1, 2, 3, 4 ,5};
    // changeFirstElementOfArray(array);
    // cout << array[0] << endl;

    // int matrix[100][100] = {{3, 4 , 5 , 4, 3}, 
    //                         {3, -4 , 5 , 1, 3}, 
    //                         {10, -40 , 5 , 66, 3},
    //                         {3, -1 , 55 , 6, 33},
    //                         {9, 6 , 5 , -61, 3}};
    // int n = 5;
    // printMaxAndMinOfMatrix(matrix, n, n);

    int matrix[100][100] = {{1, 2 , 10}, 
                            {4, 5 , 6}, 
                            {7, 8 , 9}};
    int n = 3;
    //printMatrix(matrix, n, n);
    //printSumAboveDiagonalAndBelow(matrix, n);

    int sumOfDiagonals = getSumMainDiagonal(matrix, n) + getSumSecondDiagonal(matrix, n);
    if(n % 2 != 0) {
        sumOfDiagonals -= matrix[n / 2][n / 2];
    } 
    cout << isPowerOfTwo(sumOfDiagonals);
    
}