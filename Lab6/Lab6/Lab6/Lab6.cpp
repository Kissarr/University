
#include "Bank_account.h"
#include "Bank.h"



void main()
{
    setlocale(LC_ALL, "Russian");
    try 
    {
        Bank VTB("VTB"); //Создание банков
        Bank SBER("SBER");

        Bank_account a({ "Сергей Борисович Иванов", "г. Москва, Ленинские горы, дом 1, квартира 703.", "4264 426778", 214647697, 214847 }); //Создание аккаунтов
        Bank_account b({ "Максим Владимирович Хлопонин", "г. Новосибирск, ул. Советская, дом 10, квартира 6.", "3456 875631", 543763531, 97897 });
        Bank_account c({ "Василий Васильевич Васильев", "г. Казань, ул. Светлая, дом 12, квартира 1.", "6438 475123", 534621000, 34672 });

        //Смена всех возможных параметров 1 аккаунта
        a.SetFIO("Василий Иванович Зюганов");
        a.SetAdress("г. Тюмень, Площадь Ленина, дом 21, квартира 67");
        a.SetPassport("2356 634781");
        a.AddComing(55000);
        a.AddOutGoing(333575);

        //Добавление аккаунтов к банкам
        VTB.addBank_account(a);
        VTB.addBank_account(b);
        SBER.addBank_account(c);

        //Вывод аккаунтов для банка
        VTB.print();
        SBER.print();
    }

    catch (const exception& ex)
    {
        cout << "Error: " << ex.what() << endl;
    }

}
