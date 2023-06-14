#include <iostream>
#include "Board.h"
#include "Announcement.h"
using namespace std;

int main()
{
    Announcement ann = Announcement(1, true);
    Board bord(ann);
    while (true)
    {
        int NumOfCommand = 0;
        cout << "\tMenu:\n";
        cout << "1)Add announcement\n";
        cout << "2)Delete announcement\n";
        cout << "3)Show announcement\n";
        cout << "4)Sort announcements\n";
        cout << "5)Download board\n";
        cout << "6)Save board to file\n";
        cout << "7)Board Metrics\n";
        cout << "8)End program\n";
        cout << "\nPlease, input number of command: ";
        cin >> NumOfCommand;
        cin.clear();
        cout << endl;
        switch (NumOfCommand)
        {
        case 1://Добавление элемента
        {
            int NumOfType = 0;
            cout << "Types of addition:\n";
            cout << "1)Add announcement at the end\n";
            cout << "2)Add announcement at the top\n";
            cout << "3)Add announcement with order\n";
            cout << "Please, choose type of adding: ";
            cin >> NumOfType;
            cin.clear();
            cout << endl;
            switch (NumOfType)
            {
            case 1://Добавление элемента в конец
            {
                Announcement ann1 = Announcement(1);
                bord.insertNodeEnd(ann1);
                break;
            }
            case 2://Добавление элемента в начало
            {
                Announcement ann1 = Announcement(1);
                bord.insertNodeHead(ann1);
                break;
            }
            case 3://Добавление элемента в начало и сортировка по номерам
            {
                Announcement ann1 = Announcement(1);
                bord.insertNodeHead(ann1);
                bord.SortNumber();
                break;
            }
            default:
                break;
            }
            break;
        }
        case 2://Удаление элемента
        {
            Announcement ann1 = Announcement(2, true);
            bord.deletelem(ann1);
            break;
        }
        case 3://Вывод и поиск
        {
            int NumOfShow = 0;
            cout << "Types of showing:\n";
            cout << "1)Show numbered announcement\n";
            cout << "2)Show announcements with category\n";
            cout << "3)Show announcements with word\n";
            cout << "4)Show full board\n";
            cout << "Please, choose type of showing: ";
            cin >> NumOfShow;
            cin.clear();
            cout << endl;
            switch (NumOfShow)
            {
            case 1://Вывод всех по порядку
            {
                bord.SortNumber();
                bord.printNodes();
                break;
            }
            case 2://Вывод всех по категории
            {
                bord.printCategory();
                break;
            }
            case 3://Вывод всех со словом
            {
                bord.printWord();
                break;
            }
            case 4://Вывод всех
            {
                bord.printNodes();
                break;
            }
            default:
                break;
            }
            break;

        }
        case 4://Сортировка
        {
            int NumOfSort = 0;
            cout << "Types of sorting:\n";
            cout << "1)Sort by number\n";
            cout << "2)Sort by date\n";
            cout << "3)Sort by price\n";
            cout << "Please, choose type of sorting: ";
            cin >> NumOfSort;
            cin.clear();
            cout << endl;
            switch (NumOfSort)
            {
            case 1://Number
            {
                bord.SortNumber();
                bord.printNodes();
                break;
            }
            case 2://date
            {
                bord.SortDats();
                bord.printNodes();
                break;
            }
            case 3://price
            {
                bord.SortPrice();
                bord.printNodes();
                break;
            }
            default:
                break;
            }
            break;
        }
        case 5://Загрузка мз файла
        {
            bord.InputFromFile();
            bord.printNodes();
            break;
        }
        case 6://Загрузка в файл
        {
            bord.SaveToFile();
            break;
        }
        case 7://Характеристики структуры
        {
            int NumOfMetric = 0;
            cout << "Types of metric:\n";
            cout << "1)Number of announcement\n";
            cout << "2)Sum of prices\n";
            cout << "Please, choose metric: ";
            cin >> NumOfMetric;
            cin.clear();
            cout << endl;
            switch (NumOfMetric)
            {
            case 1://Number
            {
                cout << "Now you have " << bord.NumOfAnn() << " announcements at the bord\n";
                break;
            }
            case 2://prices
            {
                cout << "Now you have sum of prices = " << bord.SumOfPrices() << " of all announcements at the bord\n";
                break;
            }
            default:
                break;
            }
            break;
        }
        case 8://Завершение работы
        {
            return 0;
            break;
        }
        default:
            break;
        }
        cout << "\n";
    }
    return 0;
}
