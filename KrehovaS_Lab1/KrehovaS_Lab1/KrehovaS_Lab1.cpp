
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
//int RandomInt(int left, int right)
//{
//	srand(time(NULL));
//	return left + (rand() % (right - left) + 1);
//}


	void PrintPipe(Pipe & p)
{
		cout << " Id of pipe is " << p.id << ". Diametr of pipe is  " << p.d << " mm." << endl;
		
		cout << "The length of pipe is  " << p.length << endl;


}
	/*void ErrorInlength(Pipe& p)
	{
		if (p.length < 1 || p.length >= 100)
			cout << "The value of pipe is impossible. Please, try again";
	}*/
	void EditPipe(Pipe &p) {
		int d2;
		cout << "Enter a new dimetr of pipe" << endl;
		cin >> p.d;
		d2 == p.d;

	}
	void EditCompressor(Compressor& c)
	{
		int tsehinwork2;
		cout << "Enter a new amount of working tseh" << endl;
		cin >> c.tsehInWork;
		tsehinwork2 == c.tsehInWork;
	}
	

   Pipe CreatePipe() {
	Pipe p;
	p.id = 0;
	cout<< "User, enter diametr"<<endl;
	cin >> p.d;


	cout << "User, enter yhe length of pipe" << endl;
	cin >> p.length;
	/*ErrorInlength(p);*/
	return p;
	
 }


   void PrintComprssor(Compressor & c) {
	   cout << " Id of Comprassor Station is " << c.id << endl
	   << "The name of Comprassor Station is " << c.name << endl
	   << "An amount of shops is  " << c.tseh << endl
	   <<"All shops that work is " << c.tsehInWork << endl
	    << "The effectivness of Station is " <<c.effect<< endl;
	   
   }
   Compressor CreateCompressor(){
	   Compressor c;
	   cout << "User, enter a name of Comressor Station" << endl;
	   cin >> c.name;
	   c.id = 0;
	   cout << "How many tseh do you have ?  "<<endl;
	   cin>>c.tseh ;
	   
	   cout << "How many tseh is working ? " << endl;
	   cin>>c.tsehInWork ;
	  
	   cout << "Enter efficiency " << endl;
	   cin >> c.effect;
	   
	   return c;
   }
   void SavePipeandComp(const Pipe& p,const Compressor&c) {
	   ofstream fout;
	   fout.open("Data345.txt", ios_base::out);
	   if (!fout.is_open()) // если файл небыл открыт
	   {
		   cout << "Файл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
		   exit;
	   }
	   fout << p.id << endl;
	   fout << p.d << endl;
		  fout << p.length<< endl;
		  fout << c.id << endl;
		  fout << c.name << endl;
		  fout << c.tseh << endl;
		  fout << c.tsehInWork << endl;
		  fout << c.effect << endl;
	   fout.close();

   }
  
   

   Pipe LoadPipe() {
	   ifstream fin;
	   fin.open("Data345.txt", ios_base::in);
	   Pipe p;
	   
	   fin >> p.id;
	   fin >> p.d;
	   fin >> p.length;
	  
	   fin.close();
	   return p;
   }
   Compressor LoadComprassor() {
	   ifstream fin;
	   fin.open("data.txt", 'r');
	   Compressor c;
	   fin >> c.id;
	   fin >> c.name;
	   fin >> c.tseh;
	   fin >> c.tsehInWork;
	   fin >> c.effect;
	   
	   return c;
   }
void print_menu() {
	system("cls"); // очищаем экран
	cout << "What do you want to do?" << endl
  << "1. Add pipe" << endl
	 << "2. Add comprassor" << endl
	 << "3. Edit pipe" << endl
	<< "4. Edit comprassor" << endl
	 << "5. Save to file" << endl
	 << "6. Load from file" << endl
	 << "7. Exit" << endl
	 << ">";
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
			SavePipeandComp(p,c);
			
			break;
			
		case 6:
			LoadPipe();
			LoadComprassor();
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



