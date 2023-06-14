#pragma once
#include <ostream>
#include <stdio.h>
using namespace std;
class Announcement 
{//Объявление
private:
	struct Announ_struct
	{
		double product_price;
		int submission_date[3];
		char* category;
		signed long long phone_number;
		char* announ_text;
		int number;
	} current_announ;//поле класса содеращее все поля объявления
public:
	friend bool compareDate(const Announcement& ann, const Announcement& ann1);// Сравнение объявлений по дате подачи для сортировки
	friend bool comparePrice(const Announcement& ann, const Announcement& ann1);// Сравнение элементов по стоимости для сортировки
	friend ostream& operator<< (ostream& str, const Announcement& ann);//Перегрузка оператора вывода в консоль
	friend fstream& operator>>(fstream& fstr, Announcement& ann);//перегрузка оператора вычитки из файла
	friend bool operator< (const Announcement& ann, const Announcement& ann1); //перегузка операторов сравнения
	friend bool operator<= (const Announcement& ann, const Announcement& ann1);
	friend bool operator> (const Announcement& ann, const Announcement& ann1);
	friend bool operator>= (const Announcement& ann, const Announcement& ann1);
	friend bool operator<(const Announcement::Announ_struct ann, const Announcement::Announ_struct ann1);
	friend fstream& operator<< (fstream& str, const Announcement& ann);//перегрузка записи в файл
	double Get_product_price();// Получить стоимость
	int* Get_submission_date();// Получить дату
	char* Get_category();// Получить категорию
	signed long long Get_phone_number();// Получить номер телефона
	char* Get_announ_text();// Получить текст
	int Get_number();// Получить логический номер
	double Set_product_price(); //Установить значение стоимости
	int* Set_submission_date();//Установить значение даты
	char* Set_category();//Установить значение категории
	signed long long Set_phone_number();//Установить значение номера телефона
	char* Set_announ_text();//Установить значение текста
	int Set_number();//Установить значение лог номера
	void Set_current_announ();//Установить значение всех полей структуры
	Announcement(int i, bool Def);//урезанный конструктор
	Announcement(int i);//конструктор для ввода нового элемента
	Announcement(); //конструктор по умолчанию
};

