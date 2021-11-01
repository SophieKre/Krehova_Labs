
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

 //  Pipe CreatePipe() {
	//Pipe p;
	//
	//p.id = 0;
	//cout<< "User, enter diametr"<<endl;
	//p.d = rightenter();
	//cout << "User, enter yhe length of pipe" << endl;
	//p.length = rightenter2();
	//p.repair = 0;
	//return p;
	//
 //}

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
   ////Compressor CreateCompressor(){
	  //// Compressor c;
	  //// c.id = 0;
	  //// cout << "User, enter a name of Comressor Station" << endl;
	  //// /*cin.ignore(32767, '\n');*/
	  //// getline(cin, c.name);
	  //// 
	  //// cout << "How many tseh do you have ?  "<<endl;
	  //// c.tseh = rightenter();
	  //// 
	  //// cout << "How many tseh is working ? " << endl;
	  //// c.tsehInWork = rightenter();
	  //// while ((c.tsehInWork < 0) || (c.tsehInWork > c.tseh)) {
		 ////  cout << "Error in enter, try again" << endl;
		 ////  c.tsehInWork = rightenter();
	  //// }
	  //// cout << "Enter efficiency " << endl;
	  //// c.effect = rightenter();
	  //// 
	  //// return c;
   ////}
   void ShowAllObjects(const vector <Pipe>& pipes,const vector <Compressor>& cs){
	   cout << "Pipes:" << endl;
	   cout << "ID:" << endl;
	   for (int i = 1; i < pipes.size() + 1; ++i) { to_string(pipes[i - 1].id); }
	   cout << "Diametr:" << endl;
	   for (int i = 1; i < pipes.size() + 1; ++i) { to_string(pipes[i - 1].d); }
	   cout << "Length:" << endl;
	   for (int i = 1; i < pipes.size() + 1; ++i) { to_string(pipes[i - 1].length); }
	   cout << "Compressor Station:" << endl;
	   cout << "Id:" << endl;
	   for (int i = 1; i < cs.size() + 1; ++i) { to_string(cs[i - 1].id); }
	   cout << "Names" << endl;
	   for (int i = 1; i < cs.size() + 1; ++i) { (cs[i - 1].name); }
	   cout << "Effectivness:" << endl;
	   for (int i = 1; i < cs.size() + 1; ++i) { to_string(cs[i - 1].effect); }



	   


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
	vector <Pipe> pipes; pipes.resize(0); vector <Compressor> cs; cs.resize(0); int i;
	
	Pipe p{};
	Compressor c{};
	int variant; // выбранный пункт меню
	do {
		print_menu();
		variant = get_variant(8);
		switch (variant) {
		case 1:
			/*if (p.d != 0) {
				cout << "The pipe is exsist" << endl;*/
			AddPipeInVector(pipes);
			/*}
			else {
				p = CreatePipe();
			}*/
			break;
		case 2:
			/*if (c.tseh != 0) {
				cout << "The station is already exist" << endl;*/
			/*}
			else {

			/*}*/
			AddKCInVector(cs);
			break;
		case 3:
			/*PrintPipe(p);
			PrintComprssor(c);*/
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
		}

		if (variant != 8)
			system("pause");
		
	} while (variant != 8);
	return 0;


	}
	
	
	
	
	
	