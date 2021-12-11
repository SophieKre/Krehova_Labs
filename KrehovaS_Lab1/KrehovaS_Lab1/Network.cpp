#include "Network.h"
using namespace std;
void Network::output() {
    Network::outputMap(pipesMap);
    Network::outputMap(stationsMap);
}

void Network::save() {
    ofstream file;

    cout << "Input File name\n";
    string fileName;
    cin >> fileName;
    fileName += ".txt";

    file.open(fileName);
    if (file.good()) {
        if (pipesMap.size() != 0) {
            for (const auto& item : pipesMap) {
                file << "Pipe:\n";
                file << item.first << "\n";
                file << item.second.name1 << "\n";
                file << item.second.diametr << "\n";
                file << item.second.length << "\n";
                file << item.second.repair << "\n";
            }
        }

        if (stationsMap.size() != 0) {
            for (const auto& item : stationsMap) {
                file << "Station:\n";
                file << item.first << "\n";
                file << item.second.name << "\n";
                file << item.second.number_ceh << "\n";
                file << item.second.number_ceh_inWork << "\n";
                file << item.second.efficiency << "\n";
            }
        }
        cout << "Saved\n";
    }
    file.close();

}

void Network::load() {
    ifstream file;

    cout << "Input File name:\n";
    string fileName;
    cin >> fileName;
    fileName += ".txt";
    file.open(fileName);
    if (file.good()) {

        pipesMap.clear();
        stationsMap.clear();

        Pipe::id = 0;
        KS::id = 0;

        while (!file.eof()) {
            string type;
            file >> type;
            if (type == "Pipe:") {

                int id;
                file >> id;

                string name;
                file >> name;

                int diameter;
                file >> diameter;

                int length;
                file >> length;

                bool isWorking;
                file >> isWorking;

                pipesMap.insert(pair<int, Pipe>(id, Pipe(name, diameter, length, isWorking)));
                // pipesMap[id] = Pipe(name, diameter, length, isWorking);  Why is it cause 2 constructor?
            }

            if (type == "Station:") {

                int id;
                file >> id;

                string name;
                file >> name;

                int numberOfWorkshops;
                file >> numberOfWorkshops;

                int numberOfWorkingWorkshops;
                file >> numberOfWorkingWorkshops;

                int efficiency;
                file >> efficiency;

                stationsMap.insert(pair<int, KS>(id, KS(name, numberOfWorkshops, numberOfWorkingWorkshops, efficiency)));
            }
        }
        cout << "Loaded\n";

        for (auto& item : pipesMap) {
            if (Pipe::id < item.first)
                Pipe::id = item.first;
        }

        for (auto& item : stationsMap) {
            if (KS::id < item.first)
                KS::id = item.first;
        }
    }
    else {
        cout << "File not found 404\n";
    }
}
