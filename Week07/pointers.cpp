#include <iostream>

using namespace std;

void changeA(int *a) {
    *a = 600;
}

void changeA(int a) {
    a = 600;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int main() {
    int a = 50;
    int b = 60;
    int *pointer_to_a = &a;
    pointer_to_a = &b;

    *pointer_to_a = 40;
    

    changeA(&a);
    cout << a << endl;

    a = 1;
    b = 2;

    swapRef(a, b);

    cout << "A - " << a << endl;
    cout << "B - " << b << endl;
     

} 