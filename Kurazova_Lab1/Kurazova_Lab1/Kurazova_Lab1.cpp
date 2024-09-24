// Kurazova_Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct Pipe
{
    std::string name;
    int length;
    int diameter;
    bool maintenance;
};

struct Compression_Station
{
    std::string name;
    int workshops_number;
    int active_workshops_number;
    int effectiveness;
};

void menu()
{
    cout << "Menu: \n";
    cout << "1. Add a pipe \n";
    cout << "2. Add a compression station \n";
    cout << "3. View all objects \n";
    cout << "4. Change pipe's maintenance status \n";
    cout << "5. Change a number of active workshops \n";
    cout << "6. Save \n";
    cout << "7. Load \n";
    cout << "0. Exit \n";
}

void add_pipe(Pipe& Truba)
{
    cout << "Insert pipe's name: \n";
    cin >> Truba.name;
    cout << "Insert pipe's length: \n";
    cin >> Truba.length;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input! \n";
        cin >> Truba.length;
    }
    cout << "Inset pipe's diameter: \n";
    cin >> Truba.diameter;
    cout << "Insert pipe's maintenance status: \n";
    cin >> Truba.maintenance;
}

void add_CS(Compression_Station& CS) {
    cout << "Insert CS's name: \n";
    cin >> CS.name;
    cout << "Insert number of workshops: \n";
    cin >> CS.workshops_number;
    cout << "Insert number of ACTIVE workshops: \n";
    cin >> CS.active_workshops_number;
    cout << "Insert effectiveness levels (in %): \n";
    cin >> CS.effectiveness;
}

int main()
{
    Pipe Truba1;
    Compression_Station CompStat1;
    while(1)
    {
        int command;
        menu();
        cin >> command;
        switch (command) {
        case 1: 
            add_pipe(Truba1);
        case 2: //Добавить КС
        case 3: //Просмотр всех объектов
        case 4: //Редактировать трубу
        case 5: //Редактировать КС
        case 6: //Сохранить
        case 7: //Загрузить
        case 0:
            return 0;
        }
    }
}

