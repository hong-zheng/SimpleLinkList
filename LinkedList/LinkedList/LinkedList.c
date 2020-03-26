//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//// ���Ա����ʽ�洢 �������Ŀռ�
//// ��������һϵ�еĽ�����
//// ����������������+ָ����
//// data next 
//// ��������ʵ��
//// ���ݽṹ�Ǵ����㷨������
//
//// O ֻ��ע��ߴ���
//// ��ߴ���ĳ�������1����ȥ
//// ����ǳ��������1
//
//// ������
//typedef struct LINKNODE{
//	void* data; // ָ���κ����͵�����
//	struct LINKNODE* next;
//}LinkNode;
//
//// ����ṹ��,����Ҫ��������ʱ����
//typedef struct LINKLIST{
//	LinkNode* head;
//	int size;
//}LinkList;
//
//
//// ��ʼ������
//LinkList* Init_LinkList(){
//	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
//	list->size = 0;
//
//	// ͷ��㲻��������
//	list->head = (LinkNode*)malloc(sizeof(LinkNode));
//	list->head->data = NULL;
//	list->head->next = NULL;
//	return list;
//}
//// ָ��λ�ò���
//void Insert_LinkList(LinkList* list,int pos,void* data){
//	if (NULL == list){
//		return;
//	}
//	if (NULL == data){
//		return;
//	}
//
//
//	// �Ѻô��� pos ���������
//	if (pos < 0 || pos > list->size){
//		pos = list->size;
//	}
//
//	// �����µĽ��
//	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
//	newnode->data = data;
//	newnode->next = NULL;
//
//	// �ҽ��
//	// ����ָ�����
//	LinkNode* pCurrent = list->head;
//	for (int i = 0; i < pos;i++){
//		pCurrent = pCurrent->next;
//	}
//	// �½��������
//	newnode->next = pCurrent->next;
//	pCurrent->next = newnode;
//	list->size++;
//}
//// ָ��λ��ɾ��ֵ
//void RemoveByPos_LinkList(LinkList* list, int pos){
//	if (NULL == list){
//		return;
//	}
//
//
//	// ɾ��ʱһ��Ҫע���ж�
//	if (pos<0 || pos >= list->size){
//		return;
//	}
//
//	// ����ɾ������ǰһ�����
//	LinkNode* pCurrent = list->head;
//	for (int i = 0; i < pos;i++){
//		pCurrent = pCurrent->next;
//	}
//
//	// ������Ҫɾ���Ľ��
//	LinkNode* pDel = pCurrent->next;
//	pCurrent->next = pDel->next;
//
//	// �ͷ�ɾ���Ľ��
//	free(pDel);
//	//pCurrent->next = pNext->next;
//	//free(pNext);
//}
//// ��������ĳ���
//int Size_LinkList(LinkList* list){
//	return list->size;
//}
//// ���ص�һ�����
//void* Front_LinkList(LinkList* list){
//	return list->head->next->data;
//}
//// ����
//int Find_LinkList(LinkList* list,void* data){
//	if (NULL == list){
//		return -1;
//	}
//	if (data == NULL){
//		return -1;
//	}
//// ��������
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
//// �ͷ������ڴ�
//void FreeSpace_LinkList(LinkList* list){
//	if (NULL == list){
//		return;
//	}
//	// ����ָ��
//	LinkNode* pCurrent = list->head;
//	while (NULL != pCurrent){
//		// ������һ�����
//		LinkNode* pNext = pCurrent->next;
//		free(pCurrent);
//		pCurrent = pNext;
//	}
//	// �ͷ������ڴ�
//	list->size = 0;
//	free(list);
//}
//// ��ӡ�ĺ���ָ��
//typedef void(*PRINTLINKNODE)(void*);
//// ��ӡ������
//void Print_LinkList(LinkList* list, PRINTLINKNODE print){
//	if (NULL == list){
//		return;
//	}
//	// ����һ������ָ�����
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
//// ��ӡ����
//void MyPrint(void* data){
//	Person* p = (Person*)data;
//	printf("Name:%s  Age:%d Score:%d\n",p->name,p->age,p->score);
//}
//int main(){
//
//	// ����һ������
//	LinkList* list = Init_LinkList();
//
//
//	// ��������
//	Person p1 = { "��1", 22, 48 };
//	Person p2 = { "��2", 23, 28 };
//	Person p3 = { "��3", 21, 98 };
//	Person p4 = { "��4", 24, 88 };
//	Person p5 = { "��5", 25, 78 };
//
//	// ���ݲ�������
//	Insert_LinkList(list, 0, &p1);
//	Insert_LinkList(list, 0, &p2);
//	Insert_LinkList(list, 0, &p3);
//	Insert_LinkList(list, 0, &p4);
//	Insert_LinkList(list, 0, &p5);
//
//
//	// ��ӡ
//	Print_LinkList(list,MyPrint);
//	printf("==============================\n");
//	// ɾ��3
//	RemoveByPos_LinkList(list,2);
//	Print_LinkList(list, MyPrint);
//
//	// ��������
//	FreeSpace_LinkList(list);
//	system("pause");
//	return 0;
//}