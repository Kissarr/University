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
    Bank_account(string valueFIO,string valueAdress, string valuePassport, int valueBIK, int valueNumber) //Конструктор класса
    {
        FIO = valueFIO;
        adress = valueAdress;
        passport = valuePassport;
        status = "Открыт";
        coming = 0;
        outgo = 0;
        BIK = valueBIK;
        number = valueNumber;
    }
    //**************************************************************** 
    string GetFIO()  //Возврат ФИО
    { 
        return FIO;
    }
    void SetFIO(string valueFIO) //Установка ФИО 
    {
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
         cout << "\n\n" << "ФИО:\t\t" << FIO << "\n" << "Адресс:\t\t" << adress << "\n" << "Паспорт:\t" << passport << "\n" << "Cтатус:\t\t" << status << "\n" << "Пополнения:\t" << coming << "\n" << "Снятия:\t\t" << outgo << "\n" << "БИК:\t\t" << BIK << "\n" << "Номер:\t\t" << number << "\n";
     }
     //****************************************************************

};  

int main()
{
    setlocale(LC_ALL, "Russian");
    Bank_account a("Сергей Борисович Иванов", "г. Москва, Ленинские горы, дом 1, квартира 703.", "4264 426778", 214647, 214847);
    Bank_account b("Максим Владимирович Хлопонин", "г. Новосибирск, ул. Советская, дом 10, квартира 6.", "3456 875631", 543763, 97897);
    a.Print_info();
    a.GetMoney();


    a.SetFIO("Василий Иванович Зюганов");
    a.SetAdress("г. Тюмень, Площадь Ленина, дом 21, квартира 67");
    a.SetPassport("2356 634781");
    a.AddComing(55000);
    a.AddOutGoing(3575);
    a.Print_info();
    a.GetMoney();

    a.AddComing(-55000);
    a.AddOutGoing(-3575);
    a.Print_info();
    a.GetMoney();

    b.Print_info();
    b.GetMoney();


}


