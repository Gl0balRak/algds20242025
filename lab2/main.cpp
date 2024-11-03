#include "LabC.h"


int main() {
	HashMap* hm = CreateHashMap((uint16_t)1024);

	char a[] = "asfdiu21";
	AddItem(hm, a, 24);
	char b[] = "srey1";
	AddItem(hm, b, 267);
	char c[] = "ifkhsd";
	AddItem(hm, c, 90);

	char** keys = GetKeys(hm);

	printf("%s %s\n", keys[0], a);
	printf("%s %s\n", keys[1], b);
	printf("%s %s\n", keys[2], c);
	/*
	// ��������� ������ �� �����
	FILE* file =  fopen(INPUT_FILE, "r");
	char** words = get_words_from_file(file);

	HashMap* dict = get_words_table(words);

	char** keys = GetKeys(dict);

	int** graph = get_segments(file, dict);
	int length = dict->keys_size;

	// ��������� �������������� ����������

	int* st = (int*)malloc((length + 1) * sizeof(int));
	st[0] = -1;
	int* visited = (int*)malloc(length * sizeof(int));
	for (int i = 0;i < length;i++) visited[i] = 0;

	// �������� ����������� ��������������� ������� �������������� ���������� ��� ������ �������
	for (int i = 0; i < length; i++)
		if (visited[i] == 0)
			top_sort(i, visited, st, graph, length);

	length = 0;
	while (st[length] != -1) length++;

	// �������� �������� ��� ����� ������������������ �� ���������� ������� �������� ��� ��� ���� ���������� ���������
	int flag = 1;
	for (int i = 0;i < length;i++) {
		for (int j = i;j < length;j++) {
			if (graph[st[i]][st[j]] == 1) {
				flag = 0;
			}
		}
	}

	// �� ����������� �������������� ���������� � �������� ���������� ��������� � �������� ����
	file = fopen(OUTPUT_FILE, "w");
	if (flag) {
		for (int j = length - 1;j >= 0;j--)
			fprintf(file, "%s ", GetKeyByValue(dict, st[j]));
	}
	else {
		fprintf(file, "[Error]");
	}
	*/
}