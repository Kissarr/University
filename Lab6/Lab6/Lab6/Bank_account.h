
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Bank_account
{
private:
    string FIO;         //���
    string adress;      //������
    string passport;    //����� �������� + ��� �����
    string status;      //������ ����� 
    float coming;       //���������� ���������� ����� �� ����
    float outgo;        //���������� ����������� ����� �� �����
    long int BIK;       //���������� ����������������� ���
    int number;         //����� �����

    //**************************************************************** 
    bool Chek_negative_score()  //�������� ������ �� ����
    {
        if (status == "������")
            return true;
        else
            return false;
    }
    //****************************************************************

public: // ��� �������� ������, ��� ���������� �� ����� ��������
    //**************************************************************** 
    Bank_account(string valueFIO, string valueAdress, string valuePassport, int valueBIK, int valueNumber) //����������� ������
    {
        if (valueFIO.length() == 0) throw invalid_argument("Uncorrect FIO");
        FIO = valueFIO;
        cout << " ����������� ��� \n";
        if (valueAdress.length() == 0) throw invalid_argument("Uncorrect adress");
        adress = valueAdress;
        cout << " ���������� ������ \n";
        if (valuePassport.length() == 0) throw invalid_argument("Uncorrect passport");
        passport = valuePassport;
        cout << " ���������� �������� \n";
        if (valueBIK < 100000000 || valueBIK > 999999999)  throw invalid_argument("Uncorrect BIK");
        BIK = valueBIK;
        cout << " ���������� BIK \n";
        if (valueNumber < 1) throw invalid_argument("Uncorrect number");
        number = valueNumber;
        cout << " ���������� ����� \n";
        status = "������";
        coming = 0;
        outgo = 0;

    }
    //**************************************************************** 
    string GetFIO()  //������� ���
    {
        return FIO;
    }
    void SetFIO(string valueFIO) //��������� ��� 
    {
        if (valueFIO.length() == 0) throw invalid_argument("Uncorrect new FIO");
        FIO = valueFIO;
        cout << " ����������� ����� ��� \n";
    }
    //****************************************************************
    string GetAdress()  //������� ������
    {
        return adress;
    }
    void SetAdress(string valueAdress) //��������� ������
    {
        if (valueAdress.length() == 0) throw invalid_argument("Uncorrect new adress");
        adress = valueAdress;
        cout << " ���������� ����� ������ \n";
    }
    //****************************************************************
    string GetPassport()  //������� ��������
    {
        return passport;
    }
    void SetPassport(string valuePassport) //��������� ��������
    {
        if (valuePassport.length() == 0) throw invalid_argument("Uncorrect new passport");
        passport = valuePassport;
        cout << " ���������� ����� ������� \n";
    }
    //****************************************************************
    string GetStatus()  //������� c��������
    {
        return status;
    }
    //****************************************************************
    float GetComing()  //������� ����� ��������
    {
        return coming;
    }
    //****************************************************************
    float GetOutGo()  //������� ����� ��������
    {
        return outgo;
    }
    //****************************************************************
    long int GetBIK()  //������� ���
    {
        return BIK;
    }
    //****************************************************************
    int GetNumber()  //������� ������ �����
    {
        return number;
    }
    //****************************************************************
    void GetMoney()  //������� ���������� ����� �� �����
    {
        if (coming - outgo >= 0)
            cout << "�� ����� �����: " << coming - outgo << "\n\n";
        else
        {
            cout << "You have debts \n\n";;
        }
    }
    //****************************************************************
    void AddComing(float valueAddComing) //���������� ���������
    {
        bool Z = Chek_negative_score();
        if (Z == true && valueAddComing > 0)
        {
            coming = coming + valueAddComing;
            cout << " ���������� ����� �� �����: " << valueAddComing << "\n";
        }
        else if (Z == true && valueAddComing <= 0)
            cout << " ����� ������ ���� ������ 0, ���������� ����� �� ������� \n";
        else
            cout << " ���� �� ������, ���������� ����� �� ������� \n";
    }
    //****************************************************************
    void AddOutGoing(float valueAddOutGoing) //����� ��������
    {
        bool Z = Chek_negative_score();
        if (Z == true && valueAddOutGoing > 0)
        {
            outgo = outgo + valueAddOutGoing;
            cout << " ����� �������� �� �����: " << valueAddOutGoing << "\n";
        }
        else if (Z == true && valueAddOutGoing <= 0)
            cout << " ����� ������ ���� ������ 0, ����� �������� �� ������ \n";
        else
            cout << " ���� �� ������, ����� �������� �� ������ \n";
    }
    //****************************************************************
    void Print_info()
    {
        cout << "\n\n" << "���:\t\t" << FIO << "\n" << "������:\t\t" << adress << "\n" << "�������:\t" << passport << "\n" << "C�����:\t\t" << status << "\n" << "����������:\t" << coming << "\n" << "������:\t\t" << outgo << "\n" << "���:\t\t" << BIK << "\n" << "�����:\t\t" << number << "\n\n";
    }
    //****************************************************************

};




