#include <iostream>
#include <stack>
#include <stdlib.h>
#include "list.h"

using namespace std;

void PrintListReverse(ListNode* pHead); 
void PrintListReverse2(ListNode* pHead);


int main() {

	ListNode* pHead = new ListNode();
	for (int i = 0; i < 5; i++) {
		AddToTail(pHead, i);
	}
	Traverse(pHead);

	//在位置1处插入一个元素3
	Insert(pHead, 0, 3);
	Traverse(pHead);

	//在链表末尾追加一个元素9
	AddToTail(pHead, 9);
	Traverse(pHead);

	//删除元素0
	Delete(pHead, 0);
	Traverse(pHead);

	PrintListReverse(pHead);


	//删除整个链表
	DeleteList(pHead);
	Traverse(pHead);

	system("pause");
	return 0;
}

//基于栈的思路 //反向输出链表元素
void PrintListReverse(ListNode* pHead) { //pHead不存储有效数据
	if (pHead == NULL)
		return;
	ListNode* pNode = pHead->next; //第一个节点
	stack<ListNode*> s;

	while (pNode != NULL) {
		s.push(pNode);
		pNode = pNode->next;
	}
	
	while (!s.empty()) {
		pNode = s.top();
		printf("%d ", pNode->value);
		s.pop();
	}
	printf("\n");
	return;
}

//其实递归也是一种栈，只是如果递归深度太深，会造成栈溢出的风险
//显式的使用栈，代码的鲁棒性更好。

void PrintListReverse2(ListNode* pHead) { //反向输出链表元素（递归版）
	if (pHead->next != NULL) {
		if (pHead->next->next != NULL) {
			PrintListReverse(pHead->next);
		}

		printf("%d ", pHead->next->value);
	}

	return;
}