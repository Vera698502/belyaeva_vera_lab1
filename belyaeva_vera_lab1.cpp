// belyaeva_vera_lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <clocale>

using namespace std;

struct Pipe{
    string name;
    double length;
    double diameter;
    bool repairing;

    Pipe() : name(""), length(0.0), diameter(0.0), repairing(false) {}

    void input() {
        cout << "Введите название трубы ";
        cin >> name;

        cout << "Введите длину трубы в километрах ";
        cin >> length;

        cout << "Введите диаметр трубы в миллиметрах ";
        cin >> diameter;

        repairing = false;
    }

    void print() const {
        cout << "\nТруба\n"
            << "Название: " << name << "\n"
            << "Длина: " << length << " км\n"
            <<"Диаметр: "<< diameter<<" мм\n"
            << "Состояние: "
            << (repairing ? "В ремонте" : "В работе")
            << "\n";
    }

    void inTheRepair() {
        repairing = !repairing;
        cout << "Признак изменён. Труба теперь: "
            << (repairing ? "В ремонте" : "В работе") << "\n";

    }
};

struct CompressorStation{
    string name;
    int numberOfWorkshops;
    int operatingWorkshops;
    int stationClass;

    CompressorStation() : name(""), numberOfWorkshops(0), operatingWorkshops(0), stationClass(0) {}

    void input() {
        cout << "Введите название кс: ";
        cin >> name;

        cout << "Количество цехов: ";
        cin >> numberOfWorkshops;

        operatingWorkshops=0;

        cout << "Класс станции: ";
        cin >> stationClass;
    }

    void print() const {
        cout << "\n КС \n"
            << "Название: " << name << "\n"
            << "Количество цехов: " << numberOfWorkshops << "\n"
            << "Количество работающих цехов: " <<operatingWorkshops<< "\n"
            << "Класс станции: " << stationClass << "\n"
            <<"Станция "
            <<(operatingWorkshops>0 ? "Работает ": "Простаивает")
            << "\n";
    }

    void startWorkshop() {
        bool canStart = (operatingWorkshops < numberOfWorkshops);
        cout << (canStart ? "Цех запущен.\n"
            : "Нельзя, все цеха в работе\n");
        if (canStart) operatingWorkshops++;
    }

    void stopWorkshop() {
        bool canStop = (operatingWorkshops > 0);
        cout << (canStop ? "Цех остановлен. \n"
            : "Нельзя, нет работающих цехов\n");
        if (canStop) operatingWorkshops--;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Pipe pipe;

    CompressorStation compressorStation;

    bool pipeFilled = false;
    bool csFilled = false;


    while (true) {
        cout << "\nМеню\n"
            << "1.Добавить трубу\n"
            << "2.Добавить кс\n"
            << "3.Просмотр всех объектов\n"
            << "4.Редактировать трубу (в ремонте/не в ремонте)\n"
            << "5.Редактировать кс (запуск/ остановка цеха)\n"
            << "0. Выход\n"
            << "\n";
         int choice;
         cout << "Ваш выбор: \n";
         cin >> choice;

         switch (choice) {

         case 1:
             pipe.input();
             pipeFilled = true;
             cout << "Труба добавлена\n";
             break;

         case 2:
             compressorStation.input();
             csFilled = true;
             cout << "Добавлена кс\n";
             break;
         
         case 3:
             if (!pipeFilled && !csFilled) {
                 cout << "Пока ничего не введено\n";
             }
             else {
                 if (pipeFilled) pipe.print();
                 if (csFilled) compressorStation.print();
             }
             break;

         case 4:
             if (!pipeFilled) {
                 cout << "Сначала добавьте трубу (п.1)\n";
             }
             else {
                 pipe.inTheRepair();
             }
             break;
         case 5:
             if (!csFilled) {
                 cout << "Сначала добавьте кс\n";
             }
             else {
                 cout << "1.Запустить цех\n"
                     << "2. Остановить цех\n";
                 int sub;
                 cout << "Выбор\n ";
                 cin >> sub;
                 switch (sub) {

                 case 1: 
                     compressorStation.startWorkshop();
                     break;
                 case 2:
                     compressorStation.stopWorkshop();
                     break;
                 default: cout << "Неверный пункт меню\n";

                 }

             }
             break;

         case 0:
             cout << "Выход из программы\n";
             return 0;
         default:
             cout << "Неыерный пункт меню!\n";
         }
    }
    return 0;
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
