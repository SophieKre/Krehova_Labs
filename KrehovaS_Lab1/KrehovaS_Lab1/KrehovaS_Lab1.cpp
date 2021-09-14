// KrehovaS_Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
#include <string>
using namespace std;

struct Pipe {
	int id;
	int d;
	int length;// length of pipe
};
struct Compressor {
	int id, tseh,tsehInWork;
	float effect; //koef of effectiveness
	string name;

};
void PrintPipe(Pipe& p)
{
	std::cout << " Id of pipe is " << p.id << ". Diametr of pipe is  " << p.d << " mm.";
}
Pipe CreatePipe() {
	Pipe p;
	p.id = 0;
	std::cout<< "User, enter diametr";
	std::cin >> p.d;
	return p;

 }
int main()
{
	Pipe p;// = { 0,1420 };
	p.id = 0;
	std::cout << "User, enter diametr  ";
	std::cin >> p.d;
	p.id = 0;
	PrintPipe(p);
	Compressor c;
	c.id = 0;

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
