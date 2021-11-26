#include "Pipe.h"
#include <iostream>
#include <fstream>
using namespace std;


Pipe::Pipe()
{
	id = MAX_ID;
	length = 0;
	diametr = 0;
	repair = 0;
	input = 0;
	output = 0;
	MAX_ID++;
}
int RandomInt(int left, int right)
{
	srand(time(NULL));
	return left + (rand() % (right - left) + 1);
}


void Pipe::ChangeStatus()   //������ ������ �������
{
	repair = !repair;
}



ifstream& operator>>(ifstream& inf, Pipe& p)
{
	inf >> p.id;
	inf >> p.length;
	inf >> p.diametr;
	inf >> p.repair;
	inf >> p.input;
	inf >> p.output;
	return inf;
}

ofstream& operator<<(ofstream& outf, const Pipe& p)
{
	outf << p.id << endl;
	outf << p.length << endl;
	outf << p.diametr << endl;
	outf << p.repair << endl;
	outf << p.input << endl;
	outf << p.output << endl;
	return outf;
}
ostream& operator <<(ostream& out, const Pipe& p)    //���������� ��������� ������ ��� �������� ����
{
	out << "ID �����: " << p.id;
	out << "\t������ �����: " << p.length;
	out << "\t������� �����: " << p.diametr;
	out << "\t������ �������: " << p.repair << "\n";
	if (p.input != 0 && p.output != 0)
	{
		out << "����� ��������� " << p.input << " �� � " << p.output << " ��" << endl;
	}
	return out;
}