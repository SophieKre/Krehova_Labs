
#include <iostream> 
#include <conio.h>
#include <string>
#include <ctime> // Для рандома
#include <vector>
#include <fstream>// for saving and loading
#include <algorithm>
#include "pipe.h"
#include "KC.h"
#include "lab.h"

#define CRLF "\n"
using namespace std; vector<int>vectorvtr;

class StreamTable {
public:
	std::ostream& os_;

	StreamTable(std::ostream& os = std::cout, char delimRow = ' ', char delimCol = ' ') :
		borderExtOn_(true),
		delimRowOn_(true),
		delimRow_(delimRow),
		delimColOn_(true),
		delimCol_(delimCol),
		os_(os),
		colIndex_(0),
		firstCell_(1) {}

	virtual ~StreamTable() {}

	virtual std::ostream& os() const {
		return os_;
	}

	//отображать внешние границы?
	void MakeBorderExt(bool on) {
		borderExtOn_ = on;
	}

	//символ разделителя строк
	void SetDelimRow(bool delimOn, char delimRow = ' ') {
		delimRowOn_ = delimOn;
		if (delimRowOn_)
			delimRow_ = delimRow;
		else if (!delimColOn_)
			MakeBorderExt(false);
	}

	//символ разделителя столбцов
	void SetDelimCol(bool delimOn, char delimCol = ' ') {
		delimColOn_ = delimOn;
		if (delimColOn_)
			delimCol_ = delimCol;
		else if (!delimRowOn_)
			MakeBorderExt(false);
	}

	int AddCol(int colWidth, bool visible = true) {
		colWidth_.push_back(colWidth);
		visible_.push_back(visible);
		return colWidth_.back();
	}

	void SetVisible(int col, bool flg) {
		visible_[col - 1] = flg;
	}

	void SetCols(int colCount, int colWidth = 0) {
		Clear();

		for (int ic = 0; ic < colCount; ic++) {
			AddCol(colWidth);
		}
	}

	virtual void Clear() {
		colWidth_.clear();
		visible_.clear();
		colIndex_ = 0;
		firstCell_ = 1;
	}

	void AddEmptyRow() {
		for (int ic = 0; ic < (int)colWidth_.size(); ic++) {
			*this << "";
		}
	}

	template <typename T> StreamTable& operator << (const T& obj) {
		Push(obj);
		return *this;
	}

	StreamTable& operator << (const std::string& s) {
		colWidth_[colIndex_] = std::max(colWidth_[colIndex_], (int)s.size() + 1);
		Push(s);
		return *this;
	}

	StreamTable& operator << (const char* s) {
		colWidth_[colIndex_] = std::max(colWidth_[colIndex_], (int)strlen(s) + 1);
		Push(s);
		return *this;
	}

protected:
	int colIndex_;

private:
	bool borderExtOn_;
	bool delimRowOn_;
	char delimRow_;

	bool delimColOn_;
	char delimCol_;

	std::vector<int> colWidth_;
	bool firstCell_;
	std::vector<int> visible_;

	template <typename T>
	void Push(const T& obj) {
		if (firstCell_) {
			if (borderExtOn_)
				MakeRowBorder();

			firstCell_ = 0;
		}

		if (visible_[colIndex_]) {
			DelimCol();

			os_.width(colWidth_[colIndex_]);
			os_.fill(' ');
			os_ << /*std::setiosflags(std::ios::left) << */obj;
		}

		if (++colIndex_ == (int)colWidth_.size()) {
			DelimCol();

			if (delimRowOn_)
				MakeRowBorder();
			else
				os_ << CRLF;

			colIndex_ = 0;
		}
	}

	void MakeRowBorder() {
		os_ << CRLF;
		DelimCol();

		int ic;
		for (ic = 0; ic < (int)colWidth_.size(); ic++) {
			if (visible_[ic]) {
				os_.width(colWidth_[ic] + 1);
				os_.fill(delimRow_);
				DelimCol();
			}
		}
		os_ << CRLF;
	}

	void DelimCol() {
		if (delimColOn_ && (borderExtOn_ || colIndex_))
			os_ << delimCol_;
		else
			os_ << ' ';
	}

	//запрет на копирование
	StreamTable& operator = (const StreamTable&);
};

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
//int RandomInt(int left, int right)
//{
//	srand(time(NULL));
//	return left + (rand() % (right - left) + 1);
//}
//bool CheckingUniquenessID(const int& ID, const vector <Pipe>& pipes)
//{
//	for (int i = 0; i < pipes.size(); ++i)
//	{
//		if (ID == pipes[i].id)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//bool CheckingUniquenessID(const int& ID, const vector <Compressor>& cs)
//{
//	for (int i = 0; i < cs.size(); ++i)
//	{
//		if (ID == cs[i].id)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//





void AddPipeInVector(vector <Pipe>& pipes)
{
	Pipe p1;
	cout << "\Pipe " << pipes.size() + 1 << "\n\n";

	// Cоздание уникального id трубы
	/*int idBuf;
	while (true)
	{
		idBuf = RandomInt(1, 9999);
		if (CheckingUniquenessID(idBuf, pipes))
		{
			p.id = idBuf;
			break;
		}
	}*/

	   cout << "User, enter diametr" << endl;
	   p1.diametr = GetNumber(1, 60000);
	   cout << "User, enter yhe length of pipe" << endl;
	   p1.length = GetNumber(1, 100);
	   cout << "Pipe in repair :(0-No,1-Yes )" << endl;
	   cin >> p1.repair;
	  
	   pipes.push_back(p1);

	   
   }
   void AddKCInVector(vector <KS>& ks) 
   {
	   KS c;
	   cout << "\Compressor Station:  " << ks.size() + 1 << "\n\n";
	  /* int idBuf;
	   while (true)
	   {
		   idBuf = RandomInt(1, 9999);
		   if (CheckingUniquenessID(idBuf, cs))
		   {
			   c.id = idBuf;
			   break;
		   }
	   }*/
	   
	   c.SetName();
	   cout << "How many tseh do you have ?  " << endl;
	   c.number_ceh= GetNumber(1,10000);

	   cout << "How many tseh is working ? " << endl;
	   c.number_ceh_inWork = GetNumber(0,1000);
	   
	   cout << "Enter efficiency " << endl;
	   c.efficiency = GetNumber(0,100);
	   ks.push_back(c);
   }
   void PrintData(const vector<Pipe>& p, const vector<KS>& ks)   //Функция для вывода данных в консоль
   {
	   int i;
	   cout << "Список труб:" << endl;
	   if (p.size() == 0)       //Если вектор труб пуст, ничего не выводим
	   {
		   cout << "Список труб пуст" << endl << " " << endl;
	   }
	   else
	   {
		   for (i = 0; i < p.size(); i++)
		   {
			   cout << p[i] << endl;      //Используем перегрузку оператора вывода
		   }
	   }
	   cout << "Список компрессорных станций:" << endl;
	   if (ks.size() == 0)
	   {
		   cout << "Список компрессорных станций пуст" << endl << " " << endl;
	   }
	   else
	   {
		   for (i = 0; i < ks.size(); i++)
		   {
			   cout << ks[i] << endl;
		   }
	   }
   }

   vector<int> FindPipe(const vector<Pipe>& p, int MaxPossibleValue);   //Объявление чтобы использовать функцию

   void RedactPipe(vector<Pipe>& p)            //Функция для редактирования трубы
   {
	   if (p.size() == 0)
	   {
		   cout << "Нет доступных труб для редактирования" << endl;
	   }
	   else
	   {
		   vector<int> pipe_indexes = FindPipe(p, p.size());             //Меняем статус найденных труб
		   for (int i = 0; i < pipe_indexes.size(); i++)
		   {
			   p[pipe_indexes[i]].ChangeStatus();
		   }
	   }
   }

   void RedactKS(vector<KS>& ks)      //Функция для редактирования кс
   {
	   if (ks.size() == 0)
	   {
		   cout << "Нет доступных компрессорных станций для редактирования" << endl;
	   }
	   else
	   {
		   cout << "Введите ID компрессорной станции, которую хотите редактировать(диапазон " << 1 << "-" << ks[0].MAX_ID << ")" << endl;
		   int id = GetNumber(1, ks[0].MAX_ID);
		   cout << "Что именно вы хотите редактировать?" << endl;
		   int WhatToRedact;  //Переменная, в неё запишется число, отражающее то что хочет редактировать пользователь
		   do
		   {
			   cout << "1-редактировать имя" << endl << "2-редактировать кол-во цехов" << endl
				   << "3-редактировать количество работающих цехов" << endl
				   << "0-закончить редактирование" << endl;   //Меню редактирования
			   WhatToRedact = GetNumber(0, 3);
			   switch (WhatToRedact)   //редактируем нужный параметр, в зависимости от переменной
			   {
			   case 1:
				   ks[id].SetName();
				   break;
			   case 2:
				   cout << "Введите новое кол-во цехов КС:" << endl;
				   ks[id].SetNumber_ceh(GetNumber(ks[id].number_ceh_inWork, 100000));
				   ks[id].efficiency = (ks[id].number_ceh_inWork / ks[id].number_ceh) * 100;;
				   break;
			   case 3:
				   cout << "Введите новое кол-во работающих цехов КС:" << endl;
				   ks[id].SetNumber_ceh_inWork(GetNumber(1.0, 100000.0));
				   ks[id].efficiency = (ks[id].number_ceh_inWork / ks[id].number_ceh) * 100;;
				   break;
			   case 0:
				   break;
			   }
		   } while (WhatToRedact != 0);   //Выходим из цикла, когда пользователь введёт 0
	   }
   }

   vector<int> FindPipe(const vector<Pipe>& p, int MaxPossibleValue)        //Функция нахождения труб
   {
	   vector<int> res;
	   if (MaxPossibleValue > 1)
	   {
		   cout << "1 - трубы в ремонте" << endl <<
			   "2 - трубы без ремонта" << endl <<
			   "3 - выбрать конкретные трубы" << endl;
		   int what_to_find = GetNumber(1, 3);
		   int i;
		   if (what_to_find == 1)
		   {
			   for (i = 0; i < p.size(); i++)
			   {
				   if (p[i].repair)      //Трубы в ремонте
					   res.push_back(i);
			   }
		   }
		   if (what_to_find == 2)
		   {
			   for (i = 0; i < p.size(); i++)
			   {
				   if (!p[i].repair)        //Трубы без ремонта
					   res.push_back(i);
			   }
		   }
		   if (what_to_find == 3)
		   {
			   if (p.size() != 0)
			   {
				   cout << "Вводите ID труб, которые хотите найти (диапазон " << 1 << "-" << p.size() << ")" << endl <<
					   "Чтобы закончить, введите ноль" << endl;
				   int id;
				   do
				   {                                                 //Ищем трубы по желанию пользователя
					   id = GetNumber(0, p.size());
					   if (id != 0)
						   res.push_back(id - 1);
				   } while (id != 0);
			   }
		   }
		   if (res.size() == 0)
			   cout << "Труб по данным параметрам не найдено!" << endl;
		   return res;
	   }
	   else
	   {
		   if (p.size() > 0)
		   {
			   cout << "Можно выбрать только одну трубу!" << endl;
			   cout << "Введите ID трубы, которую хотите выбрать (диапазон " << 1 << "-" << p[0].MAX_ID << ")" << endl;
			   int pipe_id = GetNumber(1, p[0].MAX_ID);
			   for (int i = 0; i < p.size(); i++)
				   if (p[i].id == pipe_id)
					   res.push_back(i);
			   return res;
		   }
		   else
		   {
			   res.push_back(-1);
			   cout << "Труб не существует!" << endl;
			   return res;
		   }
	   }

   }

   template<typename T>                                  //Шаблон
   using Filter = bool(*)(const KS&, T parametr);        //Указатель на функцию 

   bool CheckByID(const KS& ks, int parametr)
   {
	   return ks.id == parametr;
   }

   bool CheckByName(const KS& ks, string parametr)        //Функция для поиска по имени
   {
	   return ks.name == parametr;
   }

   bool CheckByProcent(const KS& ks, double parametr)       //Функция для поиска по задействованным цехам
   {
	   return ks.efficiency >= parametr;
   }

   template<typename T>
   vector<int> FindKS(const vector<KS>& ks, Filter<T> f, T parametr)         //Функция нахождения кс
   {
	   vector<int> res;                         //Вектор для хранения индексов
	   int i;
	   for (i = 0; i < ks.size(); i++)
	   {
		   if (f(ks[i], parametr))            //Проверяем совпадение с помощью указателя
			   res.push_back(i);
	   }
	   return res;
   }

   vector<int> UserChooseKS(const vector<KS>& ks, int MaxPossibleValue)
   {
	   vector<int> ks_indexes;                                              //Вектор, хранящий индексы найденных кс
	   cout << "1-Искать кс по ID" << endl << "2-Искать кс по названию" << endl << "3-Искать кс по проценту задействованных цехов" << endl;
	   int what_to_find = GetNumber(1, 3);
	   if (what_to_find == 1)
	   {
		   if (ks.size() != 0)
		   {
			   cout << "Вводите ID кс, которые хотите найти (диапазон " << 1 << "-" << ks[0].MAX_ID << ")" << endl <<
				   "Чтобы закончить, введите ноль" << endl;
			   int id;
			   do
			   {                                                 //Ищем кс по желанию пользователя
				   id = GetNumber(0, ks[0].MAX_ID);
				   if (id != 0)
				   {
					   for (int i = 0; i < ks.size(); i++)
						   if (ks[i].id == id)
							   ks_indexes.push_back(i);
				   }
			   } while (id != 0 && ks_indexes.size() < MaxPossibleValue);
		   }
	   }
	   else
		   if (what_to_find == 2)
		   {
			   cout << "Введите имя кс: ";
			   string find_name;
			   cin >> find_name;
			   ks_indexes = FindKS<string>(ks, CheckByName, find_name);
		   }
		   else
			   if (what_to_find == 3 && MaxPossibleValue > 1)
			   {
				   double procent;
				   cout << "Введите желаемый процент задействованных цехов: ";
				   procent = GetNumber(0.0, 100.0);
				   ks_indexes = FindKS(ks, CheckByProcent, procent);
			   }
			   else
			   {
				   cout << "Нельзя искать по проценту задействанных цехов!" << endl;
			   }
	   if (MaxPossibleValue > 1)
		   return ks_indexes;
	   else
	   {
		   if (ks_indexes.size() == 0)
			   ks_indexes.push_back(-1);
		   return ks_indexes;
	   }
   }

   void DeletePipes(vector<Pipe>& p)        //Удаление труб
   {
	   vector<int> pipe_indexes = FindPipe(p, p.size());
	   for (int i = 0; i < p.size(); i++)
	   {
		   for (int j = 0; j < pipe_indexes.size(); j++)
		   {
			   if (p[i].id == p[pipe_indexes[j]].id)
			   {

				   
				   
				   p.erase(p.begin() + i);
			   }
		   }
	   }
   }

   void DeleteKS(vector<KS>& ks, vector<Pipe>& p)      //Удаление кс
   {
	   vector<int> ks_indexes = UserChooseKS(ks, ks.size());
	   for (int i = 0; i < ks.size(); i++)
	   {
		   for (int j = 0; j < ks_indexes.size(); j++)
		   {
			   if (ks[i].id == ks[ks_indexes[j]].id)
			   {
				   
				   ks.erase(ks.begin() + i);
			   }
		   }
	   }
   }

   void SaveData(const vector<Pipe>& p, const vector<KS>& ks, const Graph& g)       //Описание функции сохранения
   {
	   cout << "Введите название файла для сохранения" << endl;
	   string filename;
	   cin >> filename;
	   filename += ".txt";
	   ofstream outf;
	   int i;
	   outf.open(filename);
	   if (p.size() == 0 && ks.size() == 0)   //Когда массивы данных труб и КС пусты, сохранения не произойдёт 
	   {
		   cout << "Нет данных для сохранения!" << endl;
	   }
	   else if (outf.is_open())
	   {
		   outf << p.size() << endl;     //В первую строку выводим кол-во труб
		   outf << ks.size() << endl;    //Во вторую кол-во КС 
		   outf << g.Pipes_in_Graph.size() << endl;  //Сохраним основные параметры сети
		   outf << g.KS_in_Graph.size() << endl;
		   outf << g.ReNumbered_ks.size() << endl;
		   outf << g.All_edges.size() << endl;
		   for (i = 0; i < p.size(); i++)           //Выводим параметры каждой трубы по списку 
		   {
			   outf << p[i];
		   }
		   for (i = 0; i < ks.size(); i++)           //Выводим параметры каждой КС по списку 
		   {
			   outf << ks[i];
		   }
		   outf << g << endl;
		   cout << "Данные успешно сохранены!" << endl;
	   };
	   outf.close();
   }

   void DownloadSaves(vector<Pipe>& p, vector<KS>& ks, Graph& g)         //Описание функции загрузки   
   {
	   cout << "Введите название файла для загрузки" << endl;
	   string filename;
	   cin >> filename;
	   filename += ".txt";
	   ifstream inf;
	   int i = 0;
	   int SizePipes, SizeKS, SizePipes_in_Graph, SizeKS_in_Graph, SizeRenumberedKS, SizeAll_edges;
	   inf.open(filename);
	   if (inf.is_open())
	   {
		   inf >> SizePipes;                       //Считываем количество труб в переменную
		   inf >> SizeKS;                         //Теперь кол-во КС
		   inf >> SizePipes_in_Graph;
		   inf >> SizeKS_in_Graph;
		   inf >> SizeRenumberedKS;
		   inf >> SizeAll_edges;
		   if (SizePipes == 0 && SizeKS == 0)    //Если значения нулевые не загружаем данные 
		   {
			   cout << "Не удалось загрузить данные, файл пуст!" << endl;
		   }
		   else
		   {
			   int data;
			   p.resize(SizePipes);
			   ks.resize(SizeKS);
			   g.ReNumbered_ks.resize(SizeRenumberedKS);
			   g.All_edges.resize(SizeAll_edges);
			   for (i = 0; i < p.size(); i++)   //По порядку записываем данные в массив труб
				   inf >> p[i];
			   for (i = 0; i < ks.size(); i++)    //По порядку записываем данные в массив КС
				   inf >> ks[i];
			   for (i = 0; i < SizePipes_in_Graph; i++)
			   {
				   inf >> data;
				   g.Pipes_in_Graph.insert(data);
			   }
			   for (i = 0; i < SizeKS_in_Graph; i++)
			   {
				   inf >> data;
				   g.KS_in_Graph.insert(data);
			   }
			   for (i = 0; i < g.ReNumbered_ks.size(); i++)
				   inf >> g.ReNumbered_ks[i];
			   for (i = 0; i < g.All_edges.size(); i++)
			   {
				   inf >> g.All_edges[i].a;
				   inf >> g.All_edges[i].b;
				   inf >> g.All_edges[i].cost;
			   }
			   cout << "Загрузка прошла успешно" << endl;
		   }
	   }
	   else
		   cout << "Не удалось произвести загрузку, введите корректное имя файла!" << endl;
	   inf.close();
   }

   
   
void print_menu() {
	system("cls"); // очищаем экран
	cout << "Что хотите сделать?" << endl
		<< "1. Добавить трубу" << endl
		<< "2. Добавить компрессорную станцию" << endl
		<< "3. Смотреть все объекты" << endl
		<< "4. Рудактировать трубу" << endl
		<< "5. Редактировать станции" << endl
		<< "6. Искать трубу" << endl
		<< "7. Искать компрессорную станцию" << endl
		<< "8.Сохранить в файл " << endl
		<< "9. Загрузить из файла" << endl
		<<"10.Выйти"
	 << ">";
}


int get_variant(int count) {
	int variant;
	string s; // строка для считывания введённых данных
	getline(cin, s); // считываем строку

	// пока ввод некорректен, сообщаем об этом и просим повторить его
	while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
		cout << "Enter: "; // выводим сообщение об ошибке
		getline(cin, s); // считываем строку повторно
	}

	return variant;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	vector <Pipe> pipes; pipes.resize(0); vector <KS> ks; ks.resize(0); int i;
	
	Pipe p{};
	KS c{};
	int variant; // выбранный пункт меню
	do {
		print_menu();
		variant = get_variant(10);
		switch (variant) {
		case 1:
			
			
			break;
		case 2:
			
			
			break;
		case 3:
			
			
			break;
		case 4:
			/*EditPipe(p);*/
			break;
		case 5:
			
			
			break;
			
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			break;
			
			}
		
		

		if (variant != 10)
			system("pause");
		
	} while (variant != 10);
	return 0;


	}
	
	
	
	
	
	