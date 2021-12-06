#include "Libraries.h"
#include "Functions.h"
#include "Employee.h"
#include "Teacher.h"
#include "Labassistant.h"
#include "decan.h"
#include "Rector.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool flag = true;
	while (flag) {
		system("cls");
		int choice1 = Menu();
		switch (choice1) {
		case 1:
			while (true) {
				system("cls");
				int regChoice = RegMenu();
				if (regChoice == 3) break;
				switch (regChoice) {
				case 1: {
					registration("Admin.txt");
					break;
				}
				case 2: {
					registration("Users.txt");
					break;
				}
				default: {
					system("cls");
					cout << "Неверный выбор!\nПовторите попытку." << endl;
					system("pause");
				}
				}
			}
			continue;
			break;
		case 2: {
			while (true) {
				system("cls");
				int EnterChoice = EnterMenu();
				if (EnterChoice == 3) break;
				switch (EnterChoice) {
				case 1: {
					system("cls");
					if (authorization("Admin.txt") == -1) continue;
					while (true) {
						system("cls");
						int choice2 = AdminMenu();
						if (choice2 == 6) break;
						switch (choice2) {
						case 1:
							while (true) {
								system("cls");
								int choice3 = AddMenu();
								if (choice3 == 5) break;
								switch (choice3) {
								case 1: {
									system("cls");
									Teacher teacher;
									AddData(&teacher, "Teachers.txt");
									break;
								}
								case 2: {
									system("cls");
									Labassistant labassistant;
									AddData(&labassistant, "Labassistants.txt");
									break;
								}
								case 3: {
									system("cls");
									Dean dean;
									AddData(&dean, "Deans.txt");
									break;
								}
								case 4: {
									system("cls");
									Rector rector;
									AddData(&rector, "Rector.txt");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						case 2:
							while (true) {
								system("cls");
								int choice4 = RedMenu();
								if (choice4 == 5) break;
								switch (choice4) {
								case 1: {
									system("cls");
									Teacher teacher;
									ShowData(teacher, &teacher, "Teachers.txt", 0);
									RedactData(teacher, &teacher, "Teachers.txt");
									break;
								}
								case 2: {
									system("cls");
									Labassistant labassistant;
									ShowData(labassistant, &labassistant, "Labassistants.txt", 0);
									RedactData(labassistant, &labassistant, "Labassistants.txt");
									break;
								}
								case 3: {
									system("cls");
									Dean dean;
									ShowData(dean, &dean, "Deans.txt", 0);
									RedactData(dean, &dean, "Deans.txt");
									break;
								}
								case 4: {
									system("cls");
									Rector rector;
									ShowData(rector, &rector, "Rector.txt", 0);
									RedactData(rector, &rector, "Rector.txt");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						case 3:
							while (true) {
								system("cls");
								int choice5 = DelMenu();
								if (choice5 == 5) break;
								switch (choice5) {
								case 1: {
									system("cls");
									Teacher teacher;
									DeleteData(teacher, &teacher, "Teachers.txt");
									break;
								}
								case 2: {
									system("cls");
									Labassistant labassistant;
									DeleteData(labassistant, &labassistant, "Labassistants.txt");
									break;
								}
								case 3: {
									system("cls");
									Dean dean;
									DeleteData(dean, &dean, "Deans.txt");
									break;
								}
								case 4: {
									system("cls");
									Rector rector;
									DeleteData(rector, &rector, "Rector.txt");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						case 4:
							while (true) {
								system("cls");
								int choice6 = ShowMenu();
								if (choice6 == 6) break;
								switch (choice6) {
								case 1: {
									system("cls");
									Teacher teacher;
									ShowData(teacher, &teacher, "Teachers.txt", 0);
									break;
								}
								case 2: {
									system("cls");
									Labassistant labassistant;
									ShowData(labassistant, &labassistant, "Labassistants.txt", 0);
									break;
								}
								case 3: {
									system("cls");
									Dean dean;
									ShowData(dean, &dean, "Deans.txt", 0);
									break;
								}
								case 4: {
									system("cls");
									Rector rector;
									ShowData(rector, &rector, "Rector.txt", 0);
									break;
								}
								case 5: {
									system("cls");
									Teacher teacher;
									cout << "Информация о преподавателях:" << endl;
									ShowData(teacher, &teacher, "Teachers.txt", 1);

									Labassistant labassistant;
									cout << "\nИнформация о лаборантах:" << endl;
									ShowData(labassistant, &labassistant, "Labassistants.txt", 1);

									Dean dean;
									cout << "\nИнформация о деканах:" << endl;
									ShowData(dean, &dean, "Deans.txt", 1);

									Rector rector;
									cout << "\nИнформация о ректоре:" << endl;
									ShowData(rector, &rector, "Rector.txt", 1);
									system("pause");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						case 5:
							while (true) {
								system("cls");
								int choice7 = FindMenu();
								if (choice7 == 6) break;
								switch (choice7) {
								case 1: {
									system("cls");
									Teacher teacher;
									FindData(teacher, &teacher, "Teachers.txt");
									break;
								}
								case 2: {
									system("cls");
									Labassistant labassistant;
									FindData(labassistant, &labassistant, "Labassistants.txt");
									break;
								}
								case 3: {
									system("cls");
									Dean dean;
									FindData(dean, &dean, "Deans.txt");
									break;
								}
								case 4: {
									system("cls");
									Rector rector;
									FindData(rector, &rector, "Rector.txt");
									break;
								}
								case 5: {
									system("cls");
									Teacher teacher;
									cout << "Преподаватели:" << endl;
									FilterSalary(teacher, &teacher, "Teachers.txt");

									Labassistant labassistant;
									cout << "\nЛаборанты:" << endl;
									FilterSalary(labassistant, &labassistant, "Labassistants.txt");

									Dean dean;
									cout << "\nДеканы:" << endl;
									FilterSalary(dean, &dean, "Deans.txt");

									Rector rector;
									cout << "\nРектор:" << endl;
									FilterSalary(rector, &rector, "Rector.txt");
									system("pause");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				}
				case 2: {
					system("cls");
					if (authorization("Users.txt") == -1) continue;
					while (true) {
						system("cls");
						int UserChoice = UserMenu();
						if (UserChoice == 4) break;
						switch (UserChoice) {
						case 1:
							while (true) {
								system("cls");
								int choice6 = ShowMenu();
								if (choice6 == 6) break;
								switch (choice6) {
								case 1: {
									system("cls");
									Teacher teacher;
									ShowData(teacher, &teacher, "Teachers.txt", 0);
									break;
								}
								case 2: {
									system("cls");
									Labassistant labassistant;
									ShowData(labassistant, &labassistant, "Labassistants.txt", 0);
									break;
								}
								case 3: {
									system("cls");
									Dean dean;
									ShowData(dean, &dean, "Deans.txt", 0);
									break;
								}
								case 4: {
									system("cls");
									Rector rector;
									ShowData(rector, &rector, "Rector.txt", 0);
									break;
								}
								case 5: {
									system("cls");
									Teacher teacher;
									cout << "Информация о преподавателях:" << endl;
									ShowData(teacher, &teacher, "Teachers.txt", 1);

									Labassistant labassistant;
									cout << "\nИнформация о лаборантах:" << endl;
									ShowData(labassistant, &labassistant, "Labassistants.txt", 1);

									Dean dean;
									cout << "\nИнформация о деканах:" << endl;
									ShowData(dean, &dean, "Deans.txt", 1);

									Rector rector;
									cout << "\nИнформация о ректоре:" << endl;
									ShowData(rector, &rector, "Rector.txt", 1);
									system("pause");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						case 2:
							while (true) {
								system("cls");
								int choice7 = FindMenu();
								if (choice7 == 6) break;
								switch (choice7) {
								case 1: {
									system("cls");
									Teacher teacher;
									FindData(teacher, &teacher, "Teachers.txt");
									break;
								}
								case 2: {
									system("cls");
									Labassistant labassistant;
									FindData(labassistant, &labassistant, "Labassistants.txt");
									break;
								}
								case 3: {
									system("cls");
									Dean dean;
									FindData(dean, &dean, "Deans.txt");
									break;
								}
								case 4: {
									system("cls");
									Rector rector;
									FindData(rector, &rector, "Rector.txt");
									break;
								}
								case 5: {
									system("cls");
									Teacher teacher;
									cout << "Преподаватели:" << endl;
									FilterSalary(teacher, &teacher, "Teachers.txt");

									Labassistant labassistant;
									cout << "\nЛаборанты:" << endl;
									FilterSalary(labassistant, &labassistant, "Labassistants.txt");

									Dean dean;
									cout << "\nДеканы:" << endl;
									FilterSalary(dean, &dean, "Deans.txt");

									Rector rector;
									cout << "\nРектор:" << endl;
									FilterSalary(rector, &rector, "Rector.txt");
									system("pause");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						case 3:
							while (true) {
								system("cls");
								int choice8 = SalaryMenu();
								if (choice8 == 6) break;
								switch (choice8) {
								case 1: {
									system("cls");
									Teacher teacher;
									GetSalary(teacher, &teacher, "Teachers.txt");
									break;
								}
								case 2: {
									system("cls");
									Labassistant labassistant;
									GetSalary(labassistant, &labassistant, "Labassistants.txt");
									break;
								}
								case 3: {
									system("cls");
									Dean dean;
									GetSalary(dean, &dean, "Deans.txt");
									break;
								}
								case 4: {
									system("cls");
									Rector rector;
									GetSalary(rector, &rector, "Rector.txt");
									break;
								}
								case 5: {
									system("cls");
									Teacher teacher;
									cout << "Преподаватели:" << endl;
									GetPrem(teacher, &teacher, "Teachers.txt");

									Labassistant labassistant;
									cout << "\nЛаборанты:" << endl;
									GetPrem(labassistant, &labassistant, "Labassistants.txt");

									Dean dean;
									cout << "\nДеканы:" << endl;
									GetPrem(dean, &dean, "Deans.txt");

									Rector rector;
									cout << "\nРектор:" << endl;
									GetPrem(rector, &rector, "Rector.txt");
									system("pause");
									break;
								}
								default: {
									system("cls");
									cout << "Неверный выбор!\nПовторите попытку." << endl;
									system("pause");
								}
								}
							}
							continue;
							break;
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				}
				default: {
					system("cls");
					cout << "Неверный выбор!\nПовторите попытку." << endl;
					system("pause");
				}
				}
			}
			break;
		}
		case 3:
			exit(0);
			break;
		default: {
			system("cls");
			cout << "Неверный выбор!\nПовторите попытку." << endl;
			system("pause");
		}
		}
	}
	return 0;
}