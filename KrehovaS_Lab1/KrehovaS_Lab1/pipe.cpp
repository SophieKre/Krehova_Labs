#include "pipe.h"
#include"lab.h"
#include <string>
using namespace std;


Pipe::Pipe()
{
    id++;
    cout << "Добавляем трубу\n";
    cout << "Введите название:\n";

    cin >> name1;

    cout << "Введите диаметр:\n";
    diametr = 0;
    diametr = GetNumber(1, 10000);

    cout << "Введите длину:\n";
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


void Pipe::ChangeStatus()   //Меняем статус ремонта
{
	repair = !repair;
}


void Pipe::output() {
	cout << "\tТруба:";
	cout << "\tНазвание: " << name1;
	cout << "\tДиаметр: " << diametr;
	cout << "\tДлина: " << length;
	cout << "\tВ ремонте: " << repair << "\t";
}

