
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
    bool repair ;
};
struct Compressor {
	int id, tseh;
		float tsehInWork;
	float effect; //koef of effectiveness
	string name;

};



	void PrintPipe(const Pipe& p)
	{
		if (p.d != 0) {
			cout << " Id of pipe is " << p.id << endl;
			cout << ". Diametr of pipe is  " << p.d << " mm." << endl;

			cout << "The length of pipe is  " << p.length << endl;
			cout << "Pipe in repair :(0-No,1-Yes )" << p.repair << endl;
		}
		else
			cout << "The pipe is not added" << endl;


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

   Pipe CreatePipe() {
	Pipe p;
	
	p.id = 0;
	cout<< "User, enter diametr"<<endl;
	p.d = rightenter();
	cout << "User, enter yhe length of pipe" << endl;
	p.length = rightenter2();
	p.repair = 0;
	return p;
	
 }


   void PrintComprssor(const Compressor & c) {
	   if (c.tseh != 0) {
		   cout << " Id of Comprassor Station is " << c.id << endl
			   << "The name of Comprassor Station is " << c.name << endl
			   << "An amount of shops is  " << c.tseh << endl
			   << "All shops that work is " << c.tsehInWork << endl
			   << "The effectivness of Station is " << c.effect << endl;
	   }
	   else
		   cout << "Compression Station was not added" << endl;
   }
   Compressor CreateCompressor(){
	   Compressor c;
	   c.id = 0;
	   cout << "User, enter a name of Comressor Station" << endl;
	   cin.ignore(32767, '\n');
	   getline(cin, c.name);
	   
	   cout << "How many tseh do you have ?  "<<endl;
	   c.tseh = rightenter();
	   
	   cout << "How many tseh is working ? " << endl;
	   c.tsehInWork = rightenter();
	   while ((c.tsehInWork < 1) || (c.tsehInWork > c.tseh)) {
		   cout << "Error in enter, try again" << endl;
		   c.tsehInWork = rightenter();
	   }
	   cout << "Enter efficiency " << endl;
	   c.effect = rightenter();
	   
	   return c;
   }
   void SavePipeandComp(const Pipe& p, const Compressor& c) {
	   ofstream fout;
	   fout.open("Data345.txt", ios_base::out);
	   if (!fout.is_open()) // если файл небыл открыт
	   {
		   cout << "Файл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
		   exit;
	   }
	   if (p.d != 0) {
		   if (p.d != 0) {
			   fout << "Pipe:" << endl;
			   fout << p.id << endl;
			   fout << p.d << endl;
			   fout << p.length << endl;
		   }
		   else
			   fout << "There are no data about pipe" << endl;
		   if (c.tseh != 0) {
			   fout << "Compression station:" << endl;
			   fout << c.id << endl;
			   fout << c.name << endl;
			   fout << c.tseh << endl;
			   fout << c.tsehInWork << endl;
			   fout << c.effect << endl;
		   }
		   else
			   fout << "There are no data about Compression Station" << endl;

	   }

   }

   void LoadPipeandComp(Pipe &p,Compressor &c) {
	   ifstream fin;
	   string str;
	   fin.open("Data345.txt", ios_base::in);
	   getline(fin, str);
	   if (str == "Pipe:") {
		   getline(fin, str);
		   p.id == stoi(str);
		   getline(fin, str);
		   p.d == stoi(str);
		   getline(fin, str);
		   p.length == stoi(str);
	   }
	   getline(fin, str);
	   if (str == "Compression Station:") {
		   getline(fin, str);
		   c.id == stoi(str);
		   getline(fin, str);
		   c.name == str;
		   getline(fin, str);
		   c.tseh == stoi(str);
		   getline(fin, str);
		  c.tsehInWork == stoi(str);
		  getline(fin, str);
		  c.effect == stoi(str);

	   }

	  
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
		<< "8.Exit" << endl
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
	
	Pipe p{};
	Compressor c{};
	int variant; // выбранный пункт меню
	do {
		print_menu();
		variant = get_variant(8);
		switch (variant) {
		case 1:
			if (p.d != 0) {
				cout << "The pipe is exsist" << endl;
			}
			else {
				p = CreatePipe();
			}
			break;
		case 2:
			if (c.tseh != 0) {
				cout << "The station is already exist" << endl;
			}
			else {
				c = CreateCompressor();
			}
			break;
		case 3:
			PrintPipe(p);
			PrintComprssor(c);
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
		}

		if (variant != 8)
			system("pause");
		
	} while (variant != 8);
	return 0;


	}
	
	
	
	
	
	