//
//  main.cpp
//  AaDS Lab 1
//
//  Created by Antony Miroshnichenko on 18.09.2023.
//



#include <iostream>
#include <time.h>

#include "Func.h"



int main()
{
    
    //Объявляем переменные
    
    int** matrixOfPrice, numberOfCities, startingCity, * minWay, minWeight, minWeightHeuristic;
    
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
    
    countMinWayStraightMethod(matrixOfPrice, minWay, numberOfCities, startingCity, MAX_PRICE);
    
    clock_t end = clock();
        
    timeStraight = (double) (end - start) / CLOCKS_PER_SEC;
    
    
        
    std::cout << std::endl << std::endl << "Точный алгоритм:" << std::endl << std::endl;
    std::cout << "Путь с минимальной ценой - ";
    
    printMassive(minWay, numberOfCities + 1);
    
    minWeight = countWayCoast(matrixOfPrice, minWay, numberOfCities);
    
    std::cout << "Цена лучшего пути - " << minWeight << std::endl;
        
    std::cout << "Время работы алгоритма - " << timeStraight << "s" << std::endl;
    
    
    //delete [] minWay;
    //minWay = new int [numberOfCities + 1];
    
    
    // Реализация эвристического алгоритма 3
    
    start = clock();
    
    countMinWayHeuristicMethod(matrixOfPrice, minWay, numberOfCities, MAX_PRICE);
    
    end = clock();
    
    timeHeuristic = (double)(end - start) / CLOCKS_PER_SEC;
    
    std::cout << std::endl << "Эвристический алгоритм 3:" << std::endl;
    std::cout << "Путь с минимальной ценой - ";
    
    printMassive(minWay, numberOfCities + 1);
    
    minWeightHeuristic = countWayCoast(matrixOfPrice, minWay, numberOfCities);
    
    std::cout << "Цена лучшего пути - " << minWeightHeuristic << std::endl;
    
    std::cout << "Время работы алгоритма - " << timeHeuristic << "s" << std::endl;    
    
    
    // Очищаем динамические массивы
    
    for (int i = 0; i < numberOfCities; i++) {
        
        delete [] matrixOfPrice[i];
        
    }
    
    delete [] matrixOfPrice;
    
    delete [] p;
    
    delete [] minWay;
    
}
