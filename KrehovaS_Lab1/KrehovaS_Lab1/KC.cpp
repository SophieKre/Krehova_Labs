#include "KC.h"
#include "lab.h"
#include <iostream>
#include <string>
#include "lab.h"
using namespace std;

int KS::MAX_ID = 1;
KS::KS(){
id++;

cout << "Adding Station\n";

cout << "Input name:\n";
cin >> name;

cout << "Input number of workshops:\n";
numberOfWorkshops = 0;
while (numberOfWorkshops <= 0) {
    numberOfWorkshops = inputInteger();
}

cout << "Input number of working workshops:\n";
numberOfWorkingWorkshops = -1;
while (numberOfWorkingWorkshops < 0 || numberOfWorkingWorkshops > numberOfWorkshops) {
    numberOfWorkingWorkshops = inputInteger();
    if (numberOfWorkingWorkshops > numberOfWorkshops) {
        cout << "Wrong input\n";
        cout << "Try again:\n";
    }
}

cout << "Input Efficiency (0 < e <= 100):\n";
efficiency = 0;
while (efficiency <= 0 || efficiency > 100) {
    efficiency = inputInteger();
    if (efficiency <= 0 || efficiency > 100) {
        cout << "Wrong input\n";
        cout << "Try again:\n";
    };
}
}

Station::Station(string name, int numberOfWorkshops, int numberOfWorkingWorkshops, int efficiency) {
    this->name = name;
    this->numberOfWorkshops = numberOfWorkshops;
    this->numberOfWorkingWorkshops = numberOfWorkingWorkshops;
    this->efficiency = efficiency;
}

Station::~Station()
{
}

void Station::output() {
    cout << "\nStation:";
    cout << "\nname: " << name;
    cout << "\nnumber of workshops: " << numberOfWorkshops;
    cout << "\nnumber of working workshops: " << numberOfWorkingWorkshops;
    cout << "\nEfficiency: " << efficiency << "\n";
}

void Station::edit() {
    cout << "\nEditing station";
    Station::output();
    cout << "\nInput number of working workshops:\n";
    do {
        numberOfWorkingWorkshops = choose(numberOfWorkshops);
    } while (numberOfWorkingWorkshops < 0 || numberOfWorkingWorkshops > numberOfWorkshops);
}
