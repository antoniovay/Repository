#pragma once


// Функции для матриц //======================================================================================================

// Вывести матрицу
void printMatrix (int** matr, int m, int n);

// Заполнить матрицу случайными числами
void randomMatrix (int** matr, int m, int n, int a, int b);


// Функции для одномерных массивов //=========================================================================================

// Вывести массив
void printMassive (int* mas, int n);

// Сделать копию массива
void doCopyOfMassive(int* masCopyFrom, int* masCopyTo, int n);


// Прочие функции //==========================================================================================================

// Поменять местами два элемента
void swap (int &a, int &b);


// Точный алгоритм //---------------------------------------------------------------------------------------------------------

// Подсчет минимального пути точным алгоритмом с генерацией перестановок алгоритмом Дейкстры
void countMinWayStraightMethod (int** matrixOfPrice, int* minWay, int* maxWay, int numberOfCities, int startingCity, const int MAX);

// Подсчёт веса текущей перестановки
int countWayCoast (int **matrixOfPrice, int *p, int numberOfCities);

// Эвристический алгоритм //--------------------------------------------------------------------------------------------------

// Подсчет минимального пути эвристическим алгоритмом 3
void countMinWayHeuristicMethod (int** matrixOfPrice, int* answerArray, int numberOfCities, int MAX_PRICE, int startingCity);

int findMinInLine(int** matrixOfPrice, int n, int line, int MAX_PRICE);


/*
 
 while (minWay[0] == startingCity - 1) {
         
     int c = minWay[0];
     
     for (int j = 0; j < numberOfCities - 1; j++) {
         
         minWay[j] = minWay[j + 1];
         
     }
     
     minWay[numberOfCities] = c;
     
 }
 
 minWay[numberOfCities] = startingCity;
 
 */
