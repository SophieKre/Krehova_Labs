#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pipe
{
public:
	string name1;
	 int id;
	double length;
	int diametr;
	bool repair;
	static int MAX_ID;
	Pipe();
	Pipe(ifstream& in);
	int getId() const;
	int getDiameter() const;
	double getLength() const;
	bool getRepair() const;
	
	void ChangeStatus();
	friend std::ostream& operator <<(std::ostream& out, const Pipe& p);   
	friend std::ifstream& operator >>(std::ifstream& inf, Pipe& p);         
	friend std::ofstream& operator <<(std::ofstream& outf, const Pipe& p);   
};
