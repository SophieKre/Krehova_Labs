#include "pipe.h"
#include"lab.h"
#include <string>
using namespace std;


Pipe::Pipe()
{
    id++;
    cout << "��������� �����\n";
    cout << "������� ��������:\n";

    cin >> name1;

    cout << "������� �������:\n";
    diametr = 0;
    diametr = GetNumber(1, 10000);

    cout << "������� �����:\n";
    length = 0;
    length = GetNumber(1, 10000);

  repair = true;
}
Pipe::~Pipe()
{
}
Pipe::Pipe(string name1, double diametr, double length, bool repair)
{
    id++;
    this->name1 = name1;
    this->diametr = diametr;
    this->length = length;
    this->repair = repair;
}


void Pipe::ChangeStatus()   //������ ������ �������
{
	repair = !repair;
}


void Pipe::output() {
	cout << "\t�����:";
	cout << "\t��������: " << name1;
	cout << "\t�������: " << diametr;
	cout << "\t�����: " << length;
	cout << "\t� �������: " << repair << "\t";
}

