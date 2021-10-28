
#include <iostream>
using namespace std;
int main()
{
    // Power
    /* double number = 0;
    int power = 0;

    cin >> number;
    cin >> power;

    bool isResultUnknown = number == 0 && power == 0;
    if (isResultUnknown) {
        cout << "unknown";
    }
    else {
        bool isPowerNegative = power < 0;
        if (isPowerNegative) {
            power *= -1;
        }

        double poweredNumber = 1;
        for (int i = 0; i < power; i++)
        {
            poweredNumber *= number;
        }

        if (isPowerNegative) {
            poweredNumber = 1 / poweredNumber;
        }

        cout << poweredNumber;
    }*/


    // Fibonnaci

    /*int fibonnaciNumber = 0;
    cin >> fibonnaciNumber;

    if (fibonnaciNumber == 0) {
        cout << 0;
    }
    else if (fibonnaciNumber == 1) {
        cout << 1;
    }
    else {
        int previousFirstNumber = 0;
        int previousSecondNumber = 1;
        cout << previousFirstNumber << " " << previousSecondNumber << " ";

        for (int i = 0; i < fibonnaciNumber - 2; i++) {
            int currentThirdNumber = previousFirstNumber + previousSecondNumber;
            previousFirstNumber = previousSecondNumber;
            previousSecondNumber = currentThirdNumber;

            cout << currentThirdNumber << " ";
        }
    }*/

    // 1 1 1
    // 1 1 1
    // 1 1 1
    //
    
    /*for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++) {
            cout << 1 << " ";
        }
        cout << endl;
    }*/
    

    //int rows = 0;
    //cin >> rows;

    //for (int i = 0; i < rows; i++) { // upper line
    //    cout << "* ";
    //}
    //cout << endl;

    //for (int i = 1; i < rows; i++) {
    //    for (int j = 0; j < rows; j++)
    //    { 
    //        if (j < i) {
    //            cout << "* ";
    //        }

    //        if (j > i) {
    //            cout << "  ";
    //        }
    //    }
    //    cout << "* ";
    //    cout << endl;
    //}

    int rows = 0;
    cin >> rows;

    int emptySpaces = rows - 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j < rows * 2; j++)
        {
            if (j <= rows - i || j >= rows + i) {
                cout << " ";
            }
            else {
                cout << "*";
            }
        }
        cout << endl;
    }
    
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < rows * 2; j++)
        {
            if (j > i && j < rows * 2 - i) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

}
