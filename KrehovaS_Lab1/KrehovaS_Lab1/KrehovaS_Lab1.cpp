
#include <iostream> 
#include <string>
#include <vector>
#include <fstream>
#include "pipe.h"
#include "KC.h"
#include "lab.h"
#include <unordered_map>
using namespace std; 


// Сохранение данных в файл
void SaveData(const unordered_map <int, Pipe>& mapPipe, const unordered_map <int, KS>& mapCS)
{
	ofstream fout;
	cout << "Введите название файлв: ";
	string filename;
	getline(cin, filename);
	fout.open(filename + ".txt", ios::out);
	if (fout.is_open())
	{
		fout << mapPipe.size() << endl;
		fout << mapCS.size() << endl;
		for (const auto& itp : mapPipe)
		{
			fout << itp.second;
		}
		for (const auto& itc : mapCS)
		{
			fout << itc.second;
		}
		cout << "Данные сохранены\n" << endl;
	}
	fout.close();
}


void Menu()          //Функция вывода меню, выводит список возможных действий пользователя
{
	system("cls");
	cout << "Меню программы" << endl <<
		"1-Добавить трубу" << endl <<
		"2-Добавить компрессорную станцию" << endl <<
		"3-Просмотр всех объектов" << endl <<
		"4-Редактировать признак в ремонте трубы" << endl <<
		"5-Редактировать компрессорную станцию по количеству работающих цез" << endl <<
		"6-Сохранить в файл" << endl <<
		"7-Загрузить из файла" << endl <<
		"8-Посмотреть определенную трубу" << endl <<
		"9-Посмотреть определенную КС" << endl<<
		"10-Удалить трубу" << endl <<
		"11-Удалить КС" << endl <<
		"12-Найти трубу" << endl <<
		"13-Пакетное редактирование трубы" << endl <<
		"14-Найти КС" << endl <<
		"15-Пакетное редактирование КС" << endl <<
		"0-Выход из программы" << endl;
}
template <typename T>
void LoadData(unordered_map <int, T>& myMap, int mapSize, ifstream& fin)
{
	myMap.clear();
	while (mapSize--)//!!!!!!!!!!!!!!!!
	{
		T val(fin);
		myMap.insert(pair<int, T>(val.getId(), val));
	}
}
template <typename C, typename T>
using filter = bool(*) (const C& p, T param, bool bParam);

bool checkRepair(const Pipe& p, bool workable, bool bParam = true)
{
	return (workable && !p.getRepair()) || (!workable && p.getRepair());
}

bool checkName(const KS& cs, string name, bool bParam) // bParam если нужно вывести КС с именем отличным от введённого
{
	return cs.getName() == name && bParam || cs.getName() != name && !bParam;
}

bool Efficiency(const KS& cs, double efficiency, bool isMore)
{
	return cs.getEfficiency() >= efficiency && isMore || (cs.getEfficiency() < efficiency) && !isMore;
}

bool percentOfWorkingShops(const KS& cs, double percent, bool isMore)
{
	return cs.getOccupancyPercentage() >= percent && isMore || (cs.getOccupancyPercentage() < percent) && !isMore;
}

template <typename C, typename T>
vector <int> findAllByFilter(const unordered_map <int, C>& myMap, filter<C, T> f, T param, bool bParam = true)
{
	vector <int> res;
	res.reserve(myMap.size());
	for (const auto& p : myMap)
	{
		if (f(p.second, param, bParam))
		{
			res.push_back(p.first);
		}
	}
	return res;
}

int get_variant(int count) {
	int variant;
	string s; // строка для считывания введённых данных
	getline(cin, s); // считываем строку

	// пока ввод некорректен, сообщаем об этом и просим повторить его
	while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
		cout << "Выберете действие: "; // выводим сообщение об ошибке
		getline(cin, s); // считываем строку повторно
	}

	return variant;
}
int main()
{
	int variant;
	setlocale(LC_ALL, "Russian");
	
	unordered_map <int, Pipe> mapPipe;
	unordered_map <int, KS> mapCS;
	//показываем меню            
	do
	{
		Menu();
		variant = get_variant(15);
	
		switch (variant)                   //цикл для обработки операций, выбранных пользователем
		{
		case 1:
			mapPipe.insert(pair<int, Pipe>(Pipe::MAX_ID + 1, Pipe())); //Создаем новую трубу
			break;
		case 2:
			mapCS.insert(pair<int, KS>(KS::MAX_ID + 1, KS()));      //Создаем новую кс
			break;
		case 3://Вывод списка объектов в консоль
		{
			if (mapPipe.size() != 0 || mapCS.size() != 0)
			{
				for (const pair<const int, Pipe>& p : mapPipe)
				{
					cout << p.second;
				}
				for (auto& [id, cs] : mapCS)
				{
					cout << cs;
				}
			}
			else
			{
				cout << endl << "Для начала добавьте трубу или КС \n" << endl;
			}
		}
		break;
		case 4:
			if (mapPipe.size() != 0)
			{
				int id = tryInput("Введите id of трубы, которую хотите редактировать: ", 1, findMaxId(mapPipe));
				auto it = mapPipe.find(id);
				if (it != mapPipe.end())
				{
					it->second.ChangeStatus();
					cout << it->second;

				}
				else
				{
					cout << "Такой id не существует" << endl;
				}
			}
			else
			{
				cout << endl << "Для начала добавьте трубу или КС \n" << endl;
			}
			break;

		case 5:
			if (mapCS.size() != 0)
			{
				int id = tryInput("Введите id КС, которую хотите редактировать : ", 1, findMaxId(mapCS));
				unordered_map <int, KS>::iterator it = mapCS.find(id);
				if (it != mapCS.end())
				{
					cout << it->second;
					it->second.editKS();
				}
				else
				{
					cout << " Такой id не существует" << endl;
				}
			}
			else
			{
				cout << endl << "Для начала добавьте труту \n" << endl;
			}
			break;
		case 6:
			if (mapPipe.size() != 0 || mapCS.size() != 0)
			{
				SaveData(mapPipe, mapCS);
			}
			else
			{
				cout << endl << "Добавьте трубу или КС \n" << endl;
			}
			break;
			break;
		case 7:
		{
			ifstream fin;
			cout << "Введите название файла: ";
			string filename;
		
			getline(cin, filename);
			fin.open(filename + ".txt", ios::in);
			if (fin.is_open())
			{
				int sizePipe, sizeCS;
				fin >> sizePipe;
				fin >> sizeCS;
				LoadData(mapPipe, sizePipe, fin);
				LoadData(mapCS, sizeCS, fin);
				Pipe::MAX_ID = findMaxId(mapPipe);
				KS::MAX_ID = findMaxId(mapCS);
				cout << "Данные успешно сохранены \n " << endl;
			}
			fin.close();
		}

		break;
		case 8:
			if (mapPipe.size() != 0)
			{
				int id = tryInput("Введите id трубы, которую хотите увидеть: ", 1, findMaxId(mapPipe));
				unordered_map <int, Pipe>::iterator it = mapPipe.find(id);
				if (it != mapPipe.end())
				{
					cout << it->second;
				}
				else
				{
					cout << "Такой id не существует" << endl;
				}
			}
			else
			{
				cout << endl << "Добавьте трубу \n" << endl;
			}
			break;
		case 9:
			if (mapCS.size() != 0)
			{
				int id;
				id = tryInput("Введите id КС, которую хотите отредактировать: ", 1, findMaxId(mapCS));
				unordered_map <int, KS>::iterator it = mapCS.find(id);
				if (it != mapCS.end())
				{
					cout << it->second;
				}
				else
				{
					cout << "Такой id не существует" << endl;
				}
			}
			else
			{
				cout << endl << "Добавьте КС \n" << endl;
			}
			break;
		case 10:
			if (mapPipe.size() != 0)
			{
				int id = tryInput("Ввндите  id трубы, которую хотите удалить: ", 1, findMaxId(mapPipe));
				if (mapPipe.find(id) != mapPipe.end())
				{
					deleteObj(mapPipe, id);

				}
				else
				{
					cout << "Такой id не существует " << endl;
				}
			}
			else
			{
				cout << endl << "Добавьте трубу\n" << endl;
			}
			break;
		case  11:
			if (mapCS.size() != 0)
			{
				int id = tryInput("Введите id КС, которую хотите удалить: ", 1, findMaxId(mapCS));
				if (mapCS.find(id) != mapCS.end())
				{
					deleteObj(mapCS, id);

				}
				else
				{
					cout << "Этот id не существует" << endl;
				}
			}
			else
			{
				cout << endl << "Добавьте КС \n" << endl;
			}
			break;
		case 12:
			if (mapPipe.size() != 0)
			{
				bool workable = tryInput<bool>("Вы хотите найти все работающие[1] или сломанные[0]? ", 0, 1);
				for (int& i : findAllByFilter(mapPipe, checkRepair, workable))
				{
					cout << mapPipe[i];
				}
			}
			else
			{
				cout << endl << "Добавьте трубу\n" << endl;
			}
			break;
		case 13:
			if (mapPipe.size() != 0)
			{
				cout << "Выберите действие: \n"
					<< "1 - Редактировать все сломанные трубы \n"
					<< "2 - Редактировать все работающие трубы\n"
					<< "3 - Редактировать все трубы \n"
					<< "4 - Редактировать некотоые трубы по id  \n"
					<< "0 - Покинуть меню "
					<< endl;
				int sort = tryInput("", 0);
				switch (sort)
				{
				case 0:
					break;
				case 1:
					for (int& i : findAllByFilter(mapPipe, checkRepair, false))
					{
						mapPipe[i].ChangeStatus();
						cout << mapPipe[i];
					}
					break;
				case 2:
					for (int& i : findAllByFilter(mapPipe, checkRepair, true))
					{
						mapPipe[i].ChangeStatus();
						cout << mapPipe[i];
					}
					break;
				case 3:
					for (pair<const int, Pipe>& p : mapPipe)
					{
						p.second.ChangeStatus();
					}
					break;
				case 4:
				{
					vector <int> vecId = inputVecId(mapPipe);
					for (int& i : vecId)
					{
						mapPipe[i].ChangeStatus();
						cout << mapPipe[i];
					}
				}
				break;
				default:
					cout << "Невозможно сделать \n" << endl;
					break;
				}
			}
			else
			{
				cout << endl << "Добавьте трубу \n" << endl;
			}
			break;
		case 14:
			if (mapCS.size() != 0)
			{
				int pick = tryInput("Вы хотите найти КС по имени[0], проценту задействованных цехов[1] ? ", 0, 2);
				switch (pick)
				{
				case 0:
				{
					cout << "Введите название КС: ";
					string name;
					cin >> name;
					for (int& i : findAllByFilter(mapCS, checkName, name))
					{
						cout << mapCS[i];
					}
				}
				break;
				case 1:
				{
					double percent = tryInput("Введите процент : ", 0.0, 100.0);
					bool sort = tryInput<bool>("Вы хотите редактировать КС с процентом больше[1] или меньше[0] : ", 0, 1);
					for (int& i : findAllByFilter(mapCS, percentOfWorkingShops, percent, sort))
					{
						cout << mapCS[i];
					}
				}
				break;
				
				default:
					cout << "Действие недоступно. " << endl;
					break;
				}
			}
			else
			{
				cout << endl << "Добавьте станцию \n" << endl;
			}
			break;
		case 15:
			if (mapCS.size() != 0)
			{
				cout << "Введите действик: \n"
					<< "1 - Редактировать по имени \n"
				
					<< "2 - Редактировать все КС по процентам \n"
					<< "3 -Редактироваь по id \n"
					<< "0 - Выйти из меню"
					<< endl;
				int sort = tryInput("", 0);
				switch (sort)
				{
				case 0:
					break;
				case 1:
				{
					cout << "Введите верное название: ";
					string name;
					cin >> name;
					for (int& i : findAllByFilter(mapCS, checkName, name))
					{
						cout << mapCS[i];
						mapCS[i].editKS();
					}
				}
				break;
				
				case 2:
				{
					double percent = tryInput("Введите проценты: ", 0.0, 100.0);
					bool sort = tryInput<bool>("вы хотите отфильтровать КС с большим процентом[1] или [0] меньше введеного : ", 0, 1);
					for (int& i : findAllByFilter(mapCS, percentOfWorkingShops, percent, sort))
					{
						cout << mapCS[i];
						mapCS[i].editKS();
					}
				}
				break;
				case 3:
				{
					vector <int> vecId = inputVecId(mapCS);
					for (int& i : vecId)
					{
						cout << mapCS[i];
						mapCS[i].editKS();
					}
				}
				break;
				default:
					cout << "Невозможно сделать \n" << endl;
					break;
				}
			}
			else
			{
				cout << endl << "Добавьте КС \n" << endl;
			}
			break;
		}
		if (variant != 0)
			system("pause");
	} while (variant != 0);
    return 0;
	}





	
	
	