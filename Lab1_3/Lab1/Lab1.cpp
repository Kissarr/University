
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

class Drobi
{
public:
    float numerator; //числитель
    float denominator; //знаменатель
    float sense; //число
    int* array; //динамический массив с целыми числами числителя
    static int Count; //статическая переменная хранящяя количество экземпляров

    //**************************************************************** 
    Drobi(void) //Конструктор класса
    {
        numerator = 1;
        denominator = 1;
        sense = numerator / denominator;
        Count++;
        array = new int[1];
        array[0] = 1;
        //cout << "\n" << "Вызван конструктор по умолчанию " << this << "\n";

    }
    //**************************************************************** 
    Drobi(float value_numerator, float value_denominator) //Конструктор класса с переменными
    {
        numerator = value_numerator;
        denominator = value_denominator;
        try 
        { 
            if (denominator == 0) throw exception("Деление на 0");
            sense = numerator / denominator; 
        }
        catch (const exception & ex)
        {
            cout << ex.what() << endl;
            cout << "Знаменатель не может равняться 0, знаменатель принят = 1" << endl;
            sense = numerator;
            denominator = 1;
        }
        int Nint = fabs(int(value_numerator));
        int size ;
        try
        {
            if (Nint == 0) throw exception("Малая размерность массива");
            size = trunc(log10(Nint)) + 1;
            array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = Nint % 10;
                Nint = Nint / 10;
            }
        }
        catch (const exception& ex)
        {
            array = new int[1];
            cout << "Размерность для массива принята как 1" << endl;
            size = 1;
            array[0] = 0;
        }

        Count++;
       /* cout << "\n" << "Вызван конструктор с переменными " << this << "\n";*/


    }
    //**************************************************************** 
    Drobi(const Drobi& other) //Конструктор копирования
    {
        numerator = other.numerator;
        denominator = other.denominator;
        try
        {
            if (denominator == 0) throw exception("Деление на 0");
            sense = numerator / denominator;
        }
        catch (const exception& ex)
        {
            cout << ex.what() << endl;
            cout << "Знаменатель не может равняться 0, знаменатель принят = 1" << endl;
            sense = numerator;
            denominator = 1;
        }
        int Nint = fabs(int(numerator));
        int size;
        try
        {
            if (Nint == 0) throw exception("Мааля размерность массива");
            size = trunc(log10(Nint)) + 1;
            array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = Nint % 10;
                Nint = Nint / 10;
            }
        }
        catch (const exception& ex)
        {
            array = new int[1];
            cout << "Размерность для массива принята как 1" << endl;
            size = 1;
            array[0] = 0;
        }
        Count++;
        //cout << "\n" << "Вызван конструктор копирования " << this << "\n";


    }
    //**************************************************************** 
    ~Drobi() //Деструктор 
    {
        delete[] array;

    }
    //**************************************************************** 
    void Print_info() //Вывод информации
    {
        cout << this << "\n" << "Числитель:\t\t" << numerator << "\n" << "Знаменатель:\t\t" << denominator << "\n" << "Число:\t\t\t" << sense << "\n" << "Количество:\t\t" << Count << "\n\n";

    }
    //****************************************************************
    void Plus(const Drobi& other) //сложение дробей
    {

        try
        {
            float ComDenominator = denominator * other.denominator;
            if (ComDenominator == 0) throw exception("Деление на 0");
            float OneNumerator = numerator * other.denominator;
            float TwoNumerator = other.numerator * denominator;
            float Sum = ((OneNumerator + TwoNumerator) / ComDenominator);
            cout << "Cумма сложения:\t\t" << Sum << "\n";
        }
        catch (const exception& ex)
        {
            cout << "Так как деление на 0 сумма принята = 1" << endl;
            float Sum = 0;
            cout << "Cумма сложения:\t\t" << Sum << "\n";
        }

    }
    //****************************************************************
    void Minus(const Drobi& other) //вычитание дробей
    {
        float ComDenominator = denominator * other.denominator;
        float OneNumerator = numerator * other.denominator;
        float TwoNumerator = other.numerator * denominator;
        float Sum = ((OneNumerator - TwoNumerator) / ComDenominator);
        cout << "Cумма вычитания:\t" << Sum << "\n";
    }
    //****************************************************************
    void Multiply(const Drobi& other) //умножение дробей
    {
        float ComDenominator = denominator * other.denominator;
        float ComNumerator = numerator * other.numerator;
        float Sum = (ComNumerator / ComDenominator);
        cout << "Cумма умножения:\t" << Sum << "\n";
    }
    //****************************************************************
    void Division(const Drobi& other) //деление дробей
    {
        float ComDenominator = denominator * other.numerator;
        float ComNumerator = numerator * other.denominator;
        float Sum = (ComNumerator / ComDenominator);
        cout << "Cумма деления:\t\t" << Sum << "\n";
    }
    //****************************************************************
    Drobi operator + (const Drobi& other) // Перегрузка сложение дроби с дробью;
    {
        Drobi temp;
        temp.numerator = ((numerator * other.denominator) + (other.numerator * denominator));
        temp.denominator = denominator * other.denominator;
        temp.sense = ((numerator * other.denominator) + (other.numerator * denominator)) / (denominator * other.denominator);
        Count--; //Так как при создании вызывается конструктор по умолчанию + при возвращении конструктор копирования
        return temp;
 
    }
    //****************************************************************
    Drobi operator - (const Drobi& other) // Перегрузка вычитание дроби с дробью;
    {
        Drobi temp;
        temp.numerator = ((numerator * other.denominator) - (other.numerator * denominator));
        temp.denominator = denominator * other.denominator;
        temp.sense = ((numerator * other.denominator) - (other.numerator * denominator)) / (denominator * other.denominator);
        Count--; //Так как при создании вызывается конструктор по умолчанию + при возвращении конструктор копирования
        return temp;

    }
    //****************************************************************
    Drobi operator + (int i) // Перегрузка сложение числа с дробью;
    {
        Drobi temp;
        temp.numerator = ((numerator) + (i * denominator));
        temp.denominator = denominator;
        temp.sense = ((numerator) + (i * denominator)) / (denominator);
        Count--; //Так как при создании вызывается конструктор по умолчанию + при возвращении конструктор копирования
        return temp;

    }
    //****************************************************************
    Drobi operator - (int i) // Перегрузка вычитание числа с дробью;
    {
        Drobi temp;
        temp.numerator = ((numerator)-(i * denominator));
        temp.denominator = denominator;
        temp.sense = ((numerator)-(i * denominator)) / (denominator);
        Count--; //Так как при создании вызывается конструктор по умолчанию + при возвращении конструктор копирования
        return temp;

    }
    //****************************************************************
    void operator = (const Drobi& other) //Перегрузка присваивания
    {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        this->sense = other.sense;
        
        if (this->array != nullptr)
            delete[] this->array;
        int Nint = fabs(int(this->numerator));
        int size;
        try
        {
            if (Nint == 0) throw exception("Мааля размерность массива");
            size = trunc(log10(Nint)) + 1;
            array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = Nint % 10;
                Nint = Nint / 10;
            }
        }
        catch (const exception& ex)
        {
            array = new int[1];
            cout << "Размерность для массива принята как 1" << endl;
            size = 1;
            array[0] = 0;
        
        }
    }
    //****************************************************************
    operator float() { return  sense; } //перегрузка приведение к типу float
    //****************************************************************

};
//****************************************************************
void printFloatSense(float value)
{
    cout << "\n" << "Дробь в типе float: " << value << "\n\n";
}
//****************************************************************
ostream& operator << (ostream& os, const Drobi& Drobi)
{
    os << Drobi.numerator << " " << Drobi.denominator << " " << Drobi.sense;
    return os;
}
//****************************************************************
istream& operator >> (istream& is,  Drobi& Drobi)
{
    is >> Drobi.numerator >> Drobi.denominator >> Drobi.sense;
    return is;
}
//****************************************************************
int Drobi::Count = 0; //cтатичная переменная, количество экземпляров класса
//****************************************************************

class DrobiResult : public Drobi
{
public:
    float senseResult; //Результат вычесления дроби по сути он есть и в классе родителя
    //****************************************************************
    DrobiResult(float value_numerator, float value_denominator) //Конструктор класса с переменными
    {
        numerator = value_numerator;
        denominator = value_denominator;
          try
          {
              if (denominator == 0) throw exception("Деление на 0");
              sense = numerator / denominator;
          }
          catch (const exception& ex)
          {
              cout << ex.what() << endl;
              cout << "Знаменатель не может равняться 0, знаменатель принят = 1" << endl;
              sense = numerator;
              denominator = 1;
          }
        sense = numerator / denominator;
        senseResult = sense;
        int Nint = fabs(int(value_numerator));
        int size;
        try
        {
            if (Nint == 0) throw exception("Мааля размерность массива");
            size = trunc(log10(Nint)) + 1;
            array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = Nint % 10;
                Nint = Nint / 10;
            }
        }
        catch (const exception& ex)
        {
            array = new int[1];
            cout << "Размерность для массива принята как 1" << endl;
            size = 1;
            array[0] = 0;
        }

        Count++;
    }
    //****************************************************************
    void Print_info() //Вывод информации
    {
        cout << this <<  "\n" << "Рез. вычисления дроби:\t" << senseResult << "\n" <<  "\n";

    }
};
//****************************************************************
class DrobiMixed : public Drobi
{
public:
    int full; //Целая часть
    float shot; //Остаток
    //****************************************************************
    DrobiMixed(float value_numerator, float value_denominator) //Конструктор класса с переменными
    {
        numerator = value_numerator;
        denominator = value_denominator;
        try
        {
            if (denominator == 0) throw exception("Деление на 0");
            sense = numerator / denominator;
        }
        catch (const exception& ex)
        {
            cout << ex.what() << endl;
            cout << "Знаменатель не может равняться 0, знаменатель принят = 1" << endl;
            sense = numerator;
            denominator = 1;
        }
        sense = numerator / denominator;
        full = numerator / denominator;
        shot = numerator - (denominator * full);
        int Nint = fabs(int(value_numerator));
        int size;
        try
        {
            if (Nint == 0) throw exception("Мааля размерность массива");
            size = trunc(log10(Nint)) + 1;
            array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = Nint % 10;
                Nint = Nint / 10;
            }
        }
        catch (const exception& ex)
        {
            array = new int[1];
            cout << "Размерность для массива принята как 1" << endl;
            size = 1;
            array[0] = 0;
        }
        Count++;
    }
    //****************************************************************
    void Print_info() //Вывод информации
    {
        cout << this << "\n" << "Смешанная дробь:\t" << full << " + " << shot << "/" << denominator << "\n";

    }
};

struct List // Создание нового типа данных
{
    Drobi value; // информационная часть
    List* next; // служебная часть
    List(Drobi val = Drobi(), List* p = NULL) // конструктор
    {
        value = val;
        next = p;


    }
};

// Включение элемента в конец списка
List* Add_last(Drobi b, List* head)
{
    List* q = new List(b), * p = head;
    if (head == NULL) return q;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
    return head;
}

// Включение элемента в начало списка
List* Insert_first(Drobi b, List* head)
{
    List* q = new List(b, head);
    return q;
}

// Удаление первого элемента из списка 
List* Delete_value(List* head)
{
    try
    {
        List* p = head, * t;
        if (head == NULL) 
        { 
            throw exception("Список пуст");
            return NULL; 
        }
        {
            t = head;
            head = head->next;
            delete t;
            return head;
        }
        return head;
    }
    catch (const exception& ex)
    {
        cout << "Список пуст удалять нечего" << endl;
        return NULL;
    }
}
// Вывод дробей списка
void Print_list(List* head)
{
    List* p = head;
    if (p == NULL) puts("List empty!");
    else
        cout << "Дроби из списка:" << '\n';
        while (p != NULL)
        {
            cout << p->value<< '\n';
            p = p->next;
        }
        cout  << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List* head = NULL;
    head = Delete_value(head);

    Drobi a(0, 0);
    Drobi b(25,5);
    DrobiMixed d(0, 0);
    DrobiResult e(0, 0);
    DrobiMixed c(0, 0);
    DrobiResult z(0, 0);
    b.Print_info();
    b = a;
    b.Print_info();
    a.Plus(b);






}


