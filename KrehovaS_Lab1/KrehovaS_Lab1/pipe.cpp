#include "Pipe.h"
#include <iostream>
#include <fstream>
using namespace std;

int Pipe::MAX_ID = 1; //https://coderoad.ru/20488579/%D0%9F%D0%BE%D1%87%D0%B5%D0%BC%D1%83-%D0%BC%D1%8B-%D0%BE%D0%B1%D1%8A%D1%8F%D0%B2%D0%BB%D1%8F%D0%B5%D0%BC-%D1%81%D1%82%D0%B0%D1%82%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D1%83%D1%8E-%D0%BF%D0%B5%D1%80%D0%B5%D0%BC%D0%B5%D0%BD%D0%BD%D1%83%D1%8E-%D0%B2-%D0%BA%D0%BB%D0%B0%D1%81%D1%81%D0%B5-%D0%B8-%D0%BE%D0%BF%D1%80%D0%B5%D0%B4%D0%B5%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5-%D0%B2%D0%BD%D0%B5-%D0%BA%D0%BB%D0%B0%D1%81%D1%81%D0%B0

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
