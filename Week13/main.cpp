#include <iostream>
using namespace std;

// Напишете (рекурсивна) функция void count(type arr, type size, type elem) ,
// която връща броя на срещанията на променливата elem в масива arr.

int countOccurencesOfElement(int* arr, int size, int element) {
    if(size == 0) {
        return 0;
    }
    if(element == *arr) {
        return 1 + countOccurencesOfElement(arr + 1, size - 1, element);
    }
    return countOccurencesOfElement(arr + 1, size - 1, element);
}

bool isLetterLexicographicallyBetter(char letterOne, char letterTwo) {
    return letterOne < letterTwo;
}

void compareLex(char* sentenceOne, char* sentenceTwo) {
    if(*sentenceOne == '\0' && *sentenceTwo == '\0') {
        cout << "Both words are equal!";
        return;
    }

    if(*sentenceOne == '\0') {
        cout << "Sentence two is greater!";
        return;
    }

    if(*sentenceTwo == '\0') {
        cout << "Sentence one is greater!";
        return;
    }

    if(isLetterLexicographicallyBetter(*sentenceOne, *sentenceTwo)) {
        cout << "Sentence one is greater!";
        return;
    }

    if(isLetterLexicographicallyBetter(*sentenceTwo, *sentenceOne)) {
        cout << "Sentence two is greater!";
    }

    compareLex(sentenceOne + 1, sentenceTwo + 1);
}

void drawPyramidRow(int n, int i) {
    if(i == 0) {
        return;
    }

    cout << n - 1 << " ";
    drawPyramidRow(n - 1, i - 1);
}

void printPyramid(int n, int i) {
    if(n == i) {
        return;
    }
    cout << n << " ";
    drawPyramidRow(n, i);
    cout << endl;

    printPyramid(n, i + 1);
}
// aabb -> GOOD / BAD / UGLY

int evaluateCountedLetters(int* array_of_letters_count, int size) {
    int result = array_of_letters_count[0];
    int countBad = 0;
    for (int i = 1; i < size; i++) {
        if(array_of_letters_count[i] == 0) {
            continue;
        }

        int check_result = result -= array_of_letters_count[i];
        if(check_result != 0) {
            countBad++;
        }

        if(countBad > 1) {
            break;
        }
    }
    return countBad;
}

void judgeWord(char* word) {
    const int ALPHABET_COUNT = 26;
    int array_of_letters_count[ALPHABET_COUNT] = {};
    for (int i = 0; word[i] != '\0'; i++) {
        char found_letter = word[i];
        array_of_letters_count[found_letter - 97]++;
    }

    int result = evaluateCountedLetters(array_of_letters_count, ALPHABET_COUNT);
    switch(result) {
        case 0:  cout << "GOOD\n"; return;
        case 1:  cout << "BAD\n"; return;
        default:  cout << "UGLY\n"; return;
    }
}
int main() {
    // const int ARRAY_SIZE = 100;
    // int test_array[ARRAY_SIZE] = {1, 2, 2, 4, 5};
    // int size = 5;

    // int element = 2;

    // cout << countOccurencesOfElement(test_array, size, element) << endl;

    // char sentence1[100] = "Ivan";
    // char sentence2[100] = "Ivan";

    // compareLex(sentence1, sentence2);

    char word[100] = "ababdc";
    judgeWord(word);
}