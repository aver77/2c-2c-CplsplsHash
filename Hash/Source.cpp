#include <iostream>
#include <fstream>
#include <string>
//��������� ���������� stl ��� ������ � ����� ��������� , int ����
//��� �� first - ���������, second - int ���� (���������)
#include <utility>
#include "HashTable.h"

using namespace std;

void Task1(hashTable HASHtable);

int main()
{
	setlocale(LC_ALL, "ru");
	hashTable HASHtable;
	//�������������
	HASHtable.Init();
	//������� hashTable
	HASHtable.create_from_file();
	//������
	HASHtable.print();
	//�������� ����� �� ������
	Task1(HASHtable);
	return 0;
}

void Task1(hashTable HASHtable)
{
	string key;
	do
	{
		cout << "������� �����:\n->";
		getline(cin, key);
		int index = HASHtable.find_index(key);
		if (HASHtable.get(index).second == 1)
		{
			cout << HASHtable.get(index).first->surname << " ";
			cout << "\n��������� ������ ���������? y/n:\n->";
			getline(cin, key);
		}
	} while (key != "y");
}