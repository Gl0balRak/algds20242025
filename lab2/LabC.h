#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "HashMap.h"

#define INPUT_FILE "graph.txt"
#define OUTPUT_FILE "output.txt"


// ������� ����������� �����
char** get_words_from_file(FILE* file);

// ������� ��������� ������� ����, ��� ������� ����� �������������� ����� �� 1 �� n
HashMap* get_words_table(char** words);

// ������� ����������� �� ����� ����� ����� �������
int** get_segments(FILE* file, HashMap* dict);

// ����������� ������� �������������� ����������
void top_sort(int i, int* visited, int* st, int** graph, int length);