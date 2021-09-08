#include <iostream>
#include <fstream>
#include <string>
//директива библиотеки stl для работы с парой структура , int ключ
//так же first - структура, second - int ключ (встроенно)
#include <utility>
#include "HashTable.h"

using namespace std;

void Task1(hashTable HASHtable);

int main()
{
	setlocale(LC_ALL, "ru");
	hashTable HASHtable;
	//инициализация
	HASHtable.Init();
	//создаем hashTable
	HASHtable.create_from_file();
	//печать
	HASHtable.print();
	//Выпоняем поиск по номеру
	Task1(HASHtable);
	return 0;
}

void Task1(hashTable HASHtable)
{
	string key;
	do
	{
		cout << "Введите номер:\n->";
		getline(cin, key);
		int index = HASHtable.find_index(key);
		if (HASHtable.get(index).second == 1)
		{
			cout << HASHtable.get(index).first->surname << " ";
			cout << "\nЗавершить работу программы? y/n:\n->";
			getline(cin, key);
		}
	} while (key != "y");
}