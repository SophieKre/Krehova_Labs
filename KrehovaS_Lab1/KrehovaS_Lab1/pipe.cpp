#include "pipe.h"
#include"lab.h"
#include <string>
using namespace std;

int Pipe::MAX_ID = 0;

Pipe::Pipe()
{
	this->id = ++MAX_ID;
	this->diametr = tryInput("Введите диаметр трубы: ", 0);
	this->length = tryInput("Введите длину трубы: ", 0.0);
	this->repair = false;
	
	
	
}



void Pipe::ChangeStatus()  
{
	repair = !repair;
}

Pipe::Pipe(ifstream& in)
{
	in >> this->id;
	in >> this->diametr;
	in >> this->length;
	in >> this->repair;
}


istream& operator>>(std::istream& in, Pipe& p)
{
	p.id = ++Pipe::MAX_ID;
	p.length = tryInput("Пожалуста, введите длину: ", 1.0);
	p.diametr = tryInput("Пожалуйста, введите диаметр: ", 1);
	
	p.repair = false;
	return in;
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
	outf << "ID:" << p.id << endl;
	outf <<"Длина:"<< p.length << endl;
	outf <<"Диаметр"<< p.diametr << endl;
	if (p.repair)
	{
		outf << "Труба нуждается в ремонте" << endl;
	}
	else
	{
		outf << "Труба рабочая" << endl;
	}
	outf << endl;
	
	/*outf << p.input << endl;
	outf << p.output << endl;*/
	return outf;
}
ostream& operator <<(ostream& out, const Pipe& p)    //���������� ��������� ������ ��� �������� ����
{
	out << "ID трубы: " << p.id;
	out << "\tДлина трубы: " << p.length;
	out << "\tДиаметр трубы: " << p.diametr;
	out << "\tПризнак в ремонте: " << p.repair << "\n";
	
	return out;
}
int Pipe::getId() const
{
	return id;
}

int Pipe::getDiameter() const
{
	return diametr;
}

double Pipe::getLength() const
{
	return length;
}

bool Pipe::getRepair() const
{
	return repair;
}