//
//  main.cpp
//  AaDS Lab 1
//
<<<<<<< Updated upstream
//  Created by Antony Miroshnichenko on 18.09.2023.
//



#include <iostream>
#include <time.h>

#include "Func.h"



int main()
{
    
    //Объявляем переменные
    
    int** matrixOfPrice, numberOfCities, startingCity, * minWay, * maxWay, minWeight, maxWeight, minWeightHeuristic;
    
    int const MIN_PRICE = 1, MAX_PRICE = 10;
    
    double timeStraight, timeHeuristic;
    
    
    //Вводим значения
    
    std::cout << "Введите количество городов >> ";
    std::cin >> numberOfCities;
    
    std::cout << "Введите начальный город >> ";
    std::cin >> startingCity;
    
    while ( (startingCity < 1) || (startingCity > numberOfCities) ) {
        
        std::cout << "Этот город не входит в число городов, попробуйте ввести начальный город снова >> ";
        std::cin >> startingCity;
        
    }
    
    
    
    // Формируем матрицу стоимостей маршрутов
    
    matrixOfPrice = new int* [numberOfCities];
    
    for (int i = 0; i < numberOfCities; i++) {
        
        matrixOfPrice[i] = new int [numberOfCities];
        
    }
    
    
    
    // Формируем массив для путей
    
    minWay = new int [numberOfCities + 1];
    maxWay = new int [numberOfCities + 1];
    
    
    
    // Формируем массив p
    
    int* p = new int [numberOfCities];
    
    for (int i = 0; i < numberOfCities; i++) {
        
        p[i] = i + 1;
        
    }
    
    
    
    // Заполняем матрицу numberOfCities*numberOfCities стооимостей маршрутов
    
    randomMatrix(matrixOfPrice, numberOfCities, numberOfCities, MIN_PRICE, MAX_PRICE);
    
    printMatrix(matrixOfPrice, numberOfCities, numberOfCities);
    
    
    
    // Реализация точного алгоритма
    
    clock_t start = clock();
    
    countMinWayStraightMethod(matrixOfPrice, minWay, maxWay, numberOfCities, startingCity, MAX_PRICE);
    
    clock_t end = clock();
        
    timeStraight = (double) (end - start) / CLOCKS_PER_SEC;
    
    
        
    std::cout << std::endl << std::endl << "Точный алгоритм:" << std::endl << std::endl;
    
    std::cout << "Путь с минимальной ценой - ";
    printMassive(minWay, numberOfCities + 1);
    
    std::cout << "Путь с максимальной ценой - ";
    printMassive(maxWay, numberOfCities + 1);
    
    minWeight = countWayCoast(matrixOfPrice, minWay, numberOfCities);
    std::cout << "Цена лучшего пути - " << minWeight << std::endl;
    
    maxWeight = countWayCoast(matrixOfPrice, maxWay, numberOfCities);
    std::cout << "Цена худшего пути - " << maxWeight << std::endl;
        
    std::cout << "Время работы алгоритма - " << timeStraight << "s" << std::endl;
    
    
    //delete [] minWay;
    //minWay = new int [numberOfCities + 1];
    
    
    // Реализация эвристического алгоритма 3
    
    start = clock();
    
    countMinWayHeuristicMethod(matrixOfPrice, minWay, numberOfCities, MAX_PRICE, startingCity);
    
    end = clock();
    
    timeHeuristic = (double)(end - start) / CLOCKS_PER_SEC;
    
    std::cout << std::endl << std::endl << "Эвристический алгоритм 3:" << std::endl << std::endl;
    std::cout << "Путь с минимальной ценой (начальный город - 1): ";
    
    //Вывод массива с началом из 1 города
    printMassive(minWay, numberOfCities + 1);
    
    minWeightHeuristic = countWayCoast(matrixOfPrice, minWay, numberOfCities);
    
    
    //Перестановка в соответствии с начальным городом
    
    if (startingCity != 1) {
        
        while (minWay[0] != startingCity - 1) {
            
            int c = minWay[0];
            
            for (int j = 0; j < numberOfCities - 1; j++) {
                
                minWay[j] = minWay[j + 1];
                
            }
            
            minWay[numberOfCities - 1] = c;
            
        }
        
        minWay[numberOfCities] = startingCity - 1;
        
        std::cout << "Путь с минимальной ценой (начальный город - " << startingCity << "): ";
        printMassive(minWay, numberOfCities + 1);
        
    }
    
    std::cout << "Цена лучшего пути - " << minWeightHeuristic << std::endl;
    
    std::cout << "Время работы алгоритма - " << timeHeuristic << "s" << std::endl;    
    
    
    
    
    
    //Отчет
    std::cout << std::endl << std::endl << "Отчёт:" << std::endl;
    
    float quality, time;
    
    
    quality = 100 - (float)(minWeightHeuristic - minWeight) / (float)(maxWeight - minWeight) * 100;
    
    std::cout << std::endl << "Качество эвристического алгоритма 3 относительно точного = " << quality << "%" << std::endl;
    
    
    time = timeHeuristic - timeStraight;
    
    if (time < 0)
        
        std::cout << "Эвристический алгоритм быстрее точного на " << -time << "s" << std::endl;
    
    else if (time > 0)
        
        std::cout << "Точный алгоритм быстрее эвристического на " << time << "s" << std::endl;
    
    else
        
        std::cout << "Алгоритмы по времени работают одинаково" << std::endl;
    
    
    
    std::cout << std::endl << std::endl;
    
    // Очищаем динамические массивы
    
    for (int i = 0; i < numberOfCities; i++) {
        
        delete [] matrixOfPrice[i];
        
    }
    
    delete [] matrixOfPrice;
    
    delete [] p;
    
    delete [] minWay;
    
=======
//  Created by Antony Miroshnichenko on 15.09.2023.
//

#include <iostream>
#include "Func.h"
using namespace std;

#define M 6
#define N 6

int main()
{
    int a[M][N] = {0};
    RandMatr(a, M, N, 1, 100);
    PrintMatr(a, M, N);
>>>>>>> Stashed changes
}
