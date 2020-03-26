#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

// ����Ϊ����ļ�ʵ��

// ����������
typedef struct LINKNODE{
	void* data;
	struct LINKNODE* next;
}LinkNode;

//  ��������
typedef struct LINKLIST{
	LinkNode* head;
	int size;
}LinkList;

typedef struct STUDENT{
	char name[1024];
	int age;
	int score;
}Student;

// ��ʼ������
LinkList* Init(){
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->size = 0;
	// ͷ����в���������
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}

// β��
void back_insert(LinkList* list,void* data){
	if (NULL == list){
		return;
	}
	// mallocһ����Ҫ����Ľ��
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	// �ҵ���Ҫ�����λ��
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < list->size;i++){
		pCurrent = pCurrent->next;
	}
	pCurrent->next = newnode;
	list->size++;
}
// ͷ�巨
void front_insert(LinkList* list,void* data){
	if (NULL == list){
		return;
	}
	// ����һ���µĲ�����
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = list->head->next;
	list->head->next = newnode;
	list->size++;
}
// ָ��λ�ò���
void insert_pos(LinkList* list,int pos,void* data){
	if (NULL == list){
		return;
	}
	if (NULL == data){
		return;
	}
	if (pos < 0 || pos >= list->size){
		return;
	}
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	LinkNode* pCurrent = list->head;
	//      pCurrent  pNext 
	///       1 2 43
	for (int i = 0; i < pos-1;i++){
		pCurrent = pCurrent->next;
	}
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	list->size++;
}

// ָ��λ��ɾ��
void DelPos(LinkList* list,int pos){
	if (NULL == list){
		return;
	}
	if (pos < 0 || pos > list->size){
		return;
	}
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos-1;i++){
		pCurrent = pCurrent->next;
	}
	LinkNode* pNext = pCurrent->next->next;
	pCurrent->next = pNext;
	list->size--;
}

// ��ӡ
typedef void(*PRINT)(void*);
void Print(LinkList* list,PRINT print){
	if (NULL == list){
		return;
	}
	LinkNode* pCurrent = list->head->next;
	while (NULL != pCurrent){
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}
void MyPrint(void* node){
	if (NULL == node){
		return;
	}
	LinkNode* newnode = (LinkNode*)node;
	Student* student = (Student*)newnode->data;
	printf("name:%s age:%d score:%d\n", student->name, student->age, student->score);
}
//����ͷ���
LinkNode* getFirst(LinkList* list){
	return list->head->next;
}
// �������
void Clear(LinkList* list){
	if (NULL == list){
		return;
	}
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < list->size;i++){
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	list->size = 0;
	free(list);
}


int main(){
	Student s1 = { "��1", 12, 56 };
	Student s2 = { "��2", 34, 78 };
	Student s3 = { "��3", 14, 34 };
	Student s4 = { "��4", 56, 92 };
	Student s5 = { "��5", 67, 56 };
	Student s6 = { "��6", 62, 16 };

	LinkList* list = Init();
	back_insert(list, &s1);
	back_insert(list, &s2);
	front_insert(list, &s3);
	front_insert(list, &s4);
	back_insert(list, &s5);
	insert_pos(list, 3, &s6);
	Print(list, MyPrint);
	printf("==== del ====\n");
	DelPos(list,1);
	Print(list,MyPrint);

	Clear(list);
	system("pause");
	return 0;
}