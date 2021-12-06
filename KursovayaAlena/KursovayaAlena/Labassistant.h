#pragma once
#include "Libraries.h"
#include "Employee.h"
#include "Functions.h"

using namespace std;

class Labassistant : public Employee {
	string studyArea;
	static int incomeTax;
public:

	static int count;

	Labassistant() {
		count++;
		studyArea = "-";
	}

	string GetUnique() {
		return studyArea;
	}

	void Set() override {
		Employee::Set();
		cout << "\nВведите исследуемую область лаборанта: "; cin >> studyArea;
	}

	void PrintItInFile() override {
		fstream fs;
		fs.open("Labassistants.txt", fstream::in | fstream::app);
		if (fs.is_open()) {
			fs << this->incomeTax;
		}
		else {
			cout << "Ошибка открытия файла Teachers.txt" << endl;
		}
	}

	void PrintUniqueInfo() override {
		fstream fs;
		fs.open("Labassistants.txt", fstream::out | fstream::app);
		if (fs.is_open()) {
			fs << " " << this->studyArea;
			fs.close();
		}
		else {
			cout << "Ошибка открытия фалйа Labassistants.txt" << endl;
		}
	}

	void SetIT() override {
		cout << "Введите подоходный налог в процентах для данной профессии: "; AvoidChar(incomeTax);
	}

	int GetCount() override {
		return count;
	}

	void SetUniqueInfo(fstream& fs) override {
		fs >> studyArea;
	}

	void SetItFromFile(fstream& fs) override {
		fs >> incomeTax;
	}

	string GetUniqueName() override {
		return " Область";
	}

	int GetIT() override {
		return this->incomeTax;
	}
};

int Labassistant::incomeTax;
int Labassistant::count = 0;