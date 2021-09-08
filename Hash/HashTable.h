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
	//������� ����������� � ���������� ������
	hashTable() {};
	~hashTable() {};

	pair<TNode, int> get(int); //��������� ������ �� ������ �����

	void Init(); //������������� ����

	int hash_func(string); //��� ������� ��� ������������� ��������

	void create_from_file();

	void print(); //������

	int find_index(string); //����� �������

	/*void remove(string); //�������� ������ �� ��� �������*/
};
