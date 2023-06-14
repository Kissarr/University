#pragma once
#include <iostream>
#include <string>
#include <vector>


class Bank {
private:
	vector <Bank_account> Banks;
	string name;
public:
	//****************************************************************
	Bank(string name)
	{
		if (name.length() == 0) throw invalid_argument("Uncorrect bank name");
		this->name = name;
		cout << " Установлено название банка \n";
	}
	//**************************************************************** 
	string GetName()  //Возврат имени
	{
		return name;
	}
	//**************************************************************** 
	void SetName(string valueName) //Установка имени 
	{
		if (valueName.length() == 0) throw invalid_argument("Uncorrect new bank name");
		name = valueName;
		cout << " Установлено новое название банка \n";
	}
	//****************************************************************
	void addBank_account(Bank_account b) {
		Banks.push_back(b);
	}
	//****************************************************************
	void print() {
		cout << "\nBank: " << name << endl;
		for (Bank_account& b1 : Banks) b1.Print_info();
	}
	//****************************************************************
};
