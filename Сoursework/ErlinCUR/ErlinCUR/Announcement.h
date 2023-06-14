#pragma once
#include <ostream>
#include <stdio.h>
using namespace std;
class Announcement 
{//����������
private:
	struct Announ_struct
	{
		double product_price;
		int submission_date[3];
		char* category;
		signed long long phone_number;
		char* announ_text;
		int number;
	} current_announ;//���� ������ ��������� ��� ���� ����������
public:
	friend bool compareDate(const Announcement& ann, const Announcement& ann1);// ��������� ���������� �� ���� ������ ��� ����������
	friend bool comparePrice(const Announcement& ann, const Announcement& ann1);// ��������� ��������� �� ��������� ��� ����������
	friend ostream& operator<< (ostream& str, const Announcement& ann);//���������� ��������� ������ � �������
	friend fstream& operator>>(fstream& fstr, Announcement& ann);//���������� ��������� ������� �� �����
	friend bool operator< (const Announcement& ann, const Announcement& ann1); //��������� ���������� ���������
	friend bool operator<= (const Announcement& ann, const Announcement& ann1);
	friend bool operator> (const Announcement& ann, const Announcement& ann1);
	friend bool operator>= (const Announcement& ann, const Announcement& ann1);
	friend bool operator<(const Announcement::Announ_struct ann, const Announcement::Announ_struct ann1);
	friend fstream& operator<< (fstream& str, const Announcement& ann);//���������� ������ � ����
	double Get_product_price();// �������� ���������
	int* Get_submission_date();// �������� ����
	char* Get_category();// �������� ���������
	signed long long Get_phone_number();// �������� ����� ��������
	char* Get_announ_text();// �������� �����
	int Get_number();// �������� ���������� �����
	double Set_product_price(); //���������� �������� ���������
	int* Set_submission_date();//���������� �������� ����
	char* Set_category();//���������� �������� ���������
	signed long long Set_phone_number();//���������� �������� ������ ��������
	char* Set_announ_text();//���������� �������� ������
	int Set_number();//���������� �������� ��� ������
	void Set_current_announ();//���������� �������� ���� ����� ���������
	Announcement(int i, bool Def);//��������� �����������
	Announcement(int i);//����������� ��� ����� ������ ��������
	Announcement(); //����������� �� ���������
};

