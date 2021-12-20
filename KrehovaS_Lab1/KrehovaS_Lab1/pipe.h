#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pipe
{
	string name1;
	 int id;
	double length;
	int diametr;
	bool repair;
public:
	static int MAX_ID;
	Pipe();
	Pipe(ifstream& in);
	int getId() const;
	int getDiameter() const;
	double getLength() const;
	bool getRepair() const;
	double getPressureDropValue() const;
	double getPerformance() const;
	void ChangeStatus();
	friend std::ostream& operator <<(std::ostream& out, const Pipe& p);   
	friend std::ifstream& operator >>(std::ifstream& inf, Pipe& p);         
	friend std::ofstream& operator <<(std::ofstream& outf, const Pipe& p);   
	friend std::istream& operator >>(std::istream& in,  Pipe& p);
};
