#include <iostream>
using namespace std;

void initializeMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
           cin >> matrix[i][j];
       }
    }
}

void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
           cout << matrix[i][j] << " ";
       }
       cout << endl;
    }
}

void printAvgOfEachRow(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int sumOfRowElements = 0;
        for (int j = 0; j < cols; j++) {
            sumOfRowElements += matrix[i][j];
        }
        double avgSum = sumOfRowElements / cols;
        cout << i + 1 << " row - " << avgSum << endl;
    }
}

void printAvgOfEachCol(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int sumOfColElements = 0;
        for (int j = 0; j < cols; j++) {
            // 1 2 3
            // 4 5 6
            // 7 5 6
            //matrix[j][i] -> // matrix[0][0] -> 1
            //matrix[j][i] -> // matrix[1][0] -> 4
            sumOfColElements += matrix[j][i];
        }
        double avgSum = sumOfColElements / rows;
        cout << i + 1 << " col - " << avgSum << endl;
    }
    
}

void solveTask0() {
    const int MAX_ROWS = 100;
    const int MAX_COLUMS = 100;
    int n = 0;
    cout << "Enter n for NxN matrix: ";
    cin >> n;

    int matrix[MAX_ROWS][MAX_COLUMS] = {};  
    initializeMatrix(matrix, n, n);
    printAvgOfEachRow(matrix, n, n);
    printAvgOfEachCol(matrix, n, n);
}
 
int main() {
    // char charArr[3] = "ab";
    // charArr[0] -= 32;
    // cout << charArr << endl;
    const int MAX_ROWS = 100;
    const int MAX_COLUMS = 100;
    // int matrix[100][100] = {};
    
    // int rows = 3;
    // int cols = 3;
    // initializeMatrix(matrix, rows, cols);
    // printMatrix(matrix, rows, cols);
    
    // TASK 0
    // int task0_matrix[MAX_ROWS][MAX_COLUMS] = {};
    // int n = 0;
    // cin >> n;

    // initializeMatrix(task0_matrix, n, n);
    // printAvgOfEachRow(task0_matrix, n, n);

    //solveTask0();

    int task1_matrix[MAX_ROWS][MAX_COLUMS] = {};
    int n = 0; 
    cin >> n;
    initializeMatrix(task1_matrix, n, n);

    int sumOfFirstDiagonal = 0;
    int sumOfSecondDiagonal = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if(i == j) {
    //             sumOfFirstDiagonal += task1_matrix[i][j];
    //         }
    //     }
    // }

    for (int i = 0; i < n; i++) {
        sumOfFirstDiagonal += task1_matrix[i][i];
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if(j == n - 1 - i) {
    //             sumOfFirstDiagonal += task1_matrix[i][j];
    //         }
    //     }
    // }

    for (int i = 0; i < n; i++) {
        sumOfSecondDiagonal += task1_matrix[i][n - 1 - i];
    }
    

    cout << sumOfFirstDiagonal << endl;
    cout << sumOfSecondDiagonal << endl;
}