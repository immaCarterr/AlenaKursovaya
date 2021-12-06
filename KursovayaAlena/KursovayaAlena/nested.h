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
	cout << "���: "; cin >> name;
	cout << "\n�������: "; cin >> surname;
	cout << "\n��������: "; cin >> patronymic;
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
		cout << "����: "; AvoidChar(day);
		if (day > 31 || day < 1) cout << "\n������� ������������ ��������!\n��������� �������\n";
		else break;
	}

	while (true) {
		cout << "\n�����: "; AvoidChar(month);
		if (month > 12 || month < 1) cout << "\n������� ������������ ��������!\n��������� �������\n";
		else break;
	}

	while (true) {
		cout << "\n���: "; AvoidChar(year);
		if (year < 1) cout << "\n������� ������������ ��������!\n��������� �������\n";
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
	cout << "������� ���� ������ �����:\n\n"; begin.Set();
	cout << "\n������� ���� ����� �����:\n\n"; end.Set();
	cout << "\n������� ���������� ������� ���� � ������ �������: "; AvoidChar(workDaysNum);
	while (true) {
		cout << "\n������� ���������� ����������� ����������� ���� �� ������ ������: ";  AvoidChar(missedDaysNum);
		if (missedDaysNum > workDaysNum) cout << "\n������� �������� ��������!\n��������� ����\n";
		else break;
	}
}