#include "pch.h"
#include "../LabA/LabA.cpp" // ����� *.cpp � �� *.h ������ ���, ��� ������,
							// ������ ������ �� �� ����� ����� ������ ������� � ���� �����
							// (����� ������� ������ �� StackOverflow, ������� ������� �������� ����� �� �������)


// ���� ���� ������������ ������ ������� � ����� ���� ����� 0, ����� ������ ������ ���� NULL ��� ��� ������ ������ ���� �� �����
TEST(UlList__ul_create_list__Test, CreateListZeroMaxlength___1) {
	ul_list* list = ul_create_list(0);
	int eq = list == NULL;
	EXPECT_EQ(1, eq);
}

// ���� ���� ������������ ������ ������� � ����� ���� ����� 5
TEST(UlList__ul_create_list__Test, CreateListFiveMaxlength___2) {
	ul_list* list = ul_create_list(5);

	int* val_list = ul_to_array(list);
	int true_list[5] = { 0, 0, 0, 0, 0 };

	int eq = ul_equal(val_list, true_list, 5);
	EXPECT_EQ(1, eq);
}

// ��������� �������� � ������ 3 �������� (����� �� 1 �� 3)
TEST(UlList__ul_add_item__Test, AddThreeElements___3) {
	ul_list* list = ul_create_list(5);

	for (int i = 1;i < 4;i++)
		ul_add_item(list, i);

	int* val_list = ul_to_array(list);
	int true_list[5] = { 1, 2, 3, 0, 0 };

	int eq = ul_equal(val_list, true_list, 5);
	EXPECT_EQ(1, eq);
}

// ��������� �������� � ������ 7 ��������� (����� �� 1 �� 7)
// � ����� �������� (�.�. ������������ ����� ��������� � node ����� 5) ������ ���� ������ ��� ���� node)
TEST(UlList__ul_add_item__Test, AddSevenElements__4) {
	ul_list* list = ul_create_list(5);

	for (int i = 1;i < 8;i++)
		ul_add_item(list, i);

	int* val_list = ul_to_array(list);
	int true_list[10] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, 0 };

	int eq = ul_equal(val_list, true_list, 10);
	EXPECT_EQ(1, eq);
}

// ��������� ������� �� ������ 1 ������� (�� �������) �� ���������� node
TEST(UlList__ul_del_item__Test, DelOneElementFromLastNode__5) {
	ul_list* list = ul_create_list(5);

	for (int i = 1;i < 8;i++)
		ul_add_item(list, i);
	ul_del_item(list, 6);

	int* val_list = ul_to_array(list);
	int true_list[10] = { 1, 2, 3, 4, 5, 6, 0, 0, 0, 0 };

	int eq = ul_equal(val_list, true_list, 10);
	EXPECT_EQ(1, eq);
}

// ��������� ������� �� ������ 1 ������� (�� �������) �� ������� node
TEST(UlList__ul_del_item__Test, DelOneElementFromFirstNode__6) {
	ul_list* list = ul_create_list(5);

	for (int i = 1;i < 8;i++)
		ul_add_item(list, i);
	ul_del_item(list, 3);

	int* val_list = ul_to_array(list);
	int true_list[10] = { 1, 2, 3, 5, 0, 6, 7, 0, 0, 0 };

	int eq = ul_equal(val_list, true_list, 10);
	EXPECT_EQ(1, eq);
}

// ��������� ������� �� ������ ��� �������� ������������� node (����� ����� node ������ ���� ��������� ���������)
TEST(UlList__ul_del_item__Test, DelAllElemntsFromOneNode__7) {
	ul_list* list = ul_create_list(5);

	for (int i = 1;i < 8;i++)
		ul_add_item(list, i);

	for (int i = 0;i < 5;i++) 
		ul_del_item(list, 0);

	int* val_list = ul_to_array(list);
	int true_list[5] = { 6, 7, 0, 0, 0 };

	int eq = ul_equal(val_list, true_list, 5);
	EXPECT_EQ(1, eq);
}

// ��������� ������� �� ������ ������� �������� ��� ��� (������� 13-�� �������, � ������ ������ 7)
TEST(UlList__ul_del_item__Test, DelOneNonExistentElement__8) {
	ul_list* list = ul_create_list(5);

	for (int i = 1;i < 8;i++)
		ul_add_item(list, i);
	ul_del_item(list, 13);

	int* val_list = ul_to_array(list);
	int true_list[10] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, 0 };

	int eq = ul_equal(val_list, true_list, 10);
	EXPECT_EQ(1, eq);
}

// ��������� ������� �� ������� ������ ���� �������
TEST(UlList__ul_del_item__Test, DelOneElementFromEmptyList__9) {
	ul_list* list = ul_create_list(5);

	ul_del_item(list, 3);

	int* val_list = ul_to_array(list);
	int true_list[5] = { 0, 0, 0, 0, 0 };

	int eq = ul_equal(val_list, true_list, 5);
	EXPECT_EQ(1, eq);
}


// ������� �������� ��������� �������
TEST(UlList__ul_get_next__Test, GetNextElement__10) {
	ul_list* list = ul_create_list(5);

	for (int i = 1;i < 8;i++)
		ul_add_item(list, i);

	int value = ul_get_next(6, list);

	EXPECT_EQ(7, value);
}


// ������� �������� ��������� ������� �������� ���
TEST(UlList__ul_get_next__Test, GetEmptyNextElement__11) {
	ul_list* list = ul_create_list(5);

	for (int i = 1;i < 8;i++)
		ul_add_item(list, i);

	int value = ul_get_next(7, list);

	EXPECT_EQ(value, NULL);
}


// ������� �������� ������ ������
TEST(UlList__ul_length__Test, GetLengthFromSevenElementsList__12) {
	ul_list* list = ul_create_list(5);

	for (int i = 1;i < 8;i++)
		ul_add_item(list, i);

	int value = ul_length(list);

	EXPECT_EQ(value, 7);
}
