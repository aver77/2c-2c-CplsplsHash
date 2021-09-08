#pragma once
#include <iostream>
#include <fstream>
#include <utility>
#include "Structure.h"

const int maxSize = 1000;

class hashTable
{
	pair<TNode, int> HashTable[maxSize];
public:
	//базовые конструктор и деструктор класса
	hashTable() {};
	~hashTable() {};

	pair<TNode, int> get(int); //получение данных на данном месте

	void Init(); //инициализация узла

	int hash_func(string); //хэш функция для предотращения коллизий

	void create_from_file();

	void print(); //печать

	int find_index(string); //поиск индекса

	/*void remove(string); //удаление данных из хэш таблицы*/
};
