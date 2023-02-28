#include <iostream>
#include <stdlib.h>

using namespace std;

class Employee {
public:
    string name;
    int age;
    int salary;

public:
    Employee() { };
    Employee(string name, int age, int salary) { this->name = name; this->age = age; this->salary = salary; };
    ~Employee() { }; // Деструктор, удалить объект

    void setPosition(string name) { this->name = name; };
    void setSalary(int salary) { this->salary = salary; };
    void setAge(int age) { this->age = age; };

    void Print(); // Метод вывода данных в консоль
};

void Employee::Print() {
    cout << "Информация о сотруднике " << name << ": " << endl;
    cout << "Возраст: " << age << endl;
    cout << "Зар. плата: " << salary << endl;
}

class BigBoss : Employee {
private:
    int bonus = 50;
public:
    int getBonus() { return bonus; }

    int salaryBonus;

    BigBoss() { };
    BigBoss(string name, int age, int salary) { this->name = name; this->age = age; this->salary = salary; }

    void Print() {
        salaryBonus = (((salary * getBonus()) / 100) + salary);
        cout << "Информация о сотруднике " << name << ": " << endl;
        cout << "Возраст: " << age << endl;
        cout << "Зар. плата с надбавкой: " << salaryBonus << endl;
    }
};


int main() {
    setlocale(LC_ALL, "rus");

    Employee Mark("Mark", 25, 35000);
    BigBoss Ivan("Ivan", 40, 90000);

    Mark.Print();

    cout << "\n";

    Ivan.Print();
}