
#include <iostream> 
#include <conio.h>
#include <string>
#include <ctime> // Для рандома
#include <vector>
#include <fstream>// for saving and loading
#include <algorithm>
using namespace std; vector<int>vectorvtr;

struct Pipe {
	int id;
	int d;
	int length;// length of pipe
    bool repair ;
	string namep;
};
struct Compressor {
	int id, tseh;
		float tsehInWork;
	float effect; //koef of effectiveness
	string name;

};
int RandomInt(int left, int right)
{
	srand(time(NULL));
	return left + (rand() % (right - left) + 1);
}
bool CheckingUniquenessID(const int& ID, const vector <Pipe>& pipes)
{
	for (int i = 0; i < pipes.size(); ++i)
	{
		if (ID == pipes[i].id)
		{
			return false;
		}
	}
	return true;
}
bool CheckingUniquenessID(const int& ID, const vector <Compressor>& cs)
{
	for (int i = 0; i < cs.size(); ++i)
	{
		if (ID == cs[i].id)
		{
			return false;
		}
	}
	return true;
}


	

	int rightenter() {
		int enter;
		while (true) {
			cin >> enter;
			if (cin.fail() || enter < 0 ) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Enter another meaning " << endl;



			}
			else
				return enter;


		}
	}
	int rightenter2() {
		int enter;
		while (true) {
			cin >> enter;
			if (cin.fail() || enter < 0 || enter>100) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Enter another meaning " << endl;



			}
			else
				return enter;


		}
	}
	

	void EditPipe(Pipe &p) {
		if (p.d != 0) {
			p.repair = !p.repair;
			if (p.repair == 0) {
				cout << "The pipe is not in repair now" << endl;
			}
			if (p.repair == 1) {
				cout << "The pipe is in repair now" << endl;
			}
		}
		else
			cout << "The pipe was not added" << endl;

	}
	void EditCompressor(Compressor& c)
	{
		int num;
		if (c.tseh != 0) {
			cout << "Enter what do you want to do (continue the work of shops or stop the work of shops)" << endl;
			cout << "1-Continue the work of shops" << endl;
			cout << "2-stop the work of shops" << endl;
			cin >> num;
			int tzeh2;
			switch (num) {
			case 1: {
				cout << "How many shops will continue working:";
				tzeh2 = rightenter();
				while (c.tsehInWork + tzeh2 > c.tseh) {
					cout << "Error of enter, enter another meaning" << endl;
					tzeh2 = rightenter();
				}
				c.tsehInWork = c.tsehInWork + tzeh2;
				break;
			}
			case 2: {
				cout << "How many shops will stop working:";
				tzeh2 = rightenter();
				while (c.tsehInWork - tzeh2 < 0) {
					cout << "Error in enter, enter another meaning" << endl;
					tzeh2 = rightenter();
				}
				c.tsehInWork = c.tsehInWork - tzeh2;
				break;
			}
			}
		}
		else
			cout << "Compression Station was not added" << endl;

	}



   void AddPipeInVector(vector <Pipe>& pipes)
   {
	    Pipe p;
	   cout << "\Pipe " << pipes.size() + 1 << "\n\n";

	   // Cоздание уникального id трубы
	   int idBuf;
	   while (true)
	   {
		   idBuf = RandomInt(1, 9999);
		   if (CheckingUniquenessID(idBuf, pipes))
		   {
			   p.id = idBuf;
			   break;
		   }
	   }
	   cout << "User, enter a name of Pipe" << endl;
	   getline(cin, p.namep);

	   cout << "User, enter diametr" << endl;
	   p.d = rightenter();
	   cout << "User, enter yhe length of pipe" << endl;
	   p.length = rightenter2();
	   
	   pipes.push_back(p);

	   
   }
   void AddKCInVector(vector <Compressor>& cs) 
   {
	   Compressor c;
	   cout << "\Compressor Station:  " << cs.size() + 1 << "\n\n";
	   int idBuf;
	   while (true)
	   {
		   idBuf = RandomInt(1, 9999);
		   if (CheckingUniquenessID(idBuf, cs))
		   {
			   c.id = idBuf;
			   break;
		   }
	   }
	   cout << "User, enter a name of Comressor Station" << endl;
	   getline(cin, c.name);

	   cout << "How many tseh do you have ?  " << endl;
	   c.tseh = rightenter();

	   cout << "How many tseh is working ? " << endl;
	   c.tsehInWork = rightenter();
	   while ((c.tsehInWork < 0) || (c.tsehInWork > c.tseh)) {
		   cout << "Error in enter, try again" << endl;
		   c.tsehInWork = rightenter();
	   }
	   cout << "Enter efficiency " << endl;
	   c.effect = rightenter();
	   cs.push_back(c);
   }
   
   string* CreateDimensionalDynamicArrayStr(int lines)
   {
	   string* array = new string  [lines];
	   
	   return array;
   }
   bool* Createarrayofrepair(int lines)
   {
	   bool* array = new bool[lines];
	   return array;
   }
   int* Createarray(int lines)
   {
	   int* array = new int[lines];
	   return array;
   }

   void ClearDimensionalDynamicArrayStr(string* array, int lines)
   {
	   
	   
		   delete[] array;
	   }
	  
   
  
   void FillTable1(string** array, const vector <Pipe>&pipes)
   {
	  
	   for (int i = 0; i < pipes.size(); ++i)
	   {
		   
		   for (int j = 0; j < 5; ++j)
		   {
			   cout.width(4);
			   cout << array[i][j]  ;

			  

		   }
		   cout << endl;

	   }
   }
   void FillTable2(string** array, const vector <Compressor>& cs)
   {

	   for (int i = 0; i < cs.size(); ++i)
	   {

		   for (int j = 0; j < 6; ++j)
		   {
			   cout.width(4);
			   cout << array[i][j]+"  ";



		   }
		   cout << endl;

	   }
   }
   void searchPipeNAme( vector<Pipe>& pipes ) {
	   string nname; int h = 0; string choice;
	   string* array3 = CreateDimensionalDynamicArrayStr(pipes.size() );
	   int* ans = Createarray(pipes.size());
	   for (int i = 0; i < pipes.size() ; ++i) {array3[i]= pipes[i].namep; }
	   cout << "Enter a name of pipe" << endl;
	   cin >> choice;
	   for (int i = 0; i < pipes.size(); i++) {
		   if (array3[i] == choice) { // проверяем равен ли arr[i] ключу
			   ans[h++] = i;
		   }
	   }

	   if (h != 0) { // проверяем были ли совпадения
		   for (int i = 0; i < h; i++) {
			   cout << " The pipe wih name: " << choice << " has number " << ans[i] << endl; //выводим все индексы
			   cout << "Id: " << endl
				   << pipes[i].id << endl
				   << "Diameter: " << endl
				   << pipes[i].d << endl
				   <<"Length: "<<endl
				   << pipes[i].length << endl
				   <<"In repair: "<<endl
				   << pipes[i].repair << endl;
				   

		   }
	   }
	   else {
		   cout << "Мы не нашли ключ " << choice << " в массиве";
	   }
	   ClearDimensionalDynamicArrayStr(array3,pipes.size());
	
   }

   void searchPipePriznak(vector<Pipe>& pipes) {
	   int h = 0; bool choice;
	   bool* array3 = Createarrayofrepair(pipes.size());
	   int* ans = Createarray(pipes.size());
	   for (int i = 0; i < pipes.size() ; ++i) { array3[i] = pipes[i ].repair; }
	   cout << "Enter 1, if you want to find all pipes in repair. Enter 0, if you want to find all pipes that work " << endl;
	   cin >> choice;
	   for (int i = 0; i < pipes.size(); i++) {
		   if (array3[i] == choice) { // проверяем равен ли arr[i] ключу
			   ans[h++] = i;
		   }
	   }

	   if (h != 0) { // проверяем были ли совпадения
		   for (int i = 0; i < h; i++) {
			   cout << "All pipes  " << choice << " находится в ячейке " << ans[i] << endl; //выводим все индексы
		   }
	   }
	   else {
		   cout << "Мы не нашли ключ " << choice << " в массиве";
	   }


   }

   
   void ShowAllObjects(const vector <Pipe>& pipes, const vector <Compressor>& cs) {
	   
	   system("cls");
	   /*string** array1 = CreateTwoDimensionalDynamicArrayStr(pipes.size() + 1, 5);
	   array1[0][0] = "number"; array1[0][1] = "id"; array1[0][2] = "length"; array1[0][3] = "diameter"; array1[0][4] = "in repair";
	   for (int i = 1; i < pipes.size() + 1; ++i) { array1[i][0] = to_string(i); }
	   for (int i = 1; i < pipes.size() + 1; ++i) { array1[i][1] = to_string(pipes[i - 1].id); }
	   for (int i = 1; i < pipes.size() + 1; ++i) { array1[i][2] = to_string(pipes[i - 1].length); }
	   for (int i = 1; i < pipes.size() + 1; ++i) { array1[i][3] = to_string(pipes[i - 1].d); }
	   for (int i = 1; i < pipes.size() + 1; ++i) { array1[i][4] = pipes[i - 1].repair; }

	   string** array2 = CreateTwoDimensionalDynamicArrayStr(cs.size() + 1, 6);
	   array2[0][0] = "number"; array2[0][1] = "id"; array2[0][2] = "name"; array2[0][3] = "amounr"; array2[0][4] = "work amounr"; array2[0][5] = "Эффективность";
	   for (int i = 1; i < cs.size() + 1; ++i) { array2[i][0] = to_string(i); }
	   for (int i = 1; i < cs.size() + 1; ++i) { array2[i][1] = to_string(cs[i - 1].id); }
	   for (int i = 1; i < cs.size() + 1; ++i) { array2[i][2] = cs[i - 1].name; }
	   for (int i = 1; i < cs.size() + 1; ++i) { array2[i][3] = to_string(cs[i - 1].tseh); }
	   for (int i = 1; i < cs.size() + 1; ++i) { array2[i][4] = to_string(cs[i - 1].tsehInWork); }
	   for (int i = 1; i < cs.size() + 1; ++i) { array2[i][5] = to_string(cs[i - 1].effect); }

	   FillTable1(array1, pipes);
	   FillTable2(array2, cs);*/
	   cout << "Pipes:" << endl;
	   cout << "ID:" << endl;
	   for (int i = 1; i < pipes.size() + 1; ++i) { to_string(pipes[i - 1].id); }
	   for (int i = 1; i < pipes.size() + 1; ++i) { cout << pipes[i - 1].id; cout << endl; }
	   cout << "Names of Pipes" << endl;
	   for (int i = 1; i < pipes.size() + 1; ++i) { (pipes[i - 1].namep); }
	   for (int i = 1; i < pipes.size() + 1; ++i) { cout << pipes[i - 1].namep; cout << endl; }
	   cout << "Diametr:" << endl;
	   for (int i = 1; i < pipes.size() + 1; ++i) { to_string(pipes[i - 1].d); }
	   for (int i = 1; i < pipes.size() + 1; ++i) { cout << pipes[i - 1].d; cout << endl; }
	   cout << "Length:" << endl;
	   for (int i = 1; i < pipes.size() + 1; ++i) { to_string(pipes[i - 1].length); }
	   for (int i = 1; i < pipes.size() + 1; ++i) { cout << pipes[i - 1].length; cout << endl; }
	   cout << "Compressor Station:" << endl;
	   cout << "Id:" << endl;
	   for (int i = 1; i < cs.size() + 1; ++i) { to_string(cs[i - 1].id); }
	   for (int i = 1; i < cs.size() + 1; ++i) { cout << cs[i - 1].id; cout << endl; }
	   cout << "Names" << endl;
	   for (int i = 1; i < cs.size() + 1; ++i) { (cs[i - 1].name); }
	   for (int i = 1; i < cs.size() + 1; ++i) { cout << cs[i - 1].name; cout << endl; }
	   cout << "Effectivness:" << endl;
	   for (int i = 1; i < cs.size() + 1; ++i) { to_string(cs[i - 1].effect); }
	   for (int i = 1; i < cs.size() + 1; ++i) { cout << cs[i - 1].effect; cout << endl; }
   }
   
   void SavePipeandComp(const Pipe& p, const Compressor& c) {
	   ofstream fout;
	   fout.open("Data345.txt", ios_base::out);
	   if (!fout.is_open()) // если файл не был открыт
	   {
		   cout << "Файл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
		   exit;
	   }
	   if (fout.good()) {
		   if (p.d != 0) {
			   fout << "Pipe:" << endl
				   << p.id << endl
				   << p.d << endl
				   << p.length << endl;

		   }
		   
		   if (c.tseh != 0) {
			   fout << "Compression " << endl;
			   fout << c.id << endl
				   << c.name << endl
				   << c.tseh << endl
				   << c.tsehInWork << endl
				   << c.effect << endl;
		   }
		   /*else*/
			 // /* fout << "There are no data about Compression Station" << endl;*/

	   //}
		   fout.close();
		   cout << "Saved";
	   }
	   else cout << "NO pipe or Comptrssor";
   }

   void LoadPipeandComp(Pipe &p,Compressor &c) {
	   ifstream fin;
	 ;
	   fin.open("Data345.txt", ios_base::in);
	   if (fin.good()) {
		   while (!fin.eof())
		   {
			   string str;
			   fin >> str;
			   if (str == "Pipe:") {
				   fin >> p.id;
				   fin >> p.d;
				   fin >> p.length;
				  
			   }
			   if (str == "Compression") {
				   fin >> c.id;
				   
				   string(c.name);
				   
				   getline(fin, c.name);
				   fin >> c.tseh;
				   fin >> c.tsehInWork;
				   fin >> c.effect;
			   }
		   }
		   cout << "Loaded";
	   }
	   

	   fin.close();
   }
   
void print_menu() {
	system("cls"); // очищаем экран
	cout << "What do you want to do?" << endl
		<< "1. Add pipe" << endl
		<< "2. Add comprassor" << endl
		<< "3. Print objects" << endl
		<< "4. Edit pipe" << endl
		<< "5. Edit comptession station" << endl
		<< "6. Save file" << endl
		<< "7. Load" << endl
		<< "8.Look for " << endl
		<< "9.Exit" << endl
	 << ">";
}
void menu2() {
	system("cls");
	cout << "1.Look for pipe " << endl
	<< "2.Look for Compressor Station "<<endl;
}


int get_variant(int count) {
	int variant;
	string s; // строка для считывания введённых данных
	getline(cin, s); // считываем строку

	// пока ввод некорректен, сообщаем об этом и просим повторить его
	while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
		cout << "Incorrect input. Try again: "; // выводим сообщение об ошибке
		getline(cin, s); // считываем строку повторно
	}

	return variant;
}
int main()
{
	vector <Pipe> pipes; pipes.resize(0); vector <Compressor> cs; cs.resize(0); int i;
	
	Pipe p{};
	Compressor c{};
	int variant; // выбранный пункт меню
	do {
		print_menu();
		variant = get_variant(9);
		switch (variant) {
		case 1:
			
			AddPipeInVector(pipes);
			
			break;
		case 2:
			
			AddKCInVector(cs);
			break;
		case 3:
			
			ShowAllObjects(pipes, cs);
			break;
		case 4:
			EditPipe(p);
			break;
		case 5:
			EditCompressor(c);
			
			break;
			
		case 6:
			SavePipeandComp(p, c);
			break;
		case 7:
			LoadPipeandComp(p,c);
			break;
		case 8:
			menu2();
			variant = get_variant(2);
			switch(variant)
			{
			case 1:
				searchPipeNAme(pipes);
			}
		}
		

		if (variant != 9)
			system("pause");
		
	} while (variant != 9);
	return 0;


	}
	
	
	
	
	
	