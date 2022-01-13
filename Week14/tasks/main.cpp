#include <iostream>

using namespace std;

void swap(int &element1, int &element2) {
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

void bubleSort(int* arr, int size) {
    bool swapped = false;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) return;
    }
}

void selectionSort(int* arr, int size) {
    int minIndex = 0;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int *arr, int size) {
    int key;
    int j;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}



void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}
// left - 0 right - 8 
// 6
// 7
// 2

// 2 6 7
int getPartitionIndex(int *arr, int left, int right, int pivot) {
    while(left <= right) {
        while(arr[left] < pivot) {
            left++;
        }

        while(arr[right] > pivot) {
            right--;
        }

        if(left <= right) {
            swap(arr[left], arr[right]);
            right--;
            left++;
        }
    }

    return left;
}

void quickSort(int *arr, int left, int right) {
    if(left < right) {
        int pivot = arr[(left + right) / 2];
        int array_delimiter = getPartitionIndex(arr, left, right, pivot);
        quickSort(arr, left, array_delimiter - 1);
        quickSort(arr, array_delimiter, right);
    }
}



int main() {
    int array[4] = {3, 4, 1, -1};
    int size = 4;
    printArray(array, size);
    quickSort(array, 0, size - 1);
    printArray(array, size);
}   