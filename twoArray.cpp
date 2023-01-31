#include <iostream>
#include <math.h>
#include <algorithm> // для функции  find()
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()
using namespace std;

const int N = 25; //кол-во элементов в массиве
const int MIN = 0; //начало диапазона случайных чисел
const int MAX = 30; //конец диапазона случайных чисел


//Функция проверяет есть ли 
//больше одного одинакового значения в массиве
int searchArr(int arr[], int s) {
    int qnt = 0;
    for(int i = 0; i<N; i++){
        if(arr[i] == s){
            qnt++;
        }
    }
    return qnt;
};

// Функция генерирования случайного числа
// Диапазон чисел: [min, max]
int genRandom(){
  int num = MIN + rand() % (MAX - MIN + 1);
  return num;
}

//Функция вывода массива в консоль
void viewArray(int arr[]){
    for(int i = 0; i<N; i++)
    {
        cout << "arr[" << i << "]= " << arr[i] << "\n";
    }
}
// Функция заполнения массива числами
void fillArray(int arr[]){
    for(int i = 0; i< N; i++){
        arr[i] = genRandom(); // Диапазон чисел
    }
}

//Функция проверки массива на повторяющееся элементы и замена их на новый
void modArray(int arr[]){
    for(int i = 0; i < N; i++){;
        if (searchArr(arr, arr[i]) > 1) {
            int newItem = genRandom();
            // проверяем новое сгенерированное число
            while(searchArr(arr, newItem) > 0){
                newItem = genRandom();
            }
            arr[i] = newItem;
        }
    }
}

//Функция суммирование элементов первого массива
int sumElementArray(int arr1[], int arr2[]){
    int summ = 0;
    for(int i = 0; i<N; i++){
        if(arr2[i] <= N){
            summ += arr1[arr2[i]];
        }
    }
    return summ;
}

int main(){
    // Установить генератор случайных чисел
    srand(time(0));
    int a[N], b[N];
    fillArray(a);
    fillArray(b);
    viewArray(a);
    modArray(b);
    viewArray(a);
    cout << sumElementArray(a, b);
    return 0;
}
