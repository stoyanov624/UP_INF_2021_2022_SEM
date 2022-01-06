#include <iostream>

using namespace std;

void initMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << endl;
}   

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int getShooterColPosition(int** matrix, int shooterRowPosition, int cols) {
    for (int i = 0; i < cols; i++) {
        if(matrix[shooterRowPosition][i] == 3) {
            return i;
        }
    }
    return -1;
}

void shootBuilding(int** matrix, int rows, int cols) {
    int shooterRowPosition = rows - 1;
    int shooterColPosition = getShooterColPosition(matrix, shooterRowPosition, cols);

    if(shooterColPosition == -1) {
        cout << "404: Traycho not found!\n";
        return;
    }

    for (int i = shooterRowPosition; i >= 0; i--) {
        if(matrix[i][shooterColPosition] == 2) {
             cout << "Hit a window\n";
             return;
        }

        if(matrix[i][shooterColPosition] == 1) {
            cout << "Hit a wall\n";
            return;
        }

        if(i == 0) {
            cout << "Over building\n";
            return;
        }
        shooterColPosition++;
    }
}

void spreadUpperRight(int** matrix, int rows, int cols, int dustRowPosition, int dustColPosition) {
    if(dustColPosition == cols - 1 || dustRowPosition == 0) {
        return;
    }
    int dustValue = matrix[dustRowPosition][dustColPosition];

    for (int j = dustColPosition + 1, i = dustRowPosition - 1; ;j++, i--) {
        if(i == 0) {
            matrix[i][j] += dustValue;
            return;
        }

        if(j == cols - 1) {
            matrix[i][j] += dustValue;
            return;
        }
        matrix[i][j] += dustValue;
    } // може да се напише и с while
    
}

void spreadUpperLeft(int** matrix, int rows, int cols, int dustRowPosition, int dustColPosition) {
    if(dustRowPosition == 0 || dustColPosition == 0) {
        return;
    }

    int dustValue = matrix[dustRowPosition][dustColPosition];

    for (int j = dustColPosition - 1, i = dustRowPosition - 1; ;j--, i--) {
        if(i == 0) {
            matrix[i][j] += dustValue;
            return;
        }

        if(j == 0) {
            matrix[i][j] += dustValue;
            return;
        }
        matrix[i][j] += dustValue;
    } // може да се напише и с while
}

void spreadDownRight(int** matrix, int rows, int cols, int dustRowPosition, int dustColPosition) {
    if(dustRowPosition == rows - 1 || dustColPosition == cols - 1) {
        return;
    }

    int dustValue = matrix[dustRowPosition][dustColPosition];

    for (int j = dustColPosition + 1, i = dustRowPosition + 1; ;j++, i++) {
        if(i == rows - 1) {
            matrix[i][j] += dustValue;
            return;
        }

        if(j == cols - 1) {
            matrix[i][j] += dustValue;
            return;
        }
        matrix[i][j] += dustValue;
    } // може да се напише и с while
}

void spreadDownLeft(int** matrix, int rows, int cols, int dustRowPosition, int dustColPosition) {
    if(dustRowPosition == rows - 1 || dustColPosition == 0) {
        return;
    }

    int dustValue = matrix[dustRowPosition][dustColPosition];

    for (int j = dustColPosition - 1, i = dustRowPosition + 1; ;j--, i++) {
        if(i == rows - 1) {
            matrix[i][j] += dustValue;
            return;
        }

        if(j == 0) {
            matrix[i][j] += dustValue;
            return;
        }
        matrix[i][j] += dustValue;
    } // може да се напише и с while
}

void spreadIce(int** matrix, int rows, int cols, int dustRowPosition, int dustColPosition) {
    spreadUpperRight(matrix, rows, cols, dustRowPosition, dustColPosition);
    spreadUpperLeft(matrix, rows, cols, dustRowPosition, dustColPosition);
    spreadDownRight(matrix, rows, cols, dustRowPosition, dustColPosition);
    spreadDownLeft(matrix, rows, cols, dustRowPosition, dustColPosition);
}

int** copyMatrix(int** matrix, int rows, int cols) {
    int** copiedMatrix = new int*[rows];

    for (size_t i = 0; i < rows; i++) {
         copiedMatrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            copiedMatrix[i][j] = matrix[i][j];
        }
    }

    return copiedMatrix;
}

void deleteMatrix(int ** matrix,int rows) {
    for (size_t i = 0; i < rows; i++) {
        delete [] matrix[i];
    }
    delete[] matrix;
}

void generateSnowflakes(int** matrix, int rows, int cols) {
    int previusValue = 0;
    int** originalMatrix = copyMatrix(matrix, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0 && originalMatrix[i][j] != 0) {
                previusValue = matrix[i][j];
                spreadIce(matrix, rows, cols, i, j);
            }
        }
    }

    deleteMatrix(originalMatrix, rows);
}


int fact(int n) {
    if(n < 0) {
        return -1;
    }

    if(n == 0) {
        return 1;
    }   
    cout << "Recursion";
    return n * fact(n - 1);
}

void test_recursion(char* sentence) {
    if(*sentence == '\0') {
        return;
    }
    char upper = char(*sentence - 32);
    *sentence = upper;
    test_recursion(sentence + 1);
}

int main() {
    // int rows = 5;
    // int cols = 5;
    // int** matrix = new int*[rows];

    // for (size_t i = 0; i < rows; i++) {
    //     matrix[i] = new int[cols];
    // }

    // initMatrix(matrix, rows, cols);

    // generateSnowflakes(matrix, rows, cols);
    // printMatrix(matrix, rows, cols);
    // deleteMatrix(matrix, rows);

    // cout << result;
}