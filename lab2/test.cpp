#include "pch.h"
#include "../LabC/LabC.cpp"
#include "../LabC/HashMap.cpp"


// ��������� ������� �������� �������
TEST(HashMap_Tests, CreateHashMap_test__1) {
	HashMap* hm = CreateHashMap((uint16_t)1024);


	EXPECT_EQ(hm->mod, 52685);
	EXPECT_EQ(hm->keys_size, 0);
	EXPECT_EQ(hm->size, 0);
}

// ��������� ������� ���������� ���� (����, ��������) � ������
TEST(HashMap_Tests, AddItem_test__2) {
	HashMap* hm = CreateHashMap((uint16_t)1024);

	char a[] = "abc";

	AddItem(hm, a, 13);

	EXPECT_EQ(GetValue(hm, a), 13);
}

// ��������� ������� ��������� �������� �� �����
TEST(HashMap_Tests, GetValue_test__3) {
	HashMap* hm = CreateHashMap((uint16_t)1024);

	char b[] = "asfdiu21";
	AddItem(hm, b, 1237);

	int value = GetValue(hm, b);

	EXPECT_EQ(value, 1237);
}

// ��������� ������� ��������� ����� �� ��������
TEST(HashMap_Tests, GetKeyByValue_test__4) {
	HashMap* hm = CreateHashMap((uint16_t)1024);

	char b[] = "asfdiu21";
	AddItem(hm, b, 563);

	char* c = GetKeyByValue(hm, 563);

	EXPECT_EQ(c, b);
}

// ��������� ������� ��������� ����� (������ ������ ������)
TEST(HashMap_Tests, cmpr_str_DiffLengthStrings_test__6) {
	char a[] = "srey1";
	char b[] = "srey1234";

	int equal = cmp_str(a, b);

	EXPECT_EQ(equal, 0);
}


// ��������� ������� ��������� ����� (������ �� �����)
TEST(HashMap_Tests, cmpr_str_DiffStrings_test__7) {
	char a[] = "sre21";
	char b[] = "srey1";

	int equal = cmp_str(a, b);

	EXPECT_EQ(equal, 0);
}


// ��������� ������� ��������� ����� (������ �����)
TEST(HashMap_Tests, cmpr_str_DiffStrings_test__8) {
	char a[] = "sre21";
	char b[] = "sre21";

	int equal = cmp_str(a, b);

	EXPECT_EQ(equal, 1);
}


// ��������� ������� ��������� ����� (������ ������)
TEST(HashMap_Tests, cmpr_str_DiffStrings_test__9) {
	char a[] = "";
	char b[] = "";

	int equal = cmp_str(a, b);

	EXPECT_EQ(equal, 1);
}

// ��������� ������� ��������� ������ ������
TEST(HashMap_Tests, GetKeys_test__5) {
	HashMap* hm = CreateHashMap((uint16_t)1024);

	char a[] = "asfdiu21";
	AddItem(hm, a, 24);
	char b[] = "srey1";
	AddItem(hm, b, 267);
	char c[] = "asfdiu21";
	AddItem(hm, c, 90);

	char** keys = GetKeys(hm);

	EXPECT_EQ(cmp_str(a, keys[0]), 1);
	EXPECT_EQ(cmp_str(b, keys[1]), 1);
	EXPECT_EQ(cmp_str(c, keys[2]), 1);
}

// ��������� ������� ������� ������� ������� (������������ ������� ����� ����� �� 0 �� n)
TEST(LabC_Tests, get_words_table_test__10) {
	char** words = (char**)malloc(sizeof(char*) * 3);

	words[0] = (char*)malloc(sizeof(char) * 3);
	for (int i = 0;i < 3;i++)
		words[0][i] = "ab"[i];

	words[1] = (char*)malloc(sizeof(char) * 3);
	for (int i = 0;i < 3;i++)
		words[1][i] = "bf"[i];

	words[2] = NULL;

	HashMap* dict = get_words_table(words);

	for (int i = 0;i < 2;i++)
		EXPECT_EQ(i, GetValue(dict, words[i]));
}