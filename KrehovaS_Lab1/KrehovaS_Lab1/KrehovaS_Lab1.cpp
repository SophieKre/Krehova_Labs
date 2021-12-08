
#include <iostream> 
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include "pipe.h"
#include "KC.h"
#include "lab.h"

using namespace std; 


double GetNumber(double min, double max)          //Функция для проверки верного ввода с клавиутуры
{
	double a;
	while ((cin >> a).fail() || a < min || a > max)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Введите корректное число!" << endl;
	}
	return a;
}
double choose(double number) {
	int result;
	do {
		result = GetNumber(0,10000);
		if (result < 0 || result > number)
			cout << "Недопустимый ввод\n";
	} while (result < 0 || result > number);

	return result;
}
void Menu()          //Функция вывода меню, выводит список возможных действий пользователя
{
	system("cls");
	cout << "Меню программы" << endl <<
		"1-Добавить трубу" << endl <<
		"2-Добавить компрессорную станцию" << endl <<
		"3-Просмотр всех объектов" << endl <<
		"4-Редактировать трубу" << endl <<
		"5-Редактировать компрессорную станцию" << endl <<
		"6-Поиск труб по признаку 'в ремонте'" << endl <<
		"7-Поиск компрессорных станций" << endl <<
		"8-Удалить трубу" << endl <<
		"9-Удалить компрессорную станцию" << endl<<
		"10-Сохранить в файл" << endl <<
		"11-Загрузить из файла" << endl <<
		"0-Выход из программы" << endl;
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
	vector <Pipe> pipes;                       //вектор для хранения труб
	vector <KS> ks;

	//показываем меню            
	do
	{
		Menu();
		variant = get_variant(11);
		/*int operation = MakeStep();          *///Запрашиваем действие пользователя
		switch (variant)                   //цикл для обработки операций, выбранных пользователем
		{
		case 1:
			 //Создаем новую трубу
			break;
		case 2:
			       //Создаем новую кс
			break;
		case 3://Вывод списка объектов в консоль
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
		{
			
		}
		break;
		case 7:
		{
			
		}
		break;
		case 8:
		
		break;
		case 9:
			
			break;
		case 10:
			
			break;
		case  11:

			break;
		}
		if (variant != 0)
			system("pause");
	} while (variant != 0);
    return 0;
	}





	
	
	