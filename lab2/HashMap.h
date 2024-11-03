#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <memory.h>


typedef struct item {
	char* key;
	int value;
} item;

// ��������� ���-�������
typedef struct HashMap {
	size_t size;
	item** items;

	size_t keys_size;
	char** keys;

	uint16_t mod;
} HashMap;

HashMap* CreateHashMap(uint16_t mod); // ������� �������� ���-�������
void AddItem(HashMap* hm, char* key, int value); // ������� ���������� ������ � ���-�������
int GetValue(HashMap* hm, char* key); // ���������� �������� �� �����
char* GetKeyByValue(HashMap* hm, int value); // ������� ��������� ����� �� �������� (������ ���������� ��� ����� ���� �� ������ ������)
char** GetKeys(HashMap* hm); // ������ ��������� ������ ���� ������ �� ���-�������

int cmp_str(char* s1, char* s2); // ������� ��������� �����