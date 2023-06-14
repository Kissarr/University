#pragma once
#include <iostream>
#include "Announcement.h"
#include <fstream>
using namespace std;

struct Announcement_list { //������
	struct Announcement_list* next = nullptr;//��������� �� ��������� ������� ������
	Announcement announ;
} typedef ListNode;

class Board {//����� ����������
public:
	explicit Board(Announcement announ) {//����������� �����
		head = new Announcement_list;
		head->next = head;
		head->announ = move(announ);
		end = head;
	};

	Announcement_list* insertNodeEnd(Announcement announ);//���������� �������� � �����
	Announcement_list* insertNodeHead(Announcement announ);//���������� �������� � ������
	Announcement_list* insertNode(Announcement announ);//���������� ��������
	Announcement_list* deletelem(Announcement announ);//�������� ��������
	Announcement_list* findElem(Announcement ann);//����� �������� �� ��� ������
	int NumOfAnn();//������� ���������� ���������
	int SumOfPrices();//������� ����� ���
	void printNodes();//����� ���� �����
	void printCategory();//����� ���������� ���������� ���������
	void printWord();//����� ���������� ���������� �������� ����� � ������
	void SortNumber();//���������� �� ������
	void SortDats();//���������� �� �����
	void SortPrice();//���������� �� ���� �� ������� � �������
	void SaveToFile();//������ �������� � ����
	void InputFromFile();//��������� �������� �� �����
	void SwapAnns(Announcement_list* announ1, Announcement_list* announ2); //����� ������� ����������
	~Board();//����������
private:
	Announcement_list* head = nullptr;//��������� ������
	Announcement_list* end = nullptr;//�������� ������� ������
};


Announcement_list* Board::insertNodeEnd(Announcement announ) { //���������� �������� � �����
	auto new_node = new Announcement_list;
	new_node->announ = announ;
	if (findElem(announ))
	{
		cout << "We can't add two announcements with same number. Please input another." << endl;
		return new_node;
	}
	new_node->next = end->next;
	new_node->announ = move(announ);

	end->next = new_node;
	end = end->next;
	return new_node;
} 
Announcement_list* Board::insertNode(Announcement announ) { //���������� �������� 
	auto new_node = new Announcement_list;
	new_node->announ = announ;
	if (findElem(announ))
	{
		return new_node;
	}
	new_node->next = end->next;
	new_node->announ = move(announ);

	end->next = new_node;
	end = end->next;
	return new_node;
}
Announcement_list* Board::insertNodeHead(Announcement announ) { //���������� �������� � ������
	auto new_node = new Announcement_list;
	new_node->announ = announ;
	if (findElem(announ))
	{
		cout << "We can't add two announcements with same number. Please input another." << endl;
		return new_node;
	}
	new_node->next = end->next;
	new_node->announ = move(announ);

	end->next = new_node;
	head = end->next;
	return new_node;
}
Board::~Board() { //����������
	while (head != end) {
		auto tmp = head;
		head = head->next;
		delete tmp;
	}
	delete head;
}
int Board::NumOfAnn() //������� ���������� ���������
{
	int count = 1;
	auto tmp = head;
	while (tmp->next != head) {
		count++;
		tmp = tmp->next;
	}
	return count;
}
int Board::SumOfPrices() //������� ����� ���
{
	int sum = 0;
	auto tmp = head;
	while (tmp->next != head) {
		sum+=tmp->announ.Get_product_price();
		tmp = tmp->next;
	}
	sum += tmp->announ.Get_product_price();
	return sum;
}
void Board::printNodes() //����� ���� �����
{
	auto tmp = head;
	while (tmp->next != head) {
		cout << tmp->announ << endl;
		tmp = tmp->next;
	}
	cout << tmp->announ << endl;
}
void Board::printCategory() //����� ���������� ���������� ���������
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	auto tmp = head;
	while (tmp->next != head) {
		bool eqalsCat = false;
		int p;
		for (p = 0; p <= i; p++)
		{
			if (tmp->announ.Get_category()[p] != category[p])break;
		}
		if (p == i + 1) eqalsCat = true;
		if(eqalsCat)
			cout << tmp->announ << endl;
		tmp = tmp->next;
	}
	bool eqalsCat = false;
	int p;
	for (p = 0; p <= i; p++)
	{
		if (tmp->announ.Get_category()[p] != category[p])break;
	}
	if (p == i + 1) eqalsCat = true;
	if (eqalsCat)
		cout << tmp->announ << endl;
}
void Board::printWord() //����� ���������� ���������� �������� ����� � ������
{
	char* txt = new char[200];
	int i = 0, j = 0;
	cout << "Input word: ";
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
	auto tmp = head;
	while (tmp->next != head) {
		bool eqals = false;
		int p;
		for (p = 0; p < 200; p++)
		{
			if (tmp->announ.Get_announ_text()[p] == full_text[0])
			{
				int k;
				for (k = 1; k <= i; k++)
				{
					if (tmp->announ.Get_announ_text()[p + k] != full_text[k]) break;
				}
				if (k == i + 1) eqals = true;
			}
			if (tmp->announ.Get_announ_text()[p] == '�') break;
		}
		if (eqals)
			cout << tmp->announ << endl;
		tmp = tmp->next;
	}
	bool eqals = false;
	int p;
	for (p = 0; p < 200; p++)
	{
		if (tmp->announ.Get_announ_text()[p] == full_text[0])
		{
			int k;
			for (k = 1; k <= i; k++)
			{
				if (tmp->announ.Get_announ_text()[p + k] != full_text[k]) break;
			}
			if (k == i + 1) eqals = true;
		}
		if (tmp->announ.Get_announ_text()[p] == '�') break;
	}
	if (eqals)
		cout << tmp->announ << endl;
}
Announcement_list* Board::deletelem(Announcement announ) //�������� ��������
{
	Announcement_list* tmp = findElem(announ);
	if (NumOfAnn() <= 2)
	{
		cout << "\nWe need more then two elements to delete something\n";
		return nullptr;
	}
	if ((tmp != nullptr) && (tmp == head))
	{
		head = head->next;
		delete tmp;
		auto new_ann = head;
		while (new_ann->next != end) {
			new_ann = new_ann->next;
		}
		end = new_ann;
		end->next = head;
	}
	else if ((tmp != nullptr) && (tmp == end))
	{
		delete tmp;
		auto new_ann = head;
		while (new_ann->next != end) {
			new_ann = new_ann->next;
		}
		end = new_ann;
		end->next = head;
	}
	else if ((tmp != nullptr) && (tmp->next == end))
	{
		auto new_ann = head;
		while (new_ann->next != tmp) {
			new_ann = new_ann->next;
		}
		delete tmp;
		new_ann->next = end;
	}
	else if ((tmp != nullptr) && (tmp == head->next))
	{
		head->next = tmp->next;
		delete tmp;
	}
	else if (tmp != nullptr)
	{
		auto new_ann = head;
		while (new_ann->next != tmp) {
			new_ann = new_ann->next;
		}
		new_ann->next = tmp->next;
		delete tmp;
	}
	return tmp;
}
Announcement_list* Board::findElem(Announcement ann) //����� �������� �� ��� ������
{
	bool finder = 0;
	auto tmp = head;
	while (tmp->next != head) {
		if (tmp->announ.Get_number() == ann.Get_number())
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	if (tmp->announ.Get_number() == ann.Get_number())
	{
		return tmp;
	}
	return(nullptr);
}
void Board::SwapAnns(Announcement_list* announ1, Announcement_list* announ2) //����� ������� ����������
{
	Announcement tmp = announ1->announ;
	announ1->announ = announ2->announ;
	announ2->announ = tmp;
}
void Board::SortNumber() //���������� �� ������ 
{
	auto tmp = head;
	int length = NumOfAnn();
	while (length--)
	{
		bool swapped = false;
		while (tmp->next != head)
		{
			if (tmp->next->announ < tmp->announ)
			{
				SwapAnns(tmp, tmp->next);
				swapped = true;
			}
			tmp = tmp->next;
		}
		if (swapped == false)
			break;
		tmp = head;
	}
}
void Board::SortDats() //���������� �� �����
{
	auto tmp = head;
	int length = NumOfAnn();
	while (length--)
	{
		bool swapped = false;
		while (tmp->next != head)
		{
			if (compareDate(tmp->announ, tmp->next->announ))
			{
				SwapAnns(tmp, tmp->next);
				swapped = true;
			}
			tmp = tmp->next;
		}
		if (swapped == false)
			break;
		tmp = head;
	}
}
void Board::SortPrice() //���������� �� ���� �� ������� � �������
{
	auto tmp = head;
	int length = NumOfAnn();
	while (length--)
	{
		bool swapped = false;
		while (tmp->next != head)
		{
			if (comparePrice(tmp->announ, tmp->next->announ))
			{
				SwapAnns(tmp, tmp->next);
				swapped = true;
			}
			tmp = tmp->next;
		}
		if (swapped == false)
			break;
		tmp = head;
	}
}
void Board::SaveToFile() //������ �������� � ����
{
	fstream fstr;
	fstr.open("C:\\Users\\Kisar\\Desktop\\txt.bat", ios::out | ios::binary);//���� �� ����� ������
	if (!fstr) {
		cout << "Can't open file\n";
	}
	auto tmp = head;
	while (tmp->next != head) {
		fstr << tmp->announ;
		tmp = tmp->next;
	}
	fstr << tmp->announ;
	fstr.close();
}
void Board::InputFromFile() //��������� �������� �� �����
{
	fstream fstr;
	fstr.open("C:\\Users\\Kisar\\Desktop\\txt.bat", ios::in | ios::binary);//���� �� ����� ������
	if (!fstr) {
		cout << "Can't open file\n";
	}
	while (!fstr.eof())
	{
		Announcement new_ann;
		fstr >> new_ann;
		insertNode(new_ann);
	}
	fstr.close();
}