#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <conio.h>
#include<cstring>
#include<windows.h>
#pragma warning(suppress : 4996)


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

// Включение элемента в начало списка
List* Insert_first(int n, List* head)
{
    List* q = new List(n, head);
    return q;
}
// Удаление элемента из списка по значению
List* Delete_value(int n, List* head)
{
    List* p = head, * t;
    if (head == NULL) { return NULL; }
    if (head->value == n) // Удаление элемента из начала списка
    {
        t = head;
        head = head->next;
        delete t;
        return head;
    }
    while (p->next != NULL) // Удаление элемента из середины списка
        if (p->next->value == n)
        {
            t = p->next;
            p->next = p->next->next;
            delete t;
            return head;
        }
        else p = p->next;

    return head;
}
// Поиск количества элементов списка, значения которых совпадают с первым и послединм элементом списка
int Search_FirstAndLast(List* head)
{
    List* p = head;
    int first = p->value;            //Взятие 1 значения
    int last, sum_elem =0;
    while (p->next->next != NULL)    //Поиск последнего значения
        p = p->next;
    last = p->next->value;

    List* z = head;
        while (z != NULL)            //Если список не пустой
        {
            if (z->value == first or z->value == last) //Пробег по списку в поиске совпадений с 1 и последним значениями
            { 
                sum_elem += 1;
                z = z->next;
            }
            else
                z = z->next;
        }
        printf("%d ", sum_elem);
        return sum_elem;
}

// Печать содержимого списка
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
// Совмещение одинаковых элементов 2 списков
int AmongUs(List* head, List* headen)
{
    int lng = 0;
    List* TWO = NULL;   // инициализация 3 списка
    List* p = headen;   // 1 список

    while (p != NULL)
    {
        List* s = head;     // 2 список
        while (s != NULL)
        {
            if (p->value == s->value)
            {
                TWO = Insert_first(p->value, TWO);
                int x = p->value; 
                lng += 1;
                s = s->next;
                Delete_value(x, s); //Удаляет значение из списка, что бы оно не повторялось
            }
            else
                s = s->next;
        }
        p = p->next;

    }


    Print_list(TWO); // Вывод списка
    puts("\n Длина нового списка");
    printf("%d ", lng); // Вывод длины списка
    return lng;
}

int main()

{
    setlocale(LC_ALL, "Russian");
    List* head = NULL;
    head = Insert_first(1, head);
    head = Add_last(2, head);
    head = Insert_first(3, head);
    head = Add_last(4, head);
    head = Insert_first(5, head);
    head = Insert_first(6, head);
    head = Insert_first(3, head);
    head = Insert_first(8, head);
    head = Insert_first(9, head);
    head = Insert_first(23, head);
    head = Add_last(17, head);
    head = Insert_first(15, head);
   // Search_FirstAndLast(head);

    List* headen = NULL;
    headen = Insert_first(16, headen);
    headen = Insert_first(23, headen);
    headen = Insert_first(19, headen);
    headen = Insert_first(18, headen);
    headen = Add_last(17, headen);
    headen = Insert_first(3, headen);


    puts("\n Первый лист");
    Print_list(head);   // 1 лист
    puts("\n Второй лист");
    Print_list(headen); // 2 лист
    puts("\n Третий лист");
    AmongUs(head, headen);




}


