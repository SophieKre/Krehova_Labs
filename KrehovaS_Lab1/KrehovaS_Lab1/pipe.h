#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pipe
{
public:
	string name1;
	static int id;
	double length;
	double diametr;
	bool repair;
	Pipe();
	Pipe(string name, double diametr, double length,bool repair);
	~Pipe();
	void ChangeStatus();
	void output();
	
};