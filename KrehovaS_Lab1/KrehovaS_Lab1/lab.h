#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
template <typename T>
T tryInput(string alert, T min, T max = 1000000)
{
	T x;
	cout << alert;
	while ((cin >> x).fail() || x < min || x > max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << alert;
	}
	return x;
}

template <typename T>
int tryInput(string alert, const unordered_map <int, T>& myMap)
{
	if (!myMap.empty())
	{
		int x;
		cout << alert;
		while ((cin >> x).fail() || myMap.find(x) == myMap.end())
		{
			if (x == 0)
				return 0;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << alert;
		}
		return x;
	}
	else
	{
		return 0;
	}
}

template <typename T>
// если есть id больше 1, то находит больше 1, если вектор пустой, то 0
int findMaxId(const T& myMap)
{
	int maxId = 0;
	for (const auto& p : myMap)
	{
		if (p.first > maxId)
		{
			maxId = p.first;
		}
	}
	return maxId;
}

// Удаление объектов
template <typename T>
void deleteObj(unordered_map <int, T>& myMap, int id) {
	myMap.erase(id);
}

template <typename T>
void swapValues(T& value1, T& value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;
}

template <typename T>
vector <int> inputVecId(unordered_map <int, T> myMap)
{
	vector <int> vecId;
	bool input = true;
	while (input)
	{
		int id = tryInput("Please, enter correct id of next pipe you want to edit or enter [0] to stop input: ", 0);
		if (id != 0)
		{
			if (myMap.find(id) != myMap.end())
			{
				vecId.push_back(id);
			}
		}
		else
		{
			input = false;
		}
	}
	return vecId;
}