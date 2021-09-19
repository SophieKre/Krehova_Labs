// KrehovaS_Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
#include <conio.h>
#include <string>

using namespace std;

struct Pipe {
	int id;
	int d;
	int length;// length of pipe
    string priznak ;
};
struct Compressor {
	int id, tseh,tsehInWork;
	float effect; //koef of effectiveness
	string name;

};

	void PrintPipe(Pipe & p)
{
	cout << " Id of pipe is " << p.id << ". Diametr of pipe is  " << p.d << " mm."<<endl;
}
   Pipe CreatePipe() {
	Pipe p;
	p.id = 0;
	std::cout<< "User, enter diametr"<<endl;
	std::cin >> p.d;
	return p;
	
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
void ErrorInlength(Pipe& p)
{
	if (p.length < 1 || p.length >= 100)
		cout << "The value of pipe is impossible. Please, try again";
}

int main()
{
	print_menu();
	//Pipe p;// = { 0,1420 };
	//p.id = 0;
	Pipe p=CreatePipe();
	
	PrintPipe(p);
	std::cout << "Please enter the length of pipe ";
	std::cin >> p.length;
	ErrorInlength(p);
	p.priznak = "New";

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
