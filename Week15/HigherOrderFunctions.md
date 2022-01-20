# Седмица 08 - Функции от по - висок ред
## Функциите от по - висок ред могат да са изключително полезни и да решават много проблеми, единствената трудност в c++ е техния синтаксис. Затова по - долу ще видите няколко имплементации на функции от по - висок ред.

``` c++
#include <iostream>

// изполваме using, за да използваме името fncPtrTwo 
// директно вместо да пишем "грозния"
// синтаксис на указател към функция в мейна

using fncPtrTwo = void (*)(int,int); // (*) означава, че това е указател към функция; 
                                    // void индикира какъв ще е тип на функцията, към която
                                    // ще сочи указателя а (int,int) индикира какви 
                                    // аргументи ще приема функцията

void onePlusOnePrint(int a,int b) { // проста функция, към която можем да насочим указател.
    std::cout << a+b << std::endl;
}

// Задача - искаме да приложим някаква промяна на всеки елемент от масив, но промените може да са много и искаме да ги обобщим с една функция.


using fncPtrApplier = int (*) (int); // указател към функция, която ще връща int и ще приема като 
                                //аргумент нещо от тип int

int increment(int element) {
    return element + 1;
}

void mapArr(int* arr, int arr_size, fncPtrApplier<int> applier) { // подаваме указател към 
                                                                //  функция като аргумент
    for (int i = 0; i < arr_size; i++) {
        arr[i] = applier(arr[i]); // applier ще приема някакво int като аргумент ще го 
                                 //  промени и ще го върне
    }
}

//Задача - искаме да изпринтираме елементите на масив, но само тези, които отговорят на някакво условие
bool isEven(int element) {
    return element % 2 == 0;
}

bool isOdd(int element) {
    return element % 2 != 0;
}

using comparatorFunc = bool (*) (int);

void filterArray(int* arr, int arr_size, comparatorFunc<int> comparator) {
    for(int i = 0; i < arr_size; i++) {
        if(comparator(arr[i])) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    void (*fncPtr)(int, int); // стандартен указател към функция тук името на указателя е в средните скоби
    fncPtr = onePlusOnePrint;  // насочваме го

    fncPtrTwo functwo = onePlusOnePrint;
    // auto functtwo = onePlusOnePrint; auto ще сложи подходящ тип на fnctwo.
    // НО не се препоръчва използването на auto!    

    fncPtr(1,5); // принтира 6
    functwo(1,5); // принтира 6

    int arr[5] = {6,4,5,3,1};
    int arr_size = 5;
    mapArr(arr,arr_size,increment); // директно си подаваме името на функцията като аргумент;

    for (int i = 0; i < arr_size; i++)
    {
        std::cout << arr[i] << " "; // ще получим 7,5,6,4,1
    }
    std::cout << std::endl;

    
    int arr2[5] = {1,2,3,4,5};
    int arr2_size = 5;
    filterArray(arr2,arr2_size,isEven);  // ще изпринтира само четните числа 
                                             // (ще ги филтрира :) )
    filterArray(arr2,arr2_size,isOdd); //  ще изпринтира само нечетните числа
}
```