
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Bank_account
{
private:
    string FIO;         //ФИО
    string adress;      //Адресс
    string passport;    //Номер паспорта + кем выдан
    string status;      //Статус счета 
    float coming;       //Количество полученных денег на счет
    float outgo;        //Количество потраченных денег со счета
    long int BIK;       //Банковский идентификационный код
    int number;         //Номер счета

    //**************************************************************** 
    bool Chek_negative_score()  //Проверка открыт ли счет
    {
        if (status == "Открыт")
            return true;
        else
            return false;
    }
    //****************************************************************

public: // БЕЗ фигурных скобок, мой компилятор не хотел работать
    //**************************************************************** 
    Bank_account(string valueFIO, string valueAdress, string valuePassport, int valueBIK, int valueNumber) //Конструктор класса
    {
        if (valueFIO.length() == 0) throw invalid_argument("Uncorrect FIO");
        FIO = valueFIO;
        cout << " Установлено ФИО \n";
        if (valueAdress.length() == 0) throw invalid_argument("Uncorrect adress");
        adress = valueAdress;
        cout << " Установлен адресс \n";
        if (valuePassport.length() == 0) throw invalid_argument("Uncorrect passport");
        passport = valuePassport;
        cout << " Установлен пасспорт \n";
        if (valueBIK < 100000000 || valueBIK > 999999999)  throw invalid_argument("Uncorrect BIK");
        BIK = valueBIK;
        cout << " Установлен BIK \n";
        if (valueNumber < 1) throw invalid_argument("Uncorrect number");
        number = valueNumber;
        cout << " Установлен номер \n";
        status = "Открыт";
        coming = 0;
        outgo = 0;

    }
    //**************************************************************** 
    string GetFIO()  //Возврат ФИО
    {
        return FIO;
    }
    void SetFIO(string valueFIO) //Установка ФИО 
    {
        if (valueFIO.length() == 0) throw invalid_argument("Uncorrect new FIO");
        FIO = valueFIO;
        cout << " Установлено новое ФИО \n";
    }
    //****************************************************************
    string GetAdress()  //Возврат адреса
    {
        return adress;
    }
    void SetAdress(string valueAdress) //Установка адреса
    {
        if (valueAdress.length() == 0) throw invalid_argument("Uncorrect new adress");
        adress = valueAdress;
        cout << " Установлен новый адресс \n";
    }
    //****************************************************************
    string GetPassport()  //Возврат паспорта
    {
        return passport;
    }
    void SetPassport(string valuePassport) //Установка паспорта
    {
        if (valuePassport.length() == 0) throw invalid_argument("Uncorrect new passport");
        passport = valuePassport;
        cout << " Установлен новый паспорт \n";
    }
    //****************************************************************
    string GetStatus()  //Возврат cостояния
    {
        return status;
    }
    //****************************************************************
    float GetComing()  //Возврат суммы приходов
    {
        return coming;
    }
    //****************************************************************
    float GetOutGo()  //Возврат суммы расходов
    {
        return outgo;
    }
    //****************************************************************
    long int GetBIK()  //Возврат БИК
    {
        return BIK;
    }
    //****************************************************************
    int GetNumber()  //Возврат номера счета
    {
        return number;
    }
    //****************************************************************
    void GetMoney()  //Возврат количества денег на счету
    {
        if (coming - outgo >= 0)
            cout << "На вашем счету: " << coming - outgo << "\n\n";
        else
        {
            cout << "You have debts \n\n";;
        }
    }
    //****************************************************************
    void AddComing(float valueAddComing) //Пополнение наличными
    {
        bool Z = Chek_negative_score();
        if (Z == true && valueAddComing > 0)
        {
            coming = coming + valueAddComing;
            cout << " Пополнение счета на сумму: " << valueAddComing << "\n";
        }
        else if (Z == true && valueAddComing <= 0)
            cout << " Число должно быть больше 0, пополнение счета не удалось \n";
        else
            cout << " Счет не открыт, пополнение счета не удалось \n";
    }
    //****************************************************************
    void AddOutGoing(float valueAddOutGoing) //Вывод наличных
    {
        bool Z = Chek_negative_score();
        if (Z == true && valueAddOutGoing > 0)
        {
            outgo = outgo + valueAddOutGoing;
            cout << " Вывод наличных на сумму: " << valueAddOutGoing << "\n";
        }
        else if (Z == true && valueAddOutGoing <= 0)
            cout << " Число должно быть больше 0, вывод наличных не удался \n";
        else
            cout << " Счет не открыт, вывод наличных не удался \n";
    }
    //****************************************************************
    void Print_info()
    {
        cout << "\n\n" << "ФИО:\t\t" << FIO << "\n" << "Адресс:\t\t" << adress << "\n" << "Паспорт:\t" << passport << "\n" << "Cтатус:\t\t" << status << "\n" << "Пополнения:\t" << coming << "\n" << "Снятия:\t\t" << outgo << "\n" << "БИК:\t\t" << BIK << "\n" << "Номер:\t\t" << number << "\n\n";
    }
    //****************************************************************

};




