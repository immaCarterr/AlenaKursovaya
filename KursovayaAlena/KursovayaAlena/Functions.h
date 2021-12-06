#pragma once
#include "Libraries.h"
#include "User.h"
#include "Employee.h"
#include "nested.h"

using namespace std;

bool operator==(Fio obj1, Fio obj2) {
	if (obj1.name == obj2.name && obj1.surname == obj2.surname && obj1.patronymic == obj2.patronymic) return true;
	else return false;
}

fstream& operator>>(fstream& fs, User& obj) {
	fs >> obj.login >> obj.password;
	return fs;
}

fstream& operator<<(fstream& fs, Date& obj) {
	fs << obj.day << " " << obj.month << " " << obj.year;
	return fs;
}

fstream& operator<<(fstream& fs, Statistic& obj) {
	fs << obj.begin << " ";
	fs << obj.end << " " << obj.workDaysNum << " " << obj.missedDaysNum;
	return fs;
}

fstream& operator<<(fstream& fs, Employee& obj) {
	fs << endl << obj.fio.GetName() << " " << obj.fio.GetSurname() << " " << obj.fio.GetPatronymic();
	fs << " " << obj.age << " " << obj.rate << " ";
	fs << obj.statistic;
	return fs;
}

fstream& operator>>(fstream& fs, Date& obj) {
	fs >> obj.day >> obj.month >> obj.year;
	return fs;
}

fstream& operator>>(fstream& fs, Fio& obj) {
	fs >> obj.name >> obj.surname >> obj.patronymic;
	return fs;
}

fstream& operator>>(fstream& fs, Statistic& obj) {
	fs >> obj.begin >> obj.end >> obj.workDaysNum >> obj.missedDaysNum;
	return fs;
}

fstream& operator>>(fstream& fs, Employee& obj) {
	fs >> obj.fio >> obj.age >> obj.rate; fs >> obj.statistic;
	return fs;
}

void Encryption(string& str) {
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str[i] + 5;
	}
}

void Decryption(string& str) {
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str[i] - 5;
	}
}

int HidePassword(string& info) {
	int flag = 0;
	info = "";
	int ch = 0; // Переменная для символа.
	while (true) // Создание бесконечного цикла.
	{
		ch = _getch(); // Помещаем код нажатой клавиши в переменную.
		if (ch == 13) // Установка Enter на прерывание цикла.
		{
			break; // Прерывание цикла.
		}
		if (ch == 27) // Установка Esc на закрытие консоли.
		{
			flag = 1;
			break; // Выход из консоли.
		}
		if (ch == 8 && !info.empty()) // Установка Backspace на удаление символов.
		{
			cout << (char)8 << ' ' << char(8);
			if (!info.empty()) info.erase(info.length() - 1);
		}

		if (ch != 8) {
			cout << "*";
			info += (char)ch;
		}
	}
	cout << endl;
	return flag;
}

int AvoidChar(int& num) {
	string info;
	int flag = 0;
	info = "";
	int ch = 0; // Переменная для символа.
	while (true) // Создание бесконечного цикла.
	{
		while (true) {
			ch = _getch(); // Помещаем код нажатой клавиши в переменную.
			if ((ch >= 48 && ch <= 57) || ch == 8 || ch == 13) break;
		}
		if (ch == 13) // Установка Enter на прерывание цикла.
		{
			break; // Прерывание цикла.
		}
		if (ch == 27) // Установка Esc на закрытие консоли.
		{
			flag = 1;
			break; // Выход из консоли.
		}
		if (ch == 8 && !info.empty()) // Установка Backspace на удаление символов.
		{
			cout << (char)8 << ' ' << char(8);
			if (!info.empty()) info.erase(info.length() - 1);
		}

		if (ch != 8) {
			cout << (char)ch;
			info += (char)ch;
		}
	}
	stringstream A; A << info; A >> num;
	cout << endl;
	return flag;
}

int AvoidChar(float& num) {
	string info;
	int flag = 0;
	info = "";
	int ch = 0; // Переменная для символа.
	while (true) // Создание бесконечного цикла.
	{
		while (true) {
			ch = _getch(); // Помещаем код нажатой клавиши в переменную.
			if ((ch >= 48 && ch <= 57) || ch == 8 || ch == 13 || ch == 46) break;
		}
		if (ch == 13) // Установка Enter на прерывание цикла.
		{
			break; // Прерывание цикла.
		}
		if (ch == 27) // Установка Esc на закрытие консоли.
		{
			flag = 1;
			break; // Выход из консоли.
		}
		if (ch == 8 && !info.empty()) // Установка Backspace на удаление символов.
		{
			cout << (char)8 << ' ' << char(8);
			if (!info.empty()) info.erase(info.length() - 1);
		}

		if (ch != 8) {
			cout << (char)ch;
			info += (char)ch;
		}
	}
	stringstream A; A << info; A >> num;
	cout << endl;
	return flag;
}

int Menu() {
	int choice;
	cout << "\n\n\n\n\n";
	cout << "\t\t\t\t\t||#########################################||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t||             1. Регистрация              ||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t||#########################################||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t||            2. Вход в систему            ||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t||#########################################||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t||               3. Выход                  ||\n"
		"\t\t\t\t\t||                                         ||\n"
		"\t\t\t\t\t||#########################################||\n\n";
	cout << "\t\t\t\t\t                Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int RegMenu() {
	int choice;
	cout << "\n\n\n\n\n\t\t\t\t||###############################################||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||        1. Регистрация администратора          ||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||###############################################||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||         2. Регистрация пользователя           ||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||###############################################||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||                  3. Назад                     ||\n"
		"\t\t\t\t||                                               ||\n"
		"\t\t\t\t||###############################################||\n\n";
	cout << "\t\t\t\t                Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int EnterMenu() {
	int choice;
	cout << "\n\n\n\n\n\t\t\t\t\t||####################################||\n"
		"\t\t\t\t\t||                                    ||\n"
		"\t\t\t\t\t||  1. Вход в режиме администратора   ||\n"
		"\t\t\t\t\t||                                    ||\n"
		"\t\t\t\t\t||####################################||\n"
		"\t\t\t\t\t||                                    ||\n"
		"\t\t\t\t\t||   2. Вход в режиме пользователя    ||\n"
		"\t\t\t\t\t||                                    ||\n"
		"\t\t\t\t\t||####################################||\n"
		"\t\t\t\t\t||                                    ||\n"
		"\t\t\t\t\t||            3. Назад                ||\n"
		"\t\t\t\t\t||                                    ||\n"
		"\t\t\t\t\t||####################################||\n\n";
	cout << "\t\t\t\t\t             Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int AdminMenu() {
	int choice;
	cout << "\n\n\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||        1. Добавить информацию         ||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||      2. Редактирование информации     ||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||        3. Удалить информацию          ||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||        4. Просмотр информации         ||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||         5. Найти информацию           ||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||               6. Назад                ||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t               Ваш выбор: "; AvoidChar(choice);
	return choice;

}

int UserMenu() {
	int choice;
	cout << "\n\n\n\n\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||        1. Просмотр информации         ||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||         2. Поиск информации           ||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||  3. Вывод отчёта о зароботной плате   ||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||               4. Назад                ||\n"
		"\t\t\t\t\t||                                       ||\n"
		"\t\t\t\t\t||#######################################||\n"
		"\t\t\t\t\t               Ваш выбор: "; AvoidChar(choice);
	return choice;

}

int AddMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t  ||##############################################||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||    1. Добавление информации о преподавателе  ||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||##############################################||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||    2. Добавление информации о лаборанте      ||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||##############################################||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||      3. Добавление информации о декане       ||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||##############################################||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||      4. Добавление информации о ректоре      ||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||##############################################||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||                  5. Назад                    ||\n"
		"\t\t\t\t  ||                                              ||\n"
		"\t\t\t\t  ||##############################################||\n\n"
		"\t\t\t\t                   Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int RedMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t||##################################################||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||    1. Редактирование информации о преподавателе  ||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||##################################################||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||    2. Редактирование информации о лаборанте      ||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||##################################################||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||      3. Редактирование информации о декане       ||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||##################################################||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||      4. Редактирование информации о ректоре      ||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||##################################################||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||                      5. Назад                    ||\n"
		"\t\t\t\t||                                                  ||\n"
		"\t\t\t\t||##################################################||\n\n"
		"\t\t\t\t                     Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int DelMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t||#############################################||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||    1. Удалить информацию о преподавателе    ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||#############################################||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||     2. Удалить информацию о лаборанте       ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||#############################################||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||       3. Удалить информацию о декане        ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||#############################################||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||       4. Удалить информацию о ректоре       ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||#############################################||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||                 5. Назад                    ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||#############################################||\n\n"
		"\t\t\t\t                 Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int ShowMenu() {
	int choice;
	cout << "\n";
	cout << "\t\t\t\t||#############################################||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||   1. Просмотр информации о преподавателях   ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||#############################################||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||    2. Просмотр информации о лаборантах      ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||#############################################||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||      3. Просмотр информации о деканах       ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||#############################################||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||       4. Просмотр информации о ректоре      ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||#############################################||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||       5. Просмотр информации о всех         ||\n"
		"\t\t\t\t||    сотрудниках с сортировкой по алфавиту    ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||#############################################||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||                 6. Назад                    ||\n"
		"\t\t\t\t||                                             ||\n"
		"\t\t\t\t||#############################################||\n\n"
		"\t\t\t\t                 Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int FindMenu() {
	int choice;
	cout << "\n";
	cout << "\t\t\t\t\t||##########################################||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||   1. Найти информацию о преподавателях   ||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||##########################################||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||    2. Найти информацию о лаборантах      ||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||##########################################||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||      3. Найти информацию о деканах       ||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||##########################################||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||       4. Найти информацию о ректоре      ||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||##########################################||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||      5. Поиск сотрудников, зарплата      ||\n"
		"\t\t\t\t\t|| которых находится во введённом диапазоне ||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||##########################################||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||                6. Назад                  ||\n"
		"\t\t\t\t\t||                                          ||\n"
		"\t\t\t\t\t||##########################################||\n\n"
		"\t\t\t\t\t                 Ваш выбор: "; AvoidChar(choice);
	return choice;
}

int SalaryMenu() {
	int choice;
	cout << "\n";
	cout << "\t\t\t\t\t||################################################||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||   1. Расcчитать зарплату для преподавателей    ||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||################################################||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||     2. Рассчитать зарплату для лаборантов      ||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||################################################||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||       3. Рассчитать зарплату для деканов       ||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||################################################||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||       4. Рассчитать зарплату для ректора       ||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||################################################||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||     5. Информации о сотрудниках с премиями     ||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||################################################||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||                  6. Назад                      ||\n"
		"\t\t\t\t\t||                                                ||\n"
		"\t\t\t\t\t||################################################||\n\n"
		"\t\t\t\t\t                 Ваш выбор: "; AvoidChar(choice);
	return choice;
}

void PrintInFile(string path, User user) {
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (fs.is_open()) {
		fs << user.login << " " << user.password << endl;
		fs.close();
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
}

int CheckExist(string path, string log, string pass) {
	int flag = 1;
	fstream fs;
	fs.open(path);
	if (fs.is_open()) {
		deque <User> U;
		while (!fs.eof())
		{
			User user;
			fs >> user;
			U.push_back(user);
		}
		fs.close();
		for (int i = 0; i < U.size(); i++)
		{
			Decryption(U[i].password);
			(U[i].login == log) ? flag = 0 : flag;
			(U[i].login == log && U[i].password == pass) ? flag = 2 : flag;
		}
	}
	else {
		flag = -1;
	}
	return flag;
}

void registration(string path) {
	User user;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "Введите логин: "; cin >> user.login;
		int ch1 = CheckExist("Users.txt", user.login, "");
		int ch2 = CheckExist("Admin.txt", user.login, "");
		if ((ch1 == 1 && ch2 == 1) || (ch1 == -1 && ch2 == 1) || (ch2 == -1 && ch1 == 1) || (ch1 == -1 && ch2 == -1)) {
			cout << "\nВведите пароль: "; HidePassword(user.password);
			cout << "\nПовторите пароль: "; HidePassword(user.confpass);
			if (user.password == user.confpass) {
				Encryption(user.password);
				cout << "\nРегистрация прошла успешно" << endl;
				system("pause");
				PrintInFile(path, user);
				flag = false;
			}
			else {
				cout << "Пароль или логин не совпадают!" << endl;
				system("pause");
			}
		}
		else {
			cout << "Пользователь с таким логином уже зарегистрирован!" << endl;
			system("pause");
		}
	}
}

int authorization(string path) {
	int res;
	User user;
	bool flag = true;
	while (flag) {
		system("cls");
		int ch = CheckExist(path, "", "");
		if (ch == -1) {
			cout << "Необходима регистрация!" << endl;
			res = -1;
			system("pause");
			break;
		}
		cout << "Введите логин: "; cin >> user.login;
		cout << "\nВведите пароль: "; HidePassword(user.password);
		ch = CheckExist(path, user.login, user.password);
		if (ch == 2) {
			res = 1;
			cout << "Вход выполнен успешно!" << endl;
			system("pause");
			flag = false;
		}
		else {
			cout << "\nНеверный логин или пароль!\n";
			system("pause");
			continue;
		}
	}
	return res;
}

void PrintObjInFile(Employee* obj, string path) {
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (fs.is_open()) {
		fs << *obj;
		fs.close();
	}
	else {
		cout << "Не удалось записать информацию" << endl;
	}
	obj->PrintUniqueInfo();
}

int Check(string path) {
	int res = 0;
	fstream fs;
	fs.open(path);
	if (fs.is_open()) res = 1;
	return res;
}

void AddData(Employee* obj, string path) {
	if (obj->GetCount() == 1 && Check(path) == 0) {
		obj->SetIT();
		obj->PrintItInFile();
	}
	obj->Set();
	PrintObjInFile(obj, path);
}

template <class Type>
void RedactData(Type type, Employee* obj, string path) {
	cout << endl;
	if (Check(path) == 0) {
		cout << "Информация о сотрудниках отсутствует!" << endl;
		system("pause");
		return;
	}
	Fio fio;
	cout << "Введите ФИО сотрудника, информацию о котором необходимо изменить: " << endl;
	fio.Set();
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		obj->SetItFromFile(fs);
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].fio == fio) {
				flag = 1;
				cout << "Введите новую информацию:" << endl << endl;
				D[i].SetIT();
				cout << endl;
				D[i].Set();
			}
		}
		if (flag == 0) {
			cout << endl << "Сотрудник с такими данными не найден, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		char Fname[20];
		for (int i = 0; i < path.size(); i++)
		{
			Fname[i] = path[i];
		}
		Fname[path.size()] = '\0';
		remove(Fname);
		fs.open(path, fstream::out | fstream::in | fstream::app);
		if (fs.is_open()) {
			obj->PrintItInFile();
			for (int i = 0; i < D.size(); i++)
			{
				PrintObjInFile(&D[i], path);
			}
			fs.close();
		}
	}
	else {
		cout << "Не удалось отредактировать информацию" << endl;
	}
}

template <class Type>
void DeleteData(Type type, Employee* obj, string path) {
	if (Check(path) == 0) {
		cout << "Информация о сотрудниках отсутствует!" << endl;
		system("pause");
		return;
	}
	Fio fio;
	cout << "Введите ФИО сотрудника, информацию о котором необходимо удалить: " << endl;
	fio.Set();
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		obj->SetItFromFile(fs);
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].fio == fio) flag = 1;
		}
		if (flag == 0) {
			cout << endl << "Сотрудник с такими данными не найден, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		char Fname[20];
		for (int i = 0; i < path.size(); i++)
		{
			Fname[i] = path[i];
		}
		Fname[path.size()] = '\0';
		remove(Fname);
		fs.open(path, fstream::out | fstream::in | fstream::app);
		if (fs.is_open()) {
			obj->PrintItInFile();
			for (int i = 0; i < D.size(); i++)
			{
				if (!(D[i].fio == fio)) PrintObjInFile(&D[i], path);
			}
			fs.close();
		}
	}
	else {
		cout << "Не удалось удалить информацию" << endl;
	}
}

template <class Type>
void ShowData(Type type, Employee* obj, string path, int flag) {
	if (Check(path) == 0) {
		cout << "Информация отсутствует!" << endl;
		system("pause");
		return;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Type> D;
		obj->SetItFromFile(fs);
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();

		if (flag == 1) {
			for (int i = 1; i < D.size(); i++)
			{
				int d = exp2(i) - 1;
				if (d <= D.size()) {

					for (int k = 0; k < D.size() - d; k++)
					{
						int j = k;
						while (j >= 0 && D[j].fio.GetName()[0] > D[j + d].fio.GetName()[0])
						{
							Type object = D[j];
							D[j] = D[j + d];
							D[j + d] = object;
							j--;
						}
					}
				}
			}
		}

		cout << "Подоходный налог в процентах: " << obj->GetIT() << endl;
		//1я и 2я строа шапки
		cout << "|" << setw(118) << setfill('=') << "|" << endl;
		cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|";
		cout << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;

		//текстовые поля шапки
		cout << resetiosflags(ios::adjustfield);
		cout.setf(ios::left);
		cout << "|" << setw(30) << setfill(' ') << " Имя Фамилия Отчество " << "|";
		cout << " Возраст | Ставка |" << setw(12) << setfill(' ') << " Начало";
		cout << "|" << setw(12) << setfill(' ') << " Конец"; cout << "| Раб. дни | Проп. дни |";
		cout << setw(18) << setfill(' ') << obj->GetUniqueName() << "|" << endl;

		//две последние строки таблицы
		cout.setf(ios::right);
		cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|";
		cout << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;
		cout << "|" << setw(118) << setfill('=') << "|" << endl;

		for (int i = 0; i < D.size(); i++)
		{
			//пустая строка текстовой ячейки
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|";
			cout << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;

			//промежуточные действия
			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::left);
			string fio = D[i].fio.GetName() + " " + D[i].fio.GetSurname() + " " + D[i].fio.GetPatronymic();
			string beg, end;
			stringstream A; A << D[i].statistic.GetBeg().GetDay() << "." << D[i].statistic.GetBeg().GetMonth() << "." << D[i].statistic.GetBeg().GetYear();
			A >> beg; A.clear(); A << D[i].statistic.GetEnd().GetDay() << "." << D[i].statistic.GetEnd().GetMonth() << "." << D[i].statistic.GetEnd().GetYear();
			A >> end;

			//текстовая строка текстовой ячейки
			cout << "| " << setw(29) << setfill(' ') << fio << "| " << setw(8) << setfill(' ') << D[i].age << "| ";
			cout << setw(7) << setfill(' ') << D[i].rate << "| " << setw(11) << setfill(' ') << beg << "| " << setw(11) << setfill(' ') << end << "| ";
			cout << setw(9) << setfill(' ') << D[i].statistic.GetWDN() << "| " << setw(10) << setfill(' ') << D[i].statistic.GetMDN() << "| " << setw(17) << setfill(' ') << D[i].GetUnique() << "|" << endl;

			//пустая строка текстовой ячейки и граница ячейки
			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::right);
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|";
			cout << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;
			cout << "|" << setw(118) << setfill('=') << "|" << endl;
		}
		if (flag == 0) system("pause");
	}
	else {
		cout << "Не удалось просмотреть информацию" << endl;
	}
}

template <class Type>
void FindData(Type type, Employee* obj, string path) {
	if (Check(path) == 0) {
		cout << "Информация о сотрудниках отсутствует!" << endl;
		system("pause");
		return;
	}
	Fio fio;
	cout << "Введите ФИО сотрудника, информацию о котором необходимо найти: " << endl;
	fio.Set();
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		obj->SetItFromFile(fs);
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].fio == fio) flag = 1;
		}
		if (flag == 0) {
			cout << endl << "Сотрудник с такими данными не найден, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		cout << endl;
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].fio == fio) {
				//первые две строки шапки
				cout << "|" << setw(118) << setfill('=') << "|" << endl;
				cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|";
				cout << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;

				//текстовые поля шапки
				cout << resetiosflags(ios::adjustfield);
				cout.setf(ios::left);
				cout << "|" << setw(30) << setfill(' ') << " Имя Фамилия Отчество " << "|";
				cout << " Возраст | Ставка |" << setw(12) << setfill(' ') << " Начало";
				cout << "|" << setw(12) << setfill(' ') << " Конец"; cout << "| Раб. дни | Проп. дни |";
				cout << setw(18) << setfill(' ') << obj->GetUniqueName() << "|" << endl;

				//две последние строки шапки таблицы
				cout.setf(ios::right);
				cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|";
				cout << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;
				cout << "|" << setw(118) << setfill('=') << "|" << endl;

				//Информация о сотруднике
				//пустая строка текстовой ячейки
				cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|";
				cout << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;

				//промежуточные действия
				cout << resetiosflags(ios::adjustfield);
				cout.setf(ios::left);
				string fio = D[i].fio.GetName() + " " + D[i].fio.GetSurname() + " " + D[i].fio.GetPatronymic();
				string beg, end;
				stringstream A; A << D[i].statistic.GetBeg().GetDay() << "." << D[i].statistic.GetBeg().GetMonth() << "." << D[i].statistic.GetBeg().GetYear();
				A >> beg; A.clear(); A << D[i].statistic.GetEnd().GetDay() << "." << D[i].statistic.GetEnd().GetMonth() << "." << D[i].statistic.GetEnd().GetYear();
				A >> end;

				//текстовая строка текстовой ячейки
				cout << "| " << setw(29) << setfill(' ') << fio << "| " << setw(8) << setfill(' ') << D[i].age << "| ";
				cout << setw(7) << setfill(' ') << D[i].rate << "| " << setw(11) << setfill(' ') << beg << "| " << setw(11) << setfill(' ') << end << "| ";
				cout << setw(9) << setfill(' ') << D[i].statistic.GetWDN() << "| " << setw(10) << setfill(' ') << D[i].statistic.GetMDN() << "| " << setw(17) << setfill(' ') << D[i].GetUnique() << "|" << endl;

				//пустая строка текстовой ячейки и граница ячейки
				cout << resetiosflags(ios::adjustfield);
				cout.setf(ios::right);
				cout << "|" << setw(31) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|";
				cout << setw(11) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;
				cout << "|" << setw(118) << setfill('=') << "|" << endl;
			}
		}
		system("pause");
	}
	else {
		cout << "Не удалось удалить информацию" << endl;
	}
}

void CalculateSalary(Employee* obj) {
	obj->salary = obj->rate * (100 - obj->GetIT()) / 100 - obj->rate / obj->statistic.GetWDN() * obj->statistic.GetMDN();
	if (obj->salary < 0) obj->salary = 0;
}

template <class Type>
void GetSalary(Type type, Employee* obj, string path) {
	if (Check(path) == 0) {
		cout << "Информация о сотрудниках отсутствует!" << endl;
		system("pause");
		return;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Type> D;
		obj->SetItFromFile(fs);
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			CalculateSalary(&D[i]);
		}

		cout << "|" << setw(68) << setfill('=') << "|" << endl;
		cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << endl;

		cout << resetiosflags(ios::adjustfield);
		cout.setf(ios::left);
		cout << "|" << setw(30) << setfill(' ') << " Имя Фамилия Отчество" << "|" << setw(12) << setfill(' ') << " Начало" << "|" << setw(12) << setfill(' ') << " Конец" << "|" << setw(10) << setfill(' ') << " Зарплата" << "|" << endl;

		cout << resetiosflags(ios::adjustfield);
		cout.setf(ios::right);
		cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << endl;
		cout << "|" << setw(68) << setfill('=') << "|" << endl;

		for (int i = 0; i < D.size(); i++)
		{
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << endl;

			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::left);

			string fio = D[i].fio.GetName() + " " + D[i].fio.GetSurname() + " " + D[i].fio.GetPatronymic();
			string beg, end;
			stringstream A; A << D[i].statistic.GetBeg().GetDay() << "." << D[i].statistic.GetBeg().GetMonth() << "." << D[i].statistic.GetBeg().GetYear();
			A >> beg; A.clear(); A << D[i].statistic.GetEnd().GetDay() << "." << D[i].statistic.GetEnd().GetMonth() << "." << D[i].statistic.GetEnd().GetYear();
			A >> end;

			cout << "| " << setw(29) << setfill(' ') << fio << "| " << setw(11) << setfill(' ') << beg << "| " << setw(11) << setfill(' ') << end << "| " << setw(9) << setfill(' ') << D[i].salary << "|" << endl;

			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::right);
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << endl;
			cout << "|" << setw(68) << setfill('=') << "|" << endl;
		}

		system("pause");
	}
}

template <class Type>
void FilterSalary(Type type, Employee* obj, string path) {
	int flag = 0;
	if (Check(path) == 0) {
		cout << "Информация отсутствует!" << endl;
		system("pause");
		return;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Type> D;
		obj->SetItFromFile(fs);
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		int minS, maxS;
		while (true) {
			cout << "Введите нижний диапазон зарплат: "; AvoidChar(minS);
			cout << "Введите верхний диапазон зарплат: "; AvoidChar(maxS);
			if (maxS <= minS) {
				cout << "Максимальная зарплата не может быть меньше, либо равна минимальной" << endl;
				system("pause");
			}
			else break;
		}
		for (int i = 0; i < D.size(); i++)
		{
			CalculateSalary(&D[i]);
			if (D[i].salary >= minS && D[i].salary <= maxS) flag = 1;
		}
		if (flag == 1) {
			cout << "|" << setw(68) << setfill('=') << "|" << endl;
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << endl;

			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::left);
			cout << "|" << setw(30) << setfill(' ') << " Имя Фамилия Отчество" << "|" << setw(12) << setfill(' ') << " Начало" << "|" << setw(12) << setfill(' ') << " Конец" << "|" << setw(10) << setfill(' ') << " Зарплата" << "|" << endl;

			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::right);
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << endl;
			cout << "|" << setw(68) << setfill('=') << "|" << endl;

			for (int i = 0; i < D.size(); i++)
			{
				if (D[i].salary >= minS && D[i].salary <= maxS) {
					cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << endl;

					cout << resetiosflags(ios::adjustfield);
					cout.setf(ios::left);

					string fio = D[i].fio.GetName() + " " + D[i].fio.GetSurname() + " " + D[i].fio.GetPatronymic();
					string beg, end;
					stringstream A; A << D[i].statistic.GetBeg().GetDay() << "." << D[i].statistic.GetBeg().GetMonth() << "." << D[i].statistic.GetBeg().GetYear();
					A >> beg; A.clear(); A << D[i].statistic.GetEnd().GetDay() << "." << D[i].statistic.GetEnd().GetMonth() << "." << D[i].statistic.GetEnd().GetYear();
					A >> end;

					cout << "| " << setw(29) << setfill(' ') << fio << "| " << setw(11) << setfill(' ') << beg << "| " << setw(11) << setfill(' ') << end << "| " << setw(9) << setfill(' ') << D[i].salary << "|" << endl;

					cout << resetiosflags(ios::adjustfield);
					cout.setf(ios::right);
					cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << endl;
					cout << "|" << setw(68) << setfill('=') << "|" << endl;
				}
			}
		}
		else {
			cout << "\nНи одного сотрудника с зарплатой в таком диапазоне не найдено\n";
		}
	}
}

template <class Type>
void GetPrem(Type type, Employee* obj, string path) {
	int flag = 0;
	if (Check(path) == 0) {
		cout << "Информация отсутствует!" << endl;
		system("pause");
		return;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Type> D;
		obj->SetItFromFile(fs);
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			CalculateSalary(&D[i]);
			if (D[i].statistic.GetMDN() == 0) flag = 1;
		}
		if (flag == 1) {
			cout << "|" << setw(94) << setfill('=') << "|" << endl;
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ');
			cout << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;

			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::left);
			cout << "|" << setw(30) << setfill(' ') << " Имя Фамилия Отчество" << "|" << setw(12) << setfill(' ') << " Начало" << "|" << setw(12) << setfill(' ') << " Конец" << "|" << setw(10) << setfill(' ') << " Зарплата" << "|" << setw(13) << setfill(' ') << " Премиальные" << "|" << setw(11) << setfill(' ') << " Итого" << "|" << endl;

			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::right);
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ');
			cout << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;
			cout << "|" << setw(94) << setfill('=') << "|" << endl;

			for (int i = 0; i < D.size(); i++)
			{
				if (D[i].statistic.GetMDN() == 0) {
					cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ');
					cout << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;

					cout << resetiosflags(ios::adjustfield);
					cout.setf(ios::left);

					string fio = D[i].fio.GetName() + " " + D[i].fio.GetSurname() + " " + D[i].fio.GetPatronymic();
					string beg, end;
					stringstream A; A << D[i].statistic.GetBeg().GetDay() << "." << D[i].statistic.GetBeg().GetMonth() << "." << D[i].statistic.GetBeg().GetYear();
					A >> beg; A.clear(); A << D[i].statistic.GetEnd().GetDay() << "." << D[i].statistic.GetEnd().GetMonth() << "." << D[i].statistic.GetEnd().GetYear();
					A >> end;

					cout << "| " << setw(29) << setfill(' ') << fio << "| " << setw(11) << setfill(' ') << beg << "| " << setw(11) << setfill(' ') << end << "| " << setw(9) << setfill(' ') << D[i].salary << "| " << setw(12) << setfill(' ') << (D[i].salary * 0.1) << "| " << setw(10) << setfill(' ') << (D[i].salary * 1.1) << "|" << endl;

					cout << resetiosflags(ios::adjustfield);
					cout.setf(ios::right);
					cout << "|" << setw(31) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(11) << setfill(' ');
					cout << "|" << setw(14) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << endl;
					cout << "|" << setw(94) << setfill('=') << "|" << endl;
				}
			}
		}
		else {
			cout << "\nСотрудники с премиальными отсутствуют" << endl;
		}
	}
}