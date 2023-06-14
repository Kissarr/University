#include "Announcement.h"
#include <iostream>
#include <fstream>
bool compareDate(const Announcement& ann, const Announcement& ann1) // Сравнение объявлений по дате подачи для сортировки
{
	if (ann.current_announ < ann1.current_announ)
		return true;
	return false;
}  

bool comparePrice(const Announcement& ann, const Announcement& ann1) // Сравнение элементов по стоимости для сортировки
{
	if (ann.current_announ.product_price < ann1.current_announ.product_price)
		return true;
	return false;
}

ostream& operator<< (ostream& str, const Announcement& ann) //Перегрузка оператора вывода в консоль
{
	str << "\nAnnouncement #" << ann.current_announ.number << "\nCategory: ";
	char symbol = ann.current_announ.category[0];
	int i = 0;
	while (i < 20 && symbol != 'э' && symbol != 'Н')
	{
		str << symbol;
		symbol = ann.current_announ.category[i+1];
		i++;
	}
	str << "\nSubmission date: " << ann.current_announ.submission_date[0] << "."
		<< ann.current_announ.submission_date[1] << "." << ann.current_announ.submission_date[2];
	str << "\nText: ";
	symbol = ann.current_announ.announ_text[0];
	i = 0;
	while (i < 200 && symbol != 'э' && symbol != 'Н')
	{
		str << symbol;
		symbol = ann.current_announ.announ_text[i + 1];
		i++;
	}
	str << "\nPrice: " << ann.current_announ.product_price;
	str << "\nPhone number: " << ann.current_announ.phone_number;
	return str;
} 

bool operator<(const Announcement& ann, const Announcement& ann1) //перегузка операторов сравнения 
{
	if (ann.current_announ.number < ann1.current_announ.number)
	{
		return true;
	}
	return false;
}
bool operator<(const Announcement::Announ_struct ann, const Announcement::Announ_struct ann1) //перегузка операторов сравнения
{
	if (ann.submission_date[2] > ann1.submission_date[2])
	{
		return true;
	}
	else if (ann.submission_date[2] == ann1.submission_date[2])
	{
		if (ann.submission_date[1] > ann1.submission_date[1])
		{
			return true;
		}
		else if (ann.submission_date[1] == ann1.submission_date[1])
		{
			if (ann.submission_date[0] > ann1.submission_date[0])
			{
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

fstream& operator<<(fstream& fstr, const Announcement& ann) //перегрузка записи в файл
{
	fstr.write((char*)& (ann.current_announ.number), sizeof(ann.current_announ.number));//number
	int i = 0;
	char* cat = new char[20];
	while (ann.current_announ.category[i] != 'э') { cat[i] = ann.current_announ.category[i]; i++;
	}
	for(int j = 0; j < 20; j++)fstr.write((char*)&(cat[j]), sizeof(cat[j]));//category
	for (int k = 0; k < 3; k++)fstr.write((char*)&(ann.current_announ.submission_date[k]), sizeof(ann.current_announ.submission_date[k]));//date
	fstr.write((char*)&(ann.current_announ.product_price), sizeof(ann.current_announ.product_price));//price
	fstr.write((char*)&(ann.current_announ.phone_number), sizeof(ann.current_announ.phone_number));//phone
	i = 0;
	char* txt = new char[200];
	while (ann.current_announ.announ_text[i] != 'э') { txt[i] = ann.current_announ.announ_text[i]; i++;}
	for (int j = 0; j < 200; j++)fstr.write((char*)&(txt[j]), sizeof(txt[j]));//text
	return fstr;
}
fstream& operator>>(fstream& fstr, Announcement& ann) //перегрузка оператора вычитки из файла
{
	ann.current_announ.category = new char[20];
	ann.current_announ.announ_text = new char[200];
	fstr.read((char*)&(ann.current_announ.number), sizeof(ann.current_announ.number));//number
	for (int j = 0; j < 20; j++)
		fstr.read((char*)&(ann.current_announ.category[j]), sizeof(ann.current_announ.category[j]));//category
	for (int k = 0; k < 3; k++)
		fstr.read((char*)&(ann.current_announ.submission_date[k]), sizeof(ann.current_announ.submission_date[k]));//date
	fstr.read((char*)&(ann.current_announ.product_price), sizeof(ann.current_announ.product_price));//price
	fstr.read((char*)&(ann.current_announ.phone_number), sizeof(ann.current_announ.phone_number));//phone
	for (int j = 0; j < 200; j++)fstr.read((char*)&(ann.current_announ.announ_text[j]), sizeof(ann.current_announ.announ_text[j]));//text
	return fstr;
}

bool operator<=(const Announcement& ann, const Announcement& ann1) //перегузка операторов сравнения
{
	if (ann.current_announ.number > ann1.current_announ.number)
	{
		return false;
	}
	return true;
}
bool operator>(const Announcement& ann, const Announcement& ann1) //перегузка операторов сравнения
{
	if (ann.current_announ.number > ann1.current_announ.number)
	{
		return true;
	}
	return false;
}
bool operator>=(const Announcement& ann, const Announcement& ann1) //перегузка операторов сравнения
{
	if (ann.current_announ.number < ann1.current_announ.number)
	{
		return false;
	}
	return true;
}

double Announcement::Get_product_price() // Получить стоимость
{
	return current_announ.product_price;
}

int* Announcement::Get_submission_date() // Получить дату
{
	return current_announ.submission_date;
}

char* Announcement::Get_category() // Получить категорию
{
	return current_announ.category;
}

signed long long Announcement::Get_phone_number() // Получить номер телефона
{
	return current_announ.phone_number;
}

char* Announcement::Get_announ_text() // Получить текст
{
	return current_announ.announ_text;
}

int Announcement::Get_number() // Получить логический номер
{
	return current_announ.number;
}

double Announcement::Set_product_price() //Установить значение стоимости
{
	cout << "Input price: ";
	double price = 0;
	cin.clear();
	cin >> price;
	cin.clear();
	cin.sync();
	return price;
}

int* Announcement::Set_submission_date() //Установить значение даты
{
	cout << "Input date:";
	int Date[3];
	cout << " Day: ";
	int data = 0;
	cin.clear();
	cin.sync();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> data;
	Date[0] = data;
	cout << "Month: ";
	data = 0;
	cin.clear();
	cin.sync();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> data;
	Date[1] = data;
	cout << "Year: ";
	data = 0;
	cin.clear();
	cin.sync();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> data;
	Date[2] = data;
	cin.get();
	cin.clear();
	cin.sync();
	return Date;
}

char* Announcement::Set_category() //Установить значение категории
{
	char* cat = new char[20];
	int i = 0, j = 0;
	cout << "Input category: ";
	cin.clear();
	char symbol = ' ';
	while (cin.get(symbol) && i < 20 && symbol != '\n')
	{
		cat[i] = symbol;
		i++;
	}
	cin.clear();
	cin.sync();
	i--;
	char* category = new char[i];
	while (i >= j)
	{
		category[j] = cat[j];
		j++;
	}
	return category;
}

signed long long Announcement::Set_phone_number() //Установить значение номера телефона
{
	cout << "Input your phone number (like 88005553535): ";
	signed long long phone_number;
	cin.clear();
	cin >> phone_number;
	cin.clear();
	cin.sync();
	return phone_number;
}

char* Announcement::Set_announ_text() //Установить значение текста
{
	char* txt = new char[200];
	int i = 0, j = 0;
	cout << "Input text: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	char symbol = ' ';
	cin.clear();
	while (cin.get(symbol) && i < 200 && symbol != '\n')
	{
		txt[i] = symbol;
		i++;
	}
	cin.clear();
	i--;
	char* full_text = new char[i];
	while (i >= j)
	{
		full_text[j] = txt[j];
		j++;
	}
	return full_text;
}

int Announcement::Set_number() //Установить значение лог номера
{
	cout << "Input number: ";
	int number = 0;
	cin.clear();
	cin >> number;
	cin.clear();
	cin.sync();
	return number;
}

void Announcement::Set_current_announ() //Установить значение всех полей структуры
{
	double product_price = Set_product_price();
	int* submission_date = Set_submission_date();
	int submission_date_value[3] = { submission_date[0], submission_date[1], submission_date[2] };
	char* category = Set_category();
	signed long long phone_number = Set_phone_number();
	char* announ_text = Set_announ_text();
	int number = Set_number();
	current_announ = Announ_struct{ product_price, {submission_date_value[0], submission_date_value[1], submission_date_value[2]},
		category, phone_number, announ_text, number };
}

Announcement::Announcement(int i, bool Def)//Default constr for filler elements
{
	if (i == 1) {
		double product_price = 100;
		int submission_date_value[3] = { 0, 0, 0 };
		char* category = new char[1];
		category[0] = '-';
		signed long long phone_number = 88005553535;
		char* announ_text = new char[1];
		announ_text[0] = '-';
		int number = 0;
		current_announ = Announ_struct{ product_price, {submission_date_value[0], submission_date_value[1], submission_date_value[2]},
			category, phone_number, announ_text, number };
	}
	else if (i == 2)
	{
		double product_price = 100;
		int submission_date_value[3] = { 0, 0, 0 };
		char* category = new char[1];
		category[0] = '-';
		signed long long phone_number = 88005553535;
		char* announ_text = new char[1];
		announ_text[0] = '-';
		int number = Set_number();
		current_announ = Announ_struct{ product_price, {submission_date_value[0], submission_date_value[1], submission_date_value[2]},
			category, phone_number, announ_text, number };
	}
}

Announcement::Announcement(int i) //конструктор
{
	Set_current_announ();
}

Announcement::Announcement() //конструктор по умолчанию
{
	current_announ = Announ_struct{};
}
