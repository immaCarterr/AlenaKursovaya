#pragma once
#include "Libraries.h"
#include "Employee.h"
#include "Functions.h"

using namespace std;

class Rector : public Employee {
	string term;
	static int incomeTax;
public:

	static int count;

	Rector() {
		count++;
		term = "-";
	}

	string GetUnique() {
		return term;
	}

	void Set() override {
		Employee::Set();
		cout << "\n������� ����, � ������� �������� ������ ��������� �� �����: ";
		cin.ignore();
		getline(cin, term);
	}

	void PrintItInFile() override {
		fstream fs;
		fs.open("Rector.txt", fstream::in | fstream::app);
		if (fs.is_open()) {
			fs << this->incomeTax;
		}
		else {
			cout << "������ �������� ����� Rector.txt" << endl;
		}
	}

	void PrintUniqueInfo() override {
		fstream fs;
		fs.open("Rector.txt", fstream::out | fstream::app);
		if (fs.is_open()) {
			fs << " " << this->term;
			fs.close();
		}
		else {
			cout << "������ �������� ����� Rector.txt" << endl;
		}
	}

	void SetIT() override {
		cout << "������� ���������� ����� � ��������� ��� ������ ���������: "; AvoidChar(incomeTax);
	}

	int GetCount() override {
		return count;
	}

	void SetUniqueInfo(fstream& fs) override {
		fs.ignore();
		getline(fs, term);
	}

	void SetItFromFile(fstream& fs) override {
		fs >> incomeTax;
	}

	string GetUniqueName() override {
		return " ����";
	}

	int GetIT() override {
		return this->incomeTax;
	}
};

int Rector::incomeTax;
int Rector::count = 0;