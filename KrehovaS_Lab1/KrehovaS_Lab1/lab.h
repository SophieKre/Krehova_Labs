#pragma once
#include"Pipe.h"
#include"KC.h"
#include <vector>
double GetNumber(double min, double max);

vector<int> UserChooseKS(const vector<KS>& ks, int MaxPossibleValue);

vector<int> FindPipe(const vector<Pipe>& p, int MaxPossibleValue);
