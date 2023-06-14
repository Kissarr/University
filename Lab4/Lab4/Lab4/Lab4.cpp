#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <conio.h>
#include<cstring>
#include<windows.h>
#pragma warning(disable : 4996)
using std::swap;
#define NUMBER 20 //Для задания количества случайных чисел

struct List // Создание нового типа данных
{
    int value; // информационная часть
    List* next; // служебная часть
    List(int val = 0, List* p = NULL) // конструктор
    {
        value = val;
        next = p;
    }
};

// Включение элемента в конец списка
List* Add_last(int n, List* head)
{
    List* q = new List(n), * p = head;
    if (head == NULL) return q;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
    return head;
}

//генерация случайных чисел и запись в файл (ФУНКЦИЯ 1 из задания)
int filewrite()
{
    FILE* f = fopen("newfile.txt", "wb");
    if (f != NULL)
    {
        srand(time(NULL));
        for (int i = 1; i <= NUMBER; i++)
        {
            int x = rand() % 109 + (-37);
            fwrite(&x, 1, sizeof(x), f);
        }
    }
    fclose(f);
    return 0;
}

// Печать содержимого списка (Функция 4)
void Print_list(List* head)
{
    List* p = head;
    if (p == NULL) puts("List empty!");
    else
        while (p != NULL)
        {
            printf("%d ", p->value);
            p = p->next;
        }
}
//Чтение неупорядоченных чисел из файла и вывод на экран; (ФУНКЦИЯ 2 из задания)
void Print_Nlist()
{
    List* NESORT = NULL;
    int sN[NUMBER];
    FILE* f = fopen("newfile.txt", "rb");
    fread(sN, 1, sizeof(sN), f);
    fclose(f);
    for (int i = 0; i < NUMBER; i++)
    {
         NESORT = Add_last(sN[i], NESORT);
    }
    if (NESORT == NULL) puts("List empty!");
    else
    while (NESORT != NULL)
    {
        printf("%d ", NESORT->value);
        NESORT = NESORT->next;
     }

 }



// Печать содержимого сортированного списка (Дополнительная функция для того что бы подсчитывать повторения в сортированных списках)
void Print_listSort(List* head)
{
    List* p = head;
    int c = 1;
    if (p == NULL) puts("List empty!");
    else {
        while (p->next != NULL)
        {
            if (p->next->value != p->value) {
                printf("%d ", p->value);
                p = p->next;
                c = 1;
            }
            else
            {
                c += 1;
                if (p->next->next != NULL) {
                    if (p->next->next->value != p->next->value)
                        printf("(%d)", c);
                    else
                        p = p->next;
                }
                p = p->next;
            }
        }
        printf("%d ", p->value);
    }
}

// Cоздание списка, упорядоченных по возрастанию значений (Функция 3)
void Sorted_list(List* head)
{
    List* p = head;
    if (p == NULL) puts("List empty!");
    else
        for (int i = 0; i <= NUMBER; i++)
        {
            List* p = head;
            while (p->next != NULL) 
            {
                if (p->next->value < p->value) 
                {
                    swap(p->value, p->next->value);
                    p = p->next;
                }
                else
                    p = p->next;
            }
        }
}



int main()

{
    setlocale(LC_ALL, "Russian");
    filewrite();

    puts("\n Изначальный список");
    Print_Nlist();

    int s2[NUMBER]; //Для записи из файла
    List* headotr = NULL; //Список положительных
    List* headpol = NULL; //Список отрицательных
    FILE* f = fopen("newfile.txt", "rb");
    if (f != NULL) 
    {
        fread(s2, 1, sizeof(s2), f);
        fclose(f);
    }
    for (int i = 0; i < NUMBER; i++) //Распределение изначального списка по положительным и отрицательным числам
    { 
        if (s2[i] < 0)
            headotr = Add_last(s2[i], headotr);
        else
            headpol = Add_last(s2[i], headpol);
    }

    puts("\n Положительные числа");
    Print_list(headpol);   // Список с отрицательными
    Sorted_list(headpol);
    puts("\n Положительные числа, отсортированные");
    Print_listSort(headpol);   // Список с отрицательными отсортированный

    puts("\n Отрицательыне числа");
    Print_list(headotr);   // Список с положительными
    Sorted_list(headotr);
    puts("\n Отрицательные числа, отсортированные");
    Print_listSort(headotr);
}