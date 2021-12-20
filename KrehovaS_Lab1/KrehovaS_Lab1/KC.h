#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "lab.h"
using namespace std;

class KS
{
public:
	 int id;
	string name;
	int number_ceh;
	int number_ceh_inWork;
	double efficiency;
	static int MAX_ID;
	
	KS();
	KS(ifstream& in);
	void editKS();
	int getId() const;
	string getName() const;
	int getShopsCount() const;
	int getWorkingShopsCount() const;
	double getEfficiency() const;
	double getOccupancyPercentage() const;
	
	friend ostream& operator << (ostream& out, const KS& ks);
	friend ifstream& operator >>(ifstream& inf, KS& ks);
	friend ofstream& operator <<(ofstream& outf, const KS& ks);

	friend istream& operator >> (istream& in, KS& ks);
};