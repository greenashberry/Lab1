#include <iostream>
#include <fstream>
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
void delete_error();
void edit_pipe(Pipe&);
void edit_CS(Compression_Station&);
bool existence_check_pipe(const Pipe&);
bool existence_check_cs(const Compression_Station&);
void save(const Pipe&, const Compression_Station&);
int load(Pipe&, Compression_Station&);
bool file_read_check();

bool existence_check_pipe(const Pipe& Truba)
{
    if ((Truba.length > 0) && (Truba.diameter > 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool existence_check_cs(const Compression_Station& CS)
{
    if ((CS.workshops_number > 0) && (CS.active_workshops_number >= 0) && (0 <= CS.effectiveness <= 100) && (CS.workshops_number >= CS.active_workshops_number))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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
    cout << "5. Change number of active workshops \n";
    cout << "6. Save \n";
    cout << "7. Load \n";
    cout << "0. Exit \n";
}

istream& operator << (istream& in, Pipe& Truba)
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
    return in;
}

istream& operator << (istream& in, Compression_Station& CS)
{
    cout << "Insert CS's name: \n";
    cin >> CS.name;
    cout << "Insert number of workshops: \n";
    cin >> CS.workshops_number;
    check_int(CS.workshops_number);
    cout << "Insert number of ACTIVE workshops: \n";
    cin >> CS.active_workshops_number;
    check_interval(CS.active_workshops_number, 0, CS.workshops_number);
    cout << "Insert effectiveness levels (in %): \n";
    cin >> CS.effectiveness;
    check_interval(CS.effectiveness, 0, 100);
    return in;
}

ostream& operator << (ostream& out, const Pipe& Truba)
{
    if (existence_check_pipe(Truba))
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
    if (existence_check_cs(CS))
    {
        cout << "Compression station " << CS.name << endl
            << "Number of workshops:" << CS.workshops_number << endl
            << "Number of active workshops:" << CS.active_workshops_number << endl
            << "Efectiveness (in %): " << CS.effectiveness << endl;
    }
    else
    {
        cout << "Compression station doesn't exist or it is invalid" << endl;
    }
    return out;
}

void edit_pipe(Pipe& Truba)
{
    if (existence_check_pipe(Truba))
    {
        cout << "Insert pipe's maintenance status (0 - not in maintenance, 1 - in maintenance): " << endl;
        cin >> Truba.maintenance;
        check_bool(Truba.maintenance);
    }
    else
    {
        cout << "Pipe doesn't exist!" << endl;
    }
}

void edit_CS(Compression_Station& CS)
{
    if (existence_check_cs(CS))
    {
        cout << "Insert number of ACTIVE workshops: \n";
        cin >> CS.active_workshops_number;
        check_interval(CS.active_workshops_number, 0, CS.workshops_number);
    }
    else
    {
        cout << "Compression station doesn't exist!" << endl;
    }
}

void save(const Pipe& Truba, const Compression_Station& CS)
{
    ofstream fout;
    fout.open("save.txt");
    if (existence_check_pipe(Truba))
    {
        fout << "Pipe" << endl
            << Truba.name << endl
            << Truba.length << endl
            << Truba.diameter << endl
            << Truba.maintenance << endl;
    }
    if (existence_check_cs(CS))
    {
        fout << "CS" << endl
            << CS.name << endl
            << CS.workshops_number << endl
            << CS.active_workshops_number << endl
            << CS.effectiveness << endl;
    }
    fout.close();
}

int load(Pipe& Truba, Compression_Station& CS)
{
    ifstream fin;
    string object_name;
    fin.open("save.txt");
    if (!fin)
    {
        cout << "File doesn't exist" << endl;
        return 0;
    }
    fin >> object_name;
    if (object_name == "Pipe")
    {
        fin >> Truba.name;
        if (fin.fail() || (fin.peek() != '\n'))
        {
            fin.clear();
            fin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "File is invalid" << endl;
            return 0;
        }
        fin >> Truba.length;
        if (fin.fail() || (fin.peek() != '\n'))
        {
            fin.clear();
            fin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "File is invalid" << endl;
            return 0;
        }
        fin >> Truba.diameter;
        if (fin.fail() || (fin.peek() != '\n'))
        {
            fin.clear();
            fin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "File is invalid" << endl;
            return 0;
        }
        fin >> Truba.maintenance;
        if (fin.fail() || (fin.peek() != '\n'))
        {
            fin.clear();
            fin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "File is invalid" << endl;
            return 0;
        }
        if (!existence_check_pipe(Truba))
        {
            fin.clear();
            fin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "File is invalid" << endl;
            return 0;
        }
        fin >> object_name;
    }
    if (object_name == "CS")
    {
        fin >> CS.name;
        if (fin.fail() || (fin.peek() != '\n'))
        {
            fin.clear();
            fin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "File is invalid" << endl;
            return 0;
        }
        fin >> CS.workshops_number;
        if (fin.fail() || (fin.peek() != '\n'))
        {
            fin.clear();
            fin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "File is invalid" << endl;
            return 0;
        }
        fin >> CS.active_workshops_number;
        if (fin.fail() || (fin.peek() != '\n'))
        {
            fin.clear();
            fin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "File is invalid" << endl;
            return 0;
        }
        fin >> CS.effectiveness;
        if (fin.fail() || (fin.peek() != '\n'))
        {
            fin.clear();
            fin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "File is invalid" << endl;
            return 0;
        }
        if (!existence_check_cs(CS))
        {
            cout << "File is invalid" << endl;
            return 0;
        }
    }
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
            cin << Truba1;
            break;
        case 2: //Добавить компрессорную станцию
            cin << CompStat1;
            break;
        case 3: //Просмотр всех объектов
            cout << Truba1;
            cout << CompStat1;
            break;
        case 4: //Редактировать трубу
            edit_pipe(Truba1);
            break;
        case 5: //Редактировать КС
            edit_CS(CompStat1);
            break;
        case 6: //Сохранить
            save(Truba1, CompStat1);
            break;
        case 7: //Загрузить
            load(Truba1, CompStat1);
            break;
        case 0:
            return 0;
            break;
        }
    }
}

