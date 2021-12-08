#include "KC.h"
#include "lab.h"
#include <iostream>
#include <string>
#include "lab.h"
using namespace std;

int KS::MAX_ID = 1;
KS::KS(){
id++;

cout << "Adding Station\n";

cout << "Input name:\n";
cin >> name;

cout << "Input number of workshops:\n";
number_ceh = 0;

    number_ceh = GetNumber(1,10000);


cout << "Input number of working workshops:\n";
number_ceh_inWork = -1;

    number_ceh_inWork= GetNumber(0,10000);
    if (number_ceh_inWork > number_ceh) {
        cout << "���������� ���������� ����� ������ ���� ������ ������ ���������� �����\n";
        cout << "���������� �����:\n";
    
}

cout << "I������� ������������� (0 < e <= 100):\n";
efficiency = 0;

    efficiency = GetNumber(1,100);
    
}


KS::KS(string name, double number_ceh, double number_ceh_inWork, double efficiency) {
    this->name = name;
    this->number_ceh = number_ceh;
    this->number_ceh_inWork = number_ceh_inWork;
    this->efficiency = efficiency;
}

KS::~KS()
{
}

void KS::output() {
    cout << "\t������������� �������:";
    cout << "\t��������: " << name;
    cout << "\t���������� �����: " << number_ceh;
    cout << "\t���������� ���������� �����: " << number_ceh_inWork;
    cout << "\t�������������: " << efficiency << "\t";
}

void KS::edit() {
    cout << "\n������������� �������";
    KS::output();
    cout << "\n������� ���������� ���������� ����� :\n";
    do {
        number_ceh = choose(number_ceh_inWork);
    } while (number_ceh_inWork < 0 || number_ceh_inWork > number_ceh);
}
