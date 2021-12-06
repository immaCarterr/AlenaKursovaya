#pragma once
#include "Libraries.h"
#include "nested.h"
#include "Functions.h"

using namespace std;

int AvoidChar(int& num);
int AvoidChar(float& num);

class Employee
{
protected:
	Fio fio;
	int age;
	float rate;
	float salary;
	Statistic statistic;
public:
	Employee();

	int GetAge() { return age; }
	float GetRate() { return rate; }
	float GetSalary() { return salary; }
	string GetUnique() {};

	virtual void Set();
	virtual void PrintUniqueInfo() = 0;
	virtual void SetIT() = 0;
	virtual void PrintItInFile() = 0;
	virtual int GetCount() = 0;
	virtual void SetUniqueInfo(fstream& fs) = 0;
	virtual void SetItFromFile(fstream& fs) = 0;
	virtual string GetUniqueName() = 0;
	virtual int GetIT() = 0;

	template <class Type> friend void DeleteData(Type type, Employee* obj, string path);
	template <class Type> friend void RedactData(Type type, Employee* obj, string path);
	template <class Type> friend void FindData(Type type, Employee* obj, string path);
	template <class Type> friend void ShowData(Type type, Employee* obj, string path, int flag);
	template <class Type> friend void GetSalary(Type type, Employee* obj, string path);
	template <class Type> friend void FilterSalary(Type type, Employee* obj, string path);
	template <class Type> friend void GetPrem(Type type, Employee* obj, string path);
	friend fstream& operator>>(fstream& fs, Employee& obj);
	friend fstream& operator<<(fstream& fs, Employee& obj);
	friend void CalculateSalary(Employee* obj);

	Fio GetFio() {
		return fio;
	}
};

Employee::Employee()
{
	age = 0;
	rate = 0;
	salary = 0;
}

void Employee::Set() {
	cout << "Введите ФИО сотрудника:\n\n"; fio.Set();
	cout << "\nВозраст сотрудника: "; AvoidChar(age);
	cout << "\nЗаработная ставка сотрудника: "; AvoidChar(rate);
	cout << "\nСтатистика сотрудника за последний период:\n\n"; statistic.Set();
}