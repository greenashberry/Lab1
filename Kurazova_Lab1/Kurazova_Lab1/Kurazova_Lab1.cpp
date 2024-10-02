
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

bool check_int(int&);
void check_interval(int&, int, int);
void check_bool(bool&);
void menu();
void add_pipe(Pipe&);
void add_CS(Compression_Station&);
void delete_error();
void edit_pipe(bool&);
void edit_CS(int&);

void delete_error()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool check_int(int& parameter) 
{
    while (!cin || (cin.peek() != '\n') || (parameter <= 0)) {
        delete_error();
        cout << "Wrong input! (not an integer or negative)\n";
        cin >> parameter;
    }
    return 1;
}

void check_interval(int& parameter, int left_border, int right_border)
{
    while (!cin || (cin.peek() != '\n') || (parameter < left_border) || (parameter > right_border))
    {
        delete_error();
        cout << "Wrong input! (interval)" << endl;
        cin >> parameter;
    }
}

void check_bool(bool& parameter)
{
    while (cin.fail() || (cin.peek() != '\n') || ((parameter != 1) && (parameter != 0)))
    {
        delete_error();
        cout << "Wrong input! (bool)" << endl;
        cin >> parameter;
    }
}

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
    check_int(Truba.length);
    cout << "Insert pipe's diameter: \n";
    cin >> Truba.diameter;
    check_int(Truba.diameter);
    cout << "Insert pipe's maintenance status (0 - not in maintenance, 1 - in maintenance): " << endl;
    cin >> Truba.maintenance;
    check_bool(Truba.maintenance);
}

void add_CS(Compression_Station& CS) {
    cout << "Insert CS's name: \n";
    cin >> CS.name;
    cout << "Insert number of workshops: \n";
    cin >> CS.workshops_number;
    check_int(CS.workshops_number);
    cout << "Insert number of ACTIVE workshops: \n";
    cin >> CS.workshops_number;
    check_interval(CS.active_workshops_number, 0, CS.workshops_number);
    cout << "Insert effectiveness levels (in %): \n";
    check_interval(CS.effectiveness, 0, 100);
}

ostream& operator << (ostream& out, const Pipe& Truba)
{
    if ((Truba.diameter > 0) && (Truba.length > 0))
    {
        cout << "Pipe " << Truba.name << endl
            << "Length: " << Truba.length << endl
            << "Diameter: " << Truba.diameter << endl
            << "Maintenance status: ";
        Truba.maintenance ? cout << "in maintenance" << endl : cout << "not in maintenance" << endl;
        return out;
    }
    else
    {
        cout << "Pipe doesn't exits or it is invalid" << endl;
    }
}

ostream& operator << (ostream& out, const Compression_Station& CS)
{
    if ((CS.workshops_number > 0) && (CS.active_workshops_number > 0) && (0 <= CS.effectiveness << 100) && (CS.workshops_number >= CS.active_workshops_number))
    {
        cout << "Compression station" << CS.name << endl
            << "Number of workshops:" << CS.workshops_number << endl
            << "Number of workshops:" << CS.active_workshops_number << endl
            << "Efectiveness (in %): " << CS.effectiveness << endl;
    }
    else
    {
        cout << "Compression station doesn't exist or it is invalid" << endl;
    }
    return out;
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
        check_interval(command, 0, 7);
        switch (command) {
        case 1: //Добавить трубу
            add_pipe(Truba1);
            break;
        case 2: //Добавить компрессорную станцию
            add_CS(CompStat1);
            break;
        case 3: //Просмотр всех объектов
            cout << Truba1;
            cout << CompStat1;
            break;
        case 4: //Редактировать трубу
            break;
        case 5: //Редактировать КС
            break;
        case 6: //Сохранить
            break;
        case 7: //Загрузить
            break;
        case 0:
            return 0;
            break;
        }
    }
}

