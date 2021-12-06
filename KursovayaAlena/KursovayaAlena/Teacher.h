#pragma once
#include "Libraries.h"
#include "Employee.h"
#include "Functions.h"
#include "nested.h"

using namespace std;

class Teacher : public Employee {
	string degree;
	static int incomeTax;
public:

	static int count;

	Teacher() {
		count++;
		degree = "-";
	}

	string GetUnique() {
		return degree;
	}

	void Set() override {
		Employee::Set();
		cout << "\nВведите учёную степень преподавателя: "; cin >> degree;
	}

	void PrintItInFile() override {
		fstream fs;
		fs.open("Teachers.txt", fstream::in | fstream::app);
		if (fs.is_open()) {
			fs << this->incomeTax;
		}
		else {
			cout << "Ошибка открытия файла Teachers.txt" << endl;
		}
	}

	void PrintUniqueInfo() override {
		fstream fs;
		fs.open("Teachers.txt", fstream::out | fstream::app);
		if (fs.is_open()) {
			fs << " " << this->degree;
			fs.close();
		}
		else {
			cout << "Ошибка открытия фалйа Teachers.txt" << endl;
		}
	}

	void SetIT() override {
		cout << "Введите подоходный налог в процентах для данной профессии: "; AvoidChar(incomeTax);
	}

	int GetCount() override {
		return count;
	}

	void SetUniqueInfo(fstream& fs) override {
		fs >> degree;
	}

	void SetItFromFile(fstream& fs) override {
		fs >> incomeTax;
	}

	string GetUniqueName() override {
		return " Степень";
	}

	int GetIT() override {
		return this->incomeTax;
	}
};

int Teacher::incomeTax;
int Teacher::count = 0;