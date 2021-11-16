
#include <iostream> 
#include <conio.h>
#include <string>
#include <ctime> // Для рандома
#include <vector>
#include <fstream>// for saving and loading
#include <algorithm>
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
struct Pipe {
	int id;
	int d;
	int length;// length of pipe
	bool repair;
	string namep;
};
struct Compressor {
	int id, tseh;
	int tsehInWork;
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
		if (cin.fail() || enter < 0) {
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


void EditPipe(vector <Pipe>& pipes) {
	Pipe p;
	if (pipes.size() != 0) {
		cout
			;
	}

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
	   cout << "Pipe in repair :(0-No,1-Yes )" << endl;
	   cin >> p.repair;
	  
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
	  
   void ClearDimensionalDynamicArrayb(bool* array, int lines)
   {


	   delete[] array;
   }
   void SearchPercent(vector<Compressor>cs) {
	   int percent;
	   int* arr_percent = Createarray(cs.size());
	   cout << "Enter percent: " << endl;
	   cin >> percent;
	   for (int i = 0; i < cs.size(); ++i) { 
		   arr_percent[i] = (cs[i].tsehInWork / cs[i].tseh) * 100; }
	   for (int i = 0; i < cs.size(); ++i) {
		   if (percent == arr_percent[i]) {
			  
			   cout << cs[i].name << endl;
			   cout << " have" << endl;
			   cout << arr_percent[i] << endl;
				   cout <<" % " << endl;
		   }
	   }

   }
   void searchKC(vector<Compressor>& cs) {
	   string nname; int h = 0; string choice;
	   string* array3 = CreateDimensionalDynamicArrayStr(cs.size());
	   int* ans = Createarray(cs.size());
	   for (int i = 0; i < cs.size(); ++i) { array3[i] = cs[i].name; }
	   cout << "Enter a name of pipe" << endl;
	   cin >> choice;
	   for (int i = 0; i < cs.size(); i++) {
		   if (array3[i] == choice) { // проверяем равен ли arr[i] ключу
			   ans[h++] = i;
		   }
	   }

	   if (h != 0) { // проверяем были ли совпадения
		   for (int i = 0; i < h; i++) {
			   cout << " The Compressor Station wih name: " << choice << " has number " << ans[i] << endl; //выводим все индексы
			   cout << "Id: " << endl
				   << cs[i].id << endl
				   << "Tseh: " << endl
				   << cs[i].tseh << endl
				   << "Working tseh: " << endl
				   << cs[i].tsehInWork << endl
				   << "Effectivness: " << endl
				   << cs[i].effect << endl;


		   }
	   }
	   else {
		   cout << "There is no Cs station with  name " << choice << endl;;
	   }
	   ClearDimensionalDynamicArrayStr(array3, cs.size());

   }
  
   void searchKCNAme( vector<Compressor>& cs ) {
	   string nname; int h = 0; string choice;
	   string* array3 = CreateDimensionalDynamicArrayStr(cs.size() );
	   int* ans = Createarray(cs.size());
	   for (int i = 0; i < cs.size() ; ++i) {array3[i]= cs[i].name; }
	   cout << "Enter a name of pipe" << endl;
	   cin >> choice;
	   for (int i = 0; i < cs.size(); i++) {
		   if (array3[i] == choice) { // проверяем равен ли arr[i] ключу
			   ans[h++] = i;
		   }
	   }

	   if (h != 0) { // проверяем были ли совпадения
		   for (int i = 0; i < h; i++) {
			   cout << " The Compressor Station wih name: " << choice << " has number " << ans[i] << endl; //выводим все индексы
			   cout << "Id: " << endl
				   << cs[i].id << endl
				   << "Tseh: " << endl
				   << cs[i].tseh << endl
				   <<"Working tseh: "<<endl
				   << cs[i].tsehInWork << endl
				   <<"Effectivness: "<<endl
				   << cs[i].effect << endl;
				   

		   }
	   }
	   else {
		   cout << "There is no Cs station with  name " << choice << endl;;
	   }
	   ClearDimensionalDynamicArrayStr(array3,cs.size());
	
   }
   void searchPipeNAme(vector<Pipe>& pipes) {
	   string nname; int h = 0; string choice;
	   string* array3 = CreateDimensionalDynamicArrayStr(pipes.size());
	   int* ans = Createarray(pipes.size());
	   for (int i = 0; i < pipes.size(); ++i) { array3[i] = pipes[i].namep; }
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
			  


		   }
		   system("clc");
		   StreamTable st(std::cout);
		   st.AddCol(5);
		   st.AddCol(15);
		   st.AddCol(10);
		   st.AddCol(10);
		   st.AddCol(10);
		   st.AddCol(15);
		   st.MakeBorderExt(true);
		   st.SetDelimRow(true, '-');
		   st.SetDelimCol(true, '|');
		   cout << "Found pipes: " << endl;
		   st << "#" << "Name" << "Id" << "diameter" << "Length" << "In repair";

		   for (int i = 0; i < h; i++) {
			   st << ans[i] << pipes[i].namep << pipes[i].id << pipes[i].d << pipes[i].length << pipes[i].repair;
		   }
	   }
	   else {
		   cout << "There is no pipe with  name " << choice << endl;;
	   }
	   

	   ClearDimensionalDynamicArrayStr(array3, pipes.size());

   }
   void searchPipePriznak(vector<Pipe>& pipes) {
	   int h = 0; bool choice;
	   bool* array3 = Createarrayofrepair(pipes.size());
	   int* ans = Createarray(pipes.size());
	   for (int i = 0; i < pipes.size() ; ++i) { array3[i] = pipes[i ].repair; }
	   cout << "Enter 1, if you want to find all pipes in repair. Enter 0, if you want to find all pipes that work " << endl;
	   cin >> choice;
	   for (int i = 0; i < pipes.size(); i++) {
		   if ( choice==true) { // проверяем равен ли arr[i] ключу
			   ans[h++] = i;
			   
		   }
	   }
	   
	   if (h != 0) { // проверяем были ли совпадения
		   cout << "Pipes in repair: " << endl;
		   		   for (int i = 0; i < h; i++) {
			   cout << " The pipe wih name: " << pipes[i].namep << " has number " << ans[i] << endl; //выводим все индексы
			  

		   }
	   }
	   else {
		   cout << "This pipes is working: " << endl;
		   for (int i = 0; i < h; i++) { cout << "The pipe with number: " << ans[i]; }
	   }
	   ClearDimensionalDynamicArrayb(array3, pipes.size());

   }
   void LookForPipe(const vector <Pipe>& pipes2) {

	   int h = 0; bool choice;
	  

   }
   void StreamTablePipe(const vector <Pipe>& pipes)
   {
	   StreamTable st(std::cout);
	   st.AddCol(5);
	   st.AddCol(15);
	   st.AddCol(10);
	   st.AddCol(10);
	   st.AddCol(10);
	   st.AddCol(15);
	   //разкомментировать, если столбцы имеют одинаковую толщину
	   //st.Clear();
	   //st.SetCols(4, 10);

	   //st.SetVisible(1, false);//столбцы можно скрывать

	   st.MakeBorderExt(true);
	   st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
	   st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

	   //заголовок и значения выводятся одинаково
	   st << "#" << "Name" << "Id" << "diameter"<<"Length"<<"In repair";
	   
	   for (int i = 0; i < pipes.size(); i++) {
		   st << i + 1 << pipes[i].namep << pipes[i].id << pipes[i].d<<pipes[i].length<<pipes[i].repair;
	   }
   }
   
   void StreamTableKC(const vector <Compressor>& cs)
   {
	   StreamTable st(std::cout);
	   st.AddCol(5);
	   st.AddCol(15);
	   st.AddCol(10);
	   st.AddCol(10);
	   st.AddCol(10);
	   st.AddCol(15);
	   //разкомментировать, если столбцы имеют одинаковую толщину
	   //st.Clear();
	   //st.SetCols(4, 10);

	   //st.SetVisible(1, false);//столбцы можно скрывать

	   st.MakeBorderExt(true);
	   st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
	   st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

	   //заголовок и значения выводятся одинаково
	   st << "#" << "Name" << "Id" << "Shops" << "Working shops" << "Effectivness";

	   for (int i = 0; i < cs.size(); i++) {
		   st << i + 1 << cs[i].name << cs[i].id << cs[i].tseh << cs[i].tsehInWork << cs[i].effect;
	   }
   }

   void ShowAllObjects(const vector <Pipe>& pipes, const vector <Compressor>& cs) {
	   
	   system("cls");
	   StreamTablePipe(pipes);
	   StreamTableKC(cs);
	 
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
void menu3() {
	system("cls");
	cout << "1.Look for name:  " << endl
		<< "2.Look for priznak.(Enter 1, if you want to see all pipes in repair, 0 to see working pipes-0) " << endl;
}
void menu4() {
	system("cls");
	cout << "1.Look for name:  " << endl
		<< "2.Look for percent " << endl;
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
			/*EditPipe(p);*/
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
				while (true) {
			case 1:
				menu3();
				variant = get_variant(2);
				switch (variant) {
				case 1:
					searchPipeNAme(pipes);
					break;
				case 2:
					searchPipePriznak(pipes);
					break;
				}
				}
			case 2:
				menu4();
				variant = get_variant(2);
				switch (variant) {
				case 1:
					searchKCNAme(cs);
					break;
				case 2:
					SearchPercent(cs);
					break;
				}
				break;

			
			}
		}
		

		if (variant != 9)
			system("pause");
		
	} while (variant != 9);
	return 0;


	}
	
	
	
	
	
	