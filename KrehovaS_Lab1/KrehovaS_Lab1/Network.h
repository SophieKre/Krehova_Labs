#pragma once
#include <unordered_map>
#include "pipe.h"
#include "KC.h"
#include <iostream>
#include <typeinfo>
using namespace std;
class Network {
public:
	unordered_map<int, Pipe>pipesMap;
	unordered_map<int, KS>KcstationMap;
	template <typename classType>
	void deleting(unordered_map<int, classType>& map);
	template <typename classType>
	void editObjectById(unordered_map<int, classType>& map);

	template <typename classType>
	vector<int> search(unordered_map<int, classType>& map);

	template <typename classType>
	void filtration(unordered_map<int, classType>& map, vector<int> vectorID);
private:
};
template<typename classType>
inline void Network::deleting(unordered_map<int, classType>& map) {
	Network::outputMap(map);
	cout << "\nInput ID(s) or 0 to exit\n";

	int choice;
	do {
		choice = choose(classType::id);
		if (choice == 0)
			break;
		if (map.count(choice))
			map.erase(choice);
		else
			cout << "Out of map\n";
	} while (choice != 0);
}



template<typename classType>
inline void Network::editObjectById(unordered_map<int, classType>& map) {
	Network::outputMap(map);
	if (map.size()) {
		cout << "\nВведите id\n";
		int tempID = choose(classType::id);
		if (map.count(tempID)) {
			map[tempID].edit();
		}
		else {
			cout << "\nWrong id\n";
		}
	}
}

template<typename classType>
inline vector<int> Network::search(unordered_map<int, classType>& map)
{
	vector<int> vectorID;
	if (map.size() == 0) {
		cout << "Map пуст";
		return vectorID;
	}

	if (typeid(classType) == typeid(Pipe)) {
		cout << "\nИскать по :\n1) имени\n2) по количеству работающих цехов\n0) Выйти\n";

		string name;
		bool isWorking;
		switch (choose(2))
		{
		case 0:
			return vectorID;
		case 1:
			cout << "\nInput name:\n";
			cin >> name;
			for (auto& item : pipesMap) {
				if (item.second.name == name) {
					vectorID.push_back(item.first);
				}
			}
			break;
		case 2:
			cout << "\nРаботает?\n0) Нет\n1) Да\n";
			isWorking = choose(1);
			for (auto& item : pipesMap)
				if (item.second.isWorking == isWorking)
					vectorID.push_back(item.first);
			break;
		default:
			break;
		}
		cout << "\nID: ";
		for (int i : vectorID)
			cout << i << "  ";
		cout << "\n";
	}
	else {
		cout << "\nИскать по :\n1) имени\n2) проценту незадействованных цехов\n0) Выйти\n";

		string name;
		double percentOfWorkshops;
		switch (choose(2))
		{
		case 0:
			return vectorID;
		case 1:
			cout << "\nВв:\n";
			cin >> name;
			for (auto& item : stationsMap) {
				if (item.second.name == name) {
					vectorID.push_back(item.first);
				}
			}
			break;
		case 2:
			cout << "\nВведите процент незадействованных цехов или нажмите 0, чтобы выйти\n";
			do
			{
				percentOfWorkshops = inputDouble();
			} while (percentOfWorkshops <= 0 || percentOfWorkshops > 100);
			if (percentOfWorkshops == 0)
				return vectorID;

			cout << "\n1) мееньше\n2) больше\n0) выйти\n";
			switch (choose(2)) {
			case 0:
				return vectorID;
			case 1:
				for (auto& item : stationsMap) {
					cout << (1.0 * item.second.numberOfWorkingWorkshops / (1.0 * item.second.numberOfWorkshops)) * 100.0;
					if ((1.0 * item.second.numberOfWorkingWorkshops / (1.0 * item.second.numberOfWorkshops)) * 100.0 < percentOfWorkshops)
						vectorID.push_back(item.first);
				}
				break;
			case 2:
				for (auto& item : stationsMap)
					if ((1.0 * item.second.numberOfWorkingWorkshops / (1.0 * item.second.numberOfWorkshops)) * 100.0 >= percentOfWorkshops)
						vectorID.push_back(item.first);
				break;
			}

		default:
			break;
		}
		cout << "\nID: ";
		for (int i : vectorID)
			cout << i << "  ";
		cout << "\n";
	}
	return vectorID;

}

template<typename classType>
inline void Network::filtration(unordered_map<int, classType>& map, vector<int> vectorID)
{
	if (!vectorID.size()) {
		return;
	}
	for (int i : vectorID)
	{
		cout << "\nID: " << i;
		map[i].output();
	}

	cout << "\nХотите изменить их/его?\n0) No\n1) Yes\n";
	if (!choose(1)) {
		return;
	}

	cout << "\nEdit all or set of objects?\n0) all\n1) set\n";

	switch (choose(1)) {
	case 0:
		for (int id : vectorID) {
			map[id].edit();
			cout << "ID: " << id;
			map[id].output();
		}
		break;
	case 1:
		cout << "\nInput id(s), which you want to change or 0 to exit\n";

		set<int> setOfChangeable;
		int choice;

		do {
			choice = choose(classType::id);
			if (choice == 0)
				break;
			if (find(vectorID.begin(), vectorID.end(), choice) != vectorID.end())
				setOfChangeable.insert(choice);
			else
				cout << "Out of set\n";
		} while (choice != 0);
		for (int id : setOfChangeable) {
			map[id].edit();
			cout << "ID: " << id;
			map[id].output();
		}
		break;
	}
}