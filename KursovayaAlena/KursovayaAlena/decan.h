#pragma once
#include "Libraries.h"
#include "Employee.h"
#include "Functions.h"

using namespace std;

class Dean : public Employee {
	string faculty;
	static int incomeTax;
public:

	static int count;

	Dean() {
		count++;
		faculty = "-";
	}

	string GetUnique() {
		return faculty;
	}

	void Set() override {
		Employee::Set();
		cout << "\nВведите факультет декана: "; cin >> faculty;
	}

	void PrintItInFile() override {
		fstream fs;
		fs.open("Deans.txt", fstream::in | fstream::app);
		if (fs.is_open()) {
			fs << this->incomeTax;
		}
		else {
			cout << "Ошибка открытия файла Deans.txt" << endl;
		}
	}

	void PrintUniqueInfo() override {
		fstream fs;
		fs.open("Deans.txt", fstream::out | fstream::app);
		if (fs.is_open()) {
			fs << " " << this->faculty;
			fs.close();
		}
		else {
			cout << "Ошибка открытия фалйа Deans.txt" << endl;
		}
	}

	void SetIT() override {
		cout << "Введите подоходный налог в процентах для данной профессии: "; AvoidChar(incomeTax);
	}

	int GetCount() override {
		return count;
	}

	void SetUniqueInfo(fstream& fs) override {
		fs >> faculty;
	}

	void SetItFromFile(fstream& fs) override {
		fs >> incomeTax;
	}

	string GetUniqueName() override {
		return " Факультет";
	}

	int GetIT() override {
		return this->incomeTax;
	}
};

int Dean::incomeTax;
int Dean::count = 0;
