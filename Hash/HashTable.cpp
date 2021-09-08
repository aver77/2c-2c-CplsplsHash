#include "HashTable.h"

void hashTable::Init()
{
	for (int i = 0; i < maxSize; i++)
	{
		HashTable[i].first = nullptr;
		HashTable[i].second = 0;
	}
}

pair<TNode, int> hashTable::get(int i = 0)
{
	return HashTable[i];
}

//складываем коды цифр и находим их остаток от деления на maxSize = 1000
int hashTable::hash_func(string number)
{
	int result = 0;
	for (int i = 0; i < number.size(); i++)
	{
		result += int(number[i]);
	}
	return (result) % maxSize;
}

void hashTable::create_from_file()
{
	ifstream fin("inp.txt");
	while (fin)
	{
		//заполняем temp_struct данными из узла поочередно
		TNode temp_struct = new Node;
		string path_struct;

		fin >> path_struct;
		temp_struct->number = path_struct;

		fin >> path_struct;
		temp_struct->surname = path_struct;
		
		//находим индекс под данную структуру
		int hashIndex = hash_func(temp_struct->number);

		//если данный индекс уже занят, то смещаемся вправо до тех пор пока не найдем свободное/удаленное (свободное) место
		while (hashIndex < maxSize && HashTable[hashIndex].second == 1)
			hashIndex++; //вычисляем нужный индекс

		//при нахождении свободного места в массиве сохраняем структуру
		if (HashTable[hashIndex].second == 0 || HashTable[hashIndex].second == -1)
		{
			HashTable[hashIndex].first = temp_struct;
			HashTable[hashIndex].second = 1; //занимает место
		}
		else
		{
			cout << "Нет места в таблице! \n";
		}
		temp_struct = nullptr;
		delete temp_struct;
	}
}

void hashTable::print()
{
	for (int i = 0; i < maxSize; i++)
	{
		if (HashTable[i].second == 1)
		{
			cout << HashTable[i].first->surname << " ";
			cout << HashTable[i].first->number << endl;
		}
	}
}
int hashTable::find_index(string key) //key - номер с клавиатуры
{
	int index = hash_func(key); //обратное хеширование номера

	bool find = false; //флаг нахождения нужного номера

	while (index < maxSize && !find && key != "y")
	{
		//проверка на существование номера + совпадение его соответствующей позиции на найденном индексе
		if (HashTable[index].first != nullptr && HashTable[index].first->number == key && HashTable[index].second == 1)
		{
			find = true;
		}
		//Если номер не находится на позиции index, то двигаемся вправо
		else if (HashTable[index].second == -1 || HashTable[index].second == 1)
		{
			index++;
		}
		//выход
		else
		{
			find = true;
		}
	}
	//если на выходе ключ (нахождение номера) 0 или 1, то он не найден
	if (HashTable[index].second == 0 || HashTable[index].second == -1)
	{
		cout << "Введёный номер не найден! \n";
	}
	return index;
}

//void hashTable::remove(string key)
//{
//	int keyHash = hash_func(key);
//
//	if (HashTable[keyHash].second == 1 && HashTable[keyHash].first->number == key)
//	{
//		HashTable[keyHash].first = nullptr;
//		delete HashTable[keyHash].first;
//		HashTable[keyHash].second = -1;
//	}
//}
