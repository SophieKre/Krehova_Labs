#include "Pipe.h"
#include <iostream>
#include <fstream>
using namespace std;

int Pipe::MAX_ID = 1;

Pipe::Pipe()
{
	id = MAX_ID;
	length = 0;
	diametr = 0;
	repair = 0;
	MAX_ID++;
}




void Pipe::ChangeStatus()   //Меняем статус ремонта
{
	repair = !repair;
}



ifstream& operator>>(ifstream& inf, Pipe& p)
{
	inf >> p.id;
	inf >> p.length;
	inf >> p.diametr;
	inf >> p.repair;
	
	return inf;
}

ofstream& operator<<(ofstream& outf, const Pipe& p)
{
	outf << p.id << endl;
	outf << p.length << endl;
	outf << p.diametr << endl;
	outf << p.repair << endl;
	
	return outf;
}
ostream& operator <<(ostream& out, const Pipe& p)    //Перегрузка оператора вывода для структур труб
{
	out << "ID трубы: " << p.id;
	out << "\tДлинна трубы: " << p.length;
	out << "\tДиаметр трубы: " << p.diametr;
	out << "\tСтатус ремонта: " << p.repair << "\n";
	
	return out;
}
