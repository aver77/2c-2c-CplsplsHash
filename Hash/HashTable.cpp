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

//���������� ���� ���� � ������� �� ������� �� ������� �� maxSize = 1000
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
		//��������� temp_struct ������� �� ���� ����������
		TNode temp_struct = new Node;
		string path_struct;

		fin >> path_struct;
		temp_struct->number = path_struct;

		fin >> path_struct;
		temp_struct->surname = path_struct;
		
		//������� ������ ��� ������ ���������
		int hashIndex = hash_func(temp_struct->number);

		//���� ������ ������ ��� �����, �� ��������� ������ �� ��� ��� ���� �� ������ ���������/��������� (���������) �����
		while (hashIndex < maxSize && HashTable[hashIndex].second == 1)
			hashIndex++; //��������� ������ ������

		//��� ���������� ���������� ����� � ������� ��������� ���������
		if (HashTable[hashIndex].second == 0 || HashTable[hashIndex].second == -1)
		{
			HashTable[hashIndex].first = temp_struct;
			HashTable[hashIndex].second = 1; //�������� �����
		}
		else
		{
			cout << "��� ����� � �������! \n";
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
int hashTable::find_index(string key) //key - ����� � ����������
{
	int index = hash_func(key); //�������� ����������� ������

	bool find = false; //���� ���������� ������� ������

	while (index < maxSize && !find && key != "y")
	{
		//�������� �� ������������� ������ + ���������� ��� ��������������� ������� �� ��������� �������
		if (HashTable[index].first != nullptr && HashTable[index].first->number == key && HashTable[index].second == 1)
		{
			find = true;
		}
		//���� ����� �� ��������� �� ������� index, �� ��������� ������
		else if (HashTable[index].second == -1 || HashTable[index].second == 1)
		{
			index++;
		}
		//�����
		else
		{
			find = true;
		}
	}
	//���� �� ������ ���� (���������� ������) 0 ��� 1, �� �� �� ������
	if (HashTable[index].second == 0 || HashTable[index].second == -1)
	{
		cout << "������� ����� �� ������! \n";
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
