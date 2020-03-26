#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

// 以下为链表的简单实现

// 定义链表结点
typedef struct LINKNODE{
	void* data;
	struct LINKNODE* next;
}LinkNode;

//  定义链表
typedef struct LINKLIST{
	LinkNode* head;
	int size;
}LinkList;

typedef struct STUDENT{
	char name[1024];
	int age;
	int score;
}Student;

// 初始化链表
LinkList* Init(){
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->size = 0;
	// 头结点中不保存数据
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}

// 尾插
void back_insert(LinkList* list,void* data){
	if (NULL == list){
		return;
	}
	// malloc一个需要插入的结点
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	// 找到需要插入的位置
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < list->size;i++){
		pCurrent = pCurrent->next;
	}
	pCurrent->next = newnode;
	list->size++;
}
// 头插法
void front_insert(LinkList* list,void* data){
	if (NULL == list){
		return;
	}
	// 创建一个新的插入结点
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = list->head->next;
	list->head->next = newnode;
	list->size++;
}
// 指定位置插入
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

// 指定位置删除
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

// 打印
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
//返回头结点
LinkNode* getFirst(LinkList* list){
	return list->head->next;
}
// 清除链表
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
	Student s1 = { "张1", 12, 56 };
	Student s2 = { "张2", 34, 78 };
	Student s3 = { "张3", 14, 34 };
	Student s4 = { "张4", 56, 92 };
	Student s5 = { "张5", 67, 56 };
	Student s6 = { "张6", 62, 16 };

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