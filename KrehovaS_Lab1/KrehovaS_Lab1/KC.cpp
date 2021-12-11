#include "KC.h"


using namespace std;

int KS::MAX_ID = 0;
KS::KS(){
	this->id = ++MAX_ID;
	cout << "Введите название КС: ";
	cin.ignore();
	getline(cin, this->name);
	this->number_ceh = tryInput("Введите количество цехов: ", 0);
	this->number_ceh_inWork = tryInput("Введите количество работающих цехов (меньше/равно всего количества цехов!): ", 0, number_ceh);
	this->efficiency = tryInput("Введите эффективность (0 - 100):", 0, 100);
}



ostream& operator <<(ostream& out, const KS& ks)       
{
	out << "ID ��: " << ks.id;
	out << "\tНазвание: " << ks.name;
	out << "\tВсего цехов: " << ks.number_ceh;
	out << "\tРаботающих цехов: " << ks.number_ceh_inWork;
	out << "\tЭффективность: " << ks.efficiency << "%" << endl << endl;
	return out;
}
KS::KS(ifstream& in)
{
	in >> this->id;
	in.ignore();
	getline(in, this->name);
	in >> this->number_ceh;
	in >> this->number_ceh_inWork;
	in >> this->efficiency;
}
int KS::getId() const
{
	return id;
}

string KS::getName() const
{
	return name;
}

int KS::getShopsCount() const
{
	return number_ceh;
}

int KS::getWorkingShopsCount() const
{
	return number_ceh_inWork;
}

double KS::getEfficiency() const
{
	return efficiency;
}

double KS::getOccupancyPercentage() const
{
	return number_ceh_inWork * (1.0 / number_ceh) * 100;
}
void KS::editKS()
{
	bool pick = tryInput<bool>("вы хотите запустить[1] или остановить [0] работаюдщие цехи(0 - shops total)? ", 0, 1);
	if (pick && number_ceh_inWork < number_ceh)
	{
		++number_ceh_inWork;
	}
	if (!pick && number_ceh_inWork > 0)
	{
		--number_ceh_inWork;
	}
}
ifstream& operator>>(ifstream& inf, KS& ks)
{
	inf >> ks.id;
	inf >> ks.name;
	inf >> ks.number_ceh;
	inf >> ks.number_ceh_inWork;
	inf >> ks.efficiency;
	return inf;
}

ofstream& operator<<(ofstream& outf, const KS& ks)
{
	outf << ks.id << endl;
	outf << ks.name << endl;
	outf << ks.number_ceh << endl;
	outf << ks.number_ceh_inWork << endl;
	outf << ks.efficiency << endl;
	return outf;
}
istream& operator>>(istream& in, KS& ks)
{
	ks.id = ++KS::MAX_ID;
	in >> ks.name;
	ks.number_ceh = tryInput("Введите количество цехов: ", 1);
	ks.number_ceh_inWork = tryInput("Введите количетво работающих цехов : ", 1);
	ks.efficiency = tryInput("Введите эффективность: ", 1);
	return in;
}