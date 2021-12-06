#pragma once
#include "Libraries.h"
#include "Functions.h"
#include "Employee.h"

using namespace std;

int AvoidChar(int& num);
int AvoidChar(float& num);

class Fio {
	string name;
	string surname;
	string patronymic;
public:
	Fio();
	void Set();
	string GetName() { return name; }
	string GetSurname() { return surname; }
	string GetPatronymic() { return patronymic; }

	friend fstream& operator>>(fstream& fs, Fio& obj);
	friend bool operator==(Fio obj1, Fio obj2);
};

Fio::Fio() {
	name = "-";
	surname = "-";
	patronymic = "-";
}

void Fio::Set() {
	cout << "Имя: "; cin >> name;
	cout << "\nФамилия: "; cin >> surname;
	cout << "\nОтчество: "; cin >> patronymic;
}

class Date {
	int day;
	int month;
	int year;
public:
	Date();
	void Set();
	int GetDay() { return day; }
	int GetMonth() { return month; }
	int GetYear() { return year; }

	friend fstream& operator>>(fstream& fs, Date& obj);
	friend fstream& operator<<(fstream& fs, Date& obj);

	Date& operator=(const Date& obj) {
		day = obj.day;
		month = obj.month;
		year = obj.year;
		return *this;
	}
};

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

void Date::Set() {
	while (true) {
		cout << "День: "; AvoidChar(day);
		if (day > 31 || day < 1) cout << "\nВведено некорректное значение!\nПовторите попытку\n";
		else break;
	}

	while (true) {
		cout << "\nМесяц: "; AvoidChar(month);
		if (month > 12 || month < 1) cout << "\nВведено некорректное значение!\nПовторите попытку\n";
		else break;
	}

	while (true) {
		cout << "\nГод: "; AvoidChar(year);
		if (year < 1) cout << "\nВведено некорректное значение!\nПовторите попытку\n";
		else break;
	}
}

class Statistic
{
	Date begin;
	Date end;
	int workDaysNum;
	int missedDaysNum;
public:
	Statistic();

	void Set();
	int GetWDN() { return workDaysNum; }
	int GetMDN() { return missedDaysNum; }
	Date GetBeg() { return begin; }
	Date GetEnd() { return end; }

	friend fstream& operator>>(fstream& fs, Statistic& obj);
	friend fstream& operator<<(fstream& fs, Statistic& obj);
};

Statistic::Statistic()
{
	workDaysNum = 0;
	missedDaysNum = 0;
}

void Statistic::Set() {
	cout << "Введите дату начала учёта:\n\n"; begin.Set();
	cout << "\nВведите дату конца учёта:\n\n"; end.Set();
	cout << "\nВведите количество рабочих дней в данном периоде: "; AvoidChar(workDaysNum);
	while (true) {
		cout << "\nВведите количество пропущенных сотрудником дней за данный период: ";  AvoidChar(missedDaysNum);
		if (missedDaysNum > workDaysNum) cout << "\nВведено неверное значение!\nПовторите ввод\n";
		else break;
	}
}