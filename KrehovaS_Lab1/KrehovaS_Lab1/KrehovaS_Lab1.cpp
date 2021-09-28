
#include <iostream> 
#include <conio.h>
#include <string>
#include <ctime> // Для рандома
#include <vector>
#include <fstream>// for saving and loading
using namespace std;

struct Pipe {
	int id;
	int d;
	int length;// length of pipe
    string priznak ;
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


	void PrintPipe(Pipe & p)
{
	cout << " Id of pipe is " << p.id << ". Diametr of pipe is  " << p.d << " mm."<<endl;
}
	void ErrorInlength(Pipe& p)
	{
		if (p.length < 1 || p.length >= 100)
			cout << "The value of pipe is impossible. Please, try again";
	}
	void EditPipe(Pipe &p) {
		int d2;
		cout << "Enter a new dimetr of pipe" << endl;
		cin >> p.d;
		d2 == p.d;

	}

   Pipe CreatePipe() {
	Pipe p;
	p.id = RandomInt(789,8000);
	cout<< "User, enter diametr"<<endl;
	cin >> p.d;
	cout << "User, enter yhe length of pipe" << endl;
	cin >> p.length;
	ErrorInlength(p);
	return p;
	
 }

   void PrintComprssor(Compressor & c) {
	   cout << " Id of Comprassor Station is " << c.id << endl;
	    cout<< "The name of Comprassor Station is " << c.name << endl;
	   cout << "An amount of shops is  " << c.tseh << endl;
	   cout<<"All shops that work is " << c.tsehInWork << endl;
   }
   Compressor CreateCompressor(){
	   Compressor c;
	   cout << "User, enter a name of Comressor Station" << endl;
	   cin >> c.name;
	   c.id = RandomInt(800,8900);
	   c.tseh = 12;
	   c.tsehInWork = 10;
	   c.effect = (c.tsehInWork / (c.tseh - c.tsehInWork)) * 100;
	   return c;
   }
   void SavePipe(const Pipe& p) {
	   ofstream fout;
	   fout.open("data.txt", 'w');
	   fout << " \tId of pipe is " << p.id 
		   << ". \tDiametr of pipe is  " << p.d 
		   << " \tmm." << endl;
   }
   void SaveComprassor(const Compressor& c) {
	   ofstream fout;
	   fout.open("data1.txt", 'w');
	   fout << " Id of Comprassor Station is " << c.id  
	    << "The name of Comprassor Station is " << c.name 
	    << "An amount of shops is  " << c.tseh  
	    << "All shops that work is " << c.tsehInWork << endl;

   }

   Pipe LoadPipe() {
	   ifstream fin;
	   fin.open("data.txt", 'r');
	   Pipe p;
	   cout << "User, enter diametr" << endl;
	   fin >> p.d;
	   cout << "User, enter yhe length of pipe" << endl;
	   fin >> p.length;
	   return p;
   }
   Compressor LoadComprassor() {
	   ifstream fin;
	   fin.open("data1.txt", 'r');
	   Compressor c;
	   cout << "User, enter a name of Comressor Station" << endl;
	   fin >> c.name;
	   c.id = RandomInt(800, 8900);
	   c.tseh = 12;
	   c.tsehInWork = 10;
	   c.effect = (c.tsehInWork / (c.tseh - c.tsehInWork)) * 100;
	   return c;
   }
void print_menu() {
	system("cls"); // очищаем экран
	cout << "What do you want to do?" << endl;
	cout << "1. Add pipe" << endl;
	cout << "2. Add comprassor" << endl;
	cout << "3. Edit pipe" << endl;
	cout << "4. Edit comprassor" << endl;
	cout << "5. Save to file" << endl;
	cout << "6. Load from file" << endl;
	cout << "7. Exit" << endl;
	cout << ">";
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
	
	Pipe p;
	Compressor c;
	int variant; // выбранный пункт меню
	do {
		print_menu();
		variant = get_variant(7);
		switch (variant) {
		case 1:

			 p = CreatePipe();
			PrintPipe(p);
			break;
		case 2:
			c = CreateCompressor();
			PrintComprssor(c);
			break;
		case 3:
			EditPipe(p);
			PrintPipe(p);
			break;
		case 4:
			break;
		case 5:
			SavePipe(p);
			break;
			LoadPipe();
		case 6:
			break;

		}
		if (variant != 7)
			system("pause");
		
	} while (variant != 7);
	return 0;


	}
	
	
	
	
	
	//Pipe p;// = { 0,1420 };
	//p.id = 0;
	//Pipe p=CreatePipe();
	
//	PrintPipe(p);
	//std::cout << "Please enter the length of pipe ";
	//std::cin >> p.length;
	//ErrorInlength(p);
	//p.priznak = "New";



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
