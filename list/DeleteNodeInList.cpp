#include <iostream>
#include <stdlib.h>
#include "list.h"

using namespace std;

int main() {
	//创建一个测试链表
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

	//测试按节点删除
	ListNode* tobeDelete = FindPosi(pHead, 6); //返回位置6处的节点地址
	Delete(pHead, tobeDelete);
	Traverse(pHead);


	system("pause");
	return 0;
}

