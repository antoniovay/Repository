//
//  Func.cpp
//  AaDS Lab 1
//
//  Created by Antony Miroshnichenko on 18.09.2023.
//

#include <iostream>
#include <time.h>
using namespace std;

#include "Func.h"

//вывод матрицы
void printMatr(int **matr, int m, int n)
{
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++) cout << matr[i][j] << " ";
        cout << endl;
    }
}

//случайная матрица
void randMatr(int **matr, int m, int n, int a, int b)
{
    srand(time(0));
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            matr[i][j]=rand()%(b-a+1)+a;
}

//Поменять местами два элемента
void swap (int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
