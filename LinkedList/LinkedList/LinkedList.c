//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//// 线性表的链式存储 不连续的空间
//// 链表是由一系列的结点组成
//// 包含两个域，数据域+指针域
//// data next 
//// 单向链表实现
//// 数据结构是处理算法的载体
//
//// O 只关注最高次项
//// 最高次项的乘数不是1就舍去
//// 如果是常数项记作1
//
//// 链表结点
//typedef struct LINKNODE{
//	void* data; // 指向任何类型的数据
//	struct LINKNODE* next;
//}LinkNode;
//
//// 链表结构体,不需要容量，当时申请
//typedef struct LINKLIST{
//	LinkNode* head;
//	int size;
//}LinkList;
//
//
//// 初始化链表
//LinkList* Init_LinkList(){
//	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
//	list->size = 0;
//
//	// 头结点不保存数据
//	list->head = (LinkNode*)malloc(sizeof(LinkNode));
//	list->head->data = NULL;
//	list->head->next = NULL;
//	return list;
//}
//// 指定位置插入
//void Insert_LinkList(LinkList* list,int pos,void* data){
//	if (NULL == list){
//		return;
//	}
//	if (NULL == data){
//		return;
//	}
//
//
//	// 友好处理 pos 不正常情况
//	if (pos < 0 || pos > list->size){
//		pos = list->size;
//	}
//
//	// 创建新的结点
//	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
//	newnode->data = data;
//	newnode->next = NULL;
//
//	// 找结点
//	// 辅助指针变量
//	LinkNode* pCurrent = list->head;
//	for (int i = 0; i < pos;i++){
//		pCurrent = pCurrent->next;
//	}
//	// 新结点入链表
//	newnode->next = pCurrent->next;
//	pCurrent->next = newnode;
//	list->size++;
//}
//// 指定位置删除值
//void RemoveByPos_LinkList(LinkList* list, int pos){
//	if (NULL == list){
//		return;
//	}
//
//
//	// 删除时一定要注意判断
//	if (pos<0 || pos >= list->size){
//		return;
//	}
//
//	// 查找删除结点的前一个结点
//	LinkNode* pCurrent = list->head;
//	for (int i = 0; i < pos;i++){
//		pCurrent = pCurrent->next;
//	}
//
//	// 缓存需要删除的结点
//	LinkNode* pDel = pCurrent->next;
//	pCurrent->next = pDel->next;
//
//	// 释放删除的结点
//	free(pDel);
//	//pCurrent->next = pNext->next;
//	//free(pNext);
//}
//// 返回链表的长度
//int Size_LinkList(LinkList* list){
//	return list->size;
//}
//// 返回第一个结点
//void* Front_LinkList(LinkList* list){
//	return list->head->next->data;
//}
//// 查找
//int Find_LinkList(LinkList* list,void* data){
//	if (NULL == list){
//		return -1;
//	}
//	if (data == NULL){
//		return -1;
//	}
//// 遍历查找
//	LinkNode* pCurrent = list->head->next;
//	int i = 0;
//	while(NULL != pCurrent){
//		if (pCurrent->data == data){
//			break;
//		}
//		i++;
//		pCurrent = pCurrent->next;
//	}
//	return 0;
//}
//// 释放链表内存
//void FreeSpace_LinkList(LinkList* list){
//	if (NULL == list){
//		return;
//	}
//	// 辅助指针
//	LinkNode* pCurrent = list->head;
//	while (NULL != pCurrent){
//		// 缓存下一个结点
//		LinkNode* pNext = pCurrent->next;
//		free(pCurrent);
//		pCurrent = pNext;
//	}
//	// 释放链表内存
//	list->size = 0;
//	free(list);
//}
//// 打印的函数指针
//typedef void(*PRINTLINKNODE)(void*);
//// 打印链表结点
//void Print_LinkList(LinkList* list, PRINTLINKNODE print){
//	if (NULL == list){
//		return;
//	}
//	// 定义一个辅助指针变量
//	LinkNode* pCurrent = list->head->next;
//	while (NULL != pCurrent){
//		print(pCurrent->data);
//		pCurrent = pCurrent->next;
//	}
//}
//
//typedef struct PERSON{
//	char name[64];
//	int age;
//	int score;
//}Person;
//
//// 打印函数
//void MyPrint(void* data){
//	Person* p = (Person*)data;
//	printf("Name:%s  Age:%d Score:%d\n",p->name,p->age,p->score);
//}
//int main(){
//
//	// 创建一个链表
//	LinkList* list = Init_LinkList();
//
//
//	// 创建数据
//	Person p1 = { "张1", 22, 48 };
//	Person p2 = { "张2", 23, 28 };
//	Person p3 = { "张3", 21, 98 };
//	Person p4 = { "张4", 24, 88 };
//	Person p5 = { "张5", 25, 78 };
//
//	// 数据插入链表
//	Insert_LinkList(list, 0, &p1);
//	Insert_LinkList(list, 0, &p2);
//	Insert_LinkList(list, 0, &p3);
//	Insert_LinkList(list, 0, &p4);
//	Insert_LinkList(list, 0, &p5);
//
//
//	// 打印
//	Print_LinkList(list,MyPrint);
//	printf("==============================\n");
//	// 删除3
//	RemoveByPos_LinkList(list,2);
//	Print_LinkList(list, MyPrint);
//
//	// 销毁链表
//	FreeSpace_LinkList(list);
//	system("pause");
//	return 0;
//}