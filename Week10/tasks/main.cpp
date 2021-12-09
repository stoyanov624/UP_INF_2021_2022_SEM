#include <iostream>

using namespace std;

void resize(int *&array, int& size, int& capacity) {
    capacity *= 2;
    int* biggerArray = new int[capacity];

    for (int i = 0; i < size; i++) {
        biggerArray[i] = array[i];
    }
    delete [] array;
    array = biggerArray;
}

void push_back(int *&array, int &size, int &capacity ,int new_element) {
    if(size == capacity) {
        resize(array, size, capacity);
    }
    array[size] = new_element;
    size++;
}

// {1, 5, 3, 7, 9};

// void swapInArray(int* array, int indexA, int indexB) {
//     int temp = array[indexB];
//     array[indexB] = array[indexA];
//     array[indexA] = temp;
// }

void swap(int& elementA, int& elementB) {
    int temp = elementB;
    elementB = elementA;
    elementA = temp;
}

void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void mergeSort(int* array1, int size1, int* array2, int size2, int* array3, int &size3) {
    int indexer1 = 0;
    int indexer2 = 0;

    while(indexer1 < size1 && indexer2 < size2) {
        if(array1[indexer1] < array2[indexer2]) {
            array3[size3] = array1[indexer1];
            size3++;
            indexer1++;
        } else {
            array3[size3] = array2[indexer2];
            size3++;
            indexer2++;
        }
    }

    if(indexer1 == size1) {
        for (int i = indexer2; i < size2; i++) {
            array3[size3] = array2[i];
            size3++;
        }
        
    } else if(indexer2 == size2) {
        for (int i = indexer1; i < size1; i++) {
            array3[size3] = array1[i];
            size3++;
        }
    }
}


int main () {
    //int* a = new int(28);
    // cout << *a;
    // delete a;

    // int size;
    // cin >> size;
    // int* array = new int[size];
    // delete [] array;


    // push_back;
    // {1, 2, 3, 5}
    // int user_wanted_capacity = 0;
    // cin >> user_wanted_capacity;
    // int * array = new int[user_wanted_capacity]; 
    // int size = 0;

    // push_back(array, size, user_wanted_capacity, 1);
    // push_back(array, size, user_wanted_capacity, 1);
    // push_back(array, size, user_wanted_capacity, 1);
    // push_back(array, size, user_wanted_capacity, 1);
    // push_back(array, size, user_wanted_capacity, 1);

    
    
    // int rows = 5;
    // int cols = 5;

    // int ** matrix = new int*[rows];
    // for (int i = 0; i < rows; i++) {
    //     matrix[i] = new int[cols];
    // }

    // for (int i = 0; i < rows; i++) {
    //     delete [] matrix[i];
    // }
    // delete [] matrix;


    int sizeArrayOne = 5;
    int arrayOne[10] = {4, 6, 7, 9, 1};

    bubbleSort(arrayOne, sizeArrayOne);

    for (int i = 0; i < sizeArrayOne; i++) {
        cout << arrayOne[i] << " ";
    }
    cout << endl;
    int sizeArrayTwo = 3;
    int arrayTwo[10] = {-1, 5, 8};

    bubbleSort(arrayTwo, sizeArrayTwo);
    for (int i = 0; i < sizeArrayTwo; i++) {
        cout << arrayTwo[i] << " ";
    }
    cout << endl;
    int* arrayThree = new int[sizeArrayOne + sizeArrayTwo];
    int sizeArrayThree = 0;
    mergeSort(arrayOne, sizeArrayOne, arrayTwo, sizeArrayTwo, arrayThree, sizeArrayThree);

    for (int i = 0; i < sizeArrayThree; i++) {
        cout << arrayThree[i] << " ";
    }
}
// -1 1 4 5 6 7 8