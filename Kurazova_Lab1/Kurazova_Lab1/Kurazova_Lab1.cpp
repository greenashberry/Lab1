// Kurazova_Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

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
    std::cout << "Menu: \n";
    std::cout << "1. Add a pipe \n";
    std::cout << "2. Add a compression station \n";
    std::cout << "3. View all objects \n";
    std::cout << "4. Change pipe's maintenance status \n";
    std::cout << "5. Change a number of active workshops \n";
    std::cout << "6. Save \n";
    std::cout << "7. Load \n";
    std::cout << "0. Exit \n";
}

int main()
{
    while(1)
    {
        int command;
        menu();
        std::cin >> command;
        switch (command) {
        case 1: //Добавить трубу
        case 2: //Добавить КС
        case 3: //Просмотр всех объектов
        case 4: //Редактировать трубу
        case 5: //Редактировать КС
        case 6: //Сохранить
        case 7: //Загрузить
        case 0:
            return 1;
        default:
            "Input error";
        }
    }
}

