#include <iostream>
using namespace std;
int tabs = 0; //Для создания отступов
struct Branch

{
	int Data; //Поле данных
	Branch* LeftBranch; //УКАЗАТЕЛИ на соседние веточки
	Branch* RightBranch;

};

//Функция внесения данных

void Add(int aData, Branch*& aBranch)

{
	//Если ветки не существует
	if (!aBranch)
	{ //создадим ее и зададим в нее данные
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}

	else //если ветка существует

		if (aBranch->Data > aData)
		{ //Если оно меньше того, что в этой ветке - добавим влево
			Add(aData, aBranch->LeftBranch);
		}
		else
		{ //Иначе в ветку справа
			Add(aData, aBranch->RightBranch);
		};
}

void print(Branch* aBranch) // Дананя часть кода написана не мной, добавена для красивого вывода
{
	if (!aBranch) return; 
	tabs += 5; 
	print(aBranch->LeftBranch); 
	for (int i = 0; i < tabs; i++) cout << " "; 
	cout << aBranch->Data << endl; 
	print(aBranch->RightBranch);
	tabs -= 5; 
	return;
}

int pr_obhLEFT(Branch* aBranch) 
{
	if (NULL == aBranch->LeftBranch) 
	{
		int t = aBranch->Data;
		return t;
	}
	pr_obhLEFT(aBranch->LeftBranch); //Обошли левое поддерево
}

int pr_obhRight(Branch* aBranch)
{
	if (NULL == aBranch->RightBranch)
	{
		int d = aBranch->Data;
		return d;
	}
	pr_obhRight(aBranch->RightBranch); //Обошли правое поддерево
}

void SmenaB (Branch* aBranch, int g)
{
	if (NULL == aBranch->LeftBranch)
	{

		aBranch->Data = g;
		return;
	}
	SmenaB(aBranch->LeftBranch, g); //Обошли левое поддерево
}

void SmenaM(Branch* aBranch, int gg)
{
	if (NULL == aBranch->RightBranch)
	{

		aBranch->Data = gg;
		return;
	}
	SmenaM(aBranch->RightBranch, gg); //Обошли правое поддерево
}



void FreeTree(Branch* aBranch) // Удалить дерево
{
	if (!aBranch) return;
	FreeTree(aBranch->LeftBranch);
	FreeTree(aBranch->RightBranch);
	delete aBranch;
	return;
}


int main()
{
	setlocale(LC_ALL, "rus");
	Branch* Root = 0;
	int vel;
	int element;
	int k, x;
	cout << "Введите кол-во элементов для будущего дерева: ";
	cin >> vel;
	cout << endl;
	cout << "Введите элементы дерева: ";
	cout << endl;
	for (int i = 0; i < vel; i++)
	{
		cin >> x;
		Add(x, Root);
	}
	cout << endl;
	cout << "Вывод бинарного дерева: " << endl;
	print(Root);
	cout << endl;
	int t = pr_obhLEFT(Root);
	int d = pr_obhRight(Root);
	SmenaB(Root, d);
	SmenaM(Root, t);
	cout << endl;
	cout << "Вывод измененного бинарного дерева: " << endl;
	print(Root);
	FreeTree(Root);
	return 0;

}