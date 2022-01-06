#include <iostream>

using namespace std;

void readArray(int* array, int size) {
    for (size_t i = 0; i < size; i++) {
        cin >> array[i]; 
    }
    
}

void printArrayRecursive(int* array, int size) {
    if(size == 0) {
        return;
    }
    cout << *array << " ";

    printArrayRecursive(array + 1, size - 1);
}

void printArrayRecursive2(int array[], int size, int i) {
    if(size == 0) {
        return;
    }

    cout << array[i] << " ";

    printArrayRecursive2(array, size - 1, i + 1);
}

void printArrayRecursive3(int array[], int size) {
    static int i = 0;
    if(size == 0) {
        return;
    }

    cout << array[i];
    i++;

    printArrayRecursive3(array, size - 1);
}

int arrayCount(int arr[], int i)
{
	if (arr[i] == 0)
	{
		cout << i;
		return 0;
	}

	arrayCount(arr, i + 1);
}

void printSentenceRecursive(char* sentence) {
    if(*sentence == '\0') {
        cout << endl;
        return;
    }

    cout << *sentence;

    printSentenceRecursive(sentence + 1);
}

int getSentenceLength(char* sentence) {
    if(*sentence == '\0') {
        return 0;
    }

    return 1 + getSentenceLength(sentence + 1);
} 

// 154 -> 10
// 15
// 1
// 0
int sumOfDigits(int number) {
    if(number == 0) {
        return 0;
    }

    int last_digit = number % 10;
    return last_digit + sumOfDigits(number / 10);
}

bool isLetter(char symbol) {
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}

int countLetters(char *sentence) {
    if(*sentence == '\0') {
        return 0;
    }

    if(isLetter(*sentence)) {
       return 1 + countLetters(sentence + 1);
    } 

    return countLetters(sentence + 1);
}
// 5
// 0 1 2 3 5 8
// "The Dark Knight Rises", 15 ->  The Dark Knight
void truncate(char* sentence, int n) {
    if(getSentenceLength(sentence) < n) {
        return;
    }
    sentence[n] = '\0';
}

int main() {
    // int size = 5;
    // int* elements = new int[size]; 
    // readArray(elements, size);
    
    // int elements2[5] = {1,2,3,4,5};
    // arrayCount(elements2, 0);
    // cout << endl;
    
    //cin.ignore();
    char sentence[100] = "The Dark Knight Rises";
    cin.getline(sentence, 30);
    //cout << countLetters(sentence);

    truncate(sentence,15);

    cout << sentence;

    // cout << getSentenceLength(sentence);


}