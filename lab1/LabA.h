#pragma once


// ��������� ����
typedef struct ul_node {
    int* numbers;
    int length;

    struct ul_node* next;

} ul_node;


// ��������� ������ ������
typedef struct {
    int max_length; // ����������� ����� ����� � ����� node
    int nodes_length; // ������� ���������� node'��, ����� ��� ���������/��������� ��������� �������

    ul_node* head; // ������ node � ������

} ul_list;



ul_list* ul_create_list(int max_length); // �������� ������� ������
ul_list* ul_add_item(ul_list* list, int item); // ���������� �������� � ������
int ul_get_item(ul_list* list, int index); // ��������� �������� �� �������
ul_list* ul_del_item(ul_list* list, int index); // �������� �������� �� �������
int ul_length(ul_list* list); // ��������� ������ ������
void ul_display(ul_list* list); // ������� ��� ������ ������ � ������

int* ul_to_array(ul_list* list); // �������������� ����� ����������� ():�?*"%;:723854708 ������ � ������� ������(��������� ��� ���������� ������)
int ul_equal(int* list1, int* list2, int length); // ����� ��� ��������� ���� ������� �������� (��������� ��� ���������� ������)
int ul_get_next(int number, ul_list* list); // ������� ��������� ���������� ��������
