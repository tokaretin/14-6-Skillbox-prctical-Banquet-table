﻿/*Задание 1. Банкетный стол
Что нужно сделать
По поводу успешного прохождения двумерных массивов собирается банкет, 
организуется стол на 12 персон. Есть два VIP-места, они рядом во главе 
стола. Стол протяжён в длину, места расположены в два ряда. Каждый 
пришедший должен быть «упакован» соответствующим образом. Во-первых, 
столовые приборы: по три на каждого человека (вилка, ложка, нож) и одна 
маленькая дополнительная ложечка для VIP-персон (для десерта). Во-вторых, 
тарелки: каждому по две (для первого и второго блюда) и ещё одна тарелка для 
VIP-персон (для десерта). В-третьих, стулья: минимум один для каждого гостя. 
Заведите соответствующие двумерные массивы для количества приборов, посуды 
и стульев и проинициализируйте их.

Но это ещё не всё. На банкете после инициализации происходят некоторые события. 
- Пришедшая на пятое место первого ряда дама привела с собой ребёнка, и поэтому 
на данное место был приставлен ещё один стул. 
- С третьего места во втором ряду в неизвестном направлении была украдена ложка. 
Одна из VIP-персон (любая) 
поделилась своей ложкой с тем, кто остался без ложки, и стала есть суп 
десертной. За ненадобностью официант забрал у VIP-гостя одну десертную тарелку, 
ведь есть десерт ложкой, которая уже побывала уже в супе, неприлично. Больше 
без происшествий, однако эти события на банкете надо отразить в инициализированных 
ранее массивах.

Советы и рекомендации
Все действия в задаче оформляются в виде выражений внутри исходного кода. 
Текстовый интерфейс для задачи делать необязательно.
Необходимо объявить несколько двумерных массивов (по типам приборов).
Массивы очень удобно инициализировать сразу при объявлении так:
int packages[2][3] = {{2, 1, 7},{3, 5, 31}}
Проще будет сначала записать в массивы значения из задания, а потом отнимать или
прибавлять нужные элементы, следуя за сценарием событий:
packages[0][0] +=1; // packages[0][0] хранит в себе цифру 2, и мы прибавляем к 
этому значению 1 — += 1.
Что оценивается
Все действия внутри массива соответствуют условию.*/

#include <iostream>
#include <vector>

int main() {
        
    //по три на каждого человека (вилка, ложка, нож)
    std::vector<std::vector<int>> cutlery { {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} }; 
    
    //по две на каждого человека (тарелки)
    std::vector<std::vector<int>> dishes { {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} }; 

    //по одному на каждого человека (стулу)
    std::vector<std::vector<int>> chairs{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} }; 

    // та же запись, но только с использованием массива
    
    ////по три на каждого человека (вилка, ложка, нож) (VIP-персоны + ложка и тарелка)
    //int cutlery[2][12] = { {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, 
    //                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} }; 
    ////по две на каждого человека (тарелки)
    //int dishes[2][12] = { {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    //                      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} }; 
    ////по одному на каждого человека (стулу)
    //int chairs[2][12] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    //                      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} }; 
    
    // VIP-персоны (+ ложка и тарелка)
    cutlery[0][5] += 1;
    cutlery[0][6] += 1;
    dishes[0][5] += 1;
    dishes[0][6] += 1;


    // Пришедшая на пятое место первого ряда дама привела с собой ребёнка, и поэтому 
    // на данное место был приставлен ещё один стул
    chairs[0][4] += 1;

    // С третьего места во втором ряду в неизвестном направлении была украдена ложка
    cutlery[1][2] -= 1;

    // Одна из VIP-персон поделилась своей ложкой с тем, кто остался без ложки
    for (int i = 0; i < 12; i++) {
        if (cutlery[1][i] == 0) {
            cutlery[1][i] += 1;
            cutlery[0][5] -= 1;
            break;
        }
    }

    // За ненадобностью официант забрал у VIP-гостя одну десертную тарелку
    dishes[0][5] -= 1;

    // Вывод состояния массивов после событий
    std::cout << "Состояние массива с приборами:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << cutlery[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Состояние массива с посудой:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << dishes[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Состояние массива со стульями:\n";
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 12; j++) 
        {
            std::cout << chairs[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

