//
//  Func.cpp
//  AaDS Lab 1
//
<<<<<<< Updated upstream
//  Created by Antony Miroshnichenko on 18.09.2023.
//

#include <iostream>
#include <stdio.h>
#include <time.h>

#include "Func.h"




// Функции для матриц //----------------------------------------------------------------------------------------------------------------------------


void printMatrix(int** matr, int m, int n) { // Вывести матрицу
    
    int i, j;
    
    for(i = 0; i < m; i++) {
        
        for(j = 0; j < n; j++) {
            
            printf("%2d ", matr[i][j]);
            
        }
        
        std::cout << std::endl;
        
    }
    
}



void randomMatrix(int** matr, int m, int n, int a, int b) { // Заполнить матрицу случайными числами
    
    srand( time(0) );
    
    int i, j;
    
    for (i = 0; i < m; i++) {
        
        for (j = 0; j < n; j++) {
            
            if (i != j) {
                
                matr[i][j] = rand() % (b - a + 1) + a;
                
            }
            
            else {
                
                matr[i][j] = 0;
                
            }
    
        }
    }
}


void doCopyOfMatrix (int** matrixCopyFrom, int** matrixCopyTo, int m, int n) { // Сделать копию матрицы
    
    for (int i = 0; i < m; i++) {
        
        for (int j = 0; j < n; j++) {
                
            matrixCopyTo[i][j] = matrixCopyFrom[i][j];
                
        }
        
    }
}



// Функции для одномерных массивов //---------------------------------------------------------------------------------------------------------------


void printMassive (int* mas, int n) { // Вывести массив
    
    for (int i = 0; i < n; i++)
            std::cout << mas[i] + 1 << ' ';
    
        std::cout << std::endl;
    
}

void doCopyOfMassive(int* masCopyFrom, int* masCopyTo, int n) { // Сделать копию массива
    
    for(int i = 0; i < n; i++)
        
        masCopyTo[i] = masCopyFrom[i];
    
}



// Прочие функции //--------------------------------------------------------------------------------------------------------------------------------


void swap (int &a, int &b) { // Поменять местами два элемента

    int c = a;
    a = b;
    b = c;
    
}


// Для точного алгоритма //-------------------------------------------------------------------------------------------------------------------------

// Подсчет минимального пути точным алгоритмом с генерацией перестановок алгоритмом Дейкстры
void countMinWayStraightMethod (int** matrixOfPrice, int* minWay, int* maxWay, int numberOfCities, int startingCity, const int MAX_PRICE) {
    
    int* p, costOfWay, minWeight = numberOfCities * MAX_PRICE, maxWeight = 0, pCount = 1;
    
    p = new int [numberOfCities + 1];
    
    
    // Генерация первой перестановки
    
    for (int i = 0, j = 0; i < numberOfCities; ) {
            
        
            if (i == 0) {
                
                p[i] = startingCity - 1;
                i++;
                
            }
            
        
            else if (j == startingCity - 1) {
                
                j++;
                
            }
            
        
            else {
                
                p[i] = j;
                j++;
                i++;
                
            }
            
        }
    
    
    
    // Вывод пути (первого)
    /*
    for (int i = 0; i < numberOfCities; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
    */
     
    
    // Добавили начальный город в конец
    p[numberOfCities] = startingCity - 1;
    
    
    // Считаем цену первой перестановки
    
    costOfWay = countWayCoast(matrixOfPrice, p, numberOfCities);
    
    doCopyOfMassive(p, minWay, numberOfCities + 1);
    
    
    // Смотрим все перестановки в цикле
    
    for (int i = numberOfCities - 2; i > 0; i--) {
        
        if (i > 0 && i < numberOfCities - 1 && p[i] < p [i + 1]) {
            
            for (int j = numberOfCities - 1; j > i; j--) {
                
                if (j > i && j <= numberOfCities - 1 && p[i] < p[j]) {
                    
                    swap(p[i], p[j]);
                    
                    for(int m = i + 1, n = numberOfCities - 1; m <= n; m++, n--) {
                        
                        swap(p[m], p[n]);
                        
                        //std::cout << "m = " << m << std::endl;
                        //std::cout << "n = " << n << std::endl;
                        
                    }
                    
                    pCount++;
                    
                    i = numberOfCities - 1;
                    
                    costOfWay = countWayCoast(matrixOfPrice, p, numberOfCities);
                    
                    
                    if (costOfWay < minWeight) {
                        
                        minWeight = costOfWay;
                        
                        doCopyOfMassive(p, minWay, numberOfCities + 1);
                    
                    }
                    
                    /* for (int i = 0; i < numberOfCities; i++)
                     std::cout << p[i] << " ";
                     std::cout << std::endl; */
                    
                    
                    else if (costOfWay > maxWeight) {
                        
                        maxWeight = costOfWay;
                        
                        doCopyOfMassive(p, maxWay, numberOfCities + 1);
                        
                    }
                    
                }
                
            }
        }
    }
    
    delete [] p;
    
}


int countWayCoast (int **matrixOfPrice, int *p, int numberOfCities) { // Подсчёт веса текущей перестановки (для точного метода)
    
    int costOfWay = 0;
    
        for (int i = 0; i < numberOfCities; i++) {
            
            costOfWay += matrixOfPrice [ p[i] ][ p[i + 1] ];
            
        }
    
        return costOfWay;
    
}


// Для эвристического алгоритма 3 //----------------------------------------------------------------------------------------------------------------

// Подсчет минимального пути эвристическим алгоритмом 3
void countMinWayHeuristicMethod(int** matrixOfPrice, int* minWay, int numberOfCities, int MAX_PRICE, int startingCity) {
    
    int indexMinElement = 0, currentLine = 0; // Начинаем с 1 города (1 элемент имеет индекс 0)
    
    
    // Делаем копию матрицы, т.к. мы будем её изменять
    
    int** matrixOfPriceCopy = new int* [numberOfCities];
    
    for (int i = 0; i < numberOfCities; i++) {
        
        matrixOfPriceCopy[i] = new int [numberOfCities];
        
    }
    
    doCopyOfMatrix(matrixOfPrice, matrixOfPriceCopy, numberOfCities, numberOfCities);
    
    
    // Формируем массив для минимального пути
    
    for (int i = 0; i <= numberOfCities + 1; i++) {
        
        minWay[i] = 0;
        
    }
    
    int i = 1;
    
    for (int j = 0; j < numberOfCities; j++) {
        
        matrixOfPriceCopy[j][i - 1] = 0;
        
    }
        
    while (i < numberOfCities) { // Проходов столько, сколько городов
        
        indexMinElement = findMinInLine(matrixOfPriceCopy, numberOfCities, currentLine, MAX_PRICE); // Индекс минимального элемента
        
        //std::cout << indexMinElement << std::endl;
        
        // Зануляем строку и столбец минимального элемента и обратный путь
        
        for (int k = 0; k < numberOfCities; k++) {
            
            matrixOfPriceCopy[currentLine][k] = 0;
            
            matrixOfPriceCopy[k][indexMinElement] = 0;
            
        }
        
        matrixOfPriceCopy[indexMinElement][currentLine] = 0; // Зануляем обратный путь
        
        /*
        std::cout << std::endl;
        printMatrix(matrixOfPriceCopy, numberOfCities, numberOfCities);
        */
        
        
        //Теперь записываем город в итоговый массив
        
        minWay[i] = indexMinElement;
        
        currentLine = indexMinElement; // Теперь индекс минимального элемента - это номер следующей строки
        
        i++;
        
    }
    
    
    
    // Очищаем использованную динамическую память
    
    for (int i = 0; i < numberOfCities; i++) {
        
        delete [] matrixOfPriceCopy[i];
        
    }
    
    delete [] matrixOfPriceCopy;
    
}



int findMinInLine(int** matrixOfPrice, int n, int line, int MAX_PRICE) {
    
    int minNumber = MAX_PRICE, minIndex = 0;
    
    for (int i = 0; i < n; i++) {
        
        if (matrixOfPrice[line][i] != 0) {
            
            if (matrixOfPrice[line][i] < minNumber) {
                
                minNumber = matrixOfPrice[line][i];
                
                minIndex = i;
                
            }
           
        }
        
    }
    
    return minIndex;
}

=======
//  Created by Antony Miroshnichenko on 15.09.2023.
//

#include <iostream>
#include "Func.h"
using namespace std;

//случайная матрица
void RandMatr(int matr[][100], int m, int n, int a, int b)
{
    srand(time(0));
    int i, j;
    for(i=0; i<m; i++)
    for(j=0; j<n; j++)
    matr[i][j]=rand()%(b-a+1)+a;
}

//вывод матрицы
void PrintMatr(int matr[][100], int m, int n)
{
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++) cout << matr[i][j] << " ";
        cout << endl;
    }
}
>>>>>>> Stashed changes
