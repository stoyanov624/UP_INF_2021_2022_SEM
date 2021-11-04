#include <iostream>
#include <cmath>
using namespace std;

// f(x) = { x^2 + x + 1 } -> 1 + 1 + 1 = 3 = y
//int functionF(int x, int g, char a, double k) {
//    int y = pow(x, 2) + x + 1;
//    return y;
//    cout << "Function F";
//}
//
//double functionD(double d) {
//    return d + d;
//}
//
//char functionC() {
//    char letter = 'a';
//    return letter;
//}
//
//bool isEven(int number) {
//    return number % 2 == 0;
//}
//
//void functionV() {
//    cout << "I am a void function!";
//    return;
//    cout << "I am hidden for even" << endl;
//}
//
//void swapTwoNumber(int numberOne, int numberTwo) {
//    int temp = numberOne;
//    numberOne = numberTwo;
//    numberTwo = temp;
//
//    cout << "in function " << endl;
//    cout << "number one " << numberOne << endl;
//    cout << "number two " << numberTwo << endl;
//}


int maxOfTwoNumbers(int numberOne, int numberTwo) {
    if (numberOne > numberTwo) {
        return numberOne;
    }
    else {
        return numberTwo;
    }
}

// f(x,y) -> h
// f(f(x,y), z);
int maxOfThreeNumbers(int numberOne, int numberTwo, int numberThree) {
    /*int biggerFromFirstTwo = maxOfTwoNumbers(numberOne, numberTwo);
    int biggestNumber = maxOfTwoNumbers(biggerFromFirstTwo, numberThree);
    return biggestNumber;*/
    return maxOfTwoNumbers(maxOfTwoNumbers(numberOne, numberTwo), numberThree);
}


double getPercentOff(double price, double percentOff) {
    return price - (price * (percentOff / 100));
}

double getPercentUp(double price, double percentOff) {
    return price + (price * (percentOff / 100));
}

double handleOrder(double money, double price) {
    return money -= price;
}

bool isBuyable(double money, double price) {
    if (money - price < 0) {
        cout << "WARNING" << endl;
        return false;
    }
    return true;
}

void handleOrders(double money, double meatball_price, double turshia_price, double shopska_price, double beer_price) {
    cout << "ORDER NOW: " << endl;
    int order = 0;
    int warnings = 0;
    while (true) {
        if (warnings == 3) {
            cout << "GET OUT!" << endl;
            return;
        }

        cin >> order;
        if (order == 0) {
            return;
        }
        else if (order == 1) {
            if (isBuyable(money, meatball_price)) {
                money -= meatball_price;
            }
            else {
                warnings++;
            }
        }
        else if (order == 2) {
            if (isBuyable(money, turshia_price)) {
                money -= turshia_price;
            }
            else {
                warnings++;
            }
        }
        else if (order == 3) {
            if (isBuyable(money, shopska_price)) {
                money -= shopska_price;
            }
            else {
                warnings++;
            }
        }
        else if (order == 4) {
            if (isBuyable(money, beer_price)) {
                money -= beer_price;
            }
            else {
                warnings++;
            }
        }
        else {
            cout << "Invalid command!" << endl;
        }
    }
}

int main()
{
    /*int x = 5;
    int y = functionF(x, 5, 'a', x);
    cout << y << endl;

    int numberOne = 5;
    int numberTwo = 6;
    swapTwoNumber(numberOne, numberTwo);
    cout << "number one " << numberOne << endl;
    cout << "number two " << numberTwo << endl;*/
    //cout << maxOfThreeNumbers(1,5, 3);



    // Menu

    double money = 0;
    cin >> money;
    int dayOfTheWeek = 0;
    cin >> dayOfTheWeek;

    double meatball_price = 2;
    double turshia_price = 3;
    double shopska_price = 3.50;
    double beer_price = 6.66;

    bool isEverythingCheaper = dayOfTheWeek >= 1 && dayOfTheWeek <= 3;
    bool isMeatballsCheaper = dayOfTheWeek >= 4 && dayOfTheWeek <= 5;
    bool isEverythingPricier = dayOfTheWeek >= 6 && dayOfTheWeek <= 7;

    if (isEverythingCheaper) {
        meatball_price = getPercentOff(meatball_price, 25);
        turshia_price = getPercentOff(turshia_price, 25);
        shopska_price = getPercentOff(shopska_price, 25);
        beer_price = getPercentOff(beer_price, 25);
    }
    else if (isMeatballsCheaper) {
        meatball_price = getPercentOff(meatball_price, 10);
    }
    else if (isEverythingPricier) {
        meatball_price = getPercentUp(meatball_price, 30);
        turshia_price = getPercentUp(turshia_price, 30);
        shopska_price = getPercentUp(shopska_price, 30);
        beer_price = getPercentUp(beer_price, 30);
    }

    handleOrders(money, meatball_price, turshia_price, shopska_price, beer_price);
}
