#include "DoublyLinkedList.h"

//�������� ������ ����
linkedListNode* createNode(const char* data) {
    linkedListNode* newNode = (linkedListNode*)malloc(sizeof(linkedListNode));
    if (!newNode) {
        fprintf(stderr, "������ ��������� ������ ��� ����\n");
        return NULL;
    }

    newNode->data = (char*)malloc(strlen(data) + 1);
    if (!newNode->data) {
        fprintf(stderr, "������ ��������� ������ ��� ������\n");
        free(newNode);
        return NULL;
    }

    strcpy(newNode->data, data);
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

//���������� ���� � ����� ������
linkedListNode* appendNode(linkedListNode* head, const char* data) {
    linkedListNode* newNode = createNode(data);
    if (!newNode) {
        return head;
    }

    //���� ������ ����, ����� ���� ���������� �������
    if (head == NULL) {
        return newNode;
    }

    //������� ��������� ����
    linkedListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    //����� ���� � �����
    current->next = newNode;
    newNode->prev = current;

    return head;
}

//������� ����� ������
int listLength(linkedListNode* head) {
    int count = 0;
    linkedListNode* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

//������������ ������ ������
void freeList(linkedListNode* head) {
    linkedListNode* current = head;
    while (current != NULL) {
        linkedListNode* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

//������ ������
void printList(linkedListNode* head) {
    linkedListNode* current = head;
    while (current != NULL) {
        printf("%s", current->data);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

//����������
linkedListNode* bubbleSort(linkedListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    int length = listLength(head);
    int swapped;

    do {
        swapped = 0;
        linkedListNode* current = head;

        while (current != NULL && current->next != NULL) {
            if (strcmp(current->data, current->next->data) > 0) {
                char* temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);

    return head;
}