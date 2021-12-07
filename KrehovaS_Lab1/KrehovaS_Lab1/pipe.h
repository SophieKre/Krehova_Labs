#pragma once
#include <iostream>
#include <fstream>

class Pipe
{
public:
	int id;
	int length;
	int diametr;
	bool repair;
	void edit();
	
	static int MAX_ID;
	Pipe();
	void ChangeStatus();
	friend std::ostream& operator <<(std::ostream& out, const Pipe& p);     //��� ������ ����� ������ � �������
	friend std::ifstream& operator >>(std::ifstream& inf, Pipe& p);         //��� ����� ����� ������ �� �����
	friend std::ofstream& operator <<(std::ofstream& outf, const Pipe& p);   //��� ������ ����� ������ � ����
};