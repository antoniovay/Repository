//
//  main.cpp
//  AaDS Lab 1
//
//  Created by Antony Miroshnichenko on 18.09.2023.
//

#include <iostream>
#include <time.h>
using namespace std;

#include "Func.h"

int main()
{
    int const N = 5, A = 1, B = 10;
    
    // Формируем матрицу N*N стооимостей маршрутов
    int** matr = new int* [N];
    for (int i = 0; i < N; i++)
            matr[i] = new int[N];
    
    
    // Формируем массив p
    int* p = new int [N];
    for (int i = 0; i < N; i++)
        p[i] = i + 1;
    
    
    // Заполняем матрицу N*N стооимостей маршрутов
    randMatr(matr, N, N, A, B);
    //printMatr(matr, N, N);
    
    
    // Заполняем массив p
    for (int i = 0; i < N; i++)
        cout << p[i] << " ";
    cout << endl;
    
    
    // Строим все возможные гамильтоновы циклы
    for (int i = N - 2; i > 0; i--)
        
        if (i > 0 && i < N - 1 && p[i] < p [i + 1])
            
            for (int j = N - 1; j > i; j--)
                
                if (j > i && j <= N - 1 && p[i] < p[j])
                {
                    swap(p[i], p[j]);
                    
                    for(int m = i + 1, n = N - 1; m <= n; m++, n--)
                    {
                        swap(p[m], p[n]);
                        //cout << "m = " << m << endl;
                        //cout << "n = " << n << endl;
                    }
                    i = N - 1;
                    /* for (int i = 0; i < N; i++)
                        cout << p[i] << " ";
                    cout << endl; */
                    
                    
                    
                    
                }
        
        
    // Очищаем динамические массивы
    for (int i = 0; i < N; i++)
        delete [] matr[i];
    delete [] matr;
    delete [] p;
    
}
